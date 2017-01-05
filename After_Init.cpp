#include <DxLib.h>

// DxLib_Init()の後にやる処理
void After_Init() {
	SetDrawScreen(DX_SCREEN_BACK);
	SetWindowUserCloseEnableFlag(FALSE);
	SetAlwaysRunFlag(TRUE);
	SetDoubleStartValidFlag(TRUE);				// ウィンドウの多重起動を許可する
}