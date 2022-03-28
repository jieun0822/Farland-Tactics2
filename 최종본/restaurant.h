#pragma once
#include"gameNode.h"
class restaurant : public gameNode
{
private:
	int activeTime;

	bool town_active;

	//fade º¯¼ö.
	int alphaValue;
	int changeAlpha;
public:
	restaurant();
	~restaurant();

	HRESULT init();
	void release();
	void update();
	void render();

	bool getTown_active() const { return town_active; }
	void setTown_active(bool active) { town_active = active; }
	void initialization() { activeTime = 0; alphaValue = 0; changeAlpha = 0; }
};

