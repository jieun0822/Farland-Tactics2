#pragma once
#include "gameNode.h"
#include "townMap.h"

class Guild : public gameNode
{
private:
	int activeTime;
	int _activeTime; //check no 눌렀을 때.
	//확인창.
	RECT confirmWindow;
	RECT confirmWin_name;
	RECT confirmWin_yesButton;
	RECT confirmWin_noButton;

	bool isCheck;
	bool isCheck_yes;
	bool isCheck_no;

	bool town_active;
	townMap* _townMap;

	//지은★★★★★★★★★★★★★★★★
	bool isFirst;
	bool quest1_complete;

	//활
	bool townNight_active;		//마을(밤)으로
	bool isSecond;				//두번째 퀘스트

public:
	Guild();
	~Guild();

	HRESULT init();
	void release();
	void update();
	void render();

	//그리기 함수.
	void shadowDraw(RECT rc);
	void lightDraw(RECT rc);
	void grayDraw(RECT rc);

	void initActiveTime() { activeTime = 0; _activeTime = 0; }
	void initChoice() { isCheck_yes = false, isCheck_no = false; }

	//마을.
	bool getTown_active() const { return town_active; }
	void setTown_active(bool active) { town_active = active; }

	//활-마을(밤)으로
	bool getTownNight_active() const { return townNight_active; }
	void setTownNight_active(bool active) { townNight_active = active; }
	

	//지은★★★★★★★★★★★★★★★★
	bool getQuest1_complete() const { return quest1_complete; }
	void setQuest1_complete(bool complete) { quest1_complete = complete; }
	bool getIsFirst() const { return isFirst; }

	//활-두번째퀘스트
	bool getIsSecond() const { return isSecond; }
	void setIsSecond(bool active) { isSecond = active; }

};

