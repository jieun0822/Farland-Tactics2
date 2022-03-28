#include "framework.h"
#include "Guild.h"

Guild::Guild()
{
}

Guild::~Guild()
{
}

HRESULT Guild::init()
{
	_townMap = new townMap;
	_townMap->init();

	IMAGE->addImage("길드맵", "images/guildMap.bmp", WINSIZEX - 10, WINSIZEY - 30, false, RGB(0, 0, 0));
	IMAGE->addImage("길드맵_NPC", "images/guildNpc.bmp", 36 + 20, 66 + 40, true, RGB(255, 0, 255));
	IMAGE->addImage("길드맵_책상앞부분", "images/guildTable_front.bmp", 64 + 30, 53 + 28, true, RGB(255, 0, 0));
	IMAGE->addImage("길드맵_플레이어", "images/guild_player.bmp", 48 + 25, 75 + 48, true, RGB(255, 0, 255));

	////길드NPC 대화창
	IMAGE->addImage("대화테두리_길드NPC", "images/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("대화창_길드NPC", "images/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("이미지_길드NPC", "images/face13a.bmp", 360, 250, true, RGB(255, 255, 255));

	//플레이어 대화창
	IMAGE->addImage("대화테두리_길드Player", "images/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("대화창_길드Player", "images/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("이미지_길드Player", "images/face02a.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("이미지_길드Player_당황", "images/face02h.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("이미지_길드Player_놀람", "images/face02b.bmp", 360, 250, true, RGB(255, 255, 255));

	//화면어둡게
	IMAGE->addImage("화면어둡게", "images/darkenScreen.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));

	//확인창
	confirmWindow = RectMake(370, 280, 280, 120);
	confirmWin_name = RectMake(confirmWindow.left + 2, confirmWindow.top + 2, 276, 30);
	confirmWin_yesButton = RectMake(confirmWindow.left + 15, confirmWindow.bottom - 43, 110, 30);
	confirmWin_noButton = RectMake(confirmWindow.left + 155, confirmWindow.bottom - 43, 110, 30);

	isCheck = false;
	isCheck_yes = false;
	isCheck_no = false;

	activeTime = 0;
	_activeTime = 0;

	//지은★★★★★★★★★★★★★★★★★★★★★★
	isFirst = true;
	//활-두번째 퀘스트 정보
	isSecond = false;

	return S_OK;
}

void Guild::release()
{
}

void Guild::update()
{
	//지은★★★★★★★★★★★★★★★★★★★★★★
	if (isFirst && !isSecond)		//활-두번째 퀘스트 false일때
	{
		if (InputManager->isOnceKeyUp(VK_LBUTTON))
		{
			if (PtInRect(&confirmWin_yesButton, m_ptMouse) && activeTime > 260) { isCheck_yes = true; }
			//활-isCheckNo 수정
			if (PtInRect(&confirmWin_noButton, m_ptMouse) && activeTime > 260) { isCheck_no = true; }//_activeTime++; }
		}

		if (isCheck_yes)
		{
			isFirst = false;
			town_active = true;
		}

		//활-_activeTime추가
		if (isCheck_no && _activeTime > 600)
		{
			isFirst = false;
			//town_active = true;
		}
	}
}

void Guild::render()
{
	//활-길드 이미지 기본으로 추가
	IMAGE->findImage("길드맵")->render(getMemDC(), 0, 0);
	IMAGE->findImage("길드맵_NPC")->render(getMemDC(), 525, 225);
	IMAGE->findImage("길드맵_책상앞부분")->render(getMemDC(), 535, 308);
	IMAGE->findImage("길드맵_플레이어")->render(getMemDC(), 605, 328);

	HFONT font, oldfont;


	//지은★★★★★★★★★★★★★★★★★★★★★★
	if (isFirst && !isSecond)		//활-두번째 퀘스트 false일때
	{
		//IMAGE->findImage("길드맵")->render(getMemDC(), 0, 0);
		//IMAGE->findImage("길드맵_NPC")->render(getMemDC(), 525, 225);
		//IMAGE->findImage("길드맵_책상앞부분")->render(getMemDC(), 535, 308);
		//IMAGE->findImage("길드맵_플레이어")->render(getMemDC(), 605, 328);

		activeTime++;
		if (activeTime >= 30 && activeTime < 140)
		{
			IMAGE->render("대화테두리_길드NPC", getMemDC(), 0, 10);
			IMAGE->alphaRender("대화창_길드NPC", getMemDC(), 0, 10, 170);
			IMAGE->render("이미지_길드NPC", getMemDC(), 10, 12);

			HFONT font, oldfont;
			SetBkMode(getMemDC(), TRANSPARENT);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 380, 55, "가스톤", lstrlen("가스톤"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TCHAR strrr[128];
			wsprintf(strrr, "「 일이 있긴 있어. 」");
			TextOut(getMemDC(), 385, 90, strrr, lstrlen(strrr));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			if (activeTime >= 80 && !(isCheck_no))
			{
				IMAGE->render("대화테두리_길드Player", getMemDC(), 0, WINSIZEY - 300);
				IMAGE->alphaRender("대화창_길드Player", getMemDC(), 0, WINSIZEY - 301, 170);
				IMAGE->render("이미지_길드Player", getMemDC(), 600, 470);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 102));
				TextOut(getMemDC(), 48, WINSIZEY - 260, "알", lstrlen("알"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				TextOut(getMemDC(), 50, WINSIZEY - 225, "「 들려 줘요. 」", lstrlen("「 들려 줘요. 」"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);
			}
		}


		if (activeTime >= 140 && !(isCheck_no))
		{


			IMAGE->render("대화테두리_길드NPC", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("대화창_길드NPC", getMemDC(), 0, WINSIZEY - 301, 170);
			//IMAGE->render("이미지_길드NPC", getMemDC(), 600, 470);


			SetBkMode(getMemDC(), TRANSPARENT);
			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "가스톤", lstrlen("가스톤"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));

			TCHAR str[100];
			wsprintf(str, "「어린아이 한명이, 여기서 조금 떨어진 곳에 있는 산속에서 미아가 되었다.");
			TextOut(getMemDC(), 50, WINSIZEY - 225, str, lstrlen(str));

			wsprintf(str, "대단한 몬스터가 있는 곳은 아니지만, 어린아이에게 있어서는");
			TextOut(getMemDC(), 75, WINSIZEY - 195, str, lstrlen(str));

			wsprintf(str, "생명에 관계된 일이지. 서둘러 도와주러 가야해. 어때, 하겠어? 」");
			TextOut(getMemDC(), 75, WINSIZEY - 165, str, lstrlen(str));

			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (/*isCheck &&*/ !(isCheck_no) && activeTime >= 300)
		{
			//확인창.
			HBRUSH brush;

			IMAGE->alphaRender("화면어둡게", getMemDC(), 0, 0, 170);
			grayDraw(confirmWindow);

			brush = CreateSolidBrush(RGB(0, 0, 204));
			Rectangle(getMemDC(), confirmWin_name.left, confirmWin_name.top, confirmWin_name.right, confirmWin_name.bottom);
			FillRect(getMemDC(), &confirmWin_name, brush);
			DeleteObject(brush);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), confirmWin_name.left + 3, confirmWin_name.top + 6, "확인", lstrlen("확인"));
			SetTextColor(getMemDC(), RGB(0, 0, 0));

			TextOut(getMemDC(), confirmWin_name.left + 82, confirmWin_name.top + 45, "일을 하겠습니까?", lstrlen("일을 하겠습니까?"));

			lightDraw(confirmWin_yesButton);
			shadowDraw(confirmWin_yesButton);
			grayDraw(confirmWin_yesButton);
			TextOut(getMemDC(), confirmWin_yesButton.left + 45, confirmWin_yesButton.top + 7, "예", lstrlen("예"));

			lightDraw(confirmWin_noButton);
			shadowDraw(confirmWin_noButton);
			grayDraw(confirmWin_noButton);
			TextOut(getMemDC(), confirmWin_noButton.left + 30, confirmWin_noButton.top + 7, "아니요", lstrlen("아니요"));
		}


		//거절했을 때.
		if (isCheck_no)
		{
			_activeTime++;

			if (_activeTime >= 30 && _activeTime < 200)
			{
				IMAGE->render("대화테두리_길드Player", getMemDC(), 0, WINSIZEY - 300);
				IMAGE->alphaRender("대화창_길드Player", getMemDC(), 0, WINSIZEY - 301, 170);
				IMAGE->render("이미지_길드Player_당황", getMemDC(), 600, 470);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 102));
				TextOut(getMemDC(), 48, WINSIZEY - 260, "알", lstrlen("알"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				TextOut(getMemDC(), 50, WINSIZEY - 225, "「 시간이 안될 것 같아요. 」", lstrlen("「 시간이 안될 것 같아요. 」"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);
			}

			if (_activeTime >= 100 && _activeTime < 350)
			{
				IMAGE->render("대화테두리_길드NPC", getMemDC(), 0, 10);
				IMAGE->alphaRender("대화창_길드NPC", getMemDC(), 0, 10, 170);
				IMAGE->render("이미지_길드NPC", getMemDC(), 10, 12);


				SetBkMode(getMemDC(), TRANSPARENT);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 102));
				TextOut(getMemDC(), 380, 55, "가스톤", lstrlen("가스톤"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);

				//활- "아이들"대사수정
				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				TCHAR strrr[128];
				wsprintf(strrr, "「 우리들이 구해주러 가도, 아이 쪽에서 ");
				TextOut(getMemDC(), 385, 90, strrr, lstrlen(strrr));
				wsprintf(strrr, "   무서워서 도망쳐 버려. 그러니 부탁해. 」");
				TextOut(getMemDC(), 395, 120, strrr, lstrlen(strrr));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);
			}

			if (_activeTime >= 200 && _activeTime < 350)
			{
				IMAGE->render("대화테두리_길드Player", getMemDC(), 0, WINSIZEY - 300);
				IMAGE->alphaRender("대화창_길드Player", getMemDC(), 0, WINSIZEY - 301, 170);
				IMAGE->render("이미지_길드Player_놀람", getMemDC(), 600, 470);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 102));
				TextOut(getMemDC(), 48, WINSIZEY - 260, "알", lstrlen("알"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				TextOut(getMemDC(), 50, WINSIZEY - 225, "「 알았어요. 」", lstrlen("「 알았어요. 」"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);
			}

			if (_activeTime >= 350 && _activeTime < 700)
			{
				IMAGE->render("대화테두리_길드NPC", getMemDC(), 0, 10);
				IMAGE->alphaRender("대화창_길드NPC", getMemDC(), 0, 10, 170);
				IMAGE->render("이미지_길드NPC", getMemDC(), 10, 12);


				SetBkMode(getMemDC(), TRANSPARENT);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 102));
				TextOut(getMemDC(), 380, 55, "가스톤", lstrlen("가스톤"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				TCHAR strrr[128];
				wsprintf(strrr, "「 최근, 악마가 돌아 다니니까 조심해. ");
				TextOut(getMemDC(), 385, 90, strrr, lstrlen(strrr));
				wsprintf(strrr, "   길가는 사람을 불러 세워, 승부를 걸어, ");
				TextOut(getMemDC(), 395, 120, strrr, lstrlen(strrr));
				wsprintf(strrr, "   있는 돈을 모두 빼앗아 가는 것 같아. 」");
				TextOut(getMemDC(), 395, 150, strrr, lstrlen(strrr));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);
			}

			if (_activeTime >= 650)
			{
				town_active = true;
				//SCENE->changeScene("townMap");
			}
		}
	}

	//quest1 완료되지 않았을 때.
	//지은★★★★★★★★★★★★★★★★★★★★★★
	else if (!isFirst && !quest1_complete)
	{
		IMAGE->findImage("길드맵")->render(getMemDC(), 0, 0);
		IMAGE->findImage("길드맵_NPC")->render(getMemDC(), 525, 225);
		IMAGE->findImage("길드맵_책상앞부분")->render(getMemDC(), 535, 308);
		IMAGE->findImage("길드맵_플레이어")->render(getMemDC(), 605, 328);

		activeTime++;

		if (activeTime > 10 && activeTime < 450)
		{
			IMAGE->render("대화테두리_길드NPC", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("대화창_길드NPC", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("이미지_길드NPC", getMemDC(), 600, 470);

			HFONT font, oldfont;
			SetBkMode(getMemDC(), TRANSPARENT);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "가스톤", lstrlen("가스톤"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TCHAR strrr[128];
			wsprintf(strrr, "「 얼른 마을 밖으로 나가, 몬스터를 처치한 후에,");
			TextOut(getMemDC(), 48, WINSIZEY - 225, strrr, lstrlen(strrr));
			wsprintf(strrr, "　아이들을 찾아줘. 보수는 섭섭치 않게 주겠어. 」");
			TextOut(getMemDC(), 48, WINSIZEY - 195, strrr, lstrlen(strrr));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (activeTime > 450)
		{
			town_active = true;
		}
	}//퀘스트를 완료했을 때.
	
	
	//활
	//내용추가 & 액티브타임구현
	//else if (!isFirst && quest1_complete)
	if (!isFirst && quest1_complete && !isSecond)		//활-두번째 퀘스트 false일때
	{
		activeTime++;

		IMAGE->findImage("길드맵")->render(getMemDC(), 0, 0);
		IMAGE->findImage("길드맵_NPC")->render(getMemDC(), 525, 225);
		IMAGE->findImage("길드맵_책상앞부분")->render(getMemDC(), 535, 308);
		IMAGE->findImage("길드맵_플레이어")->render(getMemDC(), 605, 328);

		HFONT font, oldfont;
		SetBkMode(getMemDC(), TRANSPARENT);

		if (activeTime > 30 && activeTime < 240)
		{

			IMAGE->render("대화_상인", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("대화_상인2", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("이미지_길드NPC", getMemDC(), 630, 470);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			TextOut(getMemDC(), 50, WINSIZEY - 260, "가스톤", lstrlen("가스톤"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(250, 244, 192));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "가스톤", lstrlen("가스톤"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 225, "「 첫 번째 임무를 성공적으로 수행했군.", lstrlen("「 첫 번째 임무를 성공적으로 수행했군."));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(22, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 180, "　자, 여기, 완료 보상 1000G다. 」", lstrlen("　자, 여기, 완료 보상 1000G다. 」"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (activeTime >= 240 && activeTime < 370)
		{
			IMAGE->render("대화_상인", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("대화_상인2", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("이미지_길드NPC", getMemDC(), 630, 470);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			TextOut(getMemDC(), 50, WINSIZEY - 260, "가스톤", lstrlen("가스톤"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(250, 244, 192));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "가스톤", lstrlen("가스톤"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(22, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 225, "「 날이 밝으면 다시 와줘. 새로운 업무를 맡기도록 하지. 」", lstrlen("「 날이 밝으면 다시 와줘. 새로운 업무를 맡기도록 하지. 」"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

		}

		if (activeTime >= 370)
		{
			town_active = true;
			SOUND->stop("bgm02");
			
			//활 - 두번째 퀘스트 활성화
			//if (activeTime >= 380) { isSecond = true; }		
			isSecond = true;
			//townNight_active = true;
		}
	}


	if (isSecond)
	{
		activeTime++;

		if (activeTime > 30 && activeTime <= 400)
		{

			IMAGE->render("대화테두리_길드NPC", getMemDC(), 0, 10);
			IMAGE->alphaRender("대화창_길드NPC", getMemDC(), 0, 10, 170);
			IMAGE->render("이미지_길드NPC", getMemDC(), 10, 12);

			HFONT font, oldfont;
			SetBkMode(getMemDC(), TRANSPARENT);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 380, 55, "가스톤", lstrlen("가스톤"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(28, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TCHAR strrr[128];
			wsprintf(strrr, "「 여어, 기다리고 있었지.");
			TextOut(getMemDC(), 385, 90, strrr, lstrlen(strrr));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(20, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 385, 130, "　듣자하니 이번 업무는 난이도가 꽤 있던데, 괜찮겠어? 」", lstrlen("　듣자하니 이번 업무는 난이도가 꽤 있던데, 괜찮겠어? 」"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (activeTime >= 250 && activeTime <= 790)
		{
			IMAGE->render("대화테두리_길드Player", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("대화창_길드Player", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("이미지_길드Player_놀람", getMemDC(), 600, 470);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "알", lstrlen("알"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 225, "「 뭔데요? 」", lstrlen("「 뭔데요? 」"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (activeTime > 400)
		{
			IMAGE->render("대화테두리_길드NPC", getMemDC(), 0, 10);
			IMAGE->alphaRender("대화창_길드NPC", getMemDC(), 0, 10, 170);
			IMAGE->render("이미지_길드NPC", getMemDC(), 10, 12);

			HFONT font, oldfont;
			SetBkMode(getMemDC(), TRANSPARENT);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 380, 55, "가스톤", lstrlen("가스톤"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(18, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TCHAR strrr[128];
			wsprintf(strrr, "「 최근, 마을 뒷편의 달동산에, 악마의 사제 '알비온'이 나타났어. ");
			TextOut(getMemDC(), 385, 90, strrr, lstrlen(strrr));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(18, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 385, 120, "　이 녀석을 물리치고, 마을의 평화를 되찾는게 이번 임무야. 」", lstrlen("　이 녀석을 물리치고, 마을의 평화를 되찾는게 이번 임무야. 」"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (activeTime >= 800)
		{
			IMAGE->render("대화테두리_길드Player", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("대화창_길드Player", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("이미지_길드Player_놀람", getMemDC(), 600, 470);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "알", lstrlen("알"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 225, "「 알았어요. 」", lstrlen("「 알았어요. 」"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (activeTime >= 900)
		{
			town_active = true;
		}
	}



	TCHAR str[100];
	wsprintf(str, "activeTime(no)_guild : %d", _activeTime);
	TextOut(getMemDC(), 0, 0, str, lstrlen(str));

}

void Guild::shadowDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(051, 051, 051));
	RECT shadow = RectMake(rc.left + 3, rc.top + 3, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), shadow.left, shadow.top, shadow.right, shadow.bottom);
	FillRect(getMemDC(), &shadow, brush);
	DeleteObject(brush);
}

void Guild::lightDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	RECT light = RectMake(rc.left - 1, rc.top - 1, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
	FillRect(getMemDC(), &light, brush);
	DeleteObject(brush);
}

void Guild::grayDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(204, 204, 204));
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	FillRect(getMemDC(), &rc, brush);
	DeleteObject(brush);
}
