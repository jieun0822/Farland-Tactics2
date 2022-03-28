#pragma once
#include "gameNode.h"
#include "townMap.h"

class Guild : public gameNode
{
private:
	int activeTime;
	int _activeTime; //check no ������ ��.
	//Ȯ��â.
	RECT confirmWindow;
	RECT confirmWin_name;
	RECT confirmWin_yesButton;
	RECT confirmWin_noButton;

	bool isCheck;
	bool isCheck_yes;
	bool isCheck_no;

	bool town_active;
	townMap* _townMap;

	//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	bool isFirst;
	bool quest1_complete;

	//Ȱ
	bool townNight_active;		//����(��)����
	bool isSecond;				//�ι�° ����Ʈ

public:
	Guild();
	~Guild();

	HRESULT init();
	void release();
	void update();
	void render();

	//�׸��� �Լ�.
	void shadowDraw(RECT rc);
	void lightDraw(RECT rc);
	void grayDraw(RECT rc);

	void initActiveTime() { activeTime = 0; _activeTime = 0; }
	void initChoice() { isCheck_yes = false, isCheck_no = false; }

	//����.
	bool getTown_active() const { return town_active; }
	void setTown_active(bool active) { town_active = active; }

	//Ȱ-����(��)����
	bool getTownNight_active() const { return townNight_active; }
	void setTownNight_active(bool active) { townNight_active = active; }
	

	//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	bool getQuest1_complete() const { return quest1_complete; }
	void setQuest1_complete(bool complete) { quest1_complete = complete; }
	bool getIsFirst() const { return isFirst; }

	//Ȱ-�ι�°����Ʈ
	bool getIsSecond() const { return isSecond; }
	void setIsSecond(bool active) { isSecond = active; }

};

