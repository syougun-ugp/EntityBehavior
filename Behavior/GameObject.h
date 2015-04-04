// ----------------------------------------------
// GameObject
// 
// オブジェクトのデータ
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

	// 名前を取得
	std::string Name()const
	{
		return name;
	}

protected:


private:
	std::string name; // オブジェクトの名前
};

