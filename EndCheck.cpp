// include
#include "DxLib.h"
#include "EndCheck.h"
#include "stdio.h"

// �I���m�F�����i�u�͂��v�������ꂽ��I���j
int EndCheck() {
	switch (MessageBox(GetMainWindowHandle(), _T("�ۑ����܂����H"), _T("�m�F"), MB_YESNOCANCEL))
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