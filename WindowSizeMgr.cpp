// include
#include "DxLib.h"
#include "WindowSizeMgr.h"

// グローバル変数
FILE *WindowSize_File;
int WindowSize_H;
int WindowSize_W;
int StartWindowPos_X;
int StartWindowPos_Y;

// ウィンドウの高さ・幅をファイル入力
void LoadWindowSize() {
	if ((WindowSize_File = fopen(WINDOW_SIZE_NAME, "r")) == NULL) {
		// もしもファイルが開けなかったら
		if ((WindowSize_File = fopen(WINDOW_SIZE_NAME, "w")) == NULL) {
			// ファイルが開けなかった旨を伝える
			MessageBox(
				NULL,
				TEXT("ファイルが開けませんでした"),
				TEXT("ファイルオープン"),
				MB_YESNO | MB_ICONWARNING);

			DxLib_End();
			exit(0);
		}
		fprintf(WindowSize_File, "640 480\n100 100");
		fclose(WindowSize_File);
		WindowSize_File = fopen(WINDOW_SIZE_NAME, "r");
	}
	fscanf_s(WindowSize_File, "%d%d%d%d", &WindowSize_H, &WindowSize_W, &StartWindowPos_X, &StartWindowPos_Y);
	fclose(WindowSize_File);
}

// ウィンドウの高さ・幅をファイル出力
void SaveWindowSize() {
	GetWindowSize(&WindowSize_H, &WindowSize_W);
	if ((WindowSize_File = fopen(WINDOW_SIZE_NAME, "w")) == NULL) {
		DxLib_End();
		exit(0);
	}
	int WindowPos_X, WindowPos_Y;
	GetWindowPosition(&WindowPos_X, &WindowPos_Y);
	fprintf(WindowSize_File, "%d %d\n%d %d", WindowSize_H, WindowSize_W, WindowPos_X, WindowPos_Y);
	fclose(WindowSize_File);
}

// ウィンドウの高さを返す
int GetWindowSize_H() { return WindowSize_H; }

// ウィンドウの幅を返す
int GetWindowSize_W() { return WindowSize_W; }

// ウィンドウの初期位置のX座標を返す
int GetStartWindowPos_X() { return StartWindowPos_X; }

// ウィンドウの初期位置のY座標を返す
int GetStartWindowPos_Y() { return StartWindowPos_Y; }