#ifndef _NORMAL_REFERENCE_HPP
#define _NORMAL_REFERENCE_HPP

#include <string>

#include "reference.hpp"

class NormalReference : Reference {

private:
	std::string pathToFile;

public:
	NormalReference();
};

#endif