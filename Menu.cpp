// include
#include "DxLib.h"
#include "SceneMgr.h"
#include "WindowSizeMgr.h"
#include "Menu.h"

// define
#define FILEPATH_MAX 1500
char OpenedFilePath[2][FILEPATH_MAX];	// 起動時のファイルパス

// 初期化
void Menu_Init() {

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

// 更新
void Menu_Update() {
	// 仮
	SceneMgr_ChangeScene(Scene_Show);
}

// 描画
void Menu_Draw() {

}