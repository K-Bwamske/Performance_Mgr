#include "DxLib.h"
#include "After_Init.h"

// DxLib_Init()�̌�ɂ�鏈��
void After_Init() {
	SetDrawScreen(DX_SCREEN_BACK);
	SetWindowUserCloseEnableFlag(FALSE);
	SetAlwaysRunFlag(TRUE);
	SetDoubleStartValidFlag(TRUE);				// �E�B���h�E�̑��d�N����������
}