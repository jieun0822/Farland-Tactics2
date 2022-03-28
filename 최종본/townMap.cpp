#include "framework.h"
#include "townMap.h"
//연결완
//bgm 볼륨
#define VOLUME 0

townMap::townMap()
{
}

townMap::~townMap()
{
}

HRESULT townMap::init()
{
	SOUND->addSound("마을", "sound/bgm01_평소.mp3", true, true);

	IMAGE->addImage("마을맵", "images/town00.bmp", WINSIZEX - 5, WINSIZEY - 20, false, RGB(0, 0, 0));
	IMAGE->addImage("이정표", "images/town05.bmp", WINSIZEX - 5, WINSIZEY - 20, true, RGB(255, 255, 255));
	IMAGE->addImage("이정표_달동산", "images/town07.bmp", WINSIZEX - 5, WINSIZEY - 20, true, RGB(255, 255, 255));

	_mapRect = new MapRect;
	_mapRect->hotel = RectMake(747, 265, 73, 33);
	_mapRect->ItemStore = RectMake(480, 640, 88, 33);
	_mapRect->equipStore = RectMake(260, 345, 85, 30);
	_mapRect->field = RectMake(847, 82, 115, 33);
	_mapRect->guild = RectMake(478, 284, 82, 30);
	_mapRect->park = RectMake(127, 504, 224, 30);
	_mapRect->academy = RectMake(142, 131, 100, 30);
	_mapRect->restaurant = RectMake(778, 493, 83, 33);
	//활-보스맵추가
	_mapRect->bossMap = RectMake(522, 62, 90, 30);


	_bgm = BGM::TOWN;

	town_active = true;
	//itemStore_active = false;
	//guild_active = false;

	//isQuest1 = false;
	//isQuest2 = false;
	//isQuest3 = false;

	close = RectMake(600, 500, 100, 30);
	ending_active = false;

	return S_OK;
}

void townMap::release()
{
}

void townMap::update()
{
	//WNDCLASS WndClass;

	//if (PtInRect(&_mapRect->hotel, m_ptMouse))
	//{
	//	WndClass.hCursor = LoadCursor(NULL, IDC_CROSS);
	//}



	////BGM 설정
	if (_bgm == BGM::TOWN)
	{
		//마을bgm이 이미 재생중일때
		if (SOUND->isPlaySound("마을"))
		{
			_bgm = BGM::RESUME;
			SOUND->resume("마을");
		}

		//전투->마을로 씬 체인지
		else if (SOUND->isPlaySound("전투"))
		{
			SOUND->stop("전투");
		}

		//townMap으로 씬 체인지 시
		else
		{
			_bgm = BGM::PLAY;
			SOUND->stop("bgm00");
			SOUND->stop("전투");


		}
	}


	if (InputManager->isOnceKeyUp(VK_LBUTTON))
	{
		if (PtInRect(&_mapRect->guild, m_ptMouse))
		{
			//SCENE->changeScene("Guild");
			guild_active = true;
		}

		if (PtInRect(&_mapRect->ItemStore, m_ptMouse))
		{
			//town_active = false;
			itemStore_active = true;

			//SCENE->changeScene("itemStore");
		}

		if (PtInRect(&_mapRect->hotel, m_ptMouse))
		{
			hotel_active = true;
			//SCENE->changeScene("hotel");
		}

		if (PtInRect(&_mapRect->equipStore, m_ptMouse))
		{
			equipStore_active = true;
			//SCENE->changeScene("equipStore");
		}

		if (PtInRect(&_mapRect->park, m_ptMouse))
		{
			//SCENE->changeScene("battle");
			park_active = true;

			SOUND->stop("bgm00");
			SOUND->stop("마을");
			SOUND->play("공원");

			//SOUND->play("전투", VOLUME);
		}
		if (PtInRect(&_mapRect->field, m_ptMouse))
		{
			battleMap_active = true;

			SOUND->stop("bgm00");
			SOUND->stop("마을");
			SOUND->play("전투");
		}
		if (PtInRect(&_mapRect->academy, m_ptMouse))
		{
			academy_active = true;

			SOUND->stop("bgm00");
			SOUND->stop("마을");
			SOUND->play("학원");
		}
		if (PtInRect(&_mapRect->restaurant, m_ptMouse))
		{
			restaurant_active = true;

			SOUND->stop("bgm00");
			SOUND->stop("마을");
			SOUND->play("식당");
		}
		//활-보스맵
		if (PtInRect(&_mapRect->bossMap, m_ptMouse))
		{
			bossMap_active = true;

			//SOUND->stop("bgm00");
			//SOUND->stop("마을");
			//SOUND->play("식당");
		}

		//if (PtInRect(&close, m_ptMouse))
		//{
		//	ending_active = true;
		//
		//	SOUND->stop("bgm00");
		//	SOUND->stop("마을");
		//	SOUND->stop("전투");
		//}


	}

	//편의상 만든거
	//우클릭 시 마을맵-밤
	if (InputManager->isOnceKeyUp(VK_RBUTTON))
	{
		SCENE->changeScene("townMapNight");
	}
}

void townMap::render()
{
	if (!SOUND->isPlaySound("마을"))
	{
		SOUND->play("마을");
	}

	IMAGE->render("마을맵", getMemDC(), 0, 0);

	//Rectangle(getMemDC(), _mapRect->ItemStore.left, _mapRect->ItemStore.top, _mapRect->ItemStore.right, _mapRect->ItemStore.bottom);
	//Rectangle(getMemDC(), _mapRect->equipStore.left, _mapRect->equipStore.top, _mapRect->equipStore.right, _mapRect->equipStore.bottom);
	//Rectangle(getMemDC(), _mapRect->field.left, _mapRect->field.top, _mapRect->field.right, _mapRect->field.bottom);
	//Rectangle(getMemDC(), _mapRect->guild.left, _mapRect->guild.top, _mapRect->guild.right, _mapRect->guild.bottom);
	//Rectangle(getMemDC(), _mapRect->park.left, _mapRect->park.top, _mapRect->park.right, _mapRect->park.bottom);
	//Rectangle(getMemDC(), _mapRect->hotel.left, _mapRect->hotel.top, _mapRect->hotel.right, _mapRect->hotel.bottom);
	//Rectangle(getMemDC(), _mapRect->academy.left, _mapRect->academy.top, _mapRect->academy.right, _mapRect->academy.bottom);
	//Rectangle(getMemDC(), _mapRect->restaurant.left, _mapRect->restaurant.top, _mapRect->restaurant.right, _mapRect->restaurant.bottom);
	//Rectangle(getMemDC(), _mapRect->bossMap.left, _mapRect->bossMap.top, _mapRect->bossMap.right, _mapRect->bossMap.bottom);		//활-달동산추가

	//Rectangle(getMemDC(), close.left, close.top, close.right, close.bottom);
	//TextOut(getMemDC(), close.left + 5, close.top + 3, "끝내기", lstrlen("끝내기"));
	IMAGE->render("이정표", getMemDC(), 0, 0);

	//	TCHAR str[100];
	//	wsprintf(str, "x : %d, y : %d", m_ptMouse.x, m_ptMouse.y);
	//	TextOut(getMemDC(), 200, 200, str, lstrlen(str));
}
