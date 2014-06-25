#include "vbp_validator.hpp"

#include <fstream>

VbpValidator::VbpValidator() {
}

void VbpValidator::start() {

	char fileToOpen[MAX_PATH] = { 0 };
	getVbpFileLocation(fileToOpen);

	loadReferences(fileToOpen);
	processReferences();

	//TODO: show message box with issues found
	MessageBox(NULL, "Finished Processing", "VBAutoRegister", MB_OK);
	
	//TODO: print report of issues
}

void VbpValidator::loadReferences(char* fileToOpen) {

	std::fstream fileStream;
	fileStream.open(fileToOpen, std::fstream::in);

	char lineBuffer[255] = { 0 };
	while (!fileStream.eof()) {
		fileStream.getline(lineBuffer, sizeof(lineBuffer));

		std::string line = std::string(lineBuffer);

		this->loadReference(this->convertLineToReference(line));
	}
}

bool VbpValidator::isObjectReference(std::string line) {

	return strncmp(line.c_str(), "Object=", std::string("Object=").length()) == 0;
}

bool VbpValidator::isReference(std::string line) {

	return strncmp(line.c_str(), "Reference=", std::string("Reference=").length()) == 0;
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
		currentReference != this->references.end(); currentReference++) {

		processReference(*currentReference);
	}
}

//TODO: implement
void VbpValidator::processReference(Reference reference) {

}