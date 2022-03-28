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

	int offensePower; //공격력
	int plus_offensePower;

	int defense; //방어력
	int plus_defense;

	int intellect; //지력
	int plus_intellect;

	int magicDrag; //마항력
	int plus_magicDrag;

	int agility; //민첩성
	int plus_agility;

	float EXP;
	Attribute attributeIcon;
	int attribute;

	RECT listRC;//왼쪽 리스트 박스
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

	int offensePower;	//공격력
	int defense;		//방어력
	int intellect;		//지력
	int magicDrag;		//마항력
	int agility;		//민첩성
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

//이게맞는건가요
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
	//능력창.
	Ability _ability;

	//장비창.
	vector<tagEquipInfo*> _vBelongings;
	vector<tagEquipInfo*>::iterator _viBelongings;

	tagEquipInfo* _weapon;
	tagEquipInfo* _armor;
	tagEquipInfo* _equip1;
	tagEquipInfo* _equip2;

	//마법창.
	vector<Magic*> _vMagics;
	vector<Magic*>::iterator _viMagics;

	//도구창.
	//vector<Tool*> _vTools;
	//vector<Tool*>::iterator _viTools;
	vector<tagItemInfo*> _vTools;
	vector<tagItemInfo*>::iterator _viTools;

};


//윈도우창
struct UnitWindow
{
	RECT outLine;
	RECT windowName;

	//왼쪽
	RECT characterList;

	//버튼
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

	//능력창(ability window)
	RECT characterImg;
	RECT characterInfo;
	RECT characterDetail;
	RECT characterEXP;
	RECT characterAttribute;

	//장비창
	RECT weaponDisplay;
	RECT armorDisplay;
	RECT equipment1Display;
	RECT equipment2Display;
	RECT belongingsDisplay;
	RECT detailDisplay;
	/////장비해제 옵션
	RECT disarmRC;
	bool isDisarm_weapon;
	bool isDisarm_armor;
	bool isDisarm_equip1;
	bool isDisarm_equip2;

	RECT belongingsList1;
	RECT belongingsList2;
	/////소지품 옵션
	RECT option;
	RECT option_equip;
	RECT option_sell;

	bool optionList1_left;
	bool optionList1_right;
	bool optionList2_left;
	bool optionList2_right;

	//마법창
	RECT magicName;
	RECT magidList;
	RECT magicDetail;

	//도구창
	RECT toolName;
	RECT toolList;//배경
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

	//도구창 스크롤
	RECT scrollOutline;
	RECT scroll;
	//소지품 스크롤
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

	int scrollPos;// 스크롤 조절하는 변수.
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
	
	//실험용
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

	//그리는 함수
	void shadowDraw(RECT rc);
	void lightDraw(RECT rc);
	void grayDraw(RECT rc);
	void lightGrayDraw(RECT rc);
	void clickedColor(RECT rc);

	void shadowDraw_reverse(RECT rc);
	void lightDraw_reverse(RECT rc);

};
