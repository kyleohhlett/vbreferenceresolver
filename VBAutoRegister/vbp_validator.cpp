#include "vbp_validator.hpp"

#include <fstream>

VbpValidator::VbpValidator() {
}

void VbpValidator::start() {

	MessageBox(NULL, "Select a .vbp file to check for registry errors", "VBAutoRegister", MB_OK);

	char fileToOpen[MAX_PATH] = { 0 };
	getVbpFileLocation(fileToOpen);

	loadReferences(fileToOpen);
	processReferences();

	std::string reportString = this->generateReportString();

	MessageBox(NULL, reportString.c_str(), "VBAutoRegister", MB_OK);
}

std::string VbpValidator::generateReportString() {

	std::string reportString;

	if (this->referenceErrors.size() < 1) {

		reportString = std::string("No reference issues found.");
	} else {
		for (std::vector<ReferenceError>::iterator currentReference = this->referenceErrors.begin();
			currentReference != this->referenceErrors.end(); ++currentReference) {

			if (currentReference->getReference().isNormalReference()) {

				reportString.append(currentReference->getReference().getFilepath());
				reportString.append("\n");
			} else if(currentReference->getReference().isObjectReference()) {

				reportString.append(currentReference->getReference().getFilename());
				reportString.append("\n");
			}
		}
	}

	return reportString;
}

void VbpValidator::loadReferences(char* fileToOpen) {

	std::fstream fileStream;
	fileStream.open(fileToOpen, std::fstream::in);

	char lineBuffer[255] = { 0 };
	while (!fileStream.eof()) {
		fileStream.getline(lineBuffer, sizeof(lineBuffer));

		std::string line = std::string(lineBuffer);

		if (Reference::IsReference(line))
			this->loadReference(this->convertLineToReference(line));
	}

	fileStream.close();
}

void VbpValidator::getVbpFileLocation(LPSTR fileToOpen) {

	OPENFILENAME openFilename;
	ZeroMemory(&openFilename, sizeof(openFilename));

	openFilename.lStructSize = sizeof(openFilename);
	openFilename.lpstrFilter = "Visual Basic Project File\0*.VBP\0\0";
	openFilename.lpstrFile = "\0";
	openFilename.nMaxFile = MAX_PATH;
	openFilename.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	openFilename.lpstrFile = fileToOpen;

	GetOpenFileName(&openFilename);
}

Reference VbpValidator::convertLineToReference(std::string lineInVbp) {

	return Reference(lineInVbp);
}

void VbpValidator::loadReference(Reference reference) {

	this->references.push_back(reference);
}

void VbpValidator::processReferences() {

	for (std::vector<Reference>::iterator currentReference = this->references.begin(); 
		currentReference != this->references.end(); ++currentReference) {

		processReference(*currentReference);
	}
}

void VbpValidator::processReference(Reference reference) {

	if (!reference.existsInRegistry()) {

		ReferenceError referenceError = ReferenceError(reference);
		this->referenceErrors.push_back(referenceError);
	}

	//TODO: include filepath checks
}