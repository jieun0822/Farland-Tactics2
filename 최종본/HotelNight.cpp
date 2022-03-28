#include "framework.h"
#include "HotelNight.h"

HotelNight::HotelNight()
{
}

HotelNight::~HotelNight()
{
}

HRESULT HotelNight::init()
{

	// IMAGE->addImage("ȣ��_��", "images/hotel.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
	IMAGE->addImage("ȣ��_��", "images/st14a.bmp", WINSIZEX - 5, WINSIZEY, false, RGB(0, 0, 0));
	IMAGE->addImage("ȣ��_��ο��", "images/dark.bmp", WINSIZEX - 5, WINSIZEY - 20, false, RGB(0, 0, 0));
	_R = IMAGE->addFrameImage("��", "images/R_walk2.bmp", 378, 100, 5, 1, true, RGB(255, 0, 255)); // 252*67
	IMAGE->addImage("��_����", "images/R_lie3.bmp", 144, 100, true, RGB(0, 255, 255));

	//�� ��ǥ (�ȱ�)
	_x = 370;
	_y = 220;

	//Ȯ��â
	confirmWindow = RectMake(370, 280, 280, 120);
	confirmWin_name = RectMake(confirmWindow.left + 2, confirmWindow.top + 2, 276, 30);
	confirmWin_yesButton = RectMake(confirmWindow.left + 15, confirmWindow.bottom - 43, 110, 30);
	confirmWin_noButton = RectMake(confirmWindow.left + 155, confirmWindow.bottom - 43, 110, 30);

	isCheck_yes = false;
	isCheck_no = false;

	m_time = 0;

	return S_OK;
}

void HotelNight::release()
{
}

void HotelNight::update()
{

	//�� �ȱ�
	m_time++;
	if (m_time > 0 && m_time <= 110)
	{
		//������ �����̱�
		m_count++;
		_R->setFrameY(1);

		if (m_count % 10 == 0)
		{
			m_count = 0;
			m_index--;
			if (m_index < _R->getMaxFrameY())
			{
				m_index = 3;
			}
			_R->setFrameX(m_index);
		}

		_x += 2.2;
		_y += 1.0;
	}

	if (m_time > 110)
	{
		IMAGE->deleteImage("��");

	}

	//Ȯ��â yes & no
	if (m_time > 130)
	{
		if (InputManager->isOnceKeyUp(VK_LBUTTON))
		{
			if (PtInRect(&confirmWin_yesButton, m_ptMouse))
			{
				isCheck_yes = true;
			}

			if (PtInRect(&confirmWin_noButton, m_ptMouse))
			{
				isCheck_no = true;
			}
		}
	}

	if (isCheck_yes) 
	{
		//SCENE->changeScene("townMap"); 
		town_active = true;
	}
	if (isCheck_no) 
	{
		SCENE->changeScene("townMapNight"); 
		townNight_active = true;
	}

}

void HotelNight::render()
{
	IMAGE->render("ȣ��_��", getMemDC(), 0, -30);
	IMAGE->frameRender("��", getMemDC(), _x, _y);

	if (m_time > 111)
	{
		IMAGE->render("��_����", getMemDC(), 700, 360);
	}

	if (m_time > 130)
	{
		IMAGE->alphaRender("ȣ��_��ο��", getMemDC(), 100);

		HBRUSH brush;
		SetBkMode(getMemDC(), TRANSPARENT);

		grayDraw(confirmWindow);

		brush = CreateSolidBrush(RGB(0, 0, 204));
		Rectangle(getMemDC(), confirmWin_name.left, confirmWin_name.top, confirmWin_name.right, confirmWin_name.bottom);
		FillRect(getMemDC(), &confirmWin_name, brush);
		DeleteObject(brush);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), confirmWin_name.left + 3, confirmWin_name.top + 6, "Ȯ��", lstrlen("Ȯ��"));
		SetTextColor(getMemDC(), RGB(0, 0, 0));

		TextOut(getMemDC(), confirmWin_name.left + 75, confirmWin_name.top + 45, "�ϰ��� �����մϱ�?", lstrlen("�ϰ��� �����մϱ�?"));

		lightDraw(confirmWin_yesButton);
		shadowDraw(confirmWin_yesButton);
		grayDraw(confirmWin_yesButton);
		TextOut(getMemDC(), confirmWin_yesButton.left + 45, confirmWin_yesButton.top + 7, "��", lstrlen("��"));

		lightDraw(confirmWin_noButton);
		shadowDraw(confirmWin_noButton);
		grayDraw(confirmWin_noButton);
		TextOut(getMemDC(), confirmWin_noButton.left + 30, confirmWin_noButton.top + 7, "�ƴϿ�", lstrlen("�ƴϿ�"));
	}
}

void HotelNight::shadowDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(051, 051, 051));
	RECT shadow = RectMake(rc.left + 3, rc.top + 3, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), shadow.left, shadow.top, shadow.right, shadow.bottom);
	FillRect(getMemDC(), &shadow, brush);
	DeleteObject(brush);
}

void HotelNight::lightDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	RECT light = RectMake(rc.left - 1, rc.top - 1, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
	FillRect(getMemDC(), &light, brush);
	DeleteObject(brush);
}

void HotelNight::grayDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(204, 204, 204));
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	FillRect(getMemDC(), &rc, brush);
	DeleteObject(brush);
}
