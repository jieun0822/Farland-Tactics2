#pragma once
#include "gameNode.h"

class Hotel : public gameNode
{
private:
	image* _owner;
	int activeTime;

	//프레임 움직이기
	int m_index;
	int m_count;

	bool town_active;

public:

	Hotel();
	~Hotel();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	bool getTown_active() const { return town_active; }
	void setTown_active(bool active) { town_active = active; }

	void initActiveTime() { activeTime = 0; }

};

