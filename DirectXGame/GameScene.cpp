#include "GameScene.h"

using namespace KamataEngine;

GameScene::~GameScene() {
	delete bgSprite;
	delete nextBgSprite;
	delete camera_;

	for (int i = 0; i < spriteNum; i++) {
		delete gaugeSprite_[i];
	}

	for (int i = 0; i < numberNum; i++) {
		delete numberSprite[i];
	}
}

void GameScene::Initialize() {
	camera_ = new Camera();
	camera_->Initialize();
	camera_->farZ = 1000.0f;

	player_.Initialize();

	bgHandle = TextureManager::Load("cavebg.png");
	whiteHandle = TextureManager::Load("white1x1.png");
	numberHandle = TextureManager::Load("number.png");

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

	for (int i = 0; i < numberNum; i++) {
		Vector2 StartPos = {numberPos.x + numberSize.x * i, numberPos.y};
		Sprite* sprite = Sprite::Create(numberHandle, StartPos);
		sprite->SetSize(numberSize);

		numberSprite.push_back(sprite);
	}

	number = kNumber;
	count = kNumber;
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

	number += numberSpeed;
	count = number;

	// 最初に割る数値は5桁なので1000で初期設定する
	int32_t digit = 10000;
	// 数字
	for (int i = 0; i < numberNum; i++) {
		// 今の桁の数値を取り出す
		int nowNumber = count / digit;
		// 今の桁の数値の部分を切り出すようにする
		numberSprite[i]->SetTextureRect({numberSize.x * nowNumber, 0}, numberSize);
		// 次の桁の処理のために、残りの桁の数値にする
		count %= digit;
		// 次の桁の処理のために、割る数値を10で割って桁に応じた値にする。
		digit /= 10;
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

	for (int i = 0; i < numberNum; i++) {
		numberSprite[i]->Draw();
	}

	Sprite::PostDraw();
}
