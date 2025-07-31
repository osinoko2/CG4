#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() { 
	delete bgSprite;
	delete nextBgSprite;
}

void GameScene::Initialize() { 
	bgHandle = TextureManager::Load("cavebg.png");

	bgSprite = Sprite::Create(bgHandle, {0, 0});
	nextBgSprite = Sprite::Create(bgHandle, {1280, 0});
}

void GameScene::Update() {
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

	Sprite::PreDraw(dxCommon->GetCommandList());

	bgSprite->Draw();
	nextBgSprite->Draw();

	Sprite::PostDraw();
}
