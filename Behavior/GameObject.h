// ----------------------------------------------
// GameObject
// 
// �I�u�W�F�N�g�̃f�[�^
// 
// ----------------------------------------------

#pragma once
#include <string>
#include <memory>

class GameObject
{
public:
	GameObject(const std::string &name);
	GameObject();
	virtual ~GameObject() = default;

	// ���O���擾
	std::string Name()const
	{
		return name;
	}

protected:


private:
	std::string name; // �I�u�W�F�N�g�̖��O
};

