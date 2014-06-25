#ifndef _VBP_VALIDATOR_HPP
#define _VBP_VALIDATOR_HPP

#include <string>
#include <vector>

#include <Windows.h>

#include "reference.hpp"
#include "reference_error.hpp"

class VbpValidator {

private:
	std::vector<Reference> references;
	std::vector<ReferenceError> referenceErrors;

	Reference convertLineToReference(std::string line);
	void getVbpFileLocation(LPSTR fileToOpen);
	void loadReference(Reference reference);
	void loadReferences(char* fileToOpen);
	bool isObjectReference(std::string line);
	bool isReference(std::string line);
	void processReference(Reference reference);
	void processReferences();

public:
	VbpValidator();

	void start();
};

#endif