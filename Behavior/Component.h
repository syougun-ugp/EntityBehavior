// ----------------------------------------------
// �R���|�[�l���g
// 
// �ǉ��A�폜�A�擾�A�e�̎擾���ł���
// 
// ----------------------------------------------

#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include "GameObject.h"

class EntityBehavior;

class Component :public GameObject
{
public:
	Component(const std::string &name);
	Component(const std::string &name, const std::string& parentName);
	Component();
	
	// �ǉ�
	void AddComponent(std::shared_ptr<EntityBehavior> gameObject);

	// �폜
	void RemoveComponent(const GameObject& gameObject);

	// �e���擾
	std::shared_ptr<Component> GetComponentInParent();

	// �擾
	template<class Type>
	std::shared_ptr<Type> GetComponent(const std::string& name)
	{
		auto findObject = behaviorList.find(name);
		if (findObject == behaviorList.end()) return nullptr;

		std::cout << findObject->second->Name().c_str() << " �擾" << std::endl;

		return std::dynamic_pointer_cast<Type>(findObject->second);
	}

	// �擾
	template<class Type>
	std::shared_ptr<Type> GetComponent()
	{
		std::cout << gameObject->Name().c_str() << " �擾" << std::endl;

		return std::dynamic_pointer_cast<Type>(gameObject);
	}

protected:
	void ComponentsAwake();
	void ComponentsStart();
	void ComponentsUpdate();

private:
	std::unordered_map<std::string, std::shared_ptr<EntityBehavior>> behaviorList;
	std::shared_ptr<GameObject> gameObject;
	std::string parentName;

};

