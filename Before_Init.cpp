// include
#include "DxLib.h"
#include "WindowSizeMgr.h"

// define
#define FILEPATH_MAX 1500
char OpenedFilePath[2][FILEPATH_MAX];	// 起動時のファイルパス

// DxLib_Init()の前にやる処理
void Before_Init() {
	SetOutApplicationLogValidFlag(FALSE);		// ログを作らない
	SetMainWindowText("Performance_Mgr v1.0");
	SetBackgroundColor(220, 220, 220);
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