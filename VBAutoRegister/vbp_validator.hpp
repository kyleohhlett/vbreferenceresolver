#include <string>
#include <vector>

#include <Windows.h>

class VbpValidator {

private:
	std::vector<std::string> problematicObjectReferences;
	std::vector<std::string> problematicReferences;

	void processObjectReference(std::string line, std::vector<std::string> problematicObjectReferences);
	void processReference(std::string line, std::vector<std::string> problematicReferences);
	bool isObjectReference(std::string line);
	bool isReference(std::string line);
	void getVbpFileLocation(LPSTR fileToOpen);

public:
	VbpValidator();
	void start();
};