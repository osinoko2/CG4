#pragma once
#include "KamataEngine.h"
#include "Resources/Model2/Model2.h"
#include "3d/WorldTransform.h"

class GameScene {
public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	// デストラクタ
	~GameScene();

private:
	KamataEngine::Model* modelPlane_ = nullptr;

	KamataEngine::Model2* model_ = nullptr;

	uint32_t model2Handle_;

	KamataEngine::WorldTransform worldTransform_;

	KamataEngine::Camera camera_;
};
