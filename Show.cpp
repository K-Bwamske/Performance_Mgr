// include
#include "DxLib.h"
#include "SceneMgr.h"
#include "Show.h"
#include <algorithm>

int Window_W, Window_H;		// �ꉞ������i���O�͌�ŕς��Ăˁj(WindowSizeMgr�ɐV�����֐������̂𐄏�)

int bar_size;
int bar_pos;

// ���݂̕\�����Ă���ʒu�i�X�N���[���o�[�p�j
int NowDrawPos_W;

// �X�N���[���̃X�s�[�h�i�X�N���[���o�[�p�j
int speed;

// �X�N���[������̈�i�X�N���[���o�[�p�j
int scroll_all;		// (�����ƃX�y���~�X�Ȃ�)

// ������
void Show_Init() {
	NowDrawPos_W = 0;
	speed = 20;
	scroll_all = 10000;
}

// �X�V
void Show_Update() {
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0) NowDrawPos_W += speed;
	if (CheckHitKey(KEY_INPUT_LEFT) != 0) NowDrawPos_W -= speed;
	if (NowDrawPos_W < 0) NowDrawPos_W = 0;
	if (scroll_all < NowDrawPos_W) NowDrawPos_W = scroll_all;

	GetWindowSize(&Window_W, &Window_H);

	// �X�N���[���o�[�̏��X�V
	bar_size = (Window_W * Window_W) / scroll_all;
	bar_pos = (NowDrawPos_W * (Window_W - bar_size)) / scroll_all;


}

// �`��
void Show_Draw() {

	// �ړ����Ă��邱�Ƃ̊m�F�p(�y�[�W��)
	DrawFormatString((scroll_all - NowDrawPos_W) % Window_W, 100, GetColor(0, 0, 0), "%d", scroll_all / Window_W - (scroll_all - NowDrawPos_W) / Window_W);
	
	// ������(��)(��)
	DrawCircleAA(200 - NowDrawPos_W, 300, 15, 100,  GetColor(0, 0, 0), TRUE);

	// ������(�Œ�)(��)
	DrawBox(100, 0, Window_W - 100, 50, GetColor(50, 50, 50), TRUE);
	
	// �X�N���[���o�[�̑S�̂�`��
	DrawBox(0, Window_H - 50, Window_W, Window_H, GetColor(180, 180, 180), TRUE);



	// �X�N���[���o�[�i���j�`��
	DrawBox(bar_pos, Window_H - 50, bar_pos + bar_size, Window_H, GetColor(50, 50, 50), TRUE);
}