#pragma once
#include "gameNode.h"
#include "progressBar.h"
#include "battleMap_player.h"
#define PLAYERSPEED 5
#define CAMERASPEED 5
/*
enum class PLAYER_STATE
{
	IDLE,
	MOVE,
	ATTACK1,
	ATTACK2,
	SKILL,
	DAMAGE,
	DIE
};
*/
class bossMap_player : public gameNode
{
private:
	int x;
	int y;
	int level;
	float hp;
	float mp;
	float exp;

	PLAYER_STATE _currentState;
	PLAYER_STATE _prevState;

	image* _img;
	image* _state;
	RECT rc;

	progressBar* _hpBar;
	progressBar* _mpBar;
	progressBar* _expBar;

	bool isLeft;
	bool isCollide;
	bool isPlayerDie;

	bool isDebug;

	int m_count;
	int m_index;

	int attack2_left;
	int attack2_right;
	int cycle;

	//int _camera;

	//단축키 display.
	RECT key_attack1;
	RECT key_attack2;
	RECT key_skill;

	// 	 스킬수정
	image* _skill;
	animation* skillAni;
	RECT	skillRC;

	int activeTime;
	int s_index;
	int s_count;
	bool isActive;
	float skillX;
	float skillY;
public:
	bossMap_player();
	~bossMap_player();

	HRESULT init();
	void release();
	void update();
	void render();

	image* getImg() { return _img; }

	//RECT playerHP_Front;
	//RECT playerHP_Back;

	//RECT playerMP_Front;
	//RECT playerMP_Back;

	void setPlayerX(float x) { this->x = x; }
	int getPlayerX() { return x; }
	void setPlayerY(float y) { this->y = y; }
	int getPlayerY() { return y; }

	PLAYER_STATE getCurrentState() const { return _currentState; }
	void setCurrentState(PLAYER_STATE state) { _currentState = state; }
	PLAYER_STATE getPrevState() const { return _prevState; }

	float getHP() const { return hp; }
	void setHP(float hp) { this->hp = hp; }
	float getMP() const { return mp; }
	void setMP(float mp) { this->mp = mp; }
	float getEXP() const { return exp; }
	void setEXP(float exp) { this->exp = exp; }
	int getLevel() const { return level; }
	void setLevel(int level) { this->level = level; }

	//void setCamera(int camera) { _camera = camera; }
	//int getCamera() const { return _camera; }
	void setCollide(bool isCollide) { this->isCollide = isCollide; }

	RECT getRect() const { return rc; }

	// 	 스킬수정
	RECT getSkillRect() const { return skillRC; }
};

