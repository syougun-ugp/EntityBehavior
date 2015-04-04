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

class EntityHierarchy;
class Component;

class Hierarchy
{
public:
	// �o�^
	void Register(std::shared_ptr<EntityHierarchy> entity);

	// �폜
	void Deregistration(const std::string& name);

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

	// �擾
	template<typename Type>
	static std::shared_ptr<Type> GetComponent(const std::string& name);

	// �R���|�[�l���g���擾
	static std::shared_ptr<Component> GetComponent(const std::string& name);

private:
	static std::unordered_map<std::string, std::shared_ptr<EntityHierarchy>> hierarchyList;

};
