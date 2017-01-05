#include <DxLib.h>

// DxLib_Init()の前にやる処理
void Before_Init() {
	SetOutApplicationLogValidFlag(FALSE);		// ログを作らない
	SetMainWindowText("Performance_Mgr v1.0");
	SetBackgroundColor(220, 220, 220);
	ChangeWindowMode(TRUE);
	SetWindowStyleMode(7);						// ウィンドウのモードを設定
}