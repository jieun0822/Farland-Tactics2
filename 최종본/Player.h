#pragma once
#include "gameNode.h"
class Player : public gameNode
{
private:
	image* _player;
	animation* _ani;
	string currentAni;

	int index_x;
	int index_y;
public:
	Player();
	~Player();

	HRESULT init();
	void release();
	void update();
	void render();

	//플레이어 위치.
	void setPlayerX(float x) { _player->setX(x); }
	int getPlayerX() { return _player->getX(); }
	void setPlayerY(float y) { _player->setY(y); }
	int getPlayerY() { return _player->getY(); }

	//플레이어 인덱스.
	int getIndexX() { return index_x; }
	void setIndexX(int x) { index_x = x; }
	int getIndexY() { return index_y; }
	void setIndexY(int y) { index_y = y; }

	image* getImg() { return _player; }
	void setImg(image* img) { _player = img; }

	void setAnimation(string str);
	string getCurrentAni() { return currentAni; }
};

