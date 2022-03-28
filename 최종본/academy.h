#pragma once
#include"gameNode.h"
class academy : public gameNode
{
private:
	int activeTime;

	bool town_active;
public:
	academy();
	~academy();

	HRESULT init();
	void release();
	void update();
	void render();

	bool getTown_active() const { return town_active; }
	void setTown_active(bool active) { town_active = active; }
	void initialization() { activeTime = 0; }
};

