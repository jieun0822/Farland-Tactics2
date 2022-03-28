#pragma once
#include "gameNode.h"


enum imageMove
{
	imageMove1,
	imageMove2,
	imageMove3,
	imageMove4,
	imageMove5,
	imageMove6,
	imageMove7,
	imageMove8,
	imageMove9
};


class Ending : public gameNode
{

private:

	int count_Ending;

public:

	Ending();
	~Ending();

	HRESULT init();
	void release();
	void update();
	void render();

	//이미지 이동 함수
	void alphaMove(string keyName, const char* fileName, int countWhen, imageMove imgMove);

};
