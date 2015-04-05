// ----------------------------------------------
// Hierarchy(�K�w)
// 
// �o�^�E�폜�E�S�폜
// �K�w�̎��Ԏ擾
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
	// �o�^
	static void Register(std::shared_ptr<EntityHierarchy> entity);

	// �폜
	static void Deregistration(const std::string& name);

	// �S�폜
	void Clear();

	// Start�̑O�ɏ��������s
	void Awake();

	// Update�̑O�����������s
	void Start();

	// �A�b�v�f�[�g
	void Update();

	// �`��
	void Render();

	// ���O�ŒT��
	static std::shared_ptr<EntityHierarchy> Find(const std::string& name);

	// ���O�ŒT��
	template<typename Type>
	static std::shared_ptr<Type> Find(const std::string& name)
	{
		auto findObject = hierarchyList.find(name);
		if (findObject == hierarchyList.end()) return nullptr;

		std::cout << findObject->second->Name().c_str() << " �擾" << std::endl;

		return std::dynamic_pointer_cast<Type>(findObject->second);
	}

	// �z����擾
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
			std::cout << target.second->Name().c_str() << " �擾" << std::endl;
		}

		std::cout << components.size << " ���擾" << std::endl;

		return components;

	}
private:
	static std::unordered_multimap<std::string, std::shared_ptr<EntityHierarchy>> hierarchyList;

};
