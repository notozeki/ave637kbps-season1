#include <vector>
#include <iterator>
#include "StructureManager.hpp"
#include "Structure.hpp"

void StructureManager::addStructure(Structure* s)
{
	mStructures.push_back(s);
}

void StructureManager::draw()
{
	for (std::vector<Structure*>::const_iterator it = mStructures.begin();
	     it != mStructures.end();
	     it++) {
		(*it)->draw();	
	}
}
