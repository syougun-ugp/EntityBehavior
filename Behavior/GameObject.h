// ----------------------------------------------
// GameObject
// 
// �I�u�W�F�N�g�̃f�[�^
// 
// ----------------------------------------------

#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "Tag.h"
#include "Object.h"

class Component;
class EntityHierarchy;

class GameObject:public Object
{
public:
	GameObject(const std::string &name);
	GameObject(const std::string &name, Tags tag);
	GameObject();

	Tags Tag()const
	{
		return tag;
	}


	// �Q�[���I�u�W�F�N�g��Hierarchy�ɓo�^���āA��������
	// �߂�l�Ƃ��ẮA�o�^�����Q�[���I�u�W�F�N�g
	static std::shared_ptr<GameObject> Instantiate(std::shared_ptr<EntityHierarchy> gameObject);

protected:
	Tags tag; // �I�u�W�F�N�g�̃^�O


private:
};

