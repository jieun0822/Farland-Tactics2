#include "framework.h"
#include "academy.h"

academy::academy()
{
}

academy::~academy()
{
}

HRESULT academy::init()
{
	SOUND->addSound("학원", "sound/bgm13.mp3", true, false);


	IMAGE->addImage("아카데미_배경화면", "images/아카데미/st13a.bmp", WINSIZEX - 10, WINSIZEY - 30, false, RGB(0, 0, 0));

	IMAGE->addImage("conversation_con_up", "images/아카데미/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("conversation_wnd_up", "images/아카데미/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("conversation_con_down", "images/아카데미/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("conversation_wnd_down", "images/아카데미/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));

	IMAGE->addImage("face01b", "images/아카데미/face01b.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face03c", "images/아카데미/face03c.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face03m", "images/아카데미/face03m.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face07c", "images/아카데미/face07c.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face10a", "images/아카데미/face10a.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face11e", "images/아카데미/face11e.bmp", 360, 250, true, RGB(255, 255, 255));

	IMAGE->addImage("아카데미_김미정", "images/아카데미/아카데미_김미정.bmp", 57 + 20, 66 + 20, true, RGB(255, 0, 255));
	IMAGE->addImage("아카데미_오준환선생님", "images/아카데미/아카데미_오준환선생님.bmp", 55 + 20, 65 + 20, true, RGB(255, 0, 255));
	IMAGE->addImage("아카데미_장준형", "images/아카데미/아카데미_장준형.bmp", 44 + 20, 71 + 20, true, RGB(255, 0, 255));
	IMAGE->addImage("아카데미_최지은", "images/아카데미/아카데미_최지은.bmp", 55 + 20, 57 + 20, true, RGB(0, 255, 255));
	IMAGE->addImage("아카데미_홍수진", "images/아카데미/아카데미_홍수진.bmp", 44 + 20, 69 + 20, true, RGB(255, 0, 255));

	activeTime = 0;
	town_active = false;
	return S_OK;
}

void academy::release()
{
}

void academy::update()
{
	activeTime++;
}

void academy::render()
{
	HFONT font, oldfont;

	IMAGE->render("아카데미_배경화면", getMemDC());
	IMAGE->render("아카데미_김미정", getMemDC(), 400, 300);
	IMAGE->render("아카데미_오준환선생님", getMemDC(), 550, 320);
	IMAGE->render("아카데미_장준형", getMemDC(), 370, 390);
	IMAGE->render("아카데미_최지은", getMemDC(), 440, 490);
	IMAGE->render("아카데미_홍수진", getMemDC(), 570, 430);

	TCHAR str[20];
	//SetBkMode(getMemDC(), OPAQUE);
	//wsprintf(str, "activeTime : %d", activeTime);
	//TextOut(getMemDC(), 200, 400, str, lstrlen(str));
	SetBkMode(getMemDC(), TRANSPARENT);

	//up conversation.
	//오준환 선생님.
	if (activeTime >= 20 && activeTime < 180)
	{
		IMAGE->render("conversation_wnd_up", getMemDC(), 0, 10);
		IMAGE->alphaRender("conversation_con_up", getMemDC(), 0, 10, 170);
		IMAGE->render("face11e", getMemDC(), 10, 12);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 380, 55, "오준환 선생님", lstrlen("오준환 선생님"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 380 - 2, 55, "오준환 선생님", lstrlen("오준환 선생님"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(28, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 385, 90, "「 9시다. 다들 출석체크 해야지? 」", lstrlen("「 9시다. 다들 출석체크 해야지? 」"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}
	//최지은.
	else if (activeTime >= 180 && activeTime < 280)
	{
		IMAGE->render("conversation_wnd_up", getMemDC(), 0, 10);
		IMAGE->alphaRender("conversation_con_up", getMemDC(), 0, 10, 170);
		IMAGE->render("face01b", getMemDC(), 10, 12);

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
		TextOut(getMemDC(), 385, 90, "「 헉, 지각이다~!! 」", lstrlen("「 헉, 지각이다~!! 」"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}
	//장준형.
	else if (activeTime >= 400 && activeTime < 700)
	{
		IMAGE->render("conversation_wnd_up", getMemDC(), 0, 10);
		IMAGE->alphaRender("conversation_con_up", getMemDC(), 0, 10, 170);
		IMAGE->render("face10a", getMemDC(), 10, 12);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 380, 55, "장준형", lstrlen("장준형"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 380 - 2, 55, "장준형", lstrlen("장준형"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 385, 90, "「 육쌈냉면 어때요? 」", lstrlen("「 육쌈냉면 어때요? 」"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}

	//down conversation.
	//김미정.
	if (activeTime >= 100 && activeTime < 180)
	{
		IMAGE->render("conversation_wnd_down", getMemDC(), 0, WINSIZEY - 300);
		IMAGE->alphaRender("conversation_con_down", getMemDC(), 0, WINSIZEY - 301, 170);
		IMAGE->render("face07c", getMemDC(), 600, 470);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 50, WINSIZEY - 260, "김미정", lstrlen("김미정"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 48, WINSIZEY - 260, "김미정", lstrlen("김미정"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 50, WINSIZEY - 225, "「 네~!! 」", lstrlen("「 네~!! 」"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}
	//홍수진_1.
	else if (activeTime >= 280 && activeTime < 500)
	{
		IMAGE->render("conversation_wnd_down", getMemDC(), 0, WINSIZEY - 300);
		IMAGE->alphaRender("conversation_con_down", getMemDC(), 0, WINSIZEY - 301, 170);
		IMAGE->render("face03m", getMemDC(), 600, 470);

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
		TextOut(getMemDC(), 50, WINSIZEY - 225, "「 이따 점심 뭐 먹지... 」", lstrlen("「 이따 점심 뭐 먹지... 」"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}
	//홍수진_2.
	else if (activeTime >= 500 && activeTime < 700)
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
		TextOut(getMemDC(), 50, WINSIZEY - 225, "「 좋아요!! 」", lstrlen("「 좋아요!! 」"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}

	if (activeTime >= 700)
	{
		town_active = true;

		SOUND->stop("학원");
	}
}
