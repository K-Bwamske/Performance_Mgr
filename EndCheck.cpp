// include
#include "DxLib.h"
#include "EndCheck.h"

// 終了確認処理（「はい」が押されたら終了）

int EndCheck() {
	switch (MessageBox(GetMainWindowHandle(), _T("ウィンドウの大きさを保存しますか？"), _T("確認"), MB_YESNOCANCEL))
	{
	case IDYES:
		return TRUE;
		break;
	case IDNO:
		DxLib_End();
		exit(0);
		break;
	default:
		break;
	}
	return FALSE;
}