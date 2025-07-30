#include "TitleScene.h"

using namespace KamataEngine;

TitleScene::~TitleScene() { delete TitleSprite; }

void TitleScene::Initialize() {

	TitleHandle = TextureManager::Load("title.png");

	TitleSprite = Sprite::Create(TitleHandle, {0, 0});
}

void TitleScene::Update() {

	TitleSprite->SetSize({1280.0f, 720.0f});

}

void TitleScene::Draw() {

	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxCommon->GetCommandList());

	TitleSprite->Draw();

	Sprite::PostDraw();
}
