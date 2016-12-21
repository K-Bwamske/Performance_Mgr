// include
#include "DxLib.h"
#include "SceneMgr.h"
#include "WindowSizeMgr.h"
#include "Menu.h"

// define
#define FILEPATH_MAX 1500
char OpenedFilePath[2][FILEPATH_MAX];	// 開かれたところのパス(0=コピー, 1=実際のウィンドウの名前)

// 初期化
void Menu_Init() {
	sprintf(OpenedFilePath[0], "%s", GetCommandLine());	// 起動された時のパスを得る

	// 最後の「"」を取り除く
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

	// 速くする
	{
		SetUseVramFlag(TRUE);		// VRAMを使用する
		SetUse3DFlag(FALSE);		// 3D機能を使用しない
		SetBasicBlendFlag(TRUE);	// ブレンドのクオリティを下げる。
	}

	LoadWindowSize();	// ウィンドウの大きさを読み込む

	// ウィンドウの大きさを代入
	int NowWindowSize_H = GetWindowSize_H();
	int NowWindowSize_W = GetWindowSize_W();

	// 最大化ができるようにする
	int Desktop_H, Desktop_W;						// デスクトップの大きさ
	GetDefaultState(&Desktop_H, &Desktop_W, NULL);
	SetGraphMode(Desktop_H, Desktop_W, 32);

	SetWindowSizeChangeEnableFlag(TRUE, FALSE);			// ウィンドウのサイズを変えられるようにする
	SetWindowSize(NowWindowSize_H, NowWindowSize_W);	// ウィンドウのサイズを設定する
	SetWindowPosition(GetStartWindowPos_X(), GetStartWindowPos_Y());	// ウインドウモードのウインドウの位置を設定する（枠も含めた左上座標）
}

// 更新
void Menu_Update() {

}

// 描画
void Menu_Draw() {
	DrawString(50, 50, "Hello GitHub!!", GetColor(0, 222, 0));
}