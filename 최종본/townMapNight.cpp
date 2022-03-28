#include "framework.h"
#include "townMapNight.h"

townMapNight::townMapNight()
{
}

townMapNight::~townMapNight()
{
}

HRESULT townMapNight::init()
{
	SOUND->addSound("bgm02", "sound/bgm02.mp3", true, false);

	IMAGE->addImage("∏∂¿ª∏ _π„", "images/town10.bmp", WINSIZEX - 5, WINSIZEY - 20, false, RGB(0, 0, 0));
	IMAGE->addImage("¿Ã¡§«•_π„", "images/town08.bmp", WINSIZEX - 5, WINSIZEY - 20, true, RGB(255, 255, 255));

	//hotel = RectMake(730, 280, 50, 30);

	//¡ˆ¿∫°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄
	guild = RectMake(480, 283, 80, 30);
	guild_active = false;

	return S_OK;
}

void townMapNight::release()
{
}

void townMapNight::update()
{
	//¿”Ω√ øÏ≈¨∏Ø
	if (InputManager->isOnceKeyUp(VK_RBUTTON))
	{
		//SCENE->changeScene("townMap");
	}

	if (InputManager->isOnceKeyUp(VK_LBUTTON))
	{
		//if (PtInRect(&hotel, m_ptMouse))
		//{
		//	//SCENE->changeScene("hotelNight");
		//	hotel_active = true;
		//}
		//¡ˆ¿∫°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄°⁄
		if (PtInRect(&guild, m_ptMouse))
		{
			//SCENE->changeScene("hotelNight");
			guild_active = true;
		}
	}
}

void townMapNight::render()
{
	IMAGE->render("∏∂¿ª∏ _π„", getMemDC());
	IMAGE->render("¿Ã¡§«•_π„", getMemDC());
	//Rectangle(getMemDC(), hotel.left, hotel.top, hotel.right, hotel.bottom);
	//Rectangle(getMemDC(), guild.left, guild.top, guild.right, guild.bottom);

}
