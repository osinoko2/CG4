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

	uint32_t TitleHandle;
};
