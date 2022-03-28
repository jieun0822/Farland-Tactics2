#pragma once
#include "gameNode.h"
#include "UnitList.h"
#define ITEMMAX 8


enum class CLICK
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

//struct tagItemInfo
//{
//	string	name;
//	string	detail;
//	int		num;
//	int		money;
//	image*	iconImg;
//};

struct ItemWindow
{
	RECT outLine;			//창 크기
	
	RECT windowName;		//창 제목
	RECT itemMenu;			//메뉴 이름
	RECT itemList;			//아이템 목록
	RECT descriptionBox;	//아이템 설명창

	RECT itemSelect[7];		//아이템 선택 박스
	string _select[7];

	RECT goldBox;			//소지금 표시
	RECT buyButton;			//구매 버튼
	RECT unitButton;		//유닛일람 버튼
	RECT closeButton;		//닫기 버튼

	bool isBuyButton;		//구매버튼 눌렸는지? (실험용)
	bool isClosed;

	RECT buyWindow;
	RECT buyWin_name;
	RECT buyWin_num;
	RECT buyWin_numUp;
	RECT buyWin_numDown;
	RECT buyWin_buyButton;
	RECT buyWin_exitButton;

	int buyItem_num;
	int plusMoney;
};


class itemStore : public gameNode
{

private:
	int money;

	//vector<tagItemInfo*> _vItem;
	//vector<tagItemInfo*>::iterator _viItem;

	bool town_active;
	bool itemStore_active;
	bool unitList_active;

	int activeTime;
	int _activeTime;
	bool isOpen;

	//Item _item[ITEMMAX];
	ItemWindow* _itemWindow;
	CLICK _click;

	//유닛일람
	//UnitList* _unitList;

public:
	
	itemStore();
	~itemStore();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void BuyItem();
	//tagItemInfo BuyItem();

	//실험용
	vector<tagItemInfo*> _vItem;
	vector<tagItemInfo*>::iterator _viItem;
	vector<tagItemInfo*> getVItem() const { return _vItem; }

	//산 순서대로 벡터에.
	vector<tagItemInfo*> _vTools;
	vector<tagItemInfo*>::iterator _viTools;
	vector<tagItemInfo*> getVTools() const { return _vTools; }
	void setVTools(vector<tagItemInfo*> vTools) { _vTools = vTools; }

	vector<tagItemInfo*> _vBuyItem;
	vector<tagItemInfo*>::iterator _viBuyItem;

	void setMoney(int money) { this->money = money; }
	int getMoney() const { return money; }

	bool getTown_active() const { return town_active; }
	bool getItemStore_active() const { return itemStore_active; }
	bool getUnitList_active() const { return unitList_active; }
	
	void setTown_active(bool active) { town_active = active; }
	void setItemStore_active(bool active) { itemStore_active = active; }
	void setUnitList_active(bool active) { unitList_active = active; }
	void setIsClosed(bool isClosed) { _itemWindow->isClosed = isClosed; }
	void initActiveTime() { activeTime = 0; _activeTime = 0; }

	//그리기.
	void lightGrayDraw(RECT rc);
	void shadowDraw(RECT rc);
	void lightDraw(RECT rc);

};

