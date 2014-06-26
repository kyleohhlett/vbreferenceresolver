#ifndef _KEY_VIEWER_HPP
#define _KEY_VIEWER_HPP

#include <Windows.h>

class KeyViewer {

private:

public:
	static bool KeyExists(LPCSTR keyPath); //Example keyPath value: "SOFTWARE\\Classes"
};

#endif