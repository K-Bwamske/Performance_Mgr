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

}

// 更新
void Menu_Update() {
	// 仮
	SceneMgr_ChangeScene(Scene_Show);
}

// 描画
void Menu_Draw() {

}