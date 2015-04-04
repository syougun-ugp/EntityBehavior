#include "Component.h"
#include "EntityBehavior.h"
#include "Hierarchy.h"

Component::Component(const std::string &name) :
GameObject(name),
gameObject(std::make_shared<GameObject>(name)),
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

	for (auto& behavior : behaviorList)
	{
		if (!behavior.second->IsEnable()) continue;

		std::cout << behavior.second->Name().c_str() << " Awake" << std::endl;

		behavior.second->Awake();
	}
}

void Component::ComponentsStart()
{
	std::cout << "---------- ChildrensStart ----------" << std::endl;

	for (auto& behavior : behaviorList)
	{
		if (!behavior.second->IsEnable()) continue;

		std::cout << behavior.second->Name().c_str() << " Start" << std::endl;

		behavior.second->Start();
	}
}

void Component::ComponentsUpdate()
{
	std::cout << "---------- ChildrensUpdate ----------" << std::endl;

	for (auto& behavior : behaviorList)
	{
		if (!behavior.second->IsEnable()) continue;

		std::cout << behavior.second->Name().c_str() << " Update" << std::endl;

		behavior.second->Update();
	}
}

void Component::AddComponent(std::shared_ptr<EntityBehavior> gameObject)
{
	std::cout << gameObject->Name().c_str() << " ’Ç‰Á" << std::endl;

	behaviorList.insert(std::make_pair(gameObject->Name(), gameObject));
}

void Component::RemoveComponent(const GameObject& gameObject)
{
	auto itr = behaviorList.find(gameObject.Name());
	if (itr != behaviorList.end()) return;

	std::cout << gameObject.Name().c_str() << " íœ" << std::endl;

	behaviorList.erase(itr);
}

std::shared_ptr<Component> Component::GetComponentInParent()
{
	auto parent = Hierarchy::GetComponent<Component>(parentName);
	if (parent == nullptr) return nullptr;

	std::cout << Name() << "‚Ìe@"<< parent->Name().c_str() << " ‚ðŽæ“¾" << std::endl;

	return parent;
}
