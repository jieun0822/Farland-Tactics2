#pragma once
#include "gameNode.h"
#include "progressBar.h"


enum class Attribute
{
	FIRE, WATER, WIND
};

struct Ability
{
	string name;
	string job;
	int level;
	string state;

	float HP;
	RECT hpFrontBar;
	RECT hpBackBar;

	float MP;
	RECT mpFrontBar;
	RECT mpBackBar;

	progressBar* _hpBar;
	progressBar* _mpBar;

	int offensePower; //���ݷ�
	int plus_offensePower;

	int defense; //����
	int plus_defense;

	int intellect; //����
	int plus_intellect;

	int magicDrag; //���׷�
	int plus_magicDrag;

	int agility; //��ø��
	int plus_agility;

	float EXP;
	Attribute attributeIcon;
	int attribute;

	RECT listRC;//���� ����Ʈ �ڽ�
	image* iconImg;
};

enum class EQUIP_KIND
{
	WEAPON,
	ARMOR,
	EQUIPMENT1,
	EQUIPMENT2
};

struct tagEquipInfo
{
	string name;
	string detail;
	EQUIP_KIND kind;
	int money;
	int num;
	image* iconImg;

	int offensePower;	//���ݷ�
	int defense;		//����
	int intellect;		//����
	int magicDrag;		//���׷�
	int agility;		//��ø��
};

struct Magic
{
	string name;
	string detail;
	Attribute attribute;
};

struct Tool
{
	string name;
	string detail;
	int num;
	int money;
};

//�̰Ը´°ǰ���
struct tagItemInfo
{
	string	name;
	string	detail;
	int		num;
	int		money;
	image*	iconImg;
};

struct Unit
{
	//�ɷ�â.
	Ability _ability;

	//���â.
	vector<tagEquipInfo*> _vBelongings;
	vector<tagEquipInfo*>::iterator _viBelongings;

	tagEquipInfo* _weapon;
	tagEquipInfo* _armor;
	tagEquipInfo* _equip1;
	tagEquipInfo* _equip2;

	//����â.
	vector<Magic*> _vMagics;
	vector<Magic*>::iterator _viMagics;

	//����â.
	//vector<Tool*> _vTools;
	//vector<Tool*>::iterator _viTools;
	vector<tagItemInfo*> _vTools;
	vector<tagItemInfo*>::iterator _viTools;

};


//������â
struct UnitWindow
{
	RECT outLine;
	RECT windowName;

	//����
	RECT characterList;

	//��ư
	RECT abilityButton;
	RECT equipButton;
	RECT magicButton;
	RECT toolButton;
	RECT closeButton;

	bool isAttButton;
	bool isEquipButton;
	bool isMagicButton;
	bool isToolButton;
	bool isCloseButton;

	//�ɷ�â(ability window)
	RECT characterImg;
	RECT characterInfo;
	RECT characterDetail;
	RECT characterEXP;
	RECT characterAttribute;

	//���â
	RECT weaponDisplay;
	RECT armorDisplay;
	RECT equipment1Display;
	RECT equipment2Display;
	RECT belongingsDisplay;
	RECT detailDisplay;
	/////������� �ɼ�
	RECT disarmRC;
	bool isDisarm_weapon;
	bool isDisarm_armor;
	bool isDisarm_equip1;
	bool isDisarm_equip2;

	RECT belongingsList1;
	RECT belongingsList2;
	/////����ǰ �ɼ�
	RECT option;
	RECT option_equip;
	RECT option_sell;

	bool optionList1_left;
	bool optionList1_right;
	bool optionList2_left;
	bool optionList2_right;

	//����â
	RECT magicName;
	RECT magidList;
	RECT magicDetail;

	//����â
	RECT toolName;
	RECT toolList;//���
	RECT toolList1;
	RECT toolList2;
	RECT toolList3;
	RECT toolList4;
	RECT toolList5;
	RECT toolList6;
	bool toolList1_clicked;
	bool toolList2_clicked;
	bool toolList3_clicked;
	bool toolList4_clicked;
	bool toolList5_clicked;
	bool toolList6_clicked;

	//����â ��ũ��
	RECT scrollOutline;
	RECT scroll;
	//����ǰ ��ũ��
	RECT scrollOutline1;
	RECT scroll1;

	RECT toolDetail;
	RECT sellButton;
	bool isSellButton;

	RECT sellWindow;
	RECT sellWin_name;
	RECT sellWin_num;
	RECT sellWin_numUp;
	RECT sellWin_numDown;
	RECT sellWin_sellButton;
	RECT sellWin_exitButton;

	int sellItem_num;
	int plusMoney;

	int scrollPos;// ��ũ�� �����ϴ� ����.
	int scrollPos1;
};


//class itemStore;
class UnitList : public gameNode
{
private:
	//Unit* _unit;
	UnitWindow* _unitWindow;
	bool isOpen;

	int _money;
	bool isActive;
	
	//�����
	//itemStore* _itemStore;

public:
	Unit* _unit;

	UnitList();
	~UnitList();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setMoney(int money) { _money = money; }
	int getMoney() { return _money; }

	void setActive(bool isActive) { this->isActive = isActive; }
	bool getActive()const { return isActive; }

	void setOpen(bool isOpen) { this->isOpen = isOpen; }

	vector <tagItemInfo*> getVTools() const { return _unit[0]._vTools; }
	void setVTools(vector <tagItemInfo*> vTools) { _unit[0]._vTools = vTools; }
	vector <tagEquipInfo*> getVEquip() const { return _unit[0]._vBelongings; }

	float getHP() const { return _unit[0]._ability.HP; }
	void setHP(float hp) { _unit[0]._ability.HP = hp; }
	float getMP() const { return _unit[0]._ability.MP; }
	void setMP(float mp) { _unit[0]._ability.MP = mp; }
	float getEXP() const { return _unit[0]._ability.EXP; }
	void setEXP(float exp) { _unit[0]._ability.EXP = exp; }
	int getLevel() const { return _unit[0]._ability.level; }
	void setLevel(int level) { _unit[0]._ability.level = level; }

	//�׸��� �Լ�
	void shadowDraw(RECT rc);
	void lightDraw(RECT rc);
	void grayDraw(RECT rc);
	void lightGrayDraw(RECT rc);
	void clickedColor(RECT rc);

	void shadowDraw_reverse(RECT rc);
	void lightDraw_reverse(RECT rc);

};
