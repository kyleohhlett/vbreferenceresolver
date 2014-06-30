#include <string>
#include <sstream>

#include "key_viewer.hpp"
#include "reference.hpp"

Reference::Reference() {

}

Reference::Reference(std::string lineInVbp) {

	this->lineInVbp = lineInVbp;
	
	std::string buffer;
	std::istringstream vbpLineStringStream = std::istringstream(this->lineInVbp);

	std::getline(vbpLineStringStream, buffer, '{');
	std::getline(vbpLineStringStream, this->classId, '}');
	std::getline(vbpLineStringStream, buffer, '#');
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

std::string Reference::getFilename() {

	return this->filename;
}

std::string Reference::getFilepath() {

	return this->filepath;
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

bool Reference::existsInRegistry() {

	return KeyViewer::KeyExists(this->toString().c_str());
}

//TODO: implement
bool Reference::existsOnFileSystem() {

	return false;
}

std::string Reference::toString() {
	
	std::string registryPath = std::string("SOFTWARE\\Classes\\TypeLib\\{");
	registryPath.append(this->classId);
	registryPath.append("}\\");
	registryPath.append(this->version);
	registryPath.append("\\");
	registryPath.append(this->subVersion);
	registryPath.append("\\win32");

	return registryPath;
}