#pragma once
#include"gameNode.h"
class intro : public gameNode
{
private:
	int activeTime;
	RECT background;

	bool shipMove_up;
	bool shipMove_down;
	int shipHead_pos;
	int shipRailing_pos;

	int m_count;

	int cameraX;
	int cameraY;

	bool town_active;
public:
	intro();
	~intro();

	HRESULT init();
	void release();
	void  update();
	void render();

	bool getTown_active() { return town_active; }
};

