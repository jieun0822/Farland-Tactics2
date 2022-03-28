#pragma once
#include "gameNode.h"
#include "UnitList.h"

//===============================
// ���� ��ǥ
// 1.�����϶� ����
// 2.������ ���� �� �����϶�(�κ��丮)���� ���� ó��
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
	RECT outLine;			//â ũ��

	RECT windowName;		//â ����
	RECT equipMenu;			//�޴� �̸�
	RECT equipList;			//������ ���
	RECT descriptionBox;	//������ ����â

	RECT itemSelect[7];		//������ ���� �ڽ�
	string _select[7];

	RECT goldBox;			//������ ǥ��
	RECT buyButton;			//���� ��ư
	RECT unitButton;		//�����϶� ��ư
	RECT closeButton;		//�ݱ� ��ư

	bool isClosed;
	int buyEquip_num;

	//�����
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

	//�����
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


	//�׸���.
	void lightGrayDraw(RECT rc);
	void shadowDraw(RECT rc);
	void lightDraw(RECT rc);

};

