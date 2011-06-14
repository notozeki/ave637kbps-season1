#ifndef STRUCTUREMANAGER_HPP
#define STRUCTUREMANAGER_HPP

#include <vector>
#include <iterator>
#include "Structure.hpp"

class StructureManager {
public:
	void addStructure(Structure* s);
	void draw();
private:
	std::vector<Structure*> mStructures;
};

#endif // STRUCTUREMANAGER_HPP
