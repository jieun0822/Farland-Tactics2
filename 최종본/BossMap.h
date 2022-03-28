#pragma once
#include"gameNode.h"
//#include"battleMap.h"
#include"bossMap_player.h"
#include"bossMap_monster.h"
#include"UnitList.h"
#define PLAYERSPEED 5
#define CAMERASPEED 5
class BossMap : public gameNode
{
private:
	bossMap_player* _player;
	int m_index;
	int m_count;
	//int m_camera;
	bool isLeft;

	RECT mini_rc;

	PLAYER_STATE _currentState;
	PLAYER_STATE _previousState;

	bool isDebug;

	//몬스터.
	bossMap_monster* _monster;

	vector<monsterInfo*> _vMonster;
	vector<monsterInfo*>::iterator _viMonster;

	vector<monsterInfo*> _vDevil;
	vector<monsterInfo*>::iterator _viDevil;


	vector<bossSkill*> _vMeteor;
	vector<bossSkill*>::iterator _viMeteor;
	bossSkill* lightning;
	vector<bossSkill*> _vFlame;
	vector<bossSkill*>::iterator _viFlame;
	//인벤토리.
	bool inventory_active;

	int money;

	vector<tagItemInfo*> _vTools;
	vector<tagItemInfo*>::iterator _viTools;

	RECT inventory_name;
	RECT inventory_close;
	RECT inventory_money;

	//단축키.
	RECT key_Q;
	RECT key_W;
	RECT key_E;

	tagItemInfo* Qkey_itemInfo;
	tagItemInfo* Wkey_itemInfo;
	tagItemInfo* Ekey_itemInfo;

	//마을.
	//RECT townButton;
	//bool town_active;

	bool ending_active;


public:
	BossMap();
	~BossMap();

	HRESULT init();
	void release();
	void update();
	void render();

	void changeKey();
	void setMoney(int money) { this->money = money; }

	vector<tagItemInfo*> getVTools() const { return _vTools; }
	void setVTools(vector<tagItemInfo*> vTools) { _vTools = vTools; }

	float getHP() const { return _player->getHP(); }
	void setHP(float hp) { _player->setHP(hp); }
	float getMP() const { return _player->getMP(); }
	void setMP(float mp) { _player->setMP(mp); }
	float getEXP() const { return _player->getEXP(); }
	void setEXP(float exp) { _player->setEXP(exp); }
	int getLevel() const { return _player->getLevel(); }
	void setLevel(int level) { _player->setLevel(level); }

	//마을.
	//bool getTown_active()const { return town_active; }
	//void setTown_active(bool active) { town_active = active; }
	bool getEnding_active()const { return ending_active; }
	void setEnding_active(bool active) { ending_active = active; }
	void initialization();

	//그리기.
	void lightGrayDraw(RECT rc);
	void shadowDraw(RECT rc);
	void lightDraw(RECT rc);
};