#pragma once
#include"gameNode.h"
#include"loading.h"
class loadiingTest : public gameNode
{
private:
	loading* _loading;
	bool isDone;
public:
	loadiingTest();
	~loadiingTest();

	HRESULT init();
	void release();
	void update();
	void render();

	void totalLoading();

	bool getIsDone() const { return isDone; }
	void setIsDone(bool isDone) { this->isDone = isDone; }

	void initialization();
};

