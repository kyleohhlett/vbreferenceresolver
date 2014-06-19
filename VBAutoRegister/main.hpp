void getVbpFileLocation(LPSTR fileToOpen);
bool isObjectReference(std::string line);
bool isReference(std::string line);
void processObjectReference(std::string line, std::vector<std::string> problematicObjectReferences);
void processReference(std::string line, std::vector<std::string> problematicReferences);