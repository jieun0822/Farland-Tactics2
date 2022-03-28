#include "framework.h"
#include "Ending.h"

Ending::Ending()
{
}

Ending::~Ending()
{
}


HRESULT Ending::init()
{
	count_Ending = 0;

	SOUND->addSound("bgm24", "sound/bgm24.mp3", true, false);

	IMAGE->addImage("black", "images/ending/black.bmp", WINSIZEX, WINSIZEY);
	IMAGE->addImage("black0", "images/ending/black0.bmp", WINSIZEX, WINSIZEY);

	IMAGE->addImage("over1", "images/ending/over1.bmp", WINSIZEX, WINSIZEY);
	IMAGE->addImage("over2", "images/ending/over2.bmp", WINSIZEX, WINSIZEY);

	IMAGE->addImage("ved00a", "images/ending/ved00a.bmp", 592 * 1.5, 48 * 1.5);
	IMAGE->addImage("ved00b", "images/ending/ved00b.bmp", 448 * 1.5, 96 * 1.5);
	IMAGE->addImage("ved00c", "images/ending/ved00c.bmp", 400 * 1.5, 64 * 1.5);

	IMAGE->addImage("ved01a", "images/ending/ved01a.bmp", 440 * 1.5, 360 * 1.5);
	IMAGE->addImage("ved01b", "images/ending/ved01b.bmp", 440 * 1.5, 360 * 1.5);
	IMAGE->addImage("ved01c", "images/ending/ved01c.bmp", 440 * 1.5, 360 * 1.5);
	IMAGE->addImage("ved01d", "images/ending/ved01d.bmp", 440 * 1.5, 360 * 1.5);
	IMAGE->addImage("ved01e", "images/ending/ved01e.bmp", 440 * 1.5, 360 * 1.5);
	IMAGE->addImage("ved01f", "images/ending/ved01f.bmp", 440 * 1.5, 360 * 1.5);
	IMAGE->addImage("ved01g", "images/ending/ved01g.bmp", 440 * 1.5, 360 * 1.5);
	IMAGE->addImage("ved01h", "images/ending/ved01h.bmp", 640 * 1.7, 360 * 1.7);


	IMAGE->addImage("vis03c", "images/ending/vis03c.bmp", WINSIZEX, WINSIZEY);
	IMAGE->addImage("vis10a", "images/ending/vis10a.bmp", WINSIZEX, WINSIZEY);
	IMAGE->addImage("vis15a", "images/ending/vis15a.bmp", WINSIZEX, WINSIZEY);
	IMAGE->addImage("vis15b", "images/ending/vis15b.bmp", WINSIZEX, WINSIZEY);
	IMAGE->addImage("vis15c", "images/ending/vis15c.bmp", WINSIZEX, WINSIZEY);
	IMAGE->addImage("vis17a", "images/ending/vis17a.bmp", WINSIZEX, WINSIZEY);

	IMAGE->addImage("title", "images/ending/title.bmp", WINSIZEX, WINSIZEY);
	IMAGE->addImage("white", "images/ending/white.bmp", WINSIZEX, WINSIZEY);

	return S_OK;
}


void Ending::release()
{
}


void Ending::update()
{
	count_Ending++;
}


void Ending::render()
{
	if (!SOUND->isPlaySound("마을"))
	{
		SOUND->stop("마을");
	}


	if (count_Ending < 990)
	{
		if (!SOUND->isPlaySound("bgm24"))
		{
			SOUND->play("bgm24");
		}
	}


	IMAGE->findImage("black0")->render(getMemDC());


	if (0 < count_Ending && count_Ending <= 500)
	{
		static int alphaValue1 = 255;
		static int alphaValue2 = 0;

		static int changeAlpha = 0;

		if (changeAlpha == 0)
		{

			alphaValue1 -= 2;
			alphaValue2 += 2;

			if (alphaValue1 <= 0)
			{
				alphaValue1 = 0;
				changeAlpha = 1;

			}

			IMAGE->findImage("ved00a")->alphaRender(getMemDC(), 50, 300, alphaValue1);
			IMAGE->findImage("black")->alphaRender(getMemDC(), WINSIZEX, WINSIZEY, alphaValue2);

		}


		if (changeAlpha == 1)
		{
			alphaValue1 += 1.5;
			alphaValue2 -= 1.5;
			if (alphaValue1 >= 255)
			{

				changeAlpha = 2;
				alphaValue1 = 255;
			}

			IMAGE->findImage("ved00b")->alphaRender(getMemDC(), 170, 270, alphaValue1);
			IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue1);
		}

		if (changeAlpha == 2)
		{
			alphaValue1 -= 1;
			alphaValue2 += 1;
			if (alphaValue1 <= 0)
			{
				alphaValue1 = 0;
			}

			IMAGE->findImage("ved00c")->alphaRender(getMemDC(), 230, 270, alphaValue1);
			IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue2);
		}
	}

	alphaMove("ved01a", "images/ending/ved01a.bmp", 0, imageMove3);
	alphaMove("ved01b", "images/ending/ved01b.bmp", 300, imageMove4);
	alphaMove("ved01c", "images/ending/ved01c.bmp", 600, imageMove9);
	alphaMove("ved01d", "images/ending/ved01d.bmp", 900, imageMove8);
	alphaMove("ved01e", "images/ending/ved01e.bmp", 1200, imageMove1);
	alphaMove("ved01f", "images/ending/ved01f.bmp", 1500, imageMove6);
	alphaMove("ved01g", "images/ending/ved01g.bmp", 1800, imageMove7);
	alphaMove("ved01h", "images/ending/ved01h.bmp", 2100, imageMove2);

	if (700 + 0 < count_Ending && count_Ending <= 700 + 4) IMAGE->findImage("white")->render(getMemDC());
	if (700 + 4 < count_Ending && count_Ending <= 700 + 16) IMAGE->findImage("vis03c")->render(getMemDC());
	if (700 + 16 + 10 < count_Ending && count_Ending <= 700 + 20 + 10) IMAGE->findImage("white")->render(getMemDC());
	if (700 + 20 + 10 < count_Ending && count_Ending <= 700 + 36 + 10) IMAGE->findImage("vis10a")->render(getMemDC());
	if (700 + 36 + 20 < count_Ending && count_Ending <= 700 + 40 + 20) IMAGE->findImage("white")->render(getMemDC());
	if (700 + 40 + 20 < count_Ending && count_Ending <= 700 + 56 + 20) IMAGE->findImage("vis15a")->render(getMemDC());
	if (700 + 56 + 30 < count_Ending && count_Ending <= 700 + 60 + 30) IMAGE->findImage("white")->render(getMemDC());
	if (700 + 60 + 30 < count_Ending && count_Ending <= 700 + 76 + 30)IMAGE->findImage("vis15b")->render(getMemDC());
	if (700 + 76 + 40 < count_Ending && count_Ending <= 700 + 80 + 40) IMAGE->findImage("white")->render(getMemDC());
	if (700 + 80 + 40 < count_Ending && count_Ending <= 700 + 96 + 40) IMAGE->findImage("vis15c")->render(getMemDC());
	if (700 + 96 + 50 < count_Ending && count_Ending <= 700 + 100 + 50) IMAGE->findImage("white")->render(getMemDC());
	if (700 + 100 + 50 < count_Ending && count_Ending <= 700 + 116 + 50) IMAGE->findImage("vis17a")->render(getMemDC());
	if (700 + 116 + 60 < count_Ending && count_Ending <= 700 + 120 + 60) IMAGE->findImage("white")->render(getMemDC());


	alphaMove("title", "images/ending/title.bmp", 3500, imageMove5);

	if (count_Ending > 990)
	{
		PostMessage(m_hWnd, WM_DESTROY, 0, 0);
		//IMAGE->findImage("title")->render(getMemDC());
	}
}



void Ending::alphaMove(string keyName, const char* fileName, int countWhen, imageMove imgMove)
{
	if (countWhen < count_Ending * 4 && count_Ending * 4 < countWhen + 500)
	{
		switch (imgMove)
		{

		case imageMove1:
			if (count_Ending * 4 <= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					-(count_Ending - countWhen / 4) + WINSIZEX - 600,
					(count_Ending - countWhen / 4) + 50,
					(count_Ending - countWhen / 4) * 4);
			else if (count_Ending * 4 >= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					-(count_Ending - countWhen / 4) + WINSIZEX - 600,
					(count_Ending - countWhen / 4) + 50,
					254 - ((count_Ending - countWhen / 4) * 4) % 254);
			break;

		case imageMove2:
			if (count_Ending * 4 <= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					0,
					-(count_Ending - countWhen / 4) + WINSIZEY - 550,
					(count_Ending - countWhen / 4) * 4);
			else if (count_Ending * 4 >= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					0,
					-(count_Ending - countWhen / 4) + WINSIZEY - 550,
					254 - ((count_Ending - countWhen / 4) * 4) % 254);
			break;

		case imageMove3:
			if (count_Ending * 4 <= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					(count_Ending - countWhen / 4) - 80,
					(count_Ending - countWhen / 4) - 80,
					(count_Ending - countWhen / 4) * 4);
			else if (count_Ending * 4 >= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					(count_Ending - countWhen / 4) - 80,
					(count_Ending - countWhen / 4) - 80,
					254 - ((count_Ending - countWhen / 4) * 4) % 254);
			break;

		case imageMove4:
			if (count_Ending * 4 <= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					-(count_Ending - countWhen / 4) + WINSIZEX - 500,
					40,
					(count_Ending - countWhen / 4) * 4);
			else if (count_Ending * 4 >= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					-(count_Ending - countWhen / 4) + WINSIZEX - 500,
					40,
					254 - ((count_Ending - countWhen / 4) * 4) % 254);
			break;


		case imageMove5:
			IMAGE->findImage(keyName)->alphaRender(getMemDC(),
				0,
				0, (count_Ending - countWhen / 4) * 2);
			break;

		case imageMove6:
			if (count_Ending * 4 <= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					(count_Ending - countWhen / 4) - 100,
					40,
					(count_Ending - countWhen / 4) * 4);
			else if (count_Ending * 4 >= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					(count_Ending - countWhen / 4) - 100,
					40,
					254 - ((count_Ending - countWhen / 4) * 4) % 254);
			break;

		case imageMove7:
			if (count_Ending * 4 <= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					-(count_Ending - countWhen / 4) + WINSIZEX - 570,
					-(count_Ending - countWhen / 4) + WINSIZEY - 400,
					(count_Ending - countWhen / 4) * 4);
			else if (count_Ending * 4 >= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					-(count_Ending - countWhen / 4) + WINSIZEX - 570,
					-(count_Ending - countWhen / 4) + WINSIZEY - 400,
					254 - ((count_Ending - countWhen / 4) * 4) % 254);
			break;

		case imageMove8:
			if (count_Ending * 4 <= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					120,
					(count_Ending - countWhen / 4) - 70,
					(count_Ending - countWhen / 4) * 4);
			else if (count_Ending * 4 >= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					120,
					(count_Ending - countWhen / 4) - 70,
					254 - ((count_Ending - countWhen / 4) * 4) % 254);
			break;

		case imageMove9:
			if (count_Ending * 4 <= countWhen + 254)

				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					(count_Ending - countWhen / 4) - 100,
					-(count_Ending - countWhen / 4) + WINSIZEY - 480,
					(count_Ending - countWhen / 4) * 4);
			else if (count_Ending * 4 >= countWhen + 254)
				IMAGE->findImage(keyName)->alphaRender(getMemDC(),
					(count_Ending - countWhen / 4) - 100,
					-(count_Ending - countWhen / 4) + WINSIZEY - 480,
					254 - ((count_Ending - countWhen / 4) * 4) % 254);
			break;
		}
	}
}