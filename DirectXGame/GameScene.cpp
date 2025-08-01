#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() { 
	delete bgSprite;
	delete nextBgSprite;
	delete camera_;
}

void GameScene::Initialize() {
	camera_ = new Camera();
	camera_->Initialize();
	camera_->farZ = 1000.0f;

	player_.Initialize();

	bgHandle = TextureManager::Load("cavebg.png");

	bgSprite = Sprite::Create(bgHandle, {0, 0});
	nextBgSprite = Sprite::Create(bgHandle, {1280, 0});
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



	Sprite::PostDraw();
}
