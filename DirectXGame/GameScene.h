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

	// 出す画像の総数
	int spriteNum = 2;
	std::vector<KamataEngine::Sprite*> gaugeSprite_;

	int numberNum = 5;
	std::vector<KamataEngine::Sprite*> numberSprite;

	uint32_t bgHandle;
	uint32_t whiteHandle;
	uint32_t numberHandle;

	KamataEngine::Camera* camera_;

	// ゲージのサイズ
	const KamataEngine::Vector2 stargGaugeSize_ = {200.0f, 20.0f};
	// ゲージの位置
	const KamataEngine::Vector2 gaugePos = {50.0f, 20.0f};

	// ゲージの動くスピード
	const float gaugeSpeed = 0.5f;

	// 数字のサイズ
	const KamataEngine::Vector2 numberSize = {32.0f, 64.0f};
	// 数字の位置
	const KamataEngine::Vector2 numberPos = {300.0f, 20.0f};

	// カウントの値
	int number;
	// カウントの初期値
	const int kNumber = 0;
	// カウントのスピード
	const int numberSpeed = 1;
	// 数字のカウント
	int count;
};
