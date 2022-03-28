#pragma once
#include "gameNode.h"

class townMapNight : public gameNode
{
private:
	//Ȱ-ȣ�� ������
	//RECT hotel;

	//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	RECT guild;
	bool guild_active;
public:
	bool hotel_active;

	townMapNight();
	~townMapNight();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	bool getHotel_active() const { return hotel_active; }
	void setHotel_active(bool active) { hotel_active = active; }

	//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	bool getGuild_active() const { return guild_active; }
	void setGuild_active(bool active) { guild_active = active; }

};

