#ifndef _VBP_VALIDATOR_HPP
#define _VBP_VALIDATOR_HPP

#include <string>
#include <vector>

#include <Windows.h>

#include "reference.hpp"

class VbpValidator {

private:
	std::vector<Reference> problematicReferences;

	Reference convertLineToReference(std::string line);
	void getVbpFileLocation(LPSTR fileToOpen);
	void processReference(Reference);
	bool isObjectReference(std::string line);
	bool isReference(std::string line);

public:
	VbpValidator();

	void start();
};

#endif