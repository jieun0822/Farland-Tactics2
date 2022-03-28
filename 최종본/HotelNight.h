#pragma once
#include "gameNode.h"

class HotelNight : public gameNode
{
private:
	image* _R;
	int m_time;

	//알 좌표 (걷기)
	float _x;
	float _y;

	//확인창
	RECT confirmWindow;
	RECT confirmWin_name;
	RECT confirmWin_yesButton;
	RECT confirmWin_noButton;

	bool isCheck_yes;
	bool isCheck_no;

	//프레임 움직이기
	int m_index;
	int m_count;

	bool town_active;
	bool townNight_active;

public:
	HotelNight();
	~HotelNight();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void shadowDraw(RECT rc);
	void lightDraw(RECT rc);
	void grayDraw(RECT rc);

	//마을.
	bool getTown_active() const { return town_active; }
	void setTown_active(bool active) { town_active = active; }
	bool getTownNight_active() const { return townNight_active; }
	void setTownNight_active(bool active) { townNight_active = active; }

	void initChoice() { isCheck_yes = false; isCheck_no = false; }
};

