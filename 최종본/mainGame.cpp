#include"framework.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init(true);

	//SOUND->addSound("bgm05", "sound/bgm05.mp3", false, false);
	//SOUND->addSound("bgm05", "sound/bgm05.mp3", true, true);


	IMAGE->addImage("_1", "images/_5.bmp", 0, 0, 64, 48, true, RGB(255, 255, 255));
	IMAGE->addImage("_2", "images/_6.bmp", 0, 0, 64, 48, true, RGB(255, 255, 255));
	IMAGE->addImage("_3", "images/sign1.bmp", 0, 0, 48, 67, true, RGB(0, 0, 255));
	IMAGE->addImage("tree", "images/tree.bmp", 0, 0, 64, 131, true, RGB(0, 0, 255));
	IMAGE->addImage("grass1", "images/_grass1.bmp",	0, 0, 64, 56, true, RGB(255, 255, 255));
	IMAGE->addImage("tile_area", "images/tile_area.bmp", 0, 0, CELL_WIDTH - 4, CELL_HEIGHT - 4, true, RGB(255, 255, 255));

	//==============================================
	
	//SCENE->addScene("townMap", new townMap);
	//SCENE->addScene("itemStore", new itemStore);
	//SCENE->addScene("Guild", new Guild);
	//SCENE->addScene("battle", new battleMap);

	//SCENE->addScene("hotel", new Hotel);
	//SCENE->addScene("hotelNight", new HotelNight);
	//SCENE->addScene("townMapNight", new townMapNight);

	//=================================================

	_townMap = new townMap;
	_townMap->init();

	_itemStore = new itemStore;
	_itemStore->init();

	_equipStore = new equipStore;
	_equipStore->init();

	_guild = new Guild;
	_guild->init();

	_hotel = new Hotel;
	_hotel->init();

	_unitList = new UnitList;
	_unitList->init();

	_townNight = new townMapNight;
	_townNight->init();

	_hotelNight = new HotelNight;
	_hotelNight->init();

	_park = new park;
	_park->init();

	_battleMap = new battleMap;
	_battleMap->init();

	_restaurant = new restaurant;
	_restaurant->init();

	_academy = new academy;
	_academy->init();

	_bossMap = new BossMap;
	_bossMap->init();

	_loading = new loadiingTest;
	_loading->init();

	_title = new Title;
	_title->init();

	_intro = new intro;
	_intro->init();

	_ending = new Ending;
	_ending->init();

	isNight = false;

	town_active = false;
	itemStore_active = false;
	equipStore_active = false;
	unitList_active = false;
	guild_active = false;
	hotel_active = false;
	townNight_active = true;
	hotelNight_active = false;
	park_active = false;
	battleMap_active = false;
	restaurant_active = false;
	academy_active = false;
	bossMap_active = false;
	title_active = true;
	intro_active = false;

	loading_active = false;
	ending_active = false;
	//==============================================
	//ANIMATION->update();
	
	//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	quest1_complete = false;
	quest1_firstComplete = true;

	//Ȱ-���湮����
	isFirst = true;

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	_townMap->release();
	_itemStore->release();
	_equipStore->release();
	_guild->release();
	_hotel->release();
	_unitList->release();
	_townNight->release();
	_hotelNight->release();
	_park->release();
	_battleMap->release();
	_restaurant->release();
	_academy->release();

	//_title->release();
	//_intro->release();

	_loading->release();
}

void mainGame::update()
{

	gameNode::update();

	if (title_active)
	{
		//SOUND->play("����");
		//SOUND->play("bgm05");
		
		_title->update();
		if (_title->getIntro_active() == true)
		{
			_title->release();
			title_active = false;
			intro_active = true;
			//SOUND->stop("bgm05");
		}
	}
	//else SOUND->pause("bgm05");

	if(intro_active)
	{
		//SOUND->stop("bgm05");
		_intro->update();

		if (_intro->getTown_active() == true)
		{
			intro_active = false;
			town_active = true;
		}
	}

	if (ending_active)
	{
		_ending->update();
	}
	//if (InputManager->isOnceKeyDown(VK_RBUTTON))
	//{
	//	if(!(itemStore_active) && !(guild_active) && !(hotel_active)&& !(hotelNight_active)&& !(battleMap_active))
	//		isNight = !isNight;
	//}

	//������.
	if (town_active && !isNight)
	{
		_townMap->setTown_active(true);
		_townMap->update();

		//��ȭ����.
		if (_townMap->getItemStore_active() == true)
		{
			_townMap->setItemStore_active(false);//initialization
			_townMap->setTown_active(false);
			town_active = false;
			itemStore_active = true;
		}
		//������
		if (_townMap->getEquipStore_active() == true)
		{
			_townMap->setEquipStore_active(false);//initialization
			_townMap->setTown_active(false);
			town_active = false;
			equipStore_active = true;
		}
		//���.
		if (_townMap->getGuild_active() == true)
		{
			_townMap->setGuild_active(false);//initialization
			_townMap->setTown_active(false);
			town_active = false;
			townNight_active = false;	//Ȱ-����(��)����
			guild_active = true;
		}
		//ȣ��.
		if (_townMap->getHotel_active() == true)
		{
			_townMap->setHotel_active(false);//initialization
			_townMap->setTown_active(false);
			town_active = false;
			hotel_active = true;
		}
		//����.
		if (_townMap->getPark_active() == true)
		{
			_townMap->setPark_active(false);//initialization
			_townMap->setTown_active(false);
			town_active = false;
			park_active = true;
		}
		//������
		if (_townMap->getBattleMap_active() == true && !(_guild->getIsSecond()))
		{
			_townMap->setBattleMap_active(false);//initialization
			_townMap->setTown_active(false);
			town_active = false;
			//loading_active = true;
			townNight_active = false;		//�㸶���߰�
			battleMap_active = true;
		}
		//�Ĵ�
		if (_townMap->getRestaurant_active() == true)
		{
			_townMap->setRestaurant_active(false);//initialization
			_townMap->setTown_active(false);
			town_active = false;
			restaurant_active = true;
		}
		//��ī����
		if (_townMap->getAcademy_active() == true)
		{
			_townMap->setAcademy_active(false);//initialization
			_townMap->setTown_active(false);
			town_active = false;
			academy_active = true;
		}

		if (_townMap->getEnding_active() == true)
		{
			_townMap->setTown_active(false);
			town_active = false;
			ending_active = true;
		}
		//Ȱ-������
		if (_townMap->getBossMap_active() == true && _guild->getIsSecond())
		{
			_townMap->setTown_active(false);
			town_active = false;
			bossMap_active = true;
		}

	}

	//��ȭ����.
	if (itemStore_active)
	{
		_itemStore->setMoney(_unitList->getMoney());
		_itemStore->update();

		//�����϶� ����.
		setUnitList_active(_itemStore->getUnitList_active());
		if (unitList_active) { _unitList->setActive(true); }

		_unitList->setMoney(_itemStore->getMoney());
		_unitList->_unit[0]._vTools = _itemStore->getVTools();

		if (_itemStore->getTown_active() == true)
		{
			_itemStore->setTown_active(false);//initialization
			_itemStore->setIsClosed(false);//initialization
			_itemStore->initActiveTime();//initialization

			_itemStore->setItemStore_active(false);
			itemStore_active = false;
			town_active = true;
		}
	}

	//�������
	if (equipStore_active)
	{
		_equipStore->setMoney(_unitList->getMoney());
		_equipStore->update();

		setUnitList_active(_equipStore->getUnitList_active());
		if (unitList_active) { _unitList->setActive(true); }

		_unitList->setMoney(_equipStore->getMoney());
		_unitList->_unit[0]._vBelongings = _equipStore->getVBuyEquip();

		if (_equipStore->getTown_active() == true)
		{
			_equipStore->setTown_active(false);//initialization
			_equipStore->setIsClosed(false);//initialization
			_equipStore->initActiveTime();//initialization

			_equipStore->setEquipStore_active(false);
			equipStore_active = false;
			town_active = true;
		}
	}

	//���.
	if (guild_active)
	{
		//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
		_guild->setQuest1_complete(quest1_complete);
		_guild->update();
		//Ȱ-������� �ҷ�����
		isFirst = _guild->getIsFirst();

		if (_guild->getTown_active() == true)
		{
			_guild->setTown_active(false);//initialization
			_guild->initActiveTime();//initialization
			_guild->initChoice();//initialization

			guild_active = false;
			town_active = true;
		}
		//Ȱ-����(��)����
		else if (_guild->getTownNight_active() == true)
		{
			_guild->setTown_active(false);//initialization
			_guild->initActiveTime();//initialization
			_guild->initChoice();//initialization

			town_active = false;
			townNight_active = true;
			isNight = true;
		}
	}

	//ȣ��(��)
	if (hotel_active)
	{
		_hotel->update();

		if (_hotel->getTown_active() == true)
		{
			_hotel->setTown_active(false);//initialization
			_hotel->initActiveTime();//initialization
			
			hotel_active = false;
			town_active = true;
		}
	}
	
	//����.
	if (park_active)
	{
		_park->update();

		if (_park->getTown_active() == true)
		{
			_park->setTown_active(false);//initialization
			_park->initialization();//initialization

			park_active = false;
			town_active = true;
		}
	}

	//�ε�
	if (loading_active)
	{
		_loading->update();
	
		if (_loading->getIsDone() == true)
		{
			//_loading->initialization();
			//initialization.
			SAFE_DELETE(_loading);
			_loading = new loadiingTest;
			_loading->init();
	
			loading_active = false;
			battleMap_active = true;
		}
	}

	//������.
	if (battleMap_active)
	{
		_battleMap->setMoney(_unitList->getMoney());
		//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
		quest1_complete = _battleMap->getQuest1_complete();
		//Ȱ-isFirst ������Ʈ
		_battleMap->setIsFirst(isFirst);

		_battleMap->setHP(_unitList->getHP());
		_battleMap->setMP(_unitList->getMP());
		_battleMap->setEXP(_unitList->getEXP());
		_battleMap->setLevel(_unitList->getLevel());
		_battleMap->setVTools(_unitList->getVTools());
		
		_battleMap->update();

		_unitList->setHP(_battleMap->getHP());
		_unitList->setMP(_battleMap->getMP());
		_unitList->setEXP(_battleMap->getEXP());
		_unitList->setLevel(_battleMap->getLevel());
		_unitList->setVTools(_battleMap->getVTools());
		
		if (_battleMap->getTown_active() == true)
		{
			quest1_complete = _battleMap->getQuest1_complete();
			_battleMap->setTown_active(false);//initialization
			_battleMap->initialization();//initialization

			battleMap_active = false;
			town_active = true;
		}
		//�㸶���߰�
		else if (_battleMap->getTownNight_active() == true)
		{
			quest1_complete = _battleMap->getQuest1_complete();
			_battleMap->setTown_active(false);//initialization
			_battleMap->initialization();//initialization

			//Ȱ-����(��)���� ��ȯ�Ǵ� ���ÿ� ���� 1000�� ȹ��
			_unitList->setMoney(_unitList->getMoney() + 1000);
			//if (_battleMap->getQuest1_complete()) { _guild->setIsSecond(true); }	//ù��° ����Ʈ �Ϸ��ϸ� �ι�° ����Ʈ Ȱ��ȭ (������ ��ȯ�Ǵ� ���ÿ� true ó����)

			battleMap_active = false;
			town_active = false;
			townNight_active = true;
			isNight = true;
		}
	}

	//������.
	if (bossMap_active)
	{
		_bossMap->setMoney(_unitList->getMoney());

		_bossMap->setHP(_unitList->getHP());
		_bossMap->setMP(_unitList->getMP());
		_bossMap->setEXP(_unitList->getEXP());
		_bossMap->setLevel(_unitList->getLevel());
		_bossMap->setVTools(_unitList->getVTools());

		_bossMap->update();

		_unitList->setHP(_bossMap->getHP());
		_unitList->setMP(_bossMap->getMP());
		_unitList->setEXP(_bossMap->getEXP());
		_unitList->setLevel(_bossMap->getLevel());
		_unitList->setVTools(_bossMap->getVTools());

		if (_bossMap->getEnding_active() == true)
		{
			_bossMap->setEnding_active(false);//initialization
			_bossMap->initialization();//initialization

			bossMap_active = false;
			ending_active = true;
		}
	}

	//�Ĵ�.
	if (restaurant_active)
	{
		_restaurant->update();

		if (_restaurant->getTown_active() == true)
		{
			_restaurant->setTown_active(false);//initialization
			_restaurant->initialization();//initialization

			restaurant_active = false;
			town_active = true;
		}
	}

	//��ī����.
	if (academy_active)
	{
		_academy->update();

		if (_academy->getTown_active() == true)
		{
			_academy->setTown_active(false);//initialization
			_academy->initialization();//initialization

			academy_active = false;
			town_active = true;
		}
	}

	
	//�����϶�.
	if (unitList_active)
	{
		_unitList->update();
		_unitList->setOpen(true);
		setUnitList_active(_unitList->getActive());
		if (itemStore_active)
		{
			_itemStore->setUnitList_active(_unitList->getActive());
			_itemStore->setVTools(_unitList->getVTools());
		}
		if (equipStore_active)
		{
			_equipStore->setUnitList_active(_unitList->getActive());
			//_itemStore->setVTools(_unitList->getVTools());
			_equipStore->setVBuyEquip(_unitList->getVEquip());
		}
	}

	//���϶�.
	if (townNight_active && isNight)
	{
		_townNight->update();

		//ȣ��.
		if (_townNight->getHotel_active() == true)
		{
			_townNight->setHotel_active(false);//initialization
			townNight_active = false;
			hotelNight_active = true;
		}
		//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
		//���.
		if (_townNight->getGuild_active() == true)
		{
			_townNight->setGuild_active(false);//initialization
			townNight_active = false;
			isNight = false;
			//_townMap->setTown_active(true);
			//town_active = true;
			guild_active = true;
			quest1_firstComplete = false;
		}
	}

	//ȣ��.
	if (hotelNight_active)
	{
		_hotelNight->update();

		if (_hotelNight->getTown_active() == true)
		{
			_hotelNight->setTown_active(false);//initialization
			_hotelNight->initChoice();//initialization

			hotelNight_active = false;
			town_active = true;
			isNight = false;
		}

		if (_hotelNight->getTownNight_active() == true)
		{
			_hotelNight->setTownNight_active(false);//initialization
			_hotelNight->initChoice();//initialization

			hotelNight_active = false;
			townNight_active = true;
			isNight = true;
		}
	}
}

void mainGame::render(/*HDC hdc*/)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============================================
	

	if (title_active) _title->render();

	if (town_active && !isNight) _townMap->render();
	if (_guild->getIsSecond() && !(bossMap_active)) { IMAGE->render("����ǥ_�޵���", getMemDC(), 0, 0); }		//�̰��߰�
	if (itemStore_active) _itemStore->render();
	if (equipStore_active) _equipStore->render();
	if (unitList_active) _unitList->render();
	if (guild_active) _guild->render();
	if (hotel_active)_hotel->render();
	if (townNight_active && isNight) _townNight->render();
	if (hotelNight_active) _hotelNight->render();
	if (park_active) _park->render();
	if (battleMap_active) _battleMap->render();
	if (restaurant_active)_restaurant->render();
	if (academy_active)_academy->render();
	if (bossMap_active) _bossMap->render();
	if (loading_active)_loading->render();
	if (intro_active)_intro->render();
	if (ending_active)_ending->render();
	
	//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	//Ȱ-��Ʈũ��, ��ġ ����
	if (townNight_active && quest1_complete && quest1_firstComplete)
	{
		IMAGE->render("��ȭ_����", getMemDC(), 0, WINSIZEY - 300);
		IMAGE->alphaRender("��ȭ_����2", getMemDC(), 0, WINSIZEY - 301, 170);
		IMAGE->render("�̹���_���NPC", getMemDC(), 600, 470);

		HFONT font, oldfont;
		SetBkMode(getMemDC(), TRANSPARENT);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 50, WINSIZEY - 260, "������", lstrlen("������"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 48, WINSIZEY - 260, "������", lstrlen("������"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 50, WINSIZEY - 225, "�� ���̸� ������ ������ �� ����! ", lstrlen("�� ���̸� ������ ������ �� ����! "));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(20, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 50, WINSIZEY - 180, "������ ���� ���� ���ƿ´ٸ�, �մ��� ������ �ֵ��� �ϰڳ�. ��", lstrlen("������ ���� ���� ���ƿ´ٸ�, �մ��� ������ �ֵ��� �ϰڳ�. ��"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);


	}
	/*
	TCHAR str[20];
	wsprintf(str, "town : %d", town_active);
	TextOut(getMemDC(), 10, 10, str, lstrlen(str));

	wsprintf(str, "itemStore : %d", itemStore_active);
	TextOut(getMemDC(), 10, 30, str, lstrlen(str));
	*/
	//==============================================

	//������� ������ HDC�׸���.(�ǵ帮�� ����.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

