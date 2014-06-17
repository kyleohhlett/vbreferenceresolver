#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {

	return 0;
}

//TODO: return filepath
void getVbpFileLocation(){

	OPENFILENAME openFilename = {};

	openFilename.lStructSize = sizeof(OPENFILENAME);
	openFilename.lpstrFilter = "Visual Basic Project File\0*.VBP\0\0";
	openFilename.lpstrFile = "\0";
	openFilename.nMaxFile = MAX_PATH;

	GetOpenFileName(&openFilename);
}