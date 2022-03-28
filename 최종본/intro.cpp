#include "framework.h"
#include "intro.h"

intro::intro()
{
}

intro::~intro()
{
}

HRESULT intro::init()
{
	SOUND->addSound("bgm00", "sound/bgm00_2.wav", true, false);

	//IMAGE->addImage("vop02a", "images/intro/vop02a.bmp", 640, 480, false, RGB(255, 0, 255));
	IMAGE->addImage("vop02a", "images/intro/vop02a.bmp", WINSIZEX, WINSIZEY - 150, false, RGB(255, 0, 255));

	//IMAGE->addImage("vop02b", "images/intro/vop02b.bmp", 640, 384, true, RGB(255, 0, 0));
	IMAGE->addImage("vop02b", "images/intro/vop02b.bmp", WINSIZEX, WINSIZEY - 70, true, RGB(255, 0, 0));

	//IMAGE->addImage("vop02c", "images/intro/vop02c.bmp", 640, 272, true, RGB(255, 0, 0));
	IMAGE->addImage("vop02c", "images/intro/vop02c.bmp", WINSIZEX, WINSIZEY - 300, true, RGB(255, 0, 0));

	//IMAGE->addImage("vop02d00", "images/intro/vop02d00.bmp", 144, 272, true, RGB(255, 0, 0));
	IMAGE->addImage("vop02d00", "images/intro/vop02d00.bmp", 250, 500, true, RGB(255, 0, 0));

	//IMAGE->addImage("vop02d01", "images/intro/vop02d01.bmp", 144, 272, true, RGB(255, 0, 0));
	//IMAGE->addImage("vop02d02", "images/intro/vop02d02.bmp", 144, 272, true, RGB(255, 0, 0));
	//IMAGE->addImage("vop02d03", "images/intro/vop02d03.bmp", 144, 272, true, RGB(255, 0, 0));
	//IMAGE->addImage("vop02d04", "images/intro/vop02d04.bmp", 144, 272, true, RGB(255, 0, 0));
	//IMAGE->addImage("vop02d05", "images/intro/vop02d05.bmp", 144, 272, true, RGB(255, 0, 0));
	//IMAGE->addImage("vop02d06", "images/intro/vop02d06.bmp", 144, 272, true, RGB(255, 0, 0));
	//IMAGE->addImage("vop02d07", "images/intro/vop02d07.bmp", 144, 272, true, RGB(255, 0, 0));

	IMAGE->addImage("vop02d01", "images/intro/vop02d01.bmp", 250, 500, true, RGB(255, 0, 0));
	IMAGE->addImage("vop02d02", "images/intro/vop02d02.bmp", 250, 500, true, RGB(255, 0, 0));
	IMAGE->addImage("vop02d03", "images/intro/vop02d03.bmp", 250, 500, true, RGB(255, 0, 0));
	IMAGE->addImage("vop02d04", "images/intro/vop02d04.bmp", 250, 500, true, RGB(255, 0, 0));
	IMAGE->addImage("vop02d05", "images/intro/vop02d05.bmp", 250, 500, true, RGB(255, 0, 0));
	IMAGE->addImage("vop02d06", "images/intro/vop02d06.bmp", 250, 500, true, RGB(255, 0, 0));
	IMAGE->addImage("vop02d07", "images/intro/vop02d07.bmp", 250, 500, true, RGB(255, 0, 0));

	IMAGE->addImage("black", "images/intro/black.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 0));

	//IMAGE->addImage("vop03a", "images/intro/vop03a.bmp", 640, 480, false, RGB(255, 0, 0));
	IMAGE->addImage("vop03a", "images/intro/vop03a.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 0));

	//IMAGE->addImage("vop03b00", "images/intro/vop03b00.bmp", 568, 368, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b00", "images/intro/vop03b00.bmp", WINSIZEX - 200, WINSIZEY - 180, true, RGB(255, 0, 255));

	/*
	IMAGE->addImage("vop03b01", "images/intro/vop03b01.bmp", 568, 368, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b02", "images/intro/vop03b02.bmp", 568, 368, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b03", "images/intro/vop03b03.bmp", 568, 368, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b04", "images/intro/vop03b04.bmp", 568, 368, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b05", "images/intro/vop03b05.bmp", 568, 368, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b06", "images/intro/vop03b06.bmp", 568, 368, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b07", "images/intro/vop03b07.bmp", 568, 368, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b08", "images/intro/vop03b08.bmp", 568, 368, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b09", "images/intro/vop03b09.bmp", 568, 368, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b10", "images/intro/vop03b10.bmp", 568, 368, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b11", "images/intro/vop03b11.bmp", 568, 368, true, RGB(255, 0, 255));
	*/
	IMAGE->addImage("vop03b01", "images/intro/vop03b01.bmp", WINSIZEX - 200, WINSIZEY - 180, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b02", "images/intro/vop03b02.bmp", WINSIZEX - 200, WINSIZEY - 180, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b03", "images/intro/vop03b03.bmp", WINSIZEX - 200, WINSIZEY - 180, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b04", "images/intro/vop03b04.bmp", WINSIZEX - 200, WINSIZEY - 180, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b05", "images/intro/vop03b05.bmp", WINSIZEX - 200, WINSIZEY - 180, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b06", "images/intro/vop03b06.bmp", WINSIZEX - 200, WINSIZEY - 180, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b07", "images/intro/vop03b07.bmp", WINSIZEX - 200, WINSIZEY - 180, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b08", "images/intro/vop03b08.bmp", WINSIZEX - 200, WINSIZEY - 180, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b09", "images/intro/vop03b09.bmp", WINSIZEX - 200, WINSIZEY - 180, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b10", "images/intro/vop03b10.bmp", WINSIZEX - 200, WINSIZEY - 180, true, RGB(255, 0, 255));
	IMAGE->addImage("vop03b11", "images/intro/vop03b11.bmp", WINSIZEX - 200, WINSIZEY - 180, true, RGB(255, 0, 255));

	/*
	IMAGE->addImage("vop03c00", "images/intro/vop03c00.bmp", 568, 368, false, RGB(255, 0, 255));
	IMAGE->addImage("vop03c01", "images/intro/vop03c01.bmp", 568, 368, false, RGB(255, 0, 255));
	IMAGE->addImage("vop03c02", "images/intro/vop03c02.bmp", 568, 368, false, RGB(255, 0, 255));
	IMAGE->addImage("vop03c03", "images/intro/vop03c03.bmp", 568, 368, false, RGB(255, 0, 255));
	IMAGE->addImage("vop03c04", "images/intro/vop03c04.bmp", 568, 368, false, RGB(255, 0, 255));
	*/
	IMAGE->addImage("vop03c00", "images/intro/vop03c00.bmp", 60, 100, false, RGB(255, 0, 255));
	IMAGE->addImage("vop03c01", "images/intro/vop03c01.bmp", 60, 100, false, RGB(255, 0, 255));
	IMAGE->addImage("vop03c02", "images/intro/vop03c02.bmp", 60, 100, false, RGB(255, 0, 255));
	IMAGE->addImage("vop03c03", "images/intro/vop03c03.bmp", 60, 100, false, RGB(255, 0, 255));
	IMAGE->addImage("vop03c04", "images/intro/vop03c04.bmp", 60, 100, false, RGB(255, 0, 255));

	//IMAGE->addImage("vop04a", "images/intro/vop04a.bmp", 640, 480, false, RGB(255, 0, 255));
	IMAGE->addImage("vop04a", "images/intro/vop04a.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGE->addImage("vop04b", "images/intro/vop04b.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));

	IMAGE->addImage("white", "images/intro/white.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));


	IMAGE->addImage("vop05a", "images/intro/vop05a.bmp", WINSIZEX * 2, WINSIZEY * 2, false, RGB(255, 0, 255));

	//IMAGE->addImage("vop05b00", "images/intro/vop05b00.bmp", 480, 96, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b00", "images/intro/vop05b00.bmp", 630, 180, true, RGB(255, 0, 0));

	//IMAGE->addImage("vop05b01", "images/intro/vop05b01.bmp", 440, 144, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b01", "images/intro/vop05b01.bmp", 600, 200, true, RGB(255, 0, 0));

	//IMAGE->addImage("vop05b02", "images/intro/vop05b02.bmp", 400, 176, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b02", "images/intro/vop05b02.bmp", 550, 230, true, RGB(255, 0, 0));

	//IMAGE->addImage("vop05b03", "images/intro/vop05b03.bmp", 288, 208, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b03", "images/intro/vop05b03.bmp", 380, 280, true, RGB(255, 0, 0));

	//IMAGE->addImage("vop05b04", "images/intro/vop05b04.bmp", 216, 232, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b04", "images/intro/vop05b04.bmp", 280, 280, true, RGB(255, 0, 0));

	//IMAGE->addImage("vop05b05", "images/intro/vop05b05.bmp", 168, 224, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b05", "images/intro/vop05b05.bmp", 220, 270, true, RGB(255, 0, 0));

	//IMAGE->addImage("vop05b06", "images/intro/vop05b06.bmp", 144, 224, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b06", "images/intro/vop05b06.bmp", 190, 270, true, RGB(255, 0, 0));

	//IMAGE->addImage("vop05b07", "images/intro/vop05b07.bmp", 160, 240, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b07", "images/intro/vop05b07.bmp", 210, 290, true, RGB(255, 0, 0));

	//IMAGE->addImage("vop05b08", "images/intro/vop05b08.bmp", 160, 240, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b08", "images/intro/vop05b08.bmp", 210, 290, true, RGB(255, 0, 0));

	/*
	IMAGE->addImage("vop05b09", "images/intro/vop05b09.bmp", 160, 240, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b10", "images/intro/vop05b10.bmp", 160, 240, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b11", "images/intro/vop05b11.bmp", 160, 240, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b12", "images/intro/vop05b12.bmp", 160, 240, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b13", "images/intro/vop05b13.bmp", 160, 240, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b14", "images/intro/vop05b14.bmp", 160, 240, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b15", "images/intro/vop05b15.bmp", 160, 240, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b16", "images/intro/vop05b16.bmp", 160, 240, true, RGB(255, 0, 0));
	*/

	IMAGE->addImage("vop05b09", "images/intro/vop05b09.bmp", 210, 290, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b10", "images/intro/vop05b10.bmp", 210, 290, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b11", "images/intro/vop05b11.bmp", 210, 290, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b12", "images/intro/vop05b12.bmp", 210, 290, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b13", "images/intro/vop05b13.bmp", 210, 290, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b14", "images/intro/vop05b14.bmp", 210, 290, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b15", "images/intro/vop05b15.bmp", 210, 290, true, RGB(255, 0, 0));
	IMAGE->addImage("vop05b16", "images/intro/vop05b16.bmp", 210, 290, true, RGB(255, 0, 0));

	background = RectMake(0, 0, WINSIZEX, WINSIZEY);
	activeTime = 0;

	m_count = 0;

	shipMove_up = true;
	shipMove_down = false;
	shipHead_pos = 100;
	shipRailing_pos = 330;

	cameraX = 0;
	cameraY = 0;

	town_active = false;

	return S_OK;
}

void intro::release()
{
}

void intro::update()
{
	activeTime++;
	//if (activeTime < 2565) SOUND->play("bgm00",2);
	//else if(activeTime == 2564) SOUND->stop("bgm00");
	if (activeTime < 2565) {}
	else{
		//SOUND->stop("bgm00");
		town_active = true;
	}
}

void intro::render()
{

	if ( (activeTime < 2565) && (!SOUND->isPlaySound("bgm00")) )
	{
		SOUND->play("bgm00");
	}



	if (activeTime < 650)
	{
		IMAGE->findImage("vop02a")->render(getMemDC(), 0, 0);

		if (shipMove_up)
		{
			m_count++;
			static int moveCount = 0;

			if (m_count % 2 == 0)
			{
				m_count = 0;


				moveCount++;

				if (moveCount <= 40)
				{
					int interval = 1;
					shipHead_pos += 1;
					shipRailing_pos += 2;
				}

				if (moveCount == 60)
				{
					shipMove_up = false;
					shipMove_down = true;
					moveCount = 0;
				}
			}
			IMAGE->findImage("vop02b")->render(getMemDC(), 0, shipHead_pos);
			IMAGE->findImage("vop02c")->render(getMemDC(), 0, shipRailing_pos);
		}
		else if (shipMove_down)
		{
			static int moveCount = 0;
			m_count++;
			if (m_count % 2 == 0)
			{
				m_count = 0;

				moveCount++;

				if (moveCount <= 40)
				{
					int interval = 1;
					shipHead_pos -= 1;
					shipRailing_pos -= 2;
				}

				if (moveCount == 60)
				{
					shipMove_up = true;
					shipMove_down = false;
					moveCount = 0;
				}
			}
			IMAGE->findImage("vop02b")->render(getMemDC(), 0, shipHead_pos);
			IMAGE->findImage("vop02c")->render(getMemDC(), 0, shipRailing_pos);
		}

		static int playerCount = 0;
		static int playerCount_control = 0;

		playerCount_control++;

		if (playerCount_control % 10 == 0)
		{
			playerCount++;
			playerCount_control = 0;
		}

		switch (playerCount)
		{
		case 0:
			IMAGE->findImage("vop02d00")->render(getMemDC(), 500, shipRailing_pos - 210);
			break;
		case 1:
			IMAGE->findImage("vop02d01")->render(getMemDC(), 500, shipRailing_pos - 210);
			break;
		case 2:
			IMAGE->findImage("vop02d02")->render(getMemDC(), 500, shipRailing_pos - 210);
			break;
		case 3:
			IMAGE->findImage("vop02d03")->render(getMemDC(), 500, shipRailing_pos - 210);
			break;
		case 4:
			IMAGE->findImage("vop02d04")->render(getMemDC(), 500, shipRailing_pos - 210);
			break;
		case 5:
			IMAGE->findImage("vop02d05")->render(getMemDC(), 500, shipRailing_pos - 210);
			break;
		case 6:
			IMAGE->findImage("vop02d06")->render(getMemDC(), 500, shipRailing_pos - 210);
			break;
		case 7:
			IMAGE->findImage("vop02d07")->render(getMemDC(), 500, shipRailing_pos - 210);
			break;
		case 8:
			playerCount = 0;
			IMAGE->findImage("vop02d00")->render(getMemDC(), 500, shipRailing_pos - 210);
			break;
		}
	}
	else if (activeTime < 700)
	{
		static int alphaValue = 0;
		static int changeAlpha = 0;

		if (changeAlpha == 0)
		{
			alphaValue += 10;
			if (alphaValue >= 255)
			{
				alphaValue = 255;
				changeAlpha = 1;
			}
			IMAGE->findImage("vop02a")->render(getMemDC(), 0, 0);
			IMAGE->findImage("vop02b")->render(getMemDC(), 0, shipHead_pos);
			IMAGE->findImage("vop02c")->render(getMemDC(), 0, shipRailing_pos);
			IMAGE->findImage("vop02d00")->render(getMemDC(), 500, shipRailing_pos - 210);
			IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue);
		}

		if (changeAlpha == 1)
		{
			alphaValue -= 10;
			if (alphaValue <= 0)alphaValue = 0;

			IMAGE->findImage("vop03a")->render(getMemDC(), 0, 0);
			IMAGE->findImage("vop03b00")->render(getMemDC(), 0, 0);
			IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue);
		}
	}

	else if (activeTime < 1180)
	{
		IMAGE->findImage("vop03a")->render(getMemDC(), 0, 0);

		static int playerCount = 0;
		static int playerCount_control = 0;

		playerCount_control++;

		if (playerCount_control % 10 == 0)
		{
			playerCount++;
			playerCount_control = 0;
		}

		switch (playerCount)
		{
		case 0:
			IMAGE->findImage("vop03b00")->render(getMemDC(), 0, 0);
			break;
		case 1:
			IMAGE->findImage("vop03b01")->render(getMemDC(), 0, 0);
			break;
		case 2:
			IMAGE->findImage("vop03b02")->render(getMemDC(), 0, 0);
			break;
		case 3:
			IMAGE->findImage("vop03b03")->render(getMemDC(), 0, 0);
			break;
		case 4:
			IMAGE->findImage("vop03b04")->render(getMemDC(), 0, 0);
			break;
		case 5:
			IMAGE->findImage("vop03b05")->render(getMemDC(), 0, 0);
			break;
		case 6:
			IMAGE->findImage("vop03b06")->render(getMemDC(), 0, 0);
			break;
		case 7:
			IMAGE->findImage("vop03b07")->render(getMemDC(), 0, 0);
			break;
		case 8:
			IMAGE->findImage("vop03b08")->render(getMemDC(), 0, 0);
			break;
		case 9:
			IMAGE->findImage("vop03b09")->render(getMemDC(), 0, 0);
			break;
		case 10:
			IMAGE->findImage("vop03b10")->render(getMemDC(), 0, 0);
			break;
		case 11:
			IMAGE->findImage("vop03b11")->render(getMemDC(), 0, 0);
			break;
		case 12:
			IMAGE->findImage("vop03b00")->render(getMemDC(), 0, 0);
			playerCount = 0;
			break;
		}
	}
	else if (activeTime < 1250)//입모양 변경.
	{
		IMAGE->findImage("vop03a")->render(getMemDC(), 0, 0);

		static int playerCount = 0;
		static int playerCount_control = 0;

		playerCount_control++;

		if (playerCount_control % 10 == 0)
		{
			playerCount++;
			playerCount_control = 0;
		}

		switch (playerCount)
		{
		case 0:
			IMAGE->findImage("vop03b00")->render(getMemDC(), 0, 0);
			break;
		case 1:
			IMAGE->findImage("vop03b01")->render(getMemDC(), 0, 0);
			break;
		case 2:
			IMAGE->findImage("vop03b02")->render(getMemDC(), 0, 0);
			break;
		case 3:
			IMAGE->findImage("vop03b03")->render(getMemDC(), 0, 0);
			break;
		case 4:
			IMAGE->findImage("vop03b04")->render(getMemDC(), 0, 0);
			break;
		case 5:
			IMAGE->findImage("vop03b05")->render(getMemDC(), 0, 0);
			break;
		case 6:
			IMAGE->findImage("vop03b06")->render(getMemDC(), 0, 0);
			break;
		case 7:
			IMAGE->findImage("vop03b07")->render(getMemDC(), 0, 0);
			break;
		case 8:
			IMAGE->findImage("vop03b08")->render(getMemDC(), 0, 0);
			break;
		case 9:
			IMAGE->findImage("vop03b09")->render(getMemDC(), 0, 0);
			break;
		case 10:
			IMAGE->findImage("vop03b10")->render(getMemDC(), 0, 0);
			break;
		case 11:
			IMAGE->findImage("vop03b11")->render(getMemDC(), 0, 0);
			break;
		case 12:
			IMAGE->findImage("vop03b00")->render(getMemDC(), 0, 0);
			playerCount = 0;
			break;
		}

		static int mouseCount = 0;
		static int mouseCount_control = 0;

		mouseCount_control++;

		if (mouseCount_control % 10 == 0)
		{
			mouseCount++;
			mouseCount_control = 0;
		}

		switch (mouseCount)
		{
		case 0:
			IMAGE->findImage("vop03c00")->render(getMemDC(), 525, -10);
			break;
		case 1:
			IMAGE->findImage("vop03c01")->render(getMemDC(), 525, -10);
			break;
		case 2:
			IMAGE->findImage("vop03c02")->render(getMemDC(), 525, -10);
			break;
		case 3:
			IMAGE->findImage("vop03c02")->render(getMemDC(), 525, -10);
			break;
		case 4:
			mouseCount = 3;
			break;
		}

		if (mouseCount == 3) IMAGE->findImage("vop03c02")->render(getMemDC(), 525, -10);
	}

	else if (activeTime < 1300)
	{
		static int alphaValue = 0;
		static int changeAlpha = 0;

		if (changeAlpha == 0)
		{
			alphaValue += 10;
			if (alphaValue >= 255)
			{
				alphaValue = 255;
				changeAlpha = 1;
			}
			IMAGE->findImage("vop03a")->render(getMemDC(), 0, 0);
			IMAGE->findImage("vop03b07")->render(getMemDC(), 0, 0);
			IMAGE->findImage("vop03c02")->render(getMemDC(), 525, -10);
			IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue);
		}

		if (changeAlpha == 1)
		{
			alphaValue -= 10;
			if (alphaValue <= 0)alphaValue = 0;

			IMAGE->findImage("vop04a")->render(getMemDC(), 0, 0);
			IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue);
		}
	}
	else if (activeTime < 1400)//마을 display.
	{
		IMAGE->findImage("vop04a")->render(getMemDC(), 0, 0);
	}
	else if (activeTime < 1450)
	{
		static int alphaValue = 0;
		static int changeAlpha = 0;

		if (changeAlpha == 0)
		{
			alphaValue += 10;
			if (alphaValue >= 255)
			{
				alphaValue = 255;
				changeAlpha = 1;
			}
			IMAGE->findImage("vop04a")->render(getMemDC(), 0, 0);
			IMAGE->findImage("white")->alphaRender(getMemDC(), 0, 0, alphaValue);
		}

		if (changeAlpha == 1)
		{
			alphaValue -= 10;
			if (alphaValue <= 0)alphaValue = 0;

			IMAGE->findImage("vop04b")->render(getMemDC(), 0, 0);
			IMAGE->findImage("white")->alphaRender(getMemDC(), 0, 0, alphaValue);
		}
	}
	else if (activeTime < 1650)
	{
		IMAGE->findImage("vop04b")->render(getMemDC(), 0, 0);
	}
	else if (activeTime < 1700)
	{
		static int alphaValue = 0;
		static int changeAlpha = 0;

		if (changeAlpha == 0)
		{
			alphaValue += 10;
			if (alphaValue >= 255)
			{
				alphaValue = 255;
				changeAlpha = 1;
			}
			IMAGE->findImage("vop04b")->render(getMemDC(), 0, 0);
			IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue);
		}

		if (changeAlpha == 1)
		{
			alphaValue -= 10;
			if (alphaValue <= 0)alphaValue = 0;

			IMAGE->findImage("vop05a")->render(getMemDC(), -WINSIZEX + cameraX, -WINSIZEY + cameraY);
			IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue);
		}
	}
	else if (activeTime < 1770)
	{
		if ((-WINSIZEX + cameraX != 0) && (-WINSIZEY + cameraY != 0))
		{
			cameraX++;
			cameraY++;
		}
		IMAGE->findImage("vop05a")->render(getMemDC(), -WINSIZEX + cameraX, -WINSIZEY + cameraY);


		static int birdCount_control = 0;
		static int birdCount = 0;
		birdCount_control++;
		if (birdCount_control % 6 == 0)
		{
			birdCount_control = 0;
			birdCount++;
			if (birdCount == 8)birdCount = 7;
		}

		if (birdCount == 0)IMAGE->findImage("vop05b00")->render(getMemDC(), 377, 549);
		else if (birdCount == 1)IMAGE->findImage("vop05b01")->render(getMemDC(), 407, 483);
		else if (birdCount == 2)IMAGE->findImage("vop05b02")->render(getMemDC(), 407, 273);
		else if (birdCount == 3)IMAGE->findImage("vop05b03")->render(getMemDC(), 250, 83);
		else if (birdCount == 4)IMAGE->findImage("vop05b04")->render(getMemDC(), 180, 45);
		else if (birdCount == 5)IMAGE->findImage("vop05b05")->render(getMemDC(), 130, 33);
		else if (birdCount == 6)IMAGE->findImage("vop05b06")->render(getMemDC(), 80, 25);
		else if (birdCount == 7)IMAGE->findImage("vop05b07")->render(getMemDC(), 50, 0);

	}
	else if (activeTime < 2440)
	{
		if ((-WINSIZEX + cameraX != 0) && (-WINSIZEY + cameraY != 0))
		{
			cameraX++;
			cameraY++;
		}
		IMAGE->findImage("vop05a")->render(getMemDC(), -WINSIZEX + cameraX, -WINSIZEY + cameraY);

		static int birdMove_x = 50;
		static int birdMove_y = 0;

		static int birdMove_count = 0;
		birdMove_count++;
		static int cycle = 0;


		if (birdMove_x <= 100 && cycle == 0)
		{
			if (birdMove_count % 6 == 0)
			{
				birdMove_count = 0;

				birdMove_x += 10;
				birdMove_y += 5;
			}
			IMAGE->findImage("vop05b08")->render(getMemDC(), birdMove_x, birdMove_y);
		}
		else if (birdMove_x <= 200 && cycle == 0)
		{
			if (birdMove_count % 6 == 0)
			{
				birdMove_count = 0;

				birdMove_x += 10;
				birdMove_y += 5;
			}
			IMAGE->findImage("vop05b09")->render(getMemDC(), birdMove_x, birdMove_y);
		}
		else if (birdMove_x <= 300 && cycle == 0)
		{
			if (birdMove_count % 6 == 0)
			{
				birdMove_count = 0;

				birdMove_x += 10;
				birdMove_y += 5;
			}
			IMAGE->findImage("vop05b10")->render(getMemDC(), birdMove_x, birdMove_y);
		}
		else if (birdMove_x < 350 && cycle == 0)
		{
			if (birdMove_count % 6 == 0)
			{
				birdMove_count = 0;

				birdMove_x += 10;
				birdMove_y += 5;
			}
			IMAGE->findImage("vop05b11")->render(getMemDC(), birdMove_x, birdMove_y);
		}
		else if (birdMove_x < 400 && cycle == 0)
		{
			if (birdMove_count % 6 == 0)
			{
				birdMove_count = 0;

				birdMove_x += 10;
				birdMove_y += 5;
			}
			IMAGE->findImage("vop05b12")->render(getMemDC(), birdMove_x, birdMove_y);
		}

		if (birdMove_x >= 400)
		{

			static int birdCount = 0;
			static int birdCount_control = 0;


			birdCount_control++;

			if (birdCount_control % 17 == 0)
			{
				birdCount++;
				birdCount_control = 0;
			}

			switch (birdCount)
			{
			case 0:
				IMAGE->findImage("vop05b13")->render(getMemDC(), birdMove_x, birdMove_y);
				break;
			case 1:
				IMAGE->findImage("vop05b14")->render(getMemDC(), birdMove_x, birdMove_y);
				break;
			case 2:
				IMAGE->findImage("vop05b15")->render(getMemDC(), birdMove_x, birdMove_y);
				break;
			case 3:
				IMAGE->findImage("vop05b16")->render(getMemDC(), birdMove_x, birdMove_y);
				break;
			case 4:
				birdCount = 0;
				cycle++;
				break;
			}

			if (cycle > 3)
			{
				birdMove_x -= 5;
			}
		}

		if (birdMove_x < 400 && birdMove_x>100 && cycle > 3)
		{
			static int birdCount_control = 0;
			static int birdCount = 0;
			birdCount_control++;
			if (birdCount_control % 15 == 0)
			{
				birdCount_control = 0;
				birdCount++;
				birdMove_x -= 50;
			}
			switch (birdCount)
			{
			case 0:
				IMAGE->findImage("vop05b13")->render(getMemDC(), birdMove_x, birdMove_y);
				break;
			case 1:
				IMAGE->findImage("vop05b14")->render(getMemDC(), birdMove_x, birdMove_y);
				break;
			case 2:
				IMAGE->findImage("vop05b15")->render(getMemDC(), birdMove_x, birdMove_y);
				break;
			case 3:
				IMAGE->findImage("vop05b16")->render(getMemDC(), birdMove_x, birdMove_y);
				break;
			case 4:
				birdCount = 0;
				break;
			}
		}
		if (birdMove_x <= 100 && birdMove_x > -200 && cycle > 3)
		{
			static int birdCount_control = 0;
			static int birdCount = 0;
			birdCount_control++;
			if (birdCount_control % 15 == 0)
			{
				birdCount_control = 0;
				birdCount++;
				birdMove_x -= 50;
			}
			IMAGE->findImage("vop05b12")->render(getMemDC(), birdMove_x, birdMove_y);
		}
	}

	else if (activeTime < 2565)
	{
		static int alphaValue = 0;

		alphaValue += 10;
		if (alphaValue >= 255)
		{
			alphaValue = 255;

		}
		IMAGE->findImage("vop05a")->render(getMemDC(), -WINSIZEX + cameraX, -WINSIZEY + cameraY);
		IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue);
	}


	//TCHAR str[50];
	//wsprintf(str, "activeTime : %d", activeTime);
	//TextOut(getMemDC(), 100, 100, str, lstrlen(str));
}
