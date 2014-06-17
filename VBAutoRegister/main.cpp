#include <fstream>
#include <Windows.h>
#include "main.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {

	char fileToOpen[MAX_PATH] = { 0 };
	getVbpFileLocation(fileToOpen);

	std::fstream fileStream;
	fileStream.open(fileToOpen, std::fstream::in);

	char lineBuffer[255] = { 0 };
	while (!fileStream.eof()) {
		fileStream.getline(lineBuffer, sizeof(lineBuffer));

		std::string line = std::string(lineBuffer);

		if (isObjectReference(line))
			MessageBox(NULL, line.c_str(), "", MB_OK);
		else if (isReference(line))
			MessageBox(NULL, line.c_str(), "", MB_OK);

	}

	return 0;
}

bool isObjectReference(std::string line) {
	return strncmp(line.c_str(), "Object=", std::string("Object=").length()) == 0;
}

bool isReference(std::string line) {
	return strncmp(line.c_str(), "Reference=", std::string("Reference=").length()) == 0;
}

void getVbpFileLocation(LPSTR fileToOpen) {

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