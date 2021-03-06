// include
#include "DxLib.h"
#include "SceneMgr.h"
#include "Show.h"

// スクロールバー関係の構造体
struct ScrollBar {
	int Size;									// ウィンドウ上に表示しているバーの大きさ
	int Pos;									// ウィンドウ上に表示しているバーの位置(X)
	int NowDrawPos_X;							// 表示したい全体の表示している位置
	int click_pos;								// バーをクリックしたときのバーの左端からの座標
	int clicked_pos;							// バーを最初にクリックしたときの座標
	bool click_flag;							// false == 押していない	true == 押し続けている
	const float SCROLLBAR_LEFT = 0;				// スクロールバーのウィンドウの左からのウィンドウの大きさを1としたときの割合
	const float SCROLLBAR_RIGHT = (1.0 / 6.0);	// スクロールバーのウィンドウの右からのウィンドウの大きさを1としたときの割合
	const float WINDOW_LEFT = 0;				// スクロールバーで表示するウィンドウの左からのウィンドウの大きさを1としたときの割合
	const float WINDOW_RIGHT = (1.0 / 6.0);		// スクロールバーで表示するのウィンドウの右からのウィンドウの大きさを1としたときの割合
};
ScrollBar MainBar;


// スクロールバー関係の定数
const int SCROLL_SPEED = 20;				// スクロールの速さ
const int SCROLLBAR_H = 50;					// スクロールバーの高さ
const int BAR_MOVE_SPEED = 50;				// バーではないところをクリックしたときのバーの移動速度
const int BAR_VAN_MOVE_H = 150;				// バーをクリックした後のバーが動くウィンドウの下からの最長距離

// スクロールバー関係の変数
int SCROLL_AREA = 10000;					// スクロールする領域

int Window_W, Window_H;						// 一応作った（名前は後で変えてね）(WindowSizeMgrに新しい関数を作るのを推奨)
int Mouse_X, Mouse_Y;						// マウスポインターの座標

// 初期化
void Show_Init() {
	GetWindowSize(&Window_W, &Window_H);
	MainBar.NowDrawPos_X = 0;
	MainBar.click_flag = false;
}

// 更新
void Show_Update() {
	GetWindowSize(&Window_W, &Window_H);
	ScrollBar_Update();
}

// 描画
void Show_Draw() {
	ScrollBar_Draw();
}

// スクロールバー更新
void ScrollBar_Update(){
	// 押されていない状態
	if (CheckHitKey(KEY_INPUT_RIGHT) != 0) MainBar.NowDrawPos_X += SCROLL_SPEED;
	if (CheckHitKey(KEY_INPUT_LEFT) != 0) MainBar.NowDrawPos_X -= SCROLL_SPEED;
	if (MainBar.NowDrawPos_X < 0) MainBar.NowDrawPos_X = 0;
	if (SCROLL_AREA < MainBar.NowDrawPos_X) MainBar.NowDrawPos_X = SCROLL_AREA;
	MainBar.Size = (Window_W * Window_W) / SCROLL_AREA;
	MainBar.Pos = (MainBar.NowDrawPos_X * (Window_W - MainBar.Size)) / SCROLL_AREA;

	GetMousePoint(&Mouse_X, &Mouse_Y);
	// 押されている状態
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
		if (Window_H - BAR_VAN_MOVE_H < Mouse_Y) {
			if (MainBar.click_flag == false) {
				if (Window_H - SCROLLBAR_H < Mouse_Y) {
					if (MainBar.Pos < Mouse_X &&
						Mouse_X < MainBar.Pos + MainBar.Size) {
						MainBar.click_flag = true;
						MainBar.click_pos = Mouse_X - MainBar.Pos;
						MainBar.clicked_pos = MainBar.Pos;
						
					}
					else {
						if (MainBar.Pos < Mouse_X - BAR_MOVE_SPEED) { MainBar.Pos += BAR_MOVE_SPEED; }
						else if (MainBar.Pos < Mouse_X) { MainBar.Pos += MainBar.Size; }
						else if (Mouse_X + BAR_MOVE_SPEED < MainBar.Pos + MainBar.Size) { MainBar.Pos -= BAR_MOVE_SPEED; }
						else if (Mouse_X < MainBar.Pos + MainBar.Size) { MainBar.Pos -= MainBar.Size; }
					}
				}
			}
			else { MainBar.Pos = Mouse_X - MainBar.click_pos; }
			MainBar.Pos = (MainBar.Pos < 0 ? 0 : MainBar.Pos);
			if (Window_W - MainBar.Size < MainBar.Pos) { MainBar.Pos = Window_W - MainBar.Size; }
			MainBar.NowDrawPos_X = (MainBar.Pos * SCROLL_AREA) / (Window_W - MainBar.Size);
		}
		else {
			MainBar.Pos = MainBar.clicked_pos;
			MainBar.Pos = (MainBar.Pos < 0 ? 0 : MainBar.Pos);
			if (Window_W - MainBar.Size < MainBar.Pos) { MainBar.Pos = Window_W - MainBar.Size; }
			MainBar.NowDrawPos_X = (MainBar.Pos * SCROLL_AREA) / (Window_W - MainBar.Size);
		}
	}
	else { MainBar.click_flag = false; }
}

// スクロールバー描画
void ScrollBar_Draw(){
	DrawCircleAA(200 - MainBar.NowDrawPos_X, 300, 15, 100,  GetColor(0, 0, 0), TRUE);								// 移動する表示物の書き方（例）
	DrawBox(100, 0, Window_W - 100, 50, GetColor(50, 50, 50), TRUE);											// 移動しない表示物の書き方（例）
	DrawBox(0, Window_H - SCROLLBAR_H, Window_W, Window_H, GetColor(180, 180, 180), TRUE);						// スクロールバー全体描画
	DrawBox(MainBar.Pos, Window_H - SCROLLBAR_H, MainBar.Pos + MainBar.Size, Window_H, GetColor(150, 150, 150), TRUE);		// スクロールバー（押されていない時Ver）描画
	if (MainBar.Pos < Mouse_X &&
		Mouse_X < MainBar.Pos + MainBar.Size &&
		Mouse_Y > Window_H - SCROLLBAR_H &&
		Mouse_Y < Window_H) {
		DrawBox(MainBar.Pos, Window_H - SCROLLBAR_H, MainBar.Pos + MainBar.Size, Window_H, GetColor(100, 100, 100), TRUE);		// スクロールバー（マウスが上にある時Ver）描画
	}
	if (MainBar.click_flag == true) {
		DrawBox(MainBar.Pos, Window_H - SCROLLBAR_H, MainBar.Pos + MainBar.Size, Window_H, GetColor(50, 50, 50), TRUE);		// スクロールバー（押されている時Ver）描画
	}
}
