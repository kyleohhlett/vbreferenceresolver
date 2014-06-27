#ifndef _KEY_VIEWER_HPP
#define _KEY_VIEWER_HPP

#include <string>
#include <Windows.h>

class KeyViewer {

private:

public:
	static bool KeyExists(std::string keyPath); //Example keyPath value: "SOFTWARE\\Classes"
};

#endif