#include "vbp_validator.hpp"

#include <Windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {

	VbpValidator* validator = new VbpValidator();
	validator->start();
	delete(validator);

	return 0;
}