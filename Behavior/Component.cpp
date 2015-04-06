#include "Component.h"
#include "EntityBehavior.h"
#include "Hierarchy.h"

Component::Component(const std::string &name) :
GameObject(name),
gameObject(std::make_shared<GameObject>(name)),
parentName(name)
{
}

Component::Component(const std::string &name,Tags tag) :
GameObject(name, tag),
gameObject(std::make_shared<GameObject>(name,tag)),
parentName(name)
{
}


Component::Component(const std::string &name, const std::string& parentName) :
GameObject(name),
gameObject(std::make_shared<GameObject>(name)),
parentName(parentName)
{

}


Component::Component() :
GameObject("null"),
gameObject(std::make_shared<GameObject>("null")),
parentName("null")
{
}

void Component::ComponentsAwake()
{
	std::cout << "---------- ChildrensAwake ----------" << std::endl;

	for (auto& children : childrenList)
	{
		if (!children.second->IsEnable()) continue;

		std::cout << children.second->Name().c_str() << " Awake" << std::endl;

		children.second->Awake();
	}
}

void Component::ComponentsStart()
{
	std::cout << "---------- ChildrensStart ----------" << std::endl;

	for (auto& children : childrenList)
	{
		if (!children.second->IsEnable()) continue;

		std::cout << children.second->Name().c_str() << " Start" << std::endl;

		children.second->Start();
	}
}

void Component::ComponentsUpdate()
{
	std::cout << "---------- ChildrensUpdate ----------" << std::endl;

	for (auto& children : childrenList)
	{
		if (!children.second->IsEnable()) continue;

		std::cout << children.second->Name().c_str() << " Update" << std::endl;

		children.second->Update();
	}
}

void Component::AddComponent(std::shared_ptr<EntityBehavior> gameObject)
{
	std::cout << " AddComponent()" << std::endl;

	std::cout << gameObject->Name().c_str() << " ’Ç‰Á" << std::endl;

	childrenList.insert(std::make_pair(gameObject->Name(), gameObject));
}

void Component::Destroy()
{
	std::cout << " Destroy()" << std::endl;

	auto itr = childrenList.find(Name());
	if (itr == childrenList.end()) return;

	std::cout << itr->second->Name().c_str() << " íœ" << std::endl;

	childrenList.erase(itr);
}

// íœ
void Component::Destroy(const std::string &name)
{
	std::cout << " Destroy()" << std::endl;

	auto itr = childrenList.find(name);
	if (itr == childrenList.end()) return;

	std::cout << itr->second->Name().c_str() << " íœ" << std::endl;

	childrenList.erase(itr);
}

std::shared_ptr<Component> Component::GetComponentInParent()const
{
	std::cout << " GetComponentInParent()" << std::endl;

	auto parent = Hierarchy::Find<Component>(parentName);
	if (!parent) return nullptr;

	std::cout << Name() << "‚Ìe@"<< parent->Name().c_str() << " ‚ðŽæ“¾" << std::endl;

	return parent;
}
