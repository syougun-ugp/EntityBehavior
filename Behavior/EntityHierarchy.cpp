#include "EntityHierarchy.h"


EntityHierarchy::EntityHierarchy(const std::string& name) :
Component(name, name),
isActive(true)
{
}

void EntityHierarchy::Active()
{
	isActive = true;
}

void EntityHierarchy::NonActive()
{
	isActive = false;
}

