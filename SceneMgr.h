#pragma once

// include
#include "DxLib.h"

// シーン構造体
/* シーンを追加する場合は、
   この構造体に"Scene_??"の形で追加し、
   ソースファイル・ヘッダーファイルに定義・宣言 */
typedef enum {
	Scene_Menu,
	Scene_Write,
	Scene_Show,
}Scene_S;

// 更新
void SceneMgr_Update();

// 描画
void SceneMgr_Draw();

// シーン変更
/* シーンを変更する場合は、
   この関数の引数に構造体Scene_Sの要素をいれる */
void SceneMgr_ChangeScene(Scene_S NextScene);