// ----------------------------------------------
// GameObject
// 
// オブジェクトのデータ
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


	// ゲームオブジェクトをHierarchyに登録して、生成する
	// 戻り値としては、登録したゲームオブジェクト
	static std::shared_ptr<GameObject> Instantiate(std::shared_ptr<EntityHierarchy> gameObject);

protected:
	Tags tag; // オブジェクトのタグ


private:
};

