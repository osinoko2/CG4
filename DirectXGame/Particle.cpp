#include "Particle.h"

using namespace KamataEngine;
using namespace MathUtility;

void Particle::Initialize(Model* model, Vector3 position, Vector3 velocity) {
	// NULLポインタチェック
	assert(model);

	model_ = model;

	worldTransform_.Initialize();

	// 色の設定
	objectcolor_.Initialize();
	color_ = {1, 1, 0, 1};

	worldTransform_.translation_ = position;

	velocity_ = velocity;

	// 大きさ
	worldTransform_.scale_ = {0.2f, 0.2f, 0.2f};
}

void Particle::Update() {
	// 移動
	worldTransform_.translation_ += velocity_;

	// 行列を更新
	worldTransform_.UpdateMatrix();

	// 色変更オブジェクトに色の数値を設定する
	objectcolor_.SetColor(color_);
}

void Particle::Draw(Camera& camera) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera, &objectcolor_);
}
