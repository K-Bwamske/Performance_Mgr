// include
#include "DxLib.h"
#include "EndCheck.h"

// �I���m�F�����i�u�͂��v�������ꂽ��I���j
int EndCheck(){
	switch (MessageBox(GetMainWindowHandle(), _T("�I�����܂����H"), _T("�m�F"), MB_YESNOCANCEL))
	{
	case IDYES:
		return TRUE;
		break;
	default:
		break;
	}
	return FALSE;
}