#include "EntityHierarchy.h"


EntityHierarchy::EntityHierarchy(const std::string& name,const Tags tag) :
Component(name, tag),
isActive(true)
{
}

EntityHierarchy::EntityHierarchy(const std::string& name, const SortingLayer sortingLayer) :
Component(name, sortingLayer),
isActive(true)
{
}

EntityHierarchy::EntityHierarchy(const std::string& name, const Tags tag ,const SortingLayer sortingLayer) :
Component(name, tag, sortingLayer),
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

