#include "GameObject.h"
#include "Hierarchy.h"
#include "EntityHierarchy.h"
#include "Component.h"

GameObject::GameObject(const std::string &name):
Object(name),
tag(Tags::Default)
{

}

GameObject::GameObject(const std::string &name, Tags tag) :
tag(tag),
Object(name)
{

}


GameObject::GameObject():
Object("GameObject"),
tag(Tags::Default)
{

}

// �Q�[���I�u�W�F�N�g��Hierarchy�ɓo�^���āA��������
// �߂�l�Ƃ��ẮA�o�^�����Q�[���I�u�W�F�N�g
std::shared_ptr<GameObject> GameObject::Instantiate(std::shared_ptr<EntityHierarchy> gameObject)
{
	Hierarchy::Register(gameObject);
	auto object = Hierarchy::Find(gameObject->Name());
	return object;
}
