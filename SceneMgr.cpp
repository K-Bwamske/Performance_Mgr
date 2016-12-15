// include
#include "DxLib.h"
#include "SceneMgr.h"
#include "Menu.h"
#include "Write.h"
#include "Show.h"

// グローバル変数
static Scene_S Scene = Scene_Menu;	// 起動時最初のシーン指定
bool Init_flag_Write = false;		// 初期化済みの有無
bool Init_flag_Show = false;		// 初期化済みの有無

// 更新
void SceneMgr_Update() {
	switch (Scene) {
	case Scene_Menu:
		Menu_Update();
		break;

	case Scene_Write:
		Write_Update();
		break;

	case Scene_Show:
		Show_Update();
		break;
	}
}

// 描画
void SceneMgr_Draw() {
	switch (Scene) {
	case Scene_Menu:
		Menu_Draw();
		break;

	case Scene_Write:
		Write_Draw();
		break;

	case Scene_Show:
		Show_Draw();
		break;
	}
}

// シーン変更
void SceneMgr_ChangeScene(Scene_S NextScene) {
	Scene = NextScene;
	switch (Scene) {
	case Scene_Menu:
		// main.cppで初期化済み
		break;

	case Scene_Show:
		if (Init_flag_Show == false) {
			Show_Init();
			Init_flag_Show = true;
		}
		break;

	case Scene_Write:
		if (Init_flag_Write == false) {
			Write_Init();
			Init_flag_Write = true;
		}
		break;
	}
}