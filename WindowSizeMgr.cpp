// include
#include "DxLib.h"
#include "WindowSizeMgr.h"

// �O���[�o���ϐ�
FILE *WindowSize_File;
int WindowSize_H;
int WindowSize_W;
int StartWindowPos_X;
int StartWindowPos_Y;

// �E�B���h�E�̍����E�����t�@�C������
void LoadWindowSize() {
	if ((WindowSize_File = fopen(WINDOW_SIZE_NAME, "r")) == NULL) {
		// �������t�@�C�����J���Ȃ�������
		if ((WindowSize_File = fopen(WINDOW_SIZE_NAME, "w")) == NULL) {
			// �t�@�C�����J���Ȃ������|��`����
			MessageBox(
				NULL,
				TEXT("�t�@�C�����J���܂���ł���"),
				TEXT("�t�@�C���I�[�v��"),
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

// �E�B���h�E�̍����E�����t�@�C���o��
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

// �E�B���h�E�̍�����Ԃ�
int GetWindowSize_H() { return WindowSize_H; }

// �E�B���h�E�̕���Ԃ�
int GetWindowSize_W() { return WindowSize_W; }

// �E�B���h�E�̏����ʒu��X���W��Ԃ�
int GetStartWindowPos_X() { return StartWindowPos_X; }

// �E�B���h�E�̏����ʒu��Y���W��Ԃ�
int GetStartWindowPos_Y() { return StartWindowPos_Y; }