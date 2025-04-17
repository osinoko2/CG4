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

	/// <summary>
	/// パーティクル発生
	/// </summary>
	/// <param name="position">位置</param>
	void ParticleBorn(KamataEngine::Vector3 position);

	// パーティクル3Dモデルデータ
	KamataEngine::Model* modelParticle_ = nullptr;

	// パーティクル
	std::list<Particle*> particles_;

	// カメラ
	KamataEngine::Camera camera_;

};
