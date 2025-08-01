#pragma once
#include "KamataEngine.h"

/// <summary>
///	自キャラ
/// </summary>
class Player {

public: // 引数を書くところ
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="textureHandle">テクスチャハンドル</param>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw(KamataEngine::Camera& camera);

	void Move();

	~Player();

private: // 関数（メンバ変数）
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;

	// モデル
	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Vector3 pos_;
	const float playerSpeed = 0.1f;
};
