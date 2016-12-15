// include
#include "DxLib.h"
#include "EndCheck.h"

// 終了確認処理（「はい」が押されたら終了）
int EndCheck(){
	switch (MessageBox(GetMainWindowHandle(), _T("終了しますか？"), _T("確認"), MB_YESNOCANCEL))
	{
	case IDYES:
		return TRUE;
		break;
	default:
		break;
	}
	return FALSE;
}