#include "GameScene.h"

using namespace KamataEngine;

void GameScene::Initialize() {
	// 3Dモデルデータの生成
	model_ = Model2::CreateFromOBJ("plane", true);

	// カメラの初期化
	camera_.Initialize();

	// ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	model2Handle_ = TextureManager::Load("./Resources/uvChecker.png");

	Model2::StaticInitialize();
}

void GameScene::Update() {
	worldTransform_.UpdateMatrix();
}

void GameScene::Draw() {
	// DirectXCommon インスタンスの取得
	KamataEngine::DirectXCommon* dxCommon = KamataEngine::DirectXCommon::GetInstance();

	// 3Dモデル描画前処理
	KamataEngine::Model2::PreDraw(dxCommon->GetCommandList());

	model_->Draw(worldTransform_, camera_, model2Handle_);

	// 3Dモデル描画後処理
	KamataEngine::Model2::PostDraw();
}

GameScene::~GameScene() {
	// 3Dモデルデータの解放
	delete model_;
	model_ = nullptr;

	Model2::StaticFinalize();
}
