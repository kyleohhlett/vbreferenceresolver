#include "key_viewer.hpp"

#include <Windows.h>

bool KeyViewer::KeyExists(std::string keyPath) {

	HKEY key;
	LONG returnValue = RegOpenKey(HKEY_LOCAL_MACHINE, keyPath.c_str(), &key);

	return returnValue == ERROR_SUCCESS;
}