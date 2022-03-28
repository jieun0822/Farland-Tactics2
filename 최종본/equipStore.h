#pragma once
#include "gameNode.h"
#include "UnitList.h"

//===============================
// 오늘 목표
// 1.유닛일람 열기
// 2.아이템 구매 시 유닛일람(인벤토리)으로 들어가게 처리
//===============================

enum class CLICKE
{
	SELECT,
	SELECT1,
	SELECT2,
	SELECT3,
	SELECT4,
	SELECT5,
	SELECT6,
	SELECT7,
	NONE
};

struct EquipWindow
{
	RECT outLine;			//창 크기

	RECT windowName;		//창 제목
	RECT equipMenu;			//메뉴 이름
	RECT equipList;			//아이템 목록
	RECT descriptionBox;	//아이템 설명창

	RECT itemSelect[7];		//아이템 선택 박스
	string _select[7];

	RECT goldBox;			//소지금 표시
	RECT buyButton;			//구매 버튼
	RECT unitButton;		//유닛일람 버튼
	RECT closeButton;		//닫기 버튼

	bool isClosed;
	int buyEquip_num;

	//실험용
	RECT warning;

};

class equipStore : public gameNode
{
private:
	int activeTime;
	int _activeTime;
	int __activeTime;

	bool isOpen;
	int money;

	bool town_active;
	bool equipStore_active;
	bool unitList_active;


	EquipWindow* _equipWindow;
	CLICKE _click;

	//실험용
	UnitList* _unitListEx;


public:
	equipStore();
	~equipStore();

	vector<tagEquipInfo*> _vEquip;
	vector<tagEquipInfo*>::iterator _viEquip;

	vector<tagEquipInfo*> _vBuyEquip;
	vector<tagEquipInfo*>::iterator _viBuyEquip;

	vector<tagEquipInfo*> getVBuyEquip() const { return _vBuyEquip; }
	void setVBuyEquip(vector<tagEquipInfo*> vBuyEquip) { _vBuyEquip = vBuyEquip; }

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void BuyEquip();

	void setMoney(int money) { this->money = money; }
	int getMoney() const { return money; }

	bool getTown_active() const { return town_active; }
	bool getEquipStore_active() const { return equipStore_active; }
	bool getUnitList_active() const { return unitList_active; }

	void setTown_active(bool active) { town_active = active; }
	void setEquipStore_active(bool active) { equipStore_active = active; }
	void setUnitList_active(bool active) { unitList_active = active; }
	void setIsClosed(bool isClosed) { _equipWindow->isClosed = isClosed; }
	void initActiveTime() { activeTime = 0; _activeTime = 0; }


	//그리기.
	void lightGrayDraw(RECT rc);
	void shadowDraw(RECT rc);
	void lightDraw(RECT rc);

};

