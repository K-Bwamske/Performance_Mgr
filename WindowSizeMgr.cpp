// include
#include "DxLib.h"
#include "WindowSizeMgr.h"

// グローバル変数
FILE *WindowSize_File;
int WindowSize_H;
int WindowSize_W;

// ウィンドウの高さ・幅をファイル入力
void LoadWindowSize() {
	if ((WindowSize_File = fopen(WINDOW_SIZE_NAME, "r")) == NULL) {
		if ((WindowSize_File = fopen(WINDOW_SIZE_NAME, "w")) == NULL) {
			DxLib_End();
			exit(0);
		}
		fprintf(WindowSize_File, "640 480");
		fclose(WindowSize_File);
		WindowSize_File = fopen(WINDOW_SIZE_NAME, "r");
	}
	fscanf_s(WindowSize_File, "%d%d", &WindowSize_H, &WindowSize_W);
	fclose(WindowSize_File);
}

// ウィンドウの高さ・幅をファイル出力
void SaveWindowSize() {
	GetWindowSize(&WindowSize_H, &WindowSize_W);
	if ((WindowSize_File = fopen(WINDOW_SIZE_NAME, "w")) == NULL) {
		DxLib_End();
		exit(0);
	}
	fprintf(WindowSize_File, "%d %d", WindowSize_H, WindowSize_W);
	fclose(WindowSize_File);
}

// ウィンドウの高さを返す
int GetWindowSize_H() { return WindowSize_H; }

// ウィンドウの幅を返す
int GetWindowSize_W() { return WindowSize_W; }