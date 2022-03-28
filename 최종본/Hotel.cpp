#include "framework.h"
#include "Hotel.h"

Hotel::Hotel()
{
}

Hotel::~Hotel()
{
}

HRESULT Hotel::init()
{
	//IMAGE->addImage("ȣ��", "images/st14a.bmp", WINSIZEX - 10, WINSIZEY - 30, false, RGB(0, 0, 0));
	IMAGE->addImage("ȣ��", "images/st27a.bmp", WINSIZEX - 10, WINSIZEY - 30, false, RGB(0, 0, 0));
	_owner = IMAGE->addFrameImage("ȣ������", "images/npc_03.bmp", 230, 86, 4, 1, true, RGB(255, 0, 255));

	IMAGE->addImage("��ȭ_ȣ������", "images/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("��ȭ_ȣ������2", "images/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("�̹���_ȣ������", "images/face15a.bmp", 350, 260, true, RGB(255, 255, 255));

	activeTime = 0;

	return S_OK;
}

void Hotel::release()
{
}

void Hotel::update()
{
	if (activeTime > 50 && InputManager->isOnceKeyUp(VK_LBUTTON))
	{
		town_active = true;
		//SCENE->changeScene("townMap");
	}

	//������ �����̱�
	m_count++;
	_owner->setFrameY(1);

	if (m_count % 10 == 0)
	{
		m_count = 0;
		m_index--;
		if (m_index < _owner->getMaxFrameY())
		{
			m_index = 5;
		}
		_owner->setFrameX(m_index);
	}

}

void Hotel::render()
{
	IMAGE->render("ȣ��", getMemDC());
	IMAGE->frameRender("ȣ������", getMemDC(), 320, 250);

	activeTime++;

	if (activeTime >= 45)
	{
		IMAGE->render("��ȭ_ȣ������", getMemDC(), 0, WINSIZEY - 300);
		IMAGE->alphaRender("��ȭ_ȣ������2", getMemDC(), 0, WINSIZEY - 301, 170);
		IMAGE->render("�̹���_ȣ������", getMemDC(), 625, 460);

		HFONT font, oldfont;
		SetBkMode(getMemDC(), TRANSPARENT);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 50, WINSIZEY - 260, "������", lstrlen("������"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 48, WINSIZEY - 260, "������", lstrlen("������"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(28, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 50, WINSIZEY - 225, "�� ���ú��� ��������! �й��ؾ���. ��", lstrlen("�� ���ú��� ��������! �й��ؾ���. ��"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	}


}
