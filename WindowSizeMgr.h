#pragma once

// define
#define WINDOW_SIZE_NAME "Performance_Mgr_Size.ini"

// �t�@�C�����J���Ȃ������Ƃ��ɂ��̂��Ƃ�`����
void Message_FileOpenMiss();

// �E�B���h�E�̍����E�����t�@�C������
void LoadWindowSize();

// �E�B���h�E�̍����E�����t�@�C���o��
void SaveWindowSize();

// �E�B���h�E�̍�����Ԃ�
int GetWindowSize_H();

// �E�B���h�E�̕���Ԃ�
int GetWindowSize_W();

// �E�B���h�E�̏����ʒu��X���W��Ԃ�
int GetStartWindowPos_X();

// �E�B���h�E�̏����ʒu��Y���W��Ԃ�
int GetStartWindowPos_Y();