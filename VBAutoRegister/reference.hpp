#ifndef _REFERENCE_HPP
#define _REFERENCE_HPP

#include <string>

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
	static bool IsReference(std::string lineInVbp);
};

#endif