// include
#include "DxLib.h"
#include "SceneMgr.h"
#include "Show.h"
#include <algorithm>

// スクロールバー関係の定数
const int SCROLL_SPEED = 20;	// スクロールの速さ
const int SCROLL_AREA = 10000;	// スクロールする領域

int Window_W, Window_H;		// 一応作った（名前は後で変えてね）(WindowSizeMgrに新しい関数を作るのを推奨)

// スクロールバー関係の変数
int bar_Size;				// ?
int bar_Pos;				// ?
int bar_NowDrawPos_X;		// 現在の表示している位置

// 初期化
void Show_Init() {
	bar_NowDrawPos_X = 0;
	SCROLL_SPEED = 20;
	SCROLL_AREA = 10000;
}

// 更新
void Show_Update() {
	GetWindowSize(&Window_W, &Window_H);
	ScrollBar_Update();
}

// 描画
void Show_Draw() {
	DrawFormatString((SCROLL_AREA - bar_NowDrawPos_X) % Window_W, 100, GetColor(0, 0, 0), "%d", SCROLL_AREA / Window_W - (SCROLL_AREA - bar_NowDrawPos_X) / Window_W);	// 移動していることの確認用（ページ数）
	ScrollBar_Draw();
}

// スクロールバー更新
void ScrollBar_Update(){
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0) bar_NowDrawPos_X += SCROLL_SPEED;
	if (CheckHitKey(KEY_INPUT_LEFT) != 0) bar_NowDrawPos_X -= SCROLL_SPEED;
	if (bar_NowDrawPos_X < 0) bar_NowDrawPos_X = 0;
	if (SCROLL_AREA < bar_NowDrawPos_X) bar_NowDrawPos_X = SCROLL_AREA;
	bar_Size = (Window_W * Window_W) / SCROLL_AREA;
	bar_Pos = (bar_NowDrawPos_X * (Window_W - bar_Size)) / SCROLL_AREA;
}

// スクロールバー描画
void ScrollBar_Draw(){
	DrawCircleAA(200 - bar_NowDrawPos_X, 300, 15, 100,  GetColor(0, 0, 0), TRUE);				// ?
	DrawBox(100, 0, Window_W - 100, 50, GetColor(50, 50, 50), TRUE);							// ?
	DrawBox(0, Window_H - 50, Window_W, Window_H, GetColor(180, 180, 180), TRUE);				// スクロールバー全体描画
	DrawBox(bar_Pos, Window_H - 50, bar_Pos + bar_Size, Window_H, GetColor(50, 50, 50), TRUE);	// スクロールバー（黒）描画
}