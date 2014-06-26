#include "key_viewer.hpp"

#include <Windows.h>

bool KeyViewer::KeyExists(LPCSTR keyPath) {

	HKEY key;
	LONG returnValue = RegOpenKey(HKEY_LOCAL_MACHINE, keyPath, &key);

	return returnValue == ERROR_SUCCESS;
}