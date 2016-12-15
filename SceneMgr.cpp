// include
#include "DxLib.h"
#include "SceneMgr.h"
#include "Menu.h"
#include "Write.h"
#include "Show.h"

// �O���[�o���ϐ�
static Scene_S Scene = Scene_Menu;	// �N�����ŏ��̃V�[���w��
bool Init_flag_Write = false;		// �������ς݂̗L��
bool Init_flag_Show = false;		// �������ς݂̗L��

// �X�V
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

// �`��
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

// �V�[���ύX
void SceneMgr_ChangeScene(Scene_S NextScene) {
	Scene = NextScene;
	switch (Scene) {
	case Scene_Menu:
		// main.cpp�ŏ������ς�
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