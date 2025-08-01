#include "KamataEngine.h"
#include "GameScene.h"
#include "TitleScene.h"
#include <Windows.h>
#include <map>

GameScene* gameScene = nullptr;
TitleScene* titleScene = nullptr;

enum class Scene {
	kUnknown = 0,

	Title,
	Game,
};

// 現在シーン
Scene scene = Scene::kUnknown;

void ChangeScene();
void UpdateScene();
void DrawScene();

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	// エンジンの初期化
	KamataEngine::Initialize(L"LE3C_11_サクライ_ショウセイ_CG4");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// ゲームシーンのインスタンス生成
	gameScene = new GameScene();
	// ゲームシーンの初期化
	gameScene->Initialize();

	titleScene = new TitleScene();

	titleScene->Initialize();

	scene = Scene::Title;

	// メインループ
	while (true) {
		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}

		// ゲームシーンの更新
		//gameScene->Update();
		//titleScene->Update();

		// シーン切り替え
		ChangeScene();
		// 現在シーン更新
		UpdateScene();

		// 描画開始
		dxCommon->PreDraw();

		// ゲームシーンの描画
		//gameScene->Draw();
		//titleScene->Draw();

		// 現在シーンの描画
		DrawScene();

		// 描画終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの解放
	//delete gameScene;
	//delete titleScene;
	
	// nullptrの代入
	//gameScene = nullptr;
	//titleScene = nullptr;

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}

void ChangeScene() {
	switch (scene) {
	case Scene::Title:
		if (Input::GetInstance()->TriggerKey(DIK_RETURN)) {
			// シーン変更
			scene = Scene::Game;
			// 旧シーンの開放
			delete titleScene;
			titleScene = nullptr;
			// 新シーンの生成と初期化
			gameScene = new GameScene;
			gameScene->Initialize();
		}
		break;
	case Scene::Game:
		break;
	}
}

void UpdateScene() {
	switch (scene) {
	case Scene::Title:
		titleScene->Update();
		break;
	case Scene::Game:
		gameScene->Update();
		break;
	}
}

void DrawScene() {
	switch (scene) {
	case Scene::Title:
		titleScene->Draw();
		break;
	case Scene::Game:
		gameScene->Draw();
		break;
	}
}
