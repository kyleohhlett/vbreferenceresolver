#ifndef _REFERENCE_HPP
#define _REFERENCE_HPP

#include <string>
#include <Windows.h>

class Reference {

private:
	std::string lineInVbp;
	std::string classId;
	std::string version;
	std::string subVersion;
	std::string filename;
	std::string filepath;
	std::string description;

public:
	Reference(std::string lineInVbp);

	bool isObjectReference();
	bool isNormalReference();
	bool existsInRegistry();
	bool existsOnFileSystem();
	static bool IsReference(std::string lineInVbp);
	LPCSTR toString();
};

#endif