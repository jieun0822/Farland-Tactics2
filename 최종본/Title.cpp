#include "framework.h"
#include "Title.h"

HRESULT Title::init()
{
	//SOUND->addSound("bgm05", "sound/bgm05.mp3", false, false);
	SOUND->addSound("bgm05", "sound/bgm05.mp3", true, false);
	for (int i = 0; i < 2; i++)
	{
		rc_btn[i] = RectMake(200, 550 + 60 * i, 185, 48);
	}

	IMAGE->addImage("title_btn_white", "images/menu_bg.bmp", rc_btn[0].right - rc_btn[0].left, rc_btn[0].bottom - rc_btn[0].top, false, RGB(255, 0, 255));
	IMAGE->addImage("title_btn_black", "images/shadow.bmp", rc_btn[0].right - rc_btn[0].left, rc_btn[0].bottom - rc_btn[0].top, false, RGB(255, 0, 255));
	IMAGE->addImage("title", "images/title.bmp", WINSIZEX, WINSIZEY);

	intro_active = false;

	return S_OK;
}

void Title::release()
{
}

void Title::update()
{


	if (InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&rc_btn[0], m_ptMouse))
		{
	
			//로드 팝업창 출력
			if (MessageBox(m_hWnd, "새 게임을 시작 하시겠습니까?", "Game Start", MB_YESNO) == IDYES)
			{
				SOUND->stop("bgm05");
				intro_active = true;
				//SOUND->loadScene("마을");
			}
		}

		else if (PtInRect(&rc_btn[1], m_ptMouse))
		{
			
			//종료 팝업창 출력
			if (MessageBox(m_hWnd, "게임을 종료 하시겠습니까?", "Quit", MB_YESNO) == IDYES)
			{
				
				PostMessage(m_hWnd, WM_DESTROY, 0, 0);
			}
		}
	}
}

void Title::render()
{
	if (!SOUND->isPlaySound("bgm05"))
	{
		SOUND->play("bgm05");
	}


	IMAGE->findImage("title")->render(getMemDC(), 0, 0);


	//버튼 출력
	for (int i = 0; i < 2; i++)
	{
		IMAGE->findImage("title_btn_white")->alphaRender(getMemDC(), rc_btn[i].left, rc_btn[i].top, 128);
		FrameRect(getMemDC(), rc_btn[i], RGB(0, 200, 200));
	}

	textOutFont(getMemDC(), rc_btn[0].left + 10, rc_btn[0].top + 8, "GAME START", 30);
	textOutFont(getMemDC(), rc_btn[1].left + 55, rc_btn[1].top + 8, "QUIT", 30);

	for (int i = 0; i < 5; i++)
	{
		if (PtInRect(&rc_btn[i], m_ptMouse))
		{
			IMAGE->findImage("title_btn_black")->alphaRender(getMemDC(), rc_btn[i].left, rc_btn[i].top, 220);
		}
		FrameRect(getMemDC(), rc_btn[i], RGB(200, 200, 200));
	}

	if (PtInRect(&rc_btn[0], m_ptMouse))
	{
		textOutFont(getMemDC(), rc_btn[0].left + 6, rc_btn[0].top + 8, "GAME START", 31, RGB(180, 180, 180));
	}
	else if (PtInRect(&rc_btn[1], m_ptMouse))
	{
		textOutFont(getMemDC(), rc_btn[1].left + 52, rc_btn[1].top + 8, "QUIT", 31, RGB(180, 180, 180));
	}
}

Title::Title()
{
}

Title::~Title()
{
}

void Title::textOutFont(HDC hdc, int x, int y, const char* str, int size, COLORREF color, const char* font)
{
	SetBkMode(hdc, 1);
	SetTextColor(hdc, color);

	HFONT hFont, oldFont;
	//(높이, 폭, 엥글, 한글자엥글(안됨), 두께(안됨), ?, ?, ?, 문자셋, 출력정확도, 클리핑정확도, ?, 폰트피치와그룹, 글꼴이름)
	hFont = CreateFont(size, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT(font));
	oldFont = (HFONT)SelectObject(hdc, hFont);
	TextOut(hdc, x, y, str, strlen(str));

	//복귀
	SetBkMode(hdc, 2);
	SetTextColor(hdc, RGB(0, 0, 0));
	SelectObject(hdc, oldFont);
	DeleteObject(hFont);
}