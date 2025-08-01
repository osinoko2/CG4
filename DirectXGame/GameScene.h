#pragma once
#include "KamataEngine.h"
#include "player.h"

class GameScene {
public:
	~GameScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	Player player_;

	KamataEngine::Sprite* bgSprite = nullptr;
	KamataEngine::Sprite* nextBgSprite = nullptr;

	uint32_t bgHandle;

	KamataEngine::Camera* camera_;
};
