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
	SOUND->addSound("�п�", "sound/bgm13.mp3", true, false);


	IMAGE->addImage("��ī����_���ȭ��", "images/��ī����/st13a.bmp", WINSIZEX - 10, WINSIZEY - 30, false, RGB(0, 0, 0));

	IMAGE->addImage("conversation_con_up", "images/��ī����/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("conversation_wnd_up", "images/��ī����/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("conversation_con_down", "images/��ī����/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("conversation_wnd_down", "images/��ī����/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));

	IMAGE->addImage("face01b", "images/��ī����/face01b.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face03c", "images/��ī����/face03c.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face03m", "images/��ī����/face03m.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face07c", "images/��ī����/face07c.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face10a", "images/��ī����/face10a.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("face11e", "images/��ī����/face11e.bmp", 360, 250, true, RGB(255, 255, 255));

	IMAGE->addImage("��ī����_�����", "images/��ī����/��ī����_�����.bmp", 57 + 20, 66 + 20, true, RGB(255, 0, 255));
	IMAGE->addImage("��ī����_����ȯ������", "images/��ī����/��ī����_����ȯ������.bmp", 55 + 20, 65 + 20, true, RGB(255, 0, 255));
	IMAGE->addImage("��ī����_������", "images/��ī����/��ī����_������.bmp", 44 + 20, 71 + 20, true, RGB(255, 0, 255));
	IMAGE->addImage("��ī����_������", "images/��ī����/��ī����_������.bmp", 55 + 20, 57 + 20, true, RGB(0, 255, 255));
	IMAGE->addImage("��ī����_ȫ����", "images/��ī����/��ī����_ȫ����.bmp", 44 + 20, 69 + 20, true, RGB(255, 0, 255));

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

	IMAGE->render("��ī����_���ȭ��", getMemDC());
	IMAGE->render("��ī����_�����", getMemDC(), 400, 300);
	IMAGE->render("��ī����_����ȯ������", getMemDC(), 550, 320);
	IMAGE->render("��ī����_������", getMemDC(), 370, 390);
	IMAGE->render("��ī����_������", getMemDC(), 440, 490);
	IMAGE->render("��ī����_ȫ����", getMemDC(), 570, 430);

	TCHAR str[20];
	//SetBkMode(getMemDC(), OPAQUE);
	//wsprintf(str, "activeTime : %d", activeTime);
	//TextOut(getMemDC(), 200, 400, str, lstrlen(str));
	SetBkMode(getMemDC(), TRANSPARENT);

	//up conversation.
	//����ȯ ������.
	if (activeTime >= 20 && activeTime < 180)
	{
		IMAGE->render("conversation_wnd_up", getMemDC(), 0, 10);
		IMAGE->alphaRender("conversation_con_up", getMemDC(), 0, 10, 170);
		IMAGE->render("face11e", getMemDC(), 10, 12);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 380, 55, "����ȯ ������", lstrlen("����ȯ ������"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 380 - 2, 55, "����ȯ ������", lstrlen("����ȯ ������"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(28, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 385, 90, "�� 9�ô�. �ٵ� �⼮üũ �ؾ���? ��", lstrlen("�� 9�ô�. �ٵ� �⼮üũ �ؾ���? ��"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}
	//������.
	else if (activeTime >= 180 && activeTime < 280)
	{
		IMAGE->render("conversation_wnd_up", getMemDC(), 0, 10);
		IMAGE->alphaRender("conversation_con_up", getMemDC(), 0, 10, 170);
		IMAGE->render("face01b", getMemDC(), 10, 12);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 380, 55, "������", lstrlen("������"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 380 - 2, 55, "������", lstrlen("������"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 385, 90, "�� ��, �����̴�~!! ��", lstrlen("�� ��, �����̴�~!! ��"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}
	//������.
	else if (activeTime >= 400 && activeTime < 700)
	{
		IMAGE->render("conversation_wnd_up", getMemDC(), 0, 10);
		IMAGE->alphaRender("conversation_con_up", getMemDC(), 0, 10, 170);
		IMAGE->render("face10a", getMemDC(), 10, 12);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 380, 55, "������", lstrlen("������"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 380 - 2, 55, "������", lstrlen("������"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 385, 90, "�� ���ӳø� ���? ��", lstrlen("�� ���ӳø� ���? ��"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}

	//down conversation.
	//�����.
	if (activeTime >= 100 && activeTime < 180)
	{
		IMAGE->render("conversation_wnd_down", getMemDC(), 0, WINSIZEY - 300);
		IMAGE->alphaRender("conversation_con_down", getMemDC(), 0, WINSIZEY - 301, 170);
		IMAGE->render("face07c", getMemDC(), 600, 470);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 50, WINSIZEY - 260, "�����", lstrlen("�����"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 48, WINSIZEY - 260, "�����", lstrlen("�����"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 50, WINSIZEY - 225, "�� ��~!! ��", lstrlen("�� ��~!! ��"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}
	//ȫ����_1.
	else if (activeTime >= 280 && activeTime < 500)
	{
		IMAGE->render("conversation_wnd_down", getMemDC(), 0, WINSIZEY - 300);
		IMAGE->alphaRender("conversation_con_down", getMemDC(), 0, WINSIZEY - 301, 170);
		IMAGE->render("face03m", getMemDC(), 600, 470);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 50, WINSIZEY - 260, "ȫ����", lstrlen("ȫ����"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 48, WINSIZEY - 260, "ȫ����", lstrlen("ȫ����"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 50, WINSIZEY - 225, "�� �̵� ���� �� ����... ��", lstrlen("�� �̵� ���� �� ����... ��"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}
	//ȫ����_2.
	else if (activeTime >= 500 && activeTime < 700)
	{
		IMAGE->render("conversation_wnd_down", getMemDC(), 0, WINSIZEY - 300);
		IMAGE->alphaRender("conversation_con_down", getMemDC(), 0, WINSIZEY - 301, 170);
		IMAGE->render("face03c", getMemDC(), 600, 470);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 50, WINSIZEY - 260, "ȫ����", lstrlen("ȫ����"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 48, WINSIZEY - 260, "ȫ����", lstrlen("ȫ����"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 50, WINSIZEY - 225, "�� ���ƿ�!! ��", lstrlen("�� ���ƿ�!! ��"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}

	if (activeTime >= 700)
	{
		town_active = true;

		SOUND->stop("�п�");
	}
}
