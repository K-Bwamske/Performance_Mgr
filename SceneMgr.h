#pragma once

// include
#include "DxLib.h"

// �V�[���\����
/* �V�[����ǉ�����ꍇ�́A
   ���̍\���̂�"Scene_??"�̌`�Œǉ����A
   �\�[�X�t�@�C���E�w�b�_�[�t�@�C���ɒ�`�E�錾 */
typedef enum {
	Scene_Menu,
	Scene_Write,
	Scene_Show,
}Scene_S;

// �X�V
void SceneMgr_Update();

// �`��
void SceneMgr_Draw();

// �V�[���ύX
/* �V�[����ύX����ꍇ�́A
   ���̊֐��̈����ɍ\����Scene_S�̗v�f������� */
void SceneMgr_ChangeScene(Scene_S NextScene);