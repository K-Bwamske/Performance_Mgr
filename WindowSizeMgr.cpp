// include
#include "DxLib.h"
#include "WindowSizeMgr.h"

// �O���[�o���ϐ�
FILE *WindowSize_File;
int WindowSize_H;
int WindowSize_W;

// �E�B���h�E�̍����E�����t�@�C������
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

// �E�B���h�E�̍����E�����t�@�C���o��
void SaveWindowSize() {
	GetWindowSize(&WindowSize_H, &WindowSize_W);
	if ((WindowSize_File = fopen(WINDOW_SIZE_NAME, "w")) == NULL) {
		DxLib_End();
		exit(0);
	}
	fprintf(WindowSize_File, "%d %d", WindowSize_H, WindowSize_W);
	fclose(WindowSize_File);
}

// �E�B���h�E�̍�����Ԃ�
int GetWindowSize_H() { return WindowSize_H; }

// �E�B���h�E�̕���Ԃ�
int GetWindowSize_W() { return WindowSize_W; }