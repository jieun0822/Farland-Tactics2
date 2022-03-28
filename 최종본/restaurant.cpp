#include "framework.h"
#include "restaurant.h"

restaurant::restaurant()
{
}

restaurant::~restaurant()
{
}

HRESULT restaurant::init()
{
	SOUND->addSound("식당", "sound/bgm08.mp3", true, false);


	IMAGE->addImage("식당_배경화면", "images/식당/st09a.bmp", WINSIZEX - 10, WINSIZEY - 30, false, RGB(0, 0, 0));

	IMAGE->addImage("conversation_con_up", "images/식당/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("conversation_wnd_up", "images/식당/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("conversation_con_down", "images/식당/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("conversation_wnd_down", "images/식당/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));

	IMAGE->addImage("face01c", "images/식당/face01c.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face03c", "images/식당/face03c.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face03m", "images/식당/face03m.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face25b", "images/식당/face25b.bmp", 360, 250, true, RGB(255, 255, 255));

	IMAGE->addImage("face01c_1", "images/식당/face01c.bmp", 180 + 80, 125 + 80, true, RGB(255, 255, 255));
	IMAGE->addImage("face03m_1", "images/식당/face03m.bmp", 180 + 80, 125 + 80, true, RGB(255, 255, 255));

	IMAGE->addImage("식당_이창희선생님", "images/식당/식당_이창희선생님.bmp", 38 + 20, 66 + 20, true, RGB(255, 0, 255));
	IMAGE->addImage("식당_최지은", "images/식당/식당_최지은.bmp", 49 + 20, 71 + 20, true, RGB(0, 255, 255));
	IMAGE->addImage("식당_홍수진", "images/식당/식당_홍수진.bmp", 44 + 20, 69 + 20, true, RGB(255, 0, 255));

	IMAGE->addImage("black", "images/식당/black.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));

	//fade 변수.
	alphaValue = 0;
	changeAlpha = 0;

	return S_OK;
}

void restaurant::release()
{
}

void restaurant::update()
{
	activeTime++;

}

void restaurant::render()
{

	HFONT font, oldfont;

	if (activeTime < 725)
	{
		IMAGE->render("식당_배경화면", getMemDC());
		IMAGE->render("식당_최지은", getMemDC(), 400, 300);
		IMAGE->render("식당_홍수진", getMemDC(), 380, 350);
	}
	if (activeTime >= 300 && activeTime <725) IMAGE->render("식당_이창희선생님", getMemDC(), 530, 280);


	//TCHAR str[20];
	//wsprintf(str, "activeTime : %d", activeTime);
	//TextOut(getMemDC(), 200, 400, str, lstrlen(str));
	SetBkMode(getMemDC(), TRANSPARENT);

	//위 대화.
	if (activeTime >= 20 && activeTime < 260)
	{
		IMAGE->render("conversation_wnd_up", getMemDC(), 0, 10);
		IMAGE->alphaRender("conversation_con_up", getMemDC(), 0, 10, 170);
		IMAGE->render("face01c", getMemDC(), 10, 12);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 380, 55, "최지은", lstrlen("최지은"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 380 - 2, 55, "최지은", lstrlen("최지은"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 385, 90, "「 우리 점심 뭐 먹지? 」", lstrlen("「 우리 점심 뭐 먹지? 」"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}
	else if (activeTime >= 450 && activeTime < 725)
	{
		IMAGE->render("conversation_wnd_up", getMemDC(), 0, 10);
		IMAGE->alphaRender("conversation_con_up", getMemDC(), 0, 10, 170);
		IMAGE->render("face01c_1", getMemDC(), 10, 30);
		IMAGE->render("face03m_1", getMemDC(), 160, 30);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 380, 55, "최지은,홍수진", lstrlen("최지은,홍수진"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 380 - 2, 55, "최지은,홍수진", lstrlen("최지은,홍수진"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 385, 90, "「 소고기요!!! 」", lstrlen("「 소고기요!!! 」"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}

	//아래 대화.
	if (activeTime >= 130 && activeTime < 260)
	{
		IMAGE->render("conversation_wnd_down", getMemDC(), 0, WINSIZEY - 300);
		IMAGE->alphaRender("conversation_con_down", getMemDC(), 0, WINSIZEY - 301, 170);
		IMAGE->render("face03c", getMemDC(), 600, 470);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 50, WINSIZEY - 260, "홍수진", lstrlen("홍수진"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 48, WINSIZEY - 260, "홍수진", lstrlen("홍수진"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 50, WINSIZEY - 225, "「 소고기 먹자! 」", lstrlen("「 소고기 먹자! 」"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}
	else if (activeTime >= 350 && activeTime < 520)
	{
		IMAGE->render("conversation_wnd_down", getMemDC(), 0, WINSIZEY - 300);
		IMAGE->alphaRender("conversation_con_down", getMemDC(), 0, WINSIZEY - 301, 170);
		IMAGE->render("face25b", getMemDC(), 600, 470);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 50, WINSIZEY - 260, "이창희 선생님(다이어트 중)", lstrlen("이창희 선생님(다이어트 중) "));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 48, WINSIZEY - 260, "이창희 선생님(다이어트 중) ", lstrlen("이창희 선생님(다이어트 중) "));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 50, WINSIZEY - 225, "「 너네 점심 뭐 먹었냐? 」", lstrlen("「 너네 점심 뭐 먹었냐? 」"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}
	else if (activeTime >= 520 && activeTime < 725)
	{
		IMAGE->render("conversation_wnd_down", getMemDC(), 0, WINSIZEY - 300);
		IMAGE->alphaRender("conversation_con_down", getMemDC(), 0, WINSIZEY - 301, 170);
		IMAGE->render("face25b", getMemDC(), 600, 470);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 50, WINSIZEY - 260, "이창희 선생님(다이어트 중)", lstrlen("이창희 선생님(다이어트 중) "));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 48, WINSIZEY - 260, "이창희 선생님(다이어트 중) ", lstrlen("이창희 선생님(다이어트 중) "));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 50, WINSIZEY - 225, "「 ... 」", lstrlen("「 ... 」"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}

	//fade.
	if (activeTime >= 260 && activeTime < 350)
	{
		if (changeAlpha == 0)
		{
			alphaValue += 10;
			if (alphaValue >= 255)
			{
				alphaValue = 255;
				changeAlpha = 1;
			}
			IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue);
		}

		if (changeAlpha == 1)
		{
			alphaValue -= 10;
			if (alphaValue <= 0)alphaValue = 0;

			IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue);
		}
	}

	
	if (activeTime >= 700 && activeTime < 725)
	{
		
			alphaValue += 10;
			if (alphaValue >= 255)
			{
				alphaValue = 255;
				changeAlpha = 1;
			}
			IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue);
	}

	if (activeTime >= 725 && activeTime < 750)
	{

		alphaValue -= 10;
		if (alphaValue <= 0)alphaValue = 0;

		IMAGE->render("마을맵", getMemDC(), 0, 0);
		IMAGE->render("이정표", getMemDC(), 0, 0);
		IMAGE->findImage("black")->alphaRender(getMemDC(), 0, 0, alphaValue);
	}

	if (activeTime >= 750)
	{
		town_active = true;

		SOUND->stop("식당");
	}
}
