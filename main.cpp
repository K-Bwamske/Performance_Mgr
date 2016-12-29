////////////////////////////////////////////
//                                        //
//         Performance_Mgr v1.0           //
//         (Performance Manager)          //
//             by K-Bwamske :)            //
//                                        //
////////////////////////////////////////////

// include
#include "DxLib.h"
#include "SceneMgr.h"
#include "WindowSizeMgr.h"
#include "EndCheck.h"
#include "Menu.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetOutApplicationLogValidFlag(FALSE);
	SetMainWindowText("Performance_Mgr v1.0");
	SetBackgroundColor(220, 220, 220);
	ChangeWindowMode(TRUE);
	SetWindowStyleMode(7);						// �E�B���h�E�̃��[�h���ݒ�
	if (DxLib_Init() == -1) { return -1; }
	Menu_Init();								// �N�����ŏ��̃V�[���Ȃ̂ŁA���C�����[�v�ɓ����O�ɏ�����
	DrawString(100, 100, "Loading Now�c", GetColor(0, 0, 0));
	SetDrawScreen(DX_SCREEN_BACK);
	SetWindowUserCloseEnableFlag(FALSE);
	SetAlwaysRunFlag(TRUE);
	SetDoubleStartValidFlag(TRUE);				// �E�B���h�E�̑��d�N����������

	while (ProcessMessage() == 0) {
		ClearDrawScreen();
		KeepWindowRatio();
		SceneMgr_Update();
		SceneMgr_Draw();
		if (GetWindowUserCloseFlag(TRUE) == TRUE) {
			if (EndCheck() == TRUE) { break; }
		}
		ScreenFlip();
	}

	SaveWindowSize();	// �E�B���h�E�̍����E�����t�@�C���o��

	DxLib_End();
	return 0;
}