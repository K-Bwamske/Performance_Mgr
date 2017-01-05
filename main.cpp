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
	SetWindowStyleMode(7);						// ウィンドウのモードを設定
	if (DxLib_Init() == -1) { return -1; }
	Menu_Init();								// ウィンドウの多重起動を許可する
	DrawString(100, 100, "Loading Now...", GetColor(0, 0, 0));
	SetDrawScreen(DX_SCREEN_BACK);
	SetWindowUserCloseEnableFlag(FALSE);
	SetAlwaysRunFlag(TRUE);
	SetDoubleStartValidFlag(TRUE);				// 起動時最初のシーンなので、メインループに入る前に初期化

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