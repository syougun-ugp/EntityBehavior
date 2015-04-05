// ----------------------------------------------
// Hierarchy(ŠK‘w)
// 
// “o˜^EíœE‘Síœ
// ŠK‘w‚ÌÀ‘Ôæ“¾
// 
// ----------------------------------------------

#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>
#include "EntityHierarchy.h"

class EntityHierarchy;
class Component;

class Hierarchy
{
public:
	// “o˜^
	static void Register(std::shared_ptr<EntityHierarchy> entity);

	// íœ
	static void Deregistration(const std::string& name);

	// ‘Síœ
	void Clear();

	// Start‚Ì‘O‚Éˆ—‚ªÀs
	void Awake();

	// Update‚Ì‘O‚¢ˆ—‚ªÀs
	void Start();

	// ƒAƒbƒvƒf[ƒg
	void Update();

	// •`‰æ
	void Render();

	// –¼‘O‚Å’T‚·
	static std::shared_ptr<EntityHierarchy> Find(const std::string& name);

	// –¼‘O‚Å’T‚·
	template<typename Type>
	static std::shared_ptr<Type> Find(const std::string& name)
	{
		auto findObject = hierarchyList.find(name);
		if (findObject == hierarchyList.end()) return nullptr;

		std::cout << findObject->second->Name().c_str() << " æ“¾" << std::endl;

		return std::dynamic_pointer_cast<Type>(findObject->second);
	}

	// ”z—ñ‚ğæ“¾
	template<typename Type>
	static std::vector<std::shared_ptr<Type>> FindObjectsOfType(const std::string& name)
	{
		auto findObjects = hierarchyList.equal_range(name);
		std::vector<std::shared_ptr<Type>> components;
		
		components.clear();

		for (auto iterator = findObjects.first; iterator != findObjects.second; iterator++)
		{
			auto target = *iterator;
			components.push_back(std::dynamic_pointer_cast<Type>(target.second));
			std::cout << target.second->Name().c_str() << " æ“¾" << std::endl;
		}

		std::cout << components.size << " ŒÂ‚ğæ“¾" << std::endl;

		return components;

	}
private:
	static std::unordered_multimap<std::string, std::shared_ptr<EntityHierarchy>> hierarchyList;

};
