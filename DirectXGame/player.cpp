#include "player.h"

using namespace KamataEngine;

void Player::Initialize() {
	model_ = new Model();
	model_ = Model::CreateFromOBJ("Player", true);

	worldTransform_.Initialize();
	worldTransform_.translation_ = pos_;
	worldTransform_.rotation_.y = 1.0f;
	worldTransform_.scale_ = {4.0f, 4.0f, 4.0f};
}

void Player::Update() {
	worldTransform_.translation_ = pos_;
	Move();
	worldTransform_.UpdateMatrix();
}

void Player::Draw(KamataEngine::Camera& camera) { model_->Draw(worldTransform_, camera); }

void Player::Move() {
	if (Input::GetInstance()->PushKey(DIK_D)) {
		pos_.x += playerSpeed;
	} else if (Input::GetInstance()->PushKey(DIK_A)) {
		pos_.x -= playerSpeed;
	}
	if (Input::GetInstance()->PushKey(DIK_W)) {
		pos_.y += playerSpeed;
	} else if (Input::GetInstance()->PushKey(DIK_S)) {
		pos_.y -= playerSpeed;
	}
}

Player::~Player() {
	delete model_;
	model_ = nullptr;
}
