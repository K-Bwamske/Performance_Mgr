// include
#include "DxLib.h"
#include "SceneMgr.h"
#include "Show.h"

// スクロールバー関係の定数
const int SCROLL_SPEED = 20;		// スクロールの速さ
const int SCROLL_AREA = 10000;		// スクロールする領域
const int SCROLLBAR_H = 50;			// スクロールバーの高さ
const int BAR_MOVE_SPEED = 50;		// バーではないところをクリックしたときのバーの移動速度
const int BAR_VAN_MOVE_H = 150;		// バーをクリックした後のバーが動くウィンドウの下からの最長距離

// スクロールバー関係の変数
int bar_Size;						// ウィンドウ上に表示しているバーの大きさ
int bar_Pos;						// ウィンドウ上に表示しているバーの位置
int bar_NowDrawPos_X;				// 表示したい全体の表示している位置

// スクロールバーをクリックしたときの変数
int bar_click_pos;					// バーをクリックしたときのバーの左端からの座標
int bar_clicked_pos;				// バーを最初にクリックしたときの座標
bool bar_click_flag;				// false == 押していない	true == 押し続けている

int Window_W, Window_H;				// 一応作った（名前は後で変えてね）(WindowSizeMgrに新しい関数を作るのを推奨)
int Mouse_X, Mouse_Y;				// マウスポインターの座標

// 初期化
void Show_Init() {
	GetWindowSize(&Window_W, &Window_H);
	bar_NowDrawPos_X = 0;
	bar_click_flag = false;
}

// 更新
void Show_Update() {
	GetWindowSize(&Window_W, &Window_H);
	ScrollBar_Update();
}

// 描画
void Show_Draw() {
	DrawFormatString((SCROLL_AREA - bar_NowDrawPos_X) % Window_W, 100, GetColor(0, 0, 0), "%d", SCROLL_AREA / Window_W - (SCROLL_AREA - bar_NowDrawPos_X) / Window_W);	// 移動していることの確認用（ページ数）
	ScrollBar_Draw();
}

// スクロールバー更新
void ScrollBar_Update(){
	// 押されていない状態
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0) bar_NowDrawPos_X += SCROLL_SPEED;
	if (CheckHitKey(KEY_INPUT_LEFT) != 0) bar_NowDrawPos_X -= SCROLL_SPEED;
	if (bar_NowDrawPos_X < 0) bar_NowDrawPos_X = 0;
	if (SCROLL_AREA < bar_NowDrawPos_X) bar_NowDrawPos_X = SCROLL_AREA;
	bar_Size = (Window_W * Window_W) / SCROLL_AREA;
	bar_Pos = (bar_NowDrawPos_X * (Window_W - bar_Size)) / SCROLL_AREA;
	
	// 押されている状態
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
		GetMousePoint(&Mouse_X, &Mouse_Y);
		if (Window_H - BAR_VAN_MOVE_H < Mouse_Y) {
			if (bar_click_flag == false) {
				if (Window_H - SCROLLBAR_H < Mouse_Y) {
					if (bar_Pos < Mouse_X &&
						Mouse_X < bar_Pos + bar_Size) {
						bar_click_flag = true;
						bar_click_pos = Mouse_X - bar_Pos;
						bar_clicked_pos = bar_Pos;
						
					}
					else {
						if (bar_Pos < Mouse_X - BAR_MOVE_SPEED) { bar_Pos += BAR_MOVE_SPEED; }
						else if (bar_Pos < Mouse_X) { bar_Pos += bar_Size; }
						else if (Mouse_X + BAR_MOVE_SPEED < bar_Pos + bar_Size) { bar_Pos -= BAR_MOVE_SPEED; }
						else if (Mouse_X < bar_Pos + bar_Size) { bar_Pos -= bar_Size; }
					}
				}
			}
			else { bar_Pos = Mouse_X - bar_click_pos; }
			bar_Pos = (bar_Pos < 0 ? 0 : bar_Pos);
			if (Window_W - bar_Size < bar_Pos) { bar_Pos = Window_W - bar_Size; }
			bar_NowDrawPos_X = (bar_Pos * SCROLL_AREA) / (Window_W - bar_Size);
		}
		else {
			bar_Pos = bar_clicked_pos;
			bar_Pos = (bar_Pos < 0 ? 0 : bar_Pos);
			if (Window_W - bar_Size < bar_Pos) { bar_Pos = Window_W - bar_Size; }
			bar_NowDrawPos_X = (bar_Pos * SCROLL_AREA) / (Window_W - bar_Size);
		}
	}
	else { bar_click_flag = false; }
}

// スクロールバー描画
void ScrollBar_Draw(){
	DrawCircleAA(200 - bar_NowDrawPos_X, 300, 15, 100,  GetColor(0, 0, 0), TRUE);								// 移動する表示物の書き方（例）
	DrawBox(100, 0, Window_W - 100, 50, GetColor(50, 50, 50), TRUE);											// 移動しない表示物の書き方（例）
	DrawBox(0, Window_H - SCROLLBAR_H, Window_W, Window_H, GetColor(180, 180, 180), TRUE);						// スクロールバー全体描画
	DrawBox(bar_Pos, Window_H - SCROLLBAR_H, bar_Pos + bar_Size, Window_H, GetColor(100, 100, 100), TRUE);		// スクロールバー（押されていない時Ver）描画
	if (bar_click_flag == true) {
		DrawBox(bar_Pos, Window_H - SCROLLBAR_H, bar_Pos + bar_Size, Window_H, GetColor(50, 50, 50), TRUE);		// スクロールバー（押されている時Ver）描画
	}
}
