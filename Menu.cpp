// include
#include "DxLib.h"
#include "SceneMgr.h"
#include "WindowSizeMgr.h"
#include "Menu.h"

// define
#define FILEPATH_MAX 1500
char OpenedFilePath[2][FILEPATH_MAX];	// �J���ꂽ�Ƃ���̃p�X(0=�R�s�[, 1=���ۂ̃E�B���h�E�̖��O)

// ������
void Menu_Init() {
	sprintf(OpenedFilePath[0], "%s", GetCommandLine());	// �N�����ꂽ���̃p�X�𓾂�

	// �Ō�́u"�v����菜��
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

	// ��������
	{
		SetUseVramFlag(TRUE);		// VRAM���g�p����
		SetUse3DFlag(FALSE);		// 3D�@�\���g�p���Ȃ�
		SetBasicBlendFlag(TRUE);	// �u�����h�̃N�I���e�B��������B
	}

	LoadWindowSize();	// �E�B���h�E�̑傫����ǂݍ���

	// �E�B���h�E�̑傫������
	int NowWindowSize_H = GetWindowSize_H();
	int NowWindowSize_W = GetWindowSize_W();

	// �ő剻���ł���悤�ɂ���
	int Desktop_H, Desktop_W;						// �f�X�N�g�b�v�̑傫��
	GetDefaultState(&Desktop_H, &Desktop_W, NULL);
	SetGraphMode(Desktop_H, Desktop_W, 32);

	SetWindowSizeChangeEnableFlag(TRUE, FALSE);			// �E�B���h�E�̃T�C�Y��ς�����悤�ɂ���
	SetWindowSize(NowWindowSize_H, NowWindowSize_W);	// �E�B���h�E�̃T�C�Y��ݒ肷��
	SetWindowPosition(GetStartWindowPos_X(), GetStartWindowPos_Y());	// �E�C���h�E���[�h�̃E�C���h�E�̈ʒu��ݒ肷��i�g���܂߂�������W�j
}

// �X�V
void Menu_Update() {

}

// �`��
void Menu_Draw() {
	DrawString(50, 50, "Hello GitHub!!", GetColor(0, 222, 0));
}