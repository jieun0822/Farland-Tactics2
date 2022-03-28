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
	
			//�ε� �˾�â ���
			if (MessageBox(m_hWnd, "�� ������ ���� �Ͻðڽ��ϱ�?", "Game Start", MB_YESNO) == IDYES)
			{
				SOUND->stop("bgm05");
				intro_active = true;
				//SOUND->loadScene("����");
			}
		}

		else if (PtInRect(&rc_btn[1], m_ptMouse))
		{
			
			//���� �˾�â ���
			if (MessageBox(m_hWnd, "������ ���� �Ͻðڽ��ϱ�?", "Quit", MB_YESNO) == IDYES)
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


	//��ư ���
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
	//(����, ��, ����, �ѱ��ڿ���(�ȵ�), �β�(�ȵ�), ?, ?, ?, ���ڼ�, �����Ȯ��, Ŭ������Ȯ��, ?, ��Ʈ��ġ�ͱ׷�, �۲��̸�)
	hFont = CreateFont(size, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT(font));
	oldFont = (HFONT)SelectObject(hdc, hFont);
	TextOut(hdc, x, y, str, strlen(str));

	//����
	SetBkMode(hdc, 2);
	SetTextColor(hdc, RGB(0, 0, 0));
	SelectObject(hdc, oldFont);
	DeleteObject(hFont);
}