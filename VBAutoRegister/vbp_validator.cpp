#include "vbp_validator.hpp"

#include <fstream>

VbpValidator::VbpValidator() {

}

void VbpValidator::start() {

	char fileToOpen[MAX_PATH] = { 0 };
	getVbpFileLocation(fileToOpen);

	std::fstream fileStream;
	fileStream.open(fileToOpen, std::fstream::in);

	char lineBuffer[255] = { 0 };
	while (!fileStream.eof()) {
		fileStream.getline(lineBuffer, sizeof(lineBuffer));

		std::string line = std::string(lineBuffer);

		if (isObjectReference(line))
			this->processObjectReference(line, this->problematicObjectReferences);
		else if (isReference(line))
			this->processReference(line, this->problematicReferences);
	}
	//TODO: show message box with issues found
	MessageBox(NULL, "Finished Processing", "VBAutoRegister", MB_OK);
}

void VbpValidator::processObjectReference(std::string line, std::vector<std::string> problematicObjectReferences) {
	//TODO: implement
}

void VbpValidator::processReference(std::string line, std::vector<std::string> problematicReferences) {
	//TODO: implement
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