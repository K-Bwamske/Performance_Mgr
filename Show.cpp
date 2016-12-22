// include
#include "DxLib.h"
#include "SceneMgr.h"
#include "Show.h"
#include <algorithm>

int Window_W, Window_H;		// 一応作った（名前は後で変えてね）(WindowSizeMgrに新しい関数を作るのを推奨)

int bar_size;
int bar_pos;

// 現在の表示している位置（スクロールバー用）
int NowDrawPos_W;

// スクロールのスピード（スクロールバー用）
int speed;

// スクロールする領域（スクロールバー用）
int scroll_all;		// (きっとスペルミスなし)

// 初期化
void Show_Init() {
	NowDrawPos_W = 0;
	speed = 20;
	scroll_all = 10000;
}

// 更新
void Show_Update() {
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0) NowDrawPos_W += speed;
	if (CheckHitKey(KEY_INPUT_LEFT) != 0) NowDrawPos_W -= speed;
	if (NowDrawPos_W < 0) NowDrawPos_W = 0;
	if (scroll_all < NowDrawPos_W) NowDrawPos_W = scroll_all;

	GetWindowSize(&Window_W, &Window_H);

	// スクロールバーの情報更新
	bar_size = (Window_W * Window_W) / scroll_all;
	bar_pos = (NowDrawPos_W * (Window_W - bar_size)) / scroll_all;


}

// 描画
void Show_Draw() {

	// 移動していることの確認用(ページ数)
	DrawFormatString((scroll_all - NowDrawPos_W) % Window_W, 100, GetColor(0, 0, 0), "%d", scroll_all / Window_W - (scroll_all - NowDrawPos_W) / Window_W);
	
	// 書き方(可変)(例)
	DrawCircleAA(200 - NowDrawPos_W, 300, 15, 100,  GetColor(0, 0, 0), TRUE);

	// 書き方(固定)(例)
	DrawBox(100, 0, Window_W - 100, 50, GetColor(50, 50, 50), TRUE);
	
	// スクロールバーの全体を描画
	DrawBox(0, Window_H - 50, Window_W, Window_H, GetColor(180, 180, 180), TRUE);



	// スクロールバー（黒）描画
	DrawBox(bar_pos, Window_H - 50, bar_pos + bar_size, Window_H, GetColor(50, 50, 50), TRUE);
}