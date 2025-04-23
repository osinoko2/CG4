#include "Effect.h"

using namespace KamataEngine;

void Effect::Initialize(Model* model, Vector3 Scale, Vector3 Rotate) {
	// NULLポインタチェック
	assert(model);

	model_ = model;

	worldTransform_.Initialize();

	worldTransform_.scale_ = Scale;

	worldTransform_.rotation_ = Rotate;
}

void Effect::Update() {
	// 行列を更新
	worldTransform_.UpdateMatrix();
}

void Effect::Draw(Camera& camera) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera);
}
