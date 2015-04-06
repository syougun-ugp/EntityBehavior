#include "Hierarchy.h"

std::unordered_multimap<std::string, std::shared_ptr<EntityHierarchy>> Hierarchy::hierarchyList;

void Hierarchy::Register(std::shared_ptr<EntityHierarchy> entity)
{
	std::cout << entity->Name().c_str() << " 追加" << std::endl;

	hierarchyList.insert(std::make_pair(entity->Name(), entity));
}

void Hierarchy::Deregistration(const std::string& name)
{
	auto itr = hierarchyList.find(name);
	if (itr != hierarchyList.end()) return;

	std::cout << itr->second->Name().c_str() << " 削除" << std::endl;

	hierarchyList.erase(itr);
}

void Hierarchy::Clear()
{
	hierarchyList.clear();
}

void Hierarchy::Awake()
{
	std::cout << "---------- Hierarchy Awake ----------" << std::endl;

	for (auto& hierarchy : hierarchyList)
	{
		if (!hierarchy.second->IsActive()) continue;

		std::cout << hierarchy.second->Name().c_str() << " Awake" << std::endl;

		hierarchy.second->Awake();
	}
}

void Hierarchy::Start()
{
	std::cout << "---------- Hierarchy Start ----------" << std::endl;

	for (auto& hierarchy : hierarchyList)
	{
		if (!hierarchy.second->IsActive()) continue;

		std::cout << hierarchy.second->Name().c_str() << " Start" << std::endl;

		hierarchy.second->Start();
	}
}

void Hierarchy::Update()
{
	std::cout << "---------- Hierarchy Update ----------" << std::endl;

	for (auto& hierarchy : hierarchyList)
	{
		if (!hierarchy.second->IsActive()) continue;

		std::cout << hierarchy.second->Name().c_str() << " Update" << std::endl;

		hierarchy.second->Update();
	}
}

void Hierarchy::Render()
{
	std::cout << "---------- Hierarchy Render ----------" << std::endl;

	for (auto& hierarchy : hierarchyList)
	{
		if (!hierarchy.second->IsActive()) continue;

		std::cout << hierarchy.second->Name().c_str() << " Render" << std::endl;

		hierarchy.second->Render();
	}
}



std::shared_ptr<EntityHierarchy> Hierarchy::Find(const std::string& name)
{
	std::cout << " Find()" << std::endl;

	auto findObject = hierarchyList.find(name);
	if (findObject == hierarchyList.end()) return nullptr;

	std::cout << findObject->second->Name().c_str() << " 取得" << std::endl;

	return findObject->second;
}


// Tagでのゲームオブジェクトを取得
std::shared_ptr<EntityHierarchy> Hierarchy::FindWithTag(const Tags tag)
{
	std::cout << " FindWithTag()" << std::endl;

	for (auto& hierarchy : hierarchyList)
	{
		if (hierarchy.second->Tag() != tag) continue;

		std::cout << hierarchy.second->Name().c_str() << " 取得" << std::endl;

		return hierarchy.second;
	}

	return nullptr;
}

// Tagでのゲームオブジェクトを配列で取得
std::vector<std::shared_ptr<EntityHierarchy>> Hierarchy::FindGameObjectsWithTag(const Tags tag)
{
	std::cout << " FindGameObjectsWithTag()" << std::endl;

	std::vector<std::shared_ptr<EntityHierarchy>> gameObjects;
	gameObjects.clear();

	for (auto& hierarchy : hierarchyList)
	{
		if (hierarchy.second->Tag() != tag) continue;

		std::cout << hierarchy.second->Name().c_str() << " 取得" << std::endl;

		gameObjects.push_back(hierarchy.second);
	}
	
	std::cout << gameObjects.size() << " 個を取得" << std::endl;

	return gameObjects;
}
