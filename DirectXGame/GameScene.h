#pragma once
#include "KamataEngine.h"
#include "Particle.h"

class GameScene {

public:
	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

	~GameScene();

	// パーティクル3Dモデルデータ
	Model* modelParticle_ = nullptr;

	// パーティクル
	Particle* particle_ = nullptr;

	// カメラ
	Camera camera_;

};
