#pragma once

#include <KamataEngine.h>

class Effect {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="position">位置</param>
	/// <param name="velocity">移動量</param>
	void Initialize(KamataEngine::Model* model);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="camera">カメラ</param>
	void Draw(KamataEngine::Camera& camera);

private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;
};
