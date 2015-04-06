#include "EntityHierarchy.h"


EntityHierarchy::EntityHierarchy(const std::string& name,const Tags tag) :
Component(name, tag),
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

