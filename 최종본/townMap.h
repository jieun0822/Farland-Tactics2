#pragma once
#include "gameNode.h"


struct MapRect
{
	RECT hotel;
	RECT ItemStore;
	RECT equipStore;
	RECT guild;
	RECT park;
	RECT field;
	RECT academy;
	RECT restaurant;
	RECT bossMap;		//È°-º¸½º¸ÊÃß°¡
};

class townMap : public gameNode
{
	enum class BGM
	{
		PLAY,
		TOWN,
		RESUME
	};

private:
	MapRect* _mapRect;
	BGM _bgm;

	bool town_active;
	bool itemStore_active;
	bool equipStore_active;
	bool guild_active;
	bool hotel_active;
	bool park_active;
	bool battleMap_active;
	bool academy_active;
	bool restaurant_active;

	bool bossMap_active; //È°-º¸½º¸Ê

	//bool isQuest1;
	//bool isQuest2;
	//bool isQuest3;

	RECT close;
	bool ending_active;
public:
	townMap();
	~townMap();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//È°-º¸½º¸Ê °Ù¼Â
	bool getBossMap_active() { return bossMap_active; }
	void setBossMap_active(bool active) { bossMap_active = active; }

	bool getTown_active() { return town_active; }
	bool getItemStore_active() { return itemStore_active; }
	bool getEquipStore_active() { return equipStore_active; }
	bool getGuild_active() { return guild_active; }
	bool getHotel_active() { return hotel_active; }
	bool getPark_active() { return park_active; }
	bool getBattleMap_active() { return battleMap_active; }
	bool getAcademy_active() { return academy_active; }
	bool getRestaurant_active() { return restaurant_active; }
	bool getEnding_active() { return ending_active; }

	void setTown_active(bool active) { town_active = active; }
	void setItemStore_active(bool active) { itemStore_active = active; }
	void setEquipStore_active(bool active) { equipStore_active = active; }
	void setGuild_active(bool active) { guild_active = active; }
	void setHotel_active(bool active) { hotel_active = active; }
	void setPark_active(bool active) { park_active = active; }
	void setBattleMap_active(bool active) { battleMap_active = active; }
	void setAcademy_active(bool active) { academy_active = active; }
	void setRestaurant_active(bool active) { restaurant_active = active; }

	//bool getIsQuest1() { return isQuest1; }
	//void setIsQuest1(bool active) { isQuest1 = active; }
	//void setIsQuest2(bool active) { isQuest2 = active; }
	//void setIsQuest3(bool active) { isQuest3 = active; }
};