#pragma once
#include"gameNode.h"
#include"IsoTile.h"
#include"battleMap_player.h"
#include"battleMap_monster.h"
#include"UnitList.h"
#include"Guild.h"
#define PLAYERSPEED 5
#define CAMERASPEED 5
class battleMap : public gameNode
{
private:
	battleMap_player* _player;
	int m_index;
	int m_count;
	//int m_camera;
	bool isLeft;

	RECT mini_rc;

	PLAYER_STATE _currentState;
	PLAYER_STATE _previousState;

	bool isDebug;

	//몬스터.
	battleMap_monster* _monster;
	vector<monsterInfo*> _vMonster;
	vector<monsterInfo*>::iterator _viMonster;

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
	RECT townButton;
	bool town_active;

	//꿔바로우
	//밤마을 추가
	int activeTime;					/////////////////////
	bool townNight_active;			//밤마을로 도록

	bool quest1_complete;
	
	//활-길드 정보 불러오기
	Guild* _guild;
	bool isFirst;

public:
	battleMap();
	~battleMap();

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
	bool getTown_active()const { return town_active; }
	void setTown_active(bool active) { town_active = active; }

	//꿔바로우
	//밤마을 추가
	bool getTownNight_active() const { return townNight_active; }
	void setTownNight_active(bool active) { townNight_active = active; }

	//지은★★★★★★★★★★★★★★★★★★★★★★
	bool getQuest1_complete() const { return quest1_complete; }
	void setIsFirst(bool active) { isFirst = active; }		//활-isFirst조정


	void initialization();

	//그리기.
	void lightGrayDraw(RECT rc);
	void shadowDraw(RECT rc);
	void lightDraw(RECT rc);
};