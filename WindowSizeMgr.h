#pragma once

// define
#define WINDOW_SIZE_NAME "メモ帳ウィンドウサイズ.ini"

// ウィンドウの高さ・幅をファイル入力
void LoadWindowSize();

// ウィンドウの高さ・幅をファイル出力
void SaveWindowSize();

// ウィンドウの高さを返す
int GetWindowSize_H();

// ウィンドウの幅を返す
int GetWindowSize_W();