#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::~TitleScene() { 
	delete TitleSprite;
	delete PassSprite;
}

void TitleScene::Initialize() {

	TitleHandle = TextureManager::Load("title.png");
	PassHandle = TextureManager::Load("titlepass.png");

	TitleSprite = Sprite::Create(TitleHandle, {0, -300});
	PassSprite = Sprite::Create(PassHandle, {320, 450});
}

void TitleScene::Update() {

	PassSprite->SetSize({640.0f, 160.0f});

	Vector2 position = TitleSprite->GetPosition();

	if (position.y < 0) {
		position.y += 5.0f;
	} else if (position.y > 0) {
		position.y = 0.0f;
	}

	TitleSprite->SetPosition(position);

	count++;
}

void TitleScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	TitleSprite->Draw();
	if(count % 60 >= 30){
		PassSprite->Draw();
	}

	Sprite::PostDraw();
}
