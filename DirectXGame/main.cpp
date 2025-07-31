#include "KamataEngine.h"
#include "GameScene.h"
#include "TitleScene.h"
#include <Windows.h>

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	// エンジンの初期化
	KamataEngine::Initialize(L"LE3C_11_サクライ_ショウセイ_CG4");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// ゲームシーンのインスタンス生成
	GameScene* gameScene = new GameScene();
	//TitleScene* titleScene = new TitleScene();

	// ゲームシーンの初期化
	gameScene->Initialize();
	//titleScene->Initialize();

	// メインループ
	while (true) {
		// エンジンの更新
		if (KamataEngine::Update()) {
			break;
		}

		// ゲームシーンの更新
		gameScene->Update();
		//titleScene->Update();

		// 描画開始
		dxCommon->PreDraw();

		// ゲームシーンの描画
		gameScene->Draw();
		//titleScene->Draw();

		// 描画終了
		dxCommon->PostDraw();
	}

	// ゲームシーンの解放
	delete gameScene;
	//delete titleScene;
	// nullptrの代入
	gameScene = nullptr;
	//titleScene = nullptr;

	// エンジンの終了処理
	KamataEngine::Finalize();

	return 0;
}
