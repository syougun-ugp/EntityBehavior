// ----------------------------------------------
// Hierarchy(階層)
// 
// 登録・削除・全削除
// 階層の実態取得
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
	// 登録
	void Register(std::shared_ptr<EntityHierarchy> entity);

	// 削除
	void Deregistration(const std::string& name);

	// 全削除
	void Clear();

	// Startの前に処理が実行
	void Awake();

	// Updateの前い処理が実行
	void Start();

	// アップデート
	void Update();

	// 描画
	void Render();

	// 取得
	template<typename Type>
	static std::shared_ptr<Type> GetComponent(const std::string& name);

	// コンポーネントを取得
	static std::shared_ptr<Component> GetComponent(const std::string& name);

private:
	static std::unordered_map<std::string, std::shared_ptr<EntityHierarchy>> hierarchyList;

};
