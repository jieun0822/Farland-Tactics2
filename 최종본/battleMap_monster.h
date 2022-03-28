#pragma once
#include"gameNode.h"
#include"progressBar.h"
#define MAX_MONSTER 5
enum class MONSTER_STATE
{
	IDLE,
	MOVE,
	ATTACK,
	DAMAGE,
	DIE
};

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

class battleMap_monster : public gameNode
{
private:
	//int _camera;
	int playerX;
	int playerY;

	vector<monsterInfo*> _vMonster;
	vector<monsterInfo*>::iterator _viMonster;

	bool isDebug;

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
	battleMap_monster();
	~battleMap_monster();

	HRESULT init();
	void release();
	void update();
	void render();

	vector<monsterInfo*> getVMonster() const { return _vMonster; }
	void setVMonster(vector<monsterInfo*> vMonster) { _vMonster = vMonster; }

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

