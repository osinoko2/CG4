#pragma once
#include "KamataEngine.h"
#include "Particle.h"
#include "Effect.h"

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

	/// <summary>
	/// エフェクト発生
	/// </summary>
	/// <param name="position">位置</param>
	void EffectBorn(KamataEngine::Vector3 position);

	// パーティクル3Dモデルデータ
	KamataEngine::Model* modelParticle_ = nullptr;

	// エフェクト3Dモデルデータ
	KamataEngine::Model* modelEffect_ = nullptr;

	// パーティクル
	std::list<Particle*> particles_;

	// エフェクト
	std::list<Effect*> effects_;

	// カメラ
	KamataEngine::Camera camera_;

};
