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
	std::string generateReportString();
	void getVbpFileLocation(LPSTR fileToOpen);
	void loadReference(Reference reference);
	void loadReferences(char* fileToOpen);
	void processReference(Reference reference);
	void processReferences();

public:
	VbpValidator();

	void start();
};

#endif