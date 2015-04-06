// ----------------------------------------------
// 実態の階層
// 
// 階層に入るクラスに継承するもの
// アクティブ・非アクティブを設定できる
//
// ----------------------------------------------

#pragma once
#include "Component.h"

class EntityHierarchy :public Component
{
public:
	EntityHierarchy(const std::string& name,const Tags tag);

	// Startの前に処理が実行させる
	virtual void Awake(){}

	// Updateの前に処理が実行させる
	virtual void Start(){}
	
	// アップデート
	virtual void Update(){}
	
	// 描画
	virtual void Render(){}

	// アクティブにする
	void Active();

	// 非アクティブにする
	void NonActive();

	// アクティブを取得
	bool IsActive()const{ return isActive; }

private:
	bool isActive;
};

