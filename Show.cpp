// include
#include "DxLib.h"
#include "SceneMgr.h"
#include "Show.h"
#include <algorithm>

// ���݂̕\�����Ă���ʒu�i�X�N���[���o�[�p�j
int NowDrawPos_W;

// �X�N���[���̃X�s�[�h�i�X�N���[���o�[�p�j
int speed;

// �X�N���[������̈�i�X�N���[���o�[�p�j
int scrool_all;		// (�����ƃX�y���~�X)

// ������
void Show_Init() {
	NowDrawPos_W = 0;
	speed = 20;
	scrool_all = 10000;
}

// �X�V
void Show_Update() {
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0) NowDrawPos_W -= speed;
	if (CheckHitKey(KEY_INPUT_LEFT) != 0) NowDrawPos_W += speed;
	if (NowDrawPos_W < 0) NowDrawPos_W = 0;
	if (scrool_all < NowDrawPos_W) NowDrawPos_W = scrool_all;
}

// �`��
void Show_Draw() {
	static int Window_W, Window_H;		// �ꉞ������i���O�͌�ŕς��Ăˁj(WindowSizeMgr�ɐV�����֐������̂𐄏�)
	GetWindowSize(&Window_W, &Window_H);
	DrawFormatString(NowDrawPos_W % Window_W, 100, GetColor(0, 0, 0), "%d", std::abs(NowDrawPos_W) / Window_W + 1);
	DrawBox(0, Window_H - 50, Window_W, Window_H, GetColor(180, 180, 180), TRUE);

	int bar_size;
	int bar_pos;

	bar_size = (Window_W * Window_W) / scrool_all;
	bar_pos = (NowDrawPos_W * (Window_W - bar_size)) / scrool_all;
	DrawBox(bar_pos, Window_H - 50, bar_pos + bar_size, Window_H, GetColor(50, 50, 50), TRUE);
}