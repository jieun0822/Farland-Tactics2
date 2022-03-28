#pragma once
#include "gameNode.h"
#include "townMap.h"
#include "itemStore.h"
#include "equipStore.h"
#include "Guild.h"
#include "park.h"
#include "SubIsoMap.h"
#include "IsoMap.h"
#include "townMap.h"
#include "hotel.h"
#include "townMapNight.h"
#include "HotelNight.h"
#include "battleMap.h"
#include "restaurant.h"
#include "academy.h"
#include "BossMap.h"

#include "Title.h"
#include "intro.h"
#include "Ending.h"

#include "loadiingTest.h"
#define SUBWINOPEN 1

class mainGame : public gameNode
{
private:
	bool isNight;

	townMap* _townMap;
	itemStore* _itemStore;
	equipStore* _equipStore;
	Guild* _guild;
	Hotel* _hotel;
	townMapNight* _townNight;
	HotelNight* _hotelNight;
	park* _park;
	battleMap* _battleMap;
	restaurant* _restaurant;
	academy* _academy;
	BossMap* _bossMap;

	Title* _title;
	intro* _intro;
	Ending* _ending;

	UnitList* _unitList;
	loadiingTest* _loading;

	//지은★★★★★★★★★★★★★★★★
	bool quest1_firstComplete;
	bool quest1_complete;
	//활
	bool isFirst;	//길드방문정보

	bool town_active;
	bool itemStore_active;
	bool equipStore_active;
	bool unitList_active;
	bool guild_active;
	bool hotel_active;
	bool townNight_active;
	bool hotelNight_active;
	bool park_active;
	bool battleMap_active;
	bool restaurant_active;
	bool academy_active;
	bool loading_active;
	bool bossMap_active;
	bool title_active;
	bool intro_active;
	bool ending_active;

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);

	//void setTown_active(bool active) { town_active = active; }
	//void setItemStore_active(bool active) { itemStore_active = active; }
	void setUnitList_active(bool active) { unitList_active = active; }
	
};

