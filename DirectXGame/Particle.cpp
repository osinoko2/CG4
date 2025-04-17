#include "Particle.h"

void Particle::Initialize(Model* model) {
	// NULLポインタチェック
	assert(model);

	model_ = model;

	worldTransform_.Initialize();
}

void Particle::Update() {
	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Particle::Draw(Camera& camera) {
	// 3Dモデルを描画
	model_->Draw(worldTransform_, camera);
}
