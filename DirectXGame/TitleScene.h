#pragma once
#include "KamataEngine.h"

class TitleScene {
public:
	~TitleScene();

	// 初期化
	void Initialize();

	// 更新
	void Update();

	// 描画
	void Draw();

private:
	KamataEngine::Sprite* TitleSprite = nullptr;
	KamataEngine::Sprite* PassSprite = nullptr;

	uint32_t TitleHandle;
	uint32_t PassHandle;

	int count = 0;
};
