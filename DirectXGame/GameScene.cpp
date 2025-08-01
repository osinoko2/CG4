#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {
	delete bgSprite;
	delete nextBgSprite;
	delete camera_;

	for (int i = 0; i < spriteNum; i++) {
		delete gaugeSprite_[i];
	}
}

void GameScene::Initialize() {
	camera_ = new Camera();
	camera_->Initialize();
	camera_->farZ = 1000.0f;

	player_.Initialize();

	bgHandle = TextureManager::Load("cavebg.png");
	whiteHandle = TextureManager::Load("white1x1.png");

	bgSprite = Sprite::Create(bgHandle, {0, 0});
	nextBgSprite = Sprite::Create(bgHandle, {1280, 0});

	for (int i = 0; i < spriteNum; i++) {
		Sprite* sprite = Sprite::Create(whiteHandle, gaugePos);
		sprite->SetSize(stargGaugeSize_);
		if (i == 1) {
			sprite->SetColor(Vector4(0.24f, 0.70f, 0.44f, 0.5f));
		} else {
			sprite->SetColor(Vector4(0.85f, 0.2f, 0.24f, 0.5f));
		}
		gaugeSprite_.push_back(sprite);
	}
}

void GameScene::Update() {

	camera_->UpdateMatrix();

	player_.Update();

	// 背景スクロール
	Vector2 position = bgSprite->GetPosition();
	Vector2 nextposition = nextBgSprite->GetPosition();

	position.x--;
	nextposition.x--;

	if (position.x <= -1280.0f) {
		position.x = position.x + 1280.0f;
	}

	if (nextposition.x <= 0.0f) {
		nextposition.x = nextposition.x + 1280.0f;
	}

	bgSprite->SetPosition(position);
	nextBgSprite->SetPosition(nextposition);

	for (int i = 0; i < spriteNum; i++) {

		// ゲージ
		if (i == 1) {
			gaugeSprite_[i]->SetSize(Vector2(gaugeSprite_[i]->GetSize().x - gaugeSpeed, stargGaugeSize_.y));
			if (gaugeSprite_[i]->GetSize().x <= 0) {
				gaugeSprite_[i]->SetSize(stargGaugeSize_);
			}
		}
	}
}

void GameScene::Draw() {
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// 遠景スプライト
	Sprite::PreDraw(dxCommon->GetCommandList());

	bgSprite->Draw();
	nextBgSprite->Draw();

	Sprite::PostDraw();

	// 深度バッファクリア
	dxCommon->ClearDepthBuffer();

	Model::PreDraw(dxCommon->GetCommandList());

	player_.Draw(*camera_);

	Model::PostDraw();

	// 近景スプライト
	Sprite::PreDraw(dxCommon->GetCommandList());

	for (int i = 0; i < spriteNum; i++) {
		gaugeSprite_[i]->Draw();
	}

	Sprite::PostDraw();
}
