#pragma once
#include "gameNode.h"

class Title : public gameNode
{
private:
	RECT rc_btn[5];
	bool intro_active;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	Title();
	~Title();

	bool getIntro_active() { return intro_active; }

	//폰트 (기본 검은색)
	void textOutFont(HDC hdc, int x, int y, const char* str, int size = 50, COLORREF color = RGB(255, 255, 255), const char* font = "메이플스토리");

};

