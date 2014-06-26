#include <string>
#include <sstream>

#include "reference.hpp"

Reference::Reference(std::string lineInVbp) {

	this->lineInVbp = lineInVbp;
	
	std::string buffer;
	std::istringstream vbpLineStringStream = std::istringstream(this->lineInVbp);

	std::getline(vbpLineStringStream, buffer, '{');
	std::getline(vbpLineStringStream, this->classId, '}');
	std::getline(vbpLineStringStream, buffer, '#'); //advance stream pointer to version info
	std::getline(vbpLineStringStream, this->version, '#');
	
	if (this->isNormalReference()) {
		std::getline(vbpLineStringStream, this->subVersion, '#');
		std::getline(vbpLineStringStream, this->filepath, '#');
		std::getline(std::istringstream(this->filepath), this->filepath, '#');
		std::getline(vbpLineStringStream, this->description);
	} else if (this->isObjectReference()) {
		std::getline(vbpLineStringStream, this->subVersion, ';');
		std::getline(vbpLineStringStream, buffer, ' ');
		std::getline(vbpLineStringStream, this->filename);
	}
		
}

bool Reference::isObjectReference() {

	return strncmp(this->lineInVbp.c_str(), "Object=", std::string("Object=").length()) == 0;
}

bool Reference::isNormalReference() {

	return strncmp(this->lineInVbp.c_str(), "Reference=", std::string("Reference=").length()) == 0;
}

bool Reference::IsReference(std::string lineInVbp) {

	return (strncmp(lineInVbp.c_str(), "Reference=", std::string("Reference=").length()) == 0 || 
		strncmp(lineInVbp.c_str(), "Object=", std::string("Object=").length()) == 0);
}

//TODO: implement
bool Reference::existsInRegistry() {

}

//TODO: implement
bool Reference::existsOnFileSystem() {

}

//TODO: return in form '\\SOFTWARE\\Classes\\TypeLib\\{7D868ACD-1A5D-4A47-A247-F39741353012}\\1.0\\0\\win32'
LPCSTR Reference::toString() {

}