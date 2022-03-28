#pragma once
#include"gameNode.h"
#include"progressBar.h"
#include"battleMap_monster.h"
#define MAX_MONSTER 5
/*
enum class MONSTER_STATE
{
	IDLE,
	MOVE,
	ATTACK,
	DAMAGE,
	DIE
};
*/
/*
struct monsterInfo
{
	int arrIndex;

	string name;
	int x;
	int y;
	RECT rc;

	int hp;
	image* img;
	bool isLeft;
	bool isExist;
	bool isCollide;
	MONSTER_STATE currentState;

	progressBar* bar;

	int count;
	int index;

	//상태를 변경해주는 변수.
	int stateCount;
	float startTime;
	float endTime;
};
*/

struct bossSkill
{
	int x;
	int y;
	image* img;
	bool isExist;
	RECT rc;

	int count;
	int index;
};

class bossMap_monster : public gameNode
{
private:
	//int _camera;
	int playerX;
	int playerY;
	//bool playerLeft;

	vector<monsterInfo*> _vMonster;
	vector<monsterInfo*>::iterator _viMonster;

	vector<monsterInfo*> _vDevil;
	vector<monsterInfo*>::iterator _viDevil;

	//보스 스킬.
	vector<bossSkill*> _vMeteor;
	vector<bossSkill*>::iterator _viMeteor;

	bossSkill* lightning;

	vector<bossSkill*> _vFlame;
	vector<bossSkill*>::iterator _viFlame;

	bool isDebug;

	float startTime;
	float endTime;

	float startTime_devil;
	float endTime_devil;

	int stayDamaged;
	//=======================
	// 	   애기추가쓰
	bool isKid;
	image* _kid;
	image* _click;
	RECT kidRC;
	int kidX, kidY;
	int m_index;
	int m_count;
	//=======================

public:
	bossMap_monster();
	~bossMap_monster();

	HRESULT init();
	void release();
	void update();
	void render();

	vector<monsterInfo*> getVMonster() const { return _vMonster; }
	void setVMonster(vector<monsterInfo*> vMonster) { _vMonster = vMonster; }

	vector<bossSkill*> getVMeteor() const { return _vMeteor; }
	void setVMeteor(vector<bossSkill*> vMeteor) { _vMeteor = vMeteor; }

	bossSkill* getLightning() const { return lightning; }

	vector<bossSkill*> getVFlame() const { return _vFlame; }
	void setVFlame(vector<bossSkill*> vFlame) { _vFlame = vFlame; }

	vector<monsterInfo*> getVDevil() const { return _vDevil; }
	void setVDevil(vector<monsterInfo*> vDevil) { _vDevil = vDevil; }

	//vector<meteor*> getVMeteor()

	//void setCamera(int camera) { _camera = camera; }

	void setPlayerX(int x) { playerX = x; }
	void setPlayerY(int y) { playerY = y; }


	//=======================
	// 	   애기추가쓰
	void setIsKid(bool active) { isKid = active; }
	void setKidPosX(int x) { kidX = x; }
	void setKidPosY(int y) { kidY = y; }
	RECT getKidRC() const { return kidRC; }
	bool getIsKid() const { return isKid; }

	//=======================
};

