// include
#include "DxLib.h"
#include "WindowSizeMgr.h"
#include "Before_Init.h"

// define
#define FILEPATH_MAX 1500
char OpenedFilePath[2][FILEPATH_MAX];	// 起動時のファイルパス(0が元のパス)

// DxLib_Init()の前にやる処理
void Before_Init() {
	SetOutApplicationLogValidFlag(FALSE);		// ログを作らない
	SetBackgroundColor(220, 220, 220);			// 背景色を設定
	ChangeWindowMode(TRUE);
	SetWindowStyleMode(7);						// ウィンドウのモードを設定

	// ""を取り除く
	{
		sprintf(OpenedFilePath[0], "%s", GetCommandLine());
		for (int a = FILEPATH_MAX - 1; a > 0; a--) {
			if (OpenedFilePath[0][a] == '\"') {
				OpenedFilePath[0][a] = '\0';
				break;
			}
		}
		for (int a = FILEPATH_MAX - 1; a > 0; a--) {
			if (OpenedFilePath[0][a] == '\\') {
				for (int b = 0; b < FILEPATH_MAX - a - 1; b++) {
					if (OpenedFilePath[0][a + b + 1] == '\0') {
						OpenedFilePath[1][b] = OpenedFilePath[0][a + b + 1];
						break;
					}
					OpenedFilePath[1][b] = OpenedFilePath[0][a + b + 1];
				}
				break;
			}
		}
	}

	SetMainWindowText(OpenedFilePath[1]);		// ウィンドウの名前変更


	// 高速化
	{
		SetUseVramFlag(TRUE);		// VRAMを使う
		SetUse3DFlag(FALSE);		// 3Dを使わない
		SetBasicBlendFlag(TRUE);	// Blendの質を落とす
	}

	LoadWindowSize();	// ウィンドウサイズを読み込む

						// ウィンドウの高さと幅を得る
	int NowWindowSize_H = GetWindowSize_H();
	int NowWindowSize_W = GetWindowSize_W();

	// ウィンドウの大きさを変える
	int Desktop_H, Desktop_W;
	GetDefaultState(&Desktop_H, &Desktop_W, NULL);
	SetGraphMode(Desktop_H, Desktop_W, 32);

	SetWindowSizeChangeEnableFlag(TRUE, FALSE);							// ウィンドウの大きさを変えられるようにする
	SetWindowSize(NowWindowSize_H, NowWindowSize_W);					// ウィンドウの大きさを設定する
	SetWindowPosition(GetStartWindowPos_X(), GetStartWindowPos_Y());	// ウィンドウの左上の位置を設定する
}