#include "framework.h"
#include "equipStore.h"
#define ITEMMAX 8

equipStore::equipStore()
{
}

equipStore::~equipStore()
{
}

HRESULT equipStore::init()
{
	IMAGE->addImage("equipStore", "images/st04a.bmp", WINSIZEX - 10, WINSIZEY - 30, false, RGB(0, 0, 0));
	IMAGE->addFrameImage("����", "images/npc_02.bmp", 589, 120, 7, 1, true, RGB(255, 0, 255));

	////��������,�÷��̾� �Ϸ���Ʈ
	IMAGE->addImage("�̹���_�������", "images/face16b.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("�̹���_�÷��̾�2", "images/face02b.bmp", 360, 250, true, RGB(255, 255, 255));

	//������ʱ�ȭ
	_unitListEx = new UnitList;
	_unitListEx->init();


	//â ����
	_equipWindow = new EquipWindow;
	_equipWindow->outLine = RectMake(270, 120, 500, 500);
	_equipWindow->isClosed = false;
	//_equipWindow->isBuyButton = false;
	_equipWindow->warning = RectMake(_equipWindow->outLine.right / 2, _equipWindow->outLine.bottom / 2, 150, 100);//����� ���â

	int outlineWidth = _equipWindow->outLine.right - _equipWindow->outLine.left;
	int outlintHeight = _equipWindow->outLine.bottom - _equipWindow->outLine.top;

	//â ����
	_equipWindow->windowName = RectMake(_equipWindow->outLine.left + 3, _equipWindow->outLine.top + 3, outlineWidth - 6, 30 - 6);

	//�޴� ����
	_equipWindow->equipMenu = RectMake(_equipWindow->outLine.left + 3, _equipWindow->outLine.top + 32, outlineWidth - 6, 30);

	//������ ����Ʈ
	_equipWindow->equipList = RectMake(_equipWindow->outLine.left + 3, _equipWindow->outLine.top + 70, outlineWidth - 6, 270);

	int equipListWidth = _equipWindow->equipList.right - _equipWindow->equipList.left;
	int equipListHeight = _equipWindow->equipList.bottom - _equipWindow->equipList.top;

	//������ �����
	_equipWindow->descriptionBox = RectMake(_equipWindow->outLine.left + 5, _equipWindow->outLine.top + 350, outlineWidth - 220, 140);

	//������ ǥ��â
	_equipWindow->goldBox = RectMake(_equipWindow->descriptionBox.right + 8, _equipWindow->descriptionBox.top, outlineWidth - 300, 27);

	int goldBoxWidth = _equipWindow->goldBox.right - _equipWindow->goldBox.left;
	int goldBoxHeight = _equipWindow->goldBox.bottom - _equipWindow->goldBox.top;

	//��ư
	//���� ��ư
	_equipWindow->buyButton = RectMake(_equipWindow->goldBox.left, _equipWindow->goldBox.bottom + 5, goldBoxWidth, goldBoxHeight);

	//����Ʈ �϶�
	_equipWindow->unitButton = RectMake(_equipWindow->goldBox.left, _equipWindow->buyButton.bottom + 10, goldBoxWidth, goldBoxHeight);

	//�ݱ�
	_equipWindow->closeButton = RectMake(_equipWindow->goldBox.left, _equipWindow->unitButton.bottom + 10, goldBoxWidth, goldBoxHeight);


	//������ ���� �ڽ�
	_equipWindow->itemSelect[0] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 2, equipListWidth - 2, 30);
	_equipWindow->itemSelect[1] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 32, equipListWidth - 2, 30);
	_equipWindow->itemSelect[2] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 62, equipListWidth - 2, 30);
	_equipWindow->itemSelect[3] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 92, equipListWidth - 2, 30);
	_equipWindow->itemSelect[4] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 122, equipListWidth - 2, 30);
	_equipWindow->itemSelect[5] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 152, equipListWidth - 2, 30);
	_equipWindow->itemSelect[6] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 182, equipListWidth - 2, 30);
	_equipWindow->itemSelect[7] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 212, equipListWidth - 2, 30);

	//������ �߰� (����)
	///����
	tagEquipInfo* equip = new tagEquipInfo;

	equip = new tagEquipInfo;
	equip->name = "��ε�ҵ�";
	equip->detail = "���� ���� ��. \n�ռҵ庸�� ���� �� ���ϴ�. \n���ݷ� + 10";
	equip->money = 150;
	equip->kind = EQUIP_KIND::WEAPON;
	equip->num = 0;
	equip->iconImg = IMAGE->addImage("����", "images/sword.bmp", 19, 19, true, RGB(128, 0, 128));
	equip->offensePower = 10;
	equip->defense = 0;
	equip->intellect = 0;
	equip->magicDrag = 0;
	equip->agility = 0;
	_vEquip.push_back(equip);

	equip = new tagEquipInfo;
	equip->name = "ũ���̸��";
	equip->detail = "�Ѽ����ε� ������ε� \n��� ������ ��. \n������ ���Ƽ�, �ʽ��ڰ� �ٷ�⿡�� \n������ �ִ�. \n���ݷ� + 20";
	equip->kind = EQUIP_KIND::WEAPON;
	equip->money = 300;
	equip->num = 0;
	equip->offensePower = 20;
	equip->defense = 0;
	equip->intellect = 0;
	equip->magicDrag = 0;
	equip->agility = -4;
	_vEquip.push_back(equip);

	equip = new tagEquipInfo;
	equip->name = "�׷���Ʈ�ҵ�";
	equip->detail = "��հ� �߿��� ���� �������� ���Ǿ���. \n�������� �����ϴ�. \n���ݷ� + 45";
	equip->kind = EQUIP_KIND::WEAPON;
	equip->money = 670;
	equip->num = 0;
	equip->offensePower = 45;
	equip->defense = 0;
	equip->intellect = 0;
	equip->magicDrag = 0;
	equip->agility = -7;
	_vEquip.push_back(equip);

	equip = new tagEquipInfo;
	equip->name = "�ö�����";
	equip->detail = "���õ� �������̰� ������ ��￩ \n������ٰ� �������� \n������ ���. \n���ݷ� + 50";
	equip->kind = EQUIP_KIND::WEAPON;
	equip->money = 1000;
	equip->num = 0;
	equip->offensePower = 50;
	equip->defense = 0;
	equip->intellect = 0;
	equip->magicDrag = 0;
	equip->agility = -5;
	_vEquip.push_back(equip);

	/// ��
	equip = new tagEquipInfo;
	equip->name = "���� ��������";
	equip->detail = "���뼺�� ���� ���밨�� \n������ ���װ���. \n������ ���� ������, \nū ���� ���� �ʴ� ���� ����. \n���� +8";
	equip->kind = EQUIP_KIND::ARMOR;
	equip->money = 90;
	equip->num = 0;
	equip->iconImg = IMAGE->addImage("��", "images/armor.bmp", 19, 19, true, RGB(128, 0, 128));
	equip->offensePower = 0;
	equip->defense = 8;
	equip->intellect = 0;
	equip->magicDrag = 0;
	equip->agility = -1;
	_vEquip.push_back(equip);

	equip = new tagEquipInfo;
	equip->name = "������";
	equip->detail = "�ݼ��� �Ƹ��� ǥ�鿡, �޼Ҹ� \n��ȣ���ִ� ���� ������ ��. \n���� +20, ���׷� +2";
	equip->kind = EQUIP_KIND::ARMOR;
	equip->money = 210;
	equip->num = 0;
	equip->offensePower = 0;
	equip->defense = 20;
	equip->intellect = 0;
	equip->magicDrag = 2;
	equip->agility = -4;
	_vEquip.push_back(equip);

	equip = new tagEquipInfo;
	equip->name = "������Ʈ�Ƹ�";
	equip->detail = "�پ��� ���縦 ����Ͽ� \n���� ������ ����Ų ����. \n�ټ��� �������δ� ��½�� ���� �ʴ´�. ���� +32, ���׷� +5";
	equip->kind = EQUIP_KIND::ARMOR;
	equip->money = 500;
	equip->num = 0;
	equip->offensePower = 500;
	equip->defense = 32;
	equip->intellect = 0;
	equip->magicDrag = 5;
	equip->agility = -5;
	_vEquip.push_back(equip);

	equip = new tagEquipInfo;
	equip->name = "�巡�����Ʈ";
	equip->detail = "������ ������ ���۵Ǿ���. \n��Ҽ��� ū �����̹Ƿ�, �̰��� ������ ��ô ���� ���. \n���� +45, ���׷� +10";
	equip->kind = EQUIP_KIND::ARMOR;
	equip->money = 800;
	equip->num = 0;
	equip->offensePower = 0;
	equip->defense = 45;
	equip->intellect = 0;
	equip->magicDrag = 10;
	equip->agility = -8;
	_vEquip.push_back(equip);

	//�̹���
	IMAGE->addImage("���_�޴�", "images/itemWindow_basic.bmp", _equipWindow->equipMenu.right - _equipWindow->equipMenu.left,
		_equipWindow->equipMenu.bottom - _equipWindow->equipMenu.top, true, RGB(255, 0, 255));
	IMAGE->addImage("���_������", "images/itemWindow_list.bmp", _equipWindow->equipList.right - _equipWindow->equipList.left,
		_equipWindow->equipList.bottom - _equipWindow->equipList.top, true, RGB(255, 0, 255));

	for (int i = 0; i < 7; i++)
	{
		IMAGE->addImage("���_Ŭ��", "images/backGround_blue.bmp", _equipWindow->itemSelect[i].right - _equipWindow->itemSelect[i].left,
			_equipWindow->itemSelect[i].bottom - _equipWindow->itemSelect[i].top, true, RGB(255, 0, 255));
	}

	activeTime = 0;
	_activeTime = 0;
	__activeTime = 0;

	isOpen = false;

	town_active = false;
	equipStore_active = false;
	unitList_active = false;

	_click = CLICKE::NONE;
	_equipWindow->buyEquip_num = 1;

	return S_OK;
}

void equipStore::release()
{
	//SAFE_DELETE(_equipWindow);
}

void equipStore::update()
{
	if (activeTime > 90 && !(unitList_active))
	{
		if (InputManager->isOnceKeyUp(VK_LBUTTON))
		{
			isOpen = true;

			//���ƿ���
			if (PtInRect(&_equipWindow->closeButton, m_ptMouse) && isOpen)
			{
				isOpen = !isOpen;
				_equipWindow->isClosed = true;
			}

			//�����϶�
			if (PtInRect(&_equipWindow->unitButton, m_ptMouse))
			{
				unitList_active = true;
			}

			if (PtInRect(&_equipWindow->buyButton, m_ptMouse))
			{
				BuyEquip();
			}

			//��������
			if (isOpen && !(_equipWindow->isClosed))
			{
				//������ ���� ��
				if (PtInRect(&_equipWindow->itemSelect[0], m_ptMouse)) { _click = CLICKE::SELECT; }
				if (PtInRect(&_equipWindow->itemSelect[1], m_ptMouse)) { _click = CLICKE::SELECT1; }
				if (PtInRect(&_equipWindow->itemSelect[2], m_ptMouse)) { _click = CLICKE::SELECT2; }
				if (PtInRect(&_equipWindow->itemSelect[3], m_ptMouse)) { _click = CLICKE::SELECT3; }
				if (PtInRect(&_equipWindow->itemSelect[4], m_ptMouse)) { _click = CLICKE::SELECT4; }
				if (PtInRect(&_equipWindow->itemSelect[5], m_ptMouse)) { _click = CLICKE::SELECT5; }
				if (PtInRect(&_equipWindow->itemSelect[6], m_ptMouse)) { _click = CLICKE::SELECT6; }
				if (PtInRect(&_equipWindow->itemSelect[7], m_ptMouse)) { _click = CLICKE::SELECT7; }
			}
		}
	}
}

void equipStore::render()
{
	IMAGE->render("equipStore", getMemDC());
	IMAGE->frameRender("����", getMemDC(), 285, 255);

	HFONT font, oldfont;
	SetBkMode(getMemDC(), TRANSPARENT);

	
	activeTime++;
	if (activeTime >= 30 && !(_equipWindow->isClosed))
	{
		IMAGE->render("��ȭ_����", getMemDC(), 0, 10);
		IMAGE->alphaRender("��ȭ_����2", getMemDC(), 0, 10, 170);
		IMAGE->render("�̹���_�������", getMemDC(), 15, 12);



		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 380, 55, "���� ������", lstrlen("���� ������"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 380, 55, "���� ������", lstrlen("���� ������"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(42, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 385, 90, "�� � ������.", lstrlen("�� � ������."));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(30, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 385, 150, "�������� ���Ⱑ �� �־��! ��", lstrlen("�������� ���Ⱑ �� �־��! ��"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);


		if (activeTime >= 80)
		{
			//��ǥ ����� ����
			IMAGE->render("��ȭ_�÷��̾�", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("��ȭ_�÷��̾�2", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("�̹���_�÷��̾�2", getMemDC(), 622, 450);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			TextOut(getMemDC(), 50, WINSIZEY - 260, "��", lstrlen("��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(250, 244, 192));
			TextOut(getMemDC(), 50, WINSIZEY - 260, "��", lstrlen("��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 225, "�� ����� ��ġ�� ��������. ��", lstrlen("�� ����� ��ġ�� ��������. ��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}
	}


	HBRUSH brush;
	HBRUSH oldBrush;
	HPEN hpen;
	HPEN hpenOld;

	if (isOpen && !(_equipWindow->isClosed))
	{
		//��ü â �׸���
		brush = CreateSolidBrush(RGB(204, 204, 204));
		Rectangle(getMemDC(), _equipWindow->outLine.left, _equipWindow->outLine.top, _equipWindow->outLine.right, _equipWindow->outLine.bottom);
		FillRect(getMemDC(), &_equipWindow->outLine, brush);
		DeleteObject(brush);

		//��ǰ��� â ����
		brush = CreateSolidBrush(RGB(0, 0, 153));
		Rectangle(getMemDC(), _equipWindow->windowName.left, _equipWindow->windowName.top, _equipWindow->windowName.right, _equipWindow->windowName.bottom);
		FillRect(getMemDC(), &_equipWindow->windowName, brush);
		DeleteObject(brush);

		//��ǰ��� â �ؽ�Ʈ
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TCHAR str[10];
		SetBkMode(getMemDC(), TRANSPARENT);
		wsprintf(str, "��ǰ���");
		TextOut(getMemDC(), _equipWindow->windowName.left + 5, _equipWindow->windowName.top + 5, str, lstrlen(str));
		SetTextColor(getMemDC(), RGB(0, 0, 0));

		//�޴� ���� â
		hpen = CreatePen(PS_SOLID, 1, RGB(111, 111, 111));
		hpenOld = (HPEN)::SelectObject(getMemDC(), (HGDIOBJ)hpen);
		brush = CreateSolidBrush(RGB(204, 204, 204));
		oldBrush = (HBRUSH)::SelectObject(getMemDC(), brush);
		Rectangle(getMemDC(), _equipWindow->descriptionBox.left, _equipWindow->descriptionBox.top, _equipWindow->descriptionBox.right, _equipWindow->descriptionBox.bottom);
		hpen = (HPEN)::SelectObject(getMemDC(), hpenOld);
		brush = (HBRUSH)::SelectObject(getMemDC(), oldBrush);
		DeleteObject(hpen);
		DeleteObject(brush);


		//��ư �׸���
		brush = CreateSolidBrush(RGB(93, 93, 93));
		//����
		RECT shadow = RectMake(_equipWindow->buyButton.left + 3, _equipWindow->buyButton.top + 3, _equipWindow->buyButton.right - _equipWindow->buyButton.left, _equipWindow->buyButton.bottom - _equipWindow->buyButton.top);
		Rectangle(getMemDC(), shadow.left, shadow.top, shadow.right, shadow.bottom);
		FillRect(getMemDC(), &shadow, brush);
		//����Ʈ �϶�
		RECT shadow2 = RectMake(_equipWindow->unitButton.left + 3, _equipWindow->unitButton.top + 3, _equipWindow->unitButton.right - _equipWindow->unitButton.left, _equipWindow->unitButton.bottom - _equipWindow->unitButton.top);
		Rectangle(getMemDC(), shadow2.left, shadow2.top, shadow2.right, shadow2.bottom);
		FillRect(getMemDC(), &shadow2, brush);
		//�ݱ�
		RECT shadow3 = RectMake(_equipWindow->closeButton.left + 3, _equipWindow->closeButton.top + 3, _equipWindow->closeButton.right - _equipWindow->closeButton.left, _equipWindow->closeButton.bottom - _equipWindow->closeButton.top);
		Rectangle(getMemDC(), shadow3.left, shadow3.top, shadow3.right, shadow3.bottom);
		FillRect(getMemDC(), &shadow3, brush);
		DeleteObject(brush);

		//��ư �׵θ�
		brush = CreateSolidBrush(RGB(255, 255, 255));
		//����
		RECT light = RectMake(_equipWindow->buyButton.left - 1, _equipWindow->buyButton.top - 1, _equipWindow->buyButton.right - _equipWindow->buyButton.left, _equipWindow->buyButton.bottom - _equipWindow->buyButton.top);
		Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
		FillRect(getMemDC(), &light, brush);
		//����Ʈ �϶�
		RECT light2 = RectMake(_equipWindow->unitButton.left - 1, _equipWindow->unitButton.top - 1, _equipWindow->unitButton.right - _equipWindow->unitButton.left, _equipWindow->unitButton.bottom - _equipWindow->unitButton.top);
		Rectangle(getMemDC(), light2.left, light2.top, light2.right, light2.bottom);
		FillRect(getMemDC(), &light2, brush);
		//�ݱ�
		RECT light3 = RectMake(_equipWindow->closeButton.left - 1, _equipWindow->closeButton.top - 1, _equipWindow->closeButton.right - _equipWindow->closeButton.left, _equipWindow->closeButton.bottom - _equipWindow->closeButton.top);
		Rectangle(getMemDC(), light3.left, light3.top, light3.right, light3.bottom);
		FillRect(getMemDC(), &light3, brush);
		DeleteObject(brush);

		//��ư ����
		//CreateWindow(TEXT("button"), TEXT("����"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, _equipWindow->description.right + 10, _equipWindow->description.top + 30, 195, 25, m_hWnd, (HMENU)0, m_hInstance, NULL);
		brush = CreateSolidBrush(RGB(204, 204, 204));
		//����
		Rectangle(getMemDC(), _equipWindow->buyButton.left, _equipWindow->buyButton.top, _equipWindow->buyButton.right, _equipWindow->buyButton.bottom);
		FillRect(getMemDC(), &_equipWindow->buyButton, brush);
		//����Ʈ �϶�
		Rectangle(getMemDC(), _equipWindow->unitButton.left, _equipWindow->unitButton.top, _equipWindow->unitButton.right, _equipWindow->unitButton.bottom);
		FillRect(getMemDC(), &_equipWindow->unitButton, brush);
		//�ݱ�
		Rectangle(getMemDC(), _equipWindow->closeButton.left, _equipWindow->closeButton.top, _equipWindow->closeButton.right, _equipWindow->closeButton.bottom);
		FillRect(getMemDC(), &_equipWindow->closeButton, brush);
		DeleteObject(brush);

		IMAGE->findImage("���_�޴�")->render(getMemDC(), _equipWindow->equipMenu.left, _equipWindow->equipMenu.top);
		IMAGE->findImage("���_������")->render(getMemDC(), _equipWindow->equipList.left, _equipWindow->equipList.top);

		//�޴� �ؽ�Ʈ
		TCHAR str1[10], str2[10];
		wsprintf(str1, "��Ī");
		wsprintf(str2, "����");
		TextOut(getMemDC(), _equipWindow->equipMenu.left + 55, _equipWindow->equipMenu.top + 10, str1, lstrlen(str1));
		TextOut(getMemDC(), _equipWindow->equipMenu.left + 300, _equipWindow->equipMenu.top + 10, str2, lstrlen(str2));
		SetTextColor(getMemDC(), RGB(0, 0, 0));

		//��ư �ؽ�Ʈ
		TextOut(getMemDC(), _equipWindow->buyButton.left + 85, _equipWindow->buyButton.top + 5, "����", lstrlen("����"));
		TextOut(getMemDC(), _equipWindow->unitButton.left + 60, _equipWindow->unitButton.top + 5, "����Ʈ �϶�", lstrlen("����Ʈ �϶�"));
		TextOut(getMemDC(), _equipWindow->closeButton.left + 70, _equipWindow->closeButton.top + 5, "���ƿ���", lstrlen("���ƿ���"));


		//�Ķ���� ����
		if (_click == CLICKE::SELECT) { IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _equipWindow->itemSelect[0].left, _equipWindow->itemSelect[0].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT1) { IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _equipWindow->itemSelect[1].left, _equipWindow->itemSelect[1].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT2) { IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _equipWindow->itemSelect[2].left, _equipWindow->itemSelect[2].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT3) { IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _equipWindow->itemSelect[3].left, _equipWindow->itemSelect[3].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT4) { IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _equipWindow->itemSelect[4].left, _equipWindow->itemSelect[4].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT5) { IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _equipWindow->itemSelect[5].left, _equipWindow->itemSelect[5].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT6) { IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _equipWindow->itemSelect[6].left, _equipWindow->itemSelect[6].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT7) { IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _equipWindow->itemSelect[7].left, _equipWindow->itemSelect[7].top); _click == CLICKE::NONE; }
		
		//������ ����
		for (int k = 0; k < 4; k++)
		{
			IMAGE->findImage("����")->render(getMemDC(), _equipWindow->itemSelect[k].left + 18, _equipWindow->itemSelect[k].top + 8);
		}
		for (int i = 4; i < 8; i++)
		{
			IMAGE->findImage("��")->render(getMemDC(), _equipWindow->itemSelect[i].left + 18, _equipWindow->itemSelect[i].top + 7);
		}

		//������ �ؽ�Ʈ
		for (int i = 0; i < ITEMMAX; i++)
		{
			TextOut(getMemDC(), _equipWindow->itemSelect[i].left + 50, _equipWindow->itemSelect[i].top + 10, _vEquip[i]->name.c_str(), lstrlen(_vEquip[i]->name.c_str()));
		 }
		//���� �ؽ�Ʈ
		for (int i = 0; i < ITEMMAX; i++)
		{
			TextOut(getMemDC(), _equipWindow->itemSelect[i].left + 300, _equipWindow->itemSelect[i].top + 10, to_string(_vEquip[i]->money).c_str(), lstrlen(to_string(_vEquip[i]->money).c_str()));
		}


		//����â �ؽ�Ʈ
		RECT temp_des = RectMake(_equipWindow->descriptionBox.left + 2, _equipWindow->descriptionBox.top + 2, _equipWindow->descriptionBox.right - _equipWindow->descriptionBox.left - 2, _equipWindow->descriptionBox.bottom - _equipWindow->descriptionBox.top - 2);
		if (_click == CLICKE::SELECT) { DrawText(getMemDC(), _vEquip[0]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT1) { DrawText(getMemDC(), _vEquip[1]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT2) { DrawText(getMemDC(), _vEquip[2]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT3) { DrawText(getMemDC(), _vEquip[3]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT4) { DrawText(getMemDC(), _vEquip[4]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT5) { DrawText(getMemDC(), _vEquip[5]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT6) { DrawText(getMemDC(), _vEquip[6]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT7) { DrawText(getMemDC(), _vEquip[7]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }

		
		//���â
		//brush = CreateSolidBrush(RGB(204, 204, 204));
		//Rectangle(getMemDC(), _equipWindow->warning.left, _equipWindow->warning.top, _equipWindow->warning.right, _equipWindow->warning.bottom);
		//FillRect(getMemDC(), &_equipWindow->warning, brush);
		//DeleteObject(brush);


		//_viBuyEquip = _vBuyEquip.begin();
		//for (_viBuyEquip; _viBuyEquip != _vBuyEquip.end(); ++_viBuyEquip)
		//{
		//	if ((*_viBuyEquip)->num >= 1)
		//	{
		//		//TextOut(getMemDC(), _equipWindow->itemSelect[0].left + 380, _equipWindow->itemSelect[0].top + 10, "����Ƚ�� �ʰ�", lstrlen("����Ƚ�� �ʰ�"));
		//
		//		//brush = CreateSolidBrush(RGB(204, 204, 204));
		//		//Rectangle(getMemDC(), _equipWindow->warning.left, _equipWindow->warning.top, _equipWindow->warning.right, _equipWindow->warning.bottom);
		//		//FillRect(getMemDC(), &_equipWindow->warning, brush);
		//		//DeleteObject(brush);
		//		if (_click == CLICKE::SELECT) TextOut(getMemDC(), _equipWindow->itemSelect[0].left + 380, _equipWindow->itemSelect[0].top + 10, "����Ƚ�� �ʰ�", lstrlen("����Ƚ�� �ʰ�"));
		//		if (_click == CLICKE::SELECT1) TextOut(getMemDC(), _equipWindow->itemSelect[1].left + 380, _equipWindow->itemSelect[1].top + 10, "����Ƚ�� �ʰ�", lstrlen("����Ƚ�� �ʰ�"));
		//		if (_click == CLICKE::SELECT2) TextOut(getMemDC(), _equipWindow->itemSelect[2].left + 380, _equipWindow->itemSelect[2].top + 10, "����Ƚ�� �ʰ�", lstrlen("����Ƚ�� �ʰ�"));
		//		if (_click == CLICKE::SELECT3) TextOut(getMemDC(), _equipWindow->itemSelect[3].left + 380, _equipWindow->itemSelect[3].top + 10, "����Ƚ�� �ʰ�", lstrlen("����Ƚ�� �ʰ�"));
		//		if (_click == CLICKE::SELECT4) TextOut(getMemDC(), _equipWindow->itemSelect[4].left + 380, _equipWindow->itemSelect[4].top + 10, "����Ƚ�� �ʰ�", lstrlen("����Ƚ�� �ʰ�"));
		//		if (_click == CLICKE::SELECT5) TextOut(getMemDC(), _equipWindow->itemSelect[5].left + 380, _equipWindow->itemSelect[5].top + 10, "����Ƚ�� �ʰ�", lstrlen("����Ƚ�� �ʰ�"));
		//		if (_click == CLICKE::SELECT6) TextOut(getMemDC(), _equipWindow->itemSelect[6].left + 380, _equipWindow->itemSelect[6].top + 10, "����Ƚ�� �ʰ�", lstrlen("����Ƚ�� �ʰ�"));
		//		if (_click == CLICKE::SELECT7) TextOut(getMemDC(), _equipWindow->itemSelect[7].left + 380, _equipWindow->itemSelect[7].top + 10, "����Ƚ�� �ʰ�", lstrlen("����Ƚ�� �ʰ�"));
		//	}
		//}


		
		//������ �ؽ�Ʈ
		TextOut(getMemDC(), _equipWindow->descriptionBox.right + 10, _equipWindow->descriptionBox.top + 5, "������", lstrlen("������"));
		TextOut(getMemDC(), _equipWindow->descriptionBox.right + 140, _equipWindow->descriptionBox.top + 5, to_string(money).c_str(), lstrlen(to_string(money).c_str()));
		TextOut(getMemDC(), _equipWindow->descriptionBox.right + 180, _equipWindow->descriptionBox.top + 5, "G", lstrlen("G"));

	}


	if (_equipWindow->isClosed)
	{
		_activeTime++;

		if (_activeTime <= 100)
		{
			IMAGE->render("��ȭ_����", getMemDC(), 0, 10);
			IMAGE->alphaRender("��ȭ_����2", getMemDC(), 0, 10, 170);
			IMAGE->render("�̹���_�������", getMemDC(), 15, 12);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			TextOut(getMemDC(), 380, 55, "���� ������", lstrlen("���� ������"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(250, 244, 192));
			TextOut(getMemDC(), 380, 55, "���� ������", lstrlen("���� ������"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(42, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 385, 90, "�� ��! ���÷����?", lstrlen("�� ��! ���÷����?"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(30, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 385, 150, "�����ٽ� ���⸦ ��ٸ��Կ�~ ��", lstrlen("�����ٽ� ���⸦ ��ٸ��Կ�~ ��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (_activeTime > 85)
		{
			town_active = true;
			isOpen = false;
		}
	}

	//TCHAR please[100];
	//wsprintf(please, "unitList oepn : %d", _unitListEx->getOpen());
	//SetTextColor(getMemDC(), RGB(255, 255, 255));
	//TextOut(getMemDC(), 100, 0, please, lstrlen(please));

	//TCHAR please1[100];
	//wsprintf(please1, "isOpen : %d", isOpen);
	//SetTextColor(getMemDC(), RGB(255, 255, 255));
	//TextOut(getMemDC(), 100, 0, please1, lstrlen(please1));
}

void equipStore::BuyEquip()
{
	if (_click == CLICKE::SELECT && money >= _vEquip[0]->money)
	{
		//�̹� �����ϴ��� �Ǻ�
		bool isExist = false;

		_viBuyEquip = _vBuyEquip.begin();
		for (_viBuyEquip; _viBuyEquip != _vBuyEquip.end(); ++_viBuyEquip)
		{
			if ((*_viBuyEquip)->name == _vEquip[0]->name)
			{
				isExist = true;
				(*_viBuyEquip)->num = _equipWindow->buyEquip_num;

				if ((*_viBuyEquip)->num == 0)
				{
					_click = CLICKE::NONE;
					_vEquip.erase(_viBuyEquip);
					SAFE_DELETE(*_viBuyEquip);
				}
			}
		}

		if (!(isExist))
		{
			tagEquipInfo* equip;
			equip = new tagEquipInfo;
			equip->name = _vEquip[0]->name;
			equip->detail = _vEquip[0]->detail;
			equip->kind = EQUIP_KIND::WEAPON;
			equip->money = _vEquip[0]->money;
			equip->num = _equipWindow->buyEquip_num;
			//equip->num += 1;
			equip->iconImg = _vEquip[0]->iconImg;
			equip->offensePower = _vEquip[0]->offensePower;
			equip->defense = _vEquip[0]->defense;
			equip->intellect = _vEquip[0]->intellect;
			equip->magicDrag = _vEquip[0]->magicDrag;
			equip->agility = _vEquip[0]->agility;
			_vEquip.push_back(equip);
			_vBuyEquip.push_back(equip);

			money -= (_vEquip[0]->money);
		}
	}

	if (_click == CLICKE::SELECT1 && money >= _vEquip[1]->money)
	{
		//�̹� �����ϴ��� �Ǻ�
		bool isExist = false;

		_viBuyEquip = _vBuyEquip.begin();
		for (_viBuyEquip; _viBuyEquip != _vBuyEquip.end(); ++_viBuyEquip)
		{
			if ((*_viBuyEquip)->name == _vEquip[1]->name)
			{
				isExist = true;
				(*_viBuyEquip)->num = _equipWindow->buyEquip_num;

				if ((*_viBuyEquip)->num == 0)
				{
					_click = CLICKE::NONE;
					_vEquip.erase(_viBuyEquip);
					SAFE_DELETE(*_viBuyEquip);
				}

			}
		}

		if (!(isExist))
		{
			tagEquipInfo* equip;
			equip = new tagEquipInfo;
			equip->name = _vEquip[1]->name;
			equip->detail = _vEquip[1]->detail;
			equip->kind = EQUIP_KIND::WEAPON;
			equip->money = _vEquip[1]->money;
			equip->num = _equipWindow->buyEquip_num;
			//equip->num += 1;
			equip->iconImg = _vEquip[1]->iconImg;
			equip->offensePower = _vEquip[1]->offensePower;
			equip->defense = _vEquip[1]->defense;
			equip->intellect = _vEquip[1]->intellect;
			equip->magicDrag = _vEquip[1]->magicDrag;
			equip->agility = _vEquip[1]->agility;

			_vEquip.push_back(equip);
			_vBuyEquip.push_back(equip);
			money -= (_vEquip[1]->money);
		}
	}

	if (_click == CLICKE::SELECT2 && money >= _vEquip[2]->money)
	{
		//�̹� �����ϴ��� �Ǻ�
		bool isExist = false;

		_viBuyEquip = _vBuyEquip.begin();
		for (_viBuyEquip; _viBuyEquip != _vBuyEquip.end(); ++_viBuyEquip)
		{
			if ((*_viBuyEquip)->name == _vEquip[2]->name)
			{
				isExist = true;
				(*_viBuyEquip)->num = _equipWindow->buyEquip_num;

				if ((*_viBuyEquip)->num == 0)
				{
					_click = CLICKE::NONE;
					_vEquip.erase(_viBuyEquip);
					SAFE_DELETE(*_viBuyEquip);
				}
			}
		}

		if (!(isExist))
		{
			tagEquipInfo* equip;
			equip = new tagEquipInfo;
			equip->name = _vEquip[2]->name;
			equip->detail = _vEquip[2]->detail;
			equip->kind = EQUIP_KIND::WEAPON;
			equip->money = _vEquip[2]->money;
			equip->num = _equipWindow->buyEquip_num;
			//equip->num += 1;
			equip->iconImg = _vEquip[2]->iconImg;
			equip->offensePower = _vEquip[2]->offensePower;
			equip->defense = _vEquip[2]->defense;
			equip->intellect = _vEquip[2]->intellect;
			equip->magicDrag = _vEquip[2]->magicDrag;
			equip->agility = _vEquip[2]->agility;
			_vEquip.push_back(equip);

			_vBuyEquip.push_back(equip);
		money -= (_vEquip[2]->money);
		}
	}

	if (_click == CLICKE::SELECT3 && money >= _vEquip[3]->money)
	{
		//�̹� �����ϴ��� �Ǻ�
		bool isExist = false;

		_viBuyEquip = _vBuyEquip.begin();
		for (_viBuyEquip; _viBuyEquip != _vBuyEquip.end(); ++_viBuyEquip)
		{
			if ((*_viBuyEquip)->name == _vEquip[3]->name)
			{
				isExist = true;
				(*_viBuyEquip)->num = _equipWindow->buyEquip_num;

				if ((*_viBuyEquip)->num == 0)
				{
					_click = CLICKE::NONE;
					_vEquip.erase(_viBuyEquip);
					SAFE_DELETE(*_viBuyEquip);
				}
			}
		}

		if (!(isExist))
		{
			tagEquipInfo* equip;
			equip = new tagEquipInfo;
			equip->name = _vEquip[3]->name;
			equip->detail = _vEquip[3]->detail;
			equip->kind = EQUIP_KIND::WEAPON;
			equip->money = _vEquip[3]->money;
			equip->num = _equipWindow->buyEquip_num;
			//equip->num += 1;
			equip->iconImg = _vEquip[3]->iconImg;
			equip->offensePower = _vEquip[3]->offensePower;
			equip->defense = _vEquip[3]->defense;
			equip->intellect = _vEquip[3]->intellect;
			equip->magicDrag = _vEquip[3]->magicDrag;
			equip->agility = _vEquip[3]->agility;
			_vEquip.push_back(equip);

			_vBuyEquip.push_back(equip);
		money -= (_vEquip[3]->money);
		}
	}

	if (_click == CLICKE::SELECT4 && money >= _vEquip[4]->money)
	{
		//�̹� �����ϴ��� �Ǻ�
		bool isExist = false;

		_viBuyEquip = _vBuyEquip.begin();
		for (_viBuyEquip; _viBuyEquip != _vBuyEquip.end(); ++_viBuyEquip)
		{
			if ((*_viBuyEquip)->name == _vEquip[4]->name)
			{
				isExist = true;
				(*_viBuyEquip)->num = _equipWindow->buyEquip_num;

				if ((*_viBuyEquip)->num == 0)
				{
					_click = CLICKE::NONE;
					_vEquip.erase(_viBuyEquip);
					SAFE_DELETE(*_viBuyEquip);
				}
			}
		}

		if (!(isExist))
		{
			tagEquipInfo* equip;
			equip = new tagEquipInfo;
			equip->name = _vEquip[4]->name;
			equip->detail = _vEquip[4]->detail;
			equip->kind = EQUIP_KIND::ARMOR;
			equip->money = _vEquip[4]->money;
			equip->num = _equipWindow->buyEquip_num;
			//equip->num += 1;
			equip->iconImg = _vEquip[4]->iconImg;
			equip->offensePower = _vEquip[4]->offensePower;
			equip->defense = _vEquip[4]->defense;
			equip->intellect = _vEquip[4]->intellect;
			equip->magicDrag = _vEquip[4]->magicDrag;
			equip->agility = _vEquip[4]->agility;
			_vEquip.push_back(equip);

			_vBuyEquip.push_back(equip);
		money -= (_vEquip[4]->money);
		}
	}

	if (_click == CLICKE::SELECT5 && money >= _vEquip[5]->money)
	{
		//�̹� �����ϴ��� �Ǻ�
		bool isExist = false;

		_viBuyEquip = _vBuyEquip.begin();
		for (_viBuyEquip; _viBuyEquip != _vBuyEquip.end(); ++_viBuyEquip)
		{
			if ((*_viBuyEquip)->name == _vEquip[5]->name)
			{
				isExist = true;
				(*_viBuyEquip)->num = _equipWindow->buyEquip_num;

				if ((*_viBuyEquip)->num == 0)
				{
					_click = CLICKE::NONE;
					_vEquip.erase(_viBuyEquip);
					SAFE_DELETE(*_viBuyEquip);
				}
			}
		}

		if (!(isExist))
		{
			tagEquipInfo* equip;
			equip = new tagEquipInfo;
			equip->name = _vEquip[5]->name;
			equip->detail = _vEquip[5]->detail;
			equip->kind = EQUIP_KIND::ARMOR;
			equip->money = _vEquip[5]->money;
			equip->num = _equipWindow->buyEquip_num;
			//equip->num += 1;
			equip->iconImg = _vEquip[5]->iconImg;
			equip->offensePower = _vEquip[5]->offensePower;
			equip->defense = _vEquip[5]->defense;
			equip->intellect = _vEquip[5]->intellect;
			equip->magicDrag = _vEquip[5]->magicDrag;
			equip->agility = _vEquip[5]->agility;
			_vEquip.push_back(equip);

			_vBuyEquip.push_back(equip);
		money -= (_vEquip[5]->money);
		}
	}
	
	if (_click == CLICKE::SELECT6 && money >= _vEquip[6]->money)
	{
		//�̹� �����ϴ��� �Ǻ�
		bool isExist = false;

		_viBuyEquip = _vBuyEquip.begin();
		for (_viBuyEquip; _viBuyEquip != _vBuyEquip.end(); ++_viBuyEquip)
		{
			if ((*_viBuyEquip)->name == _vEquip[6]->name)
			{
				isExist = true;
				(*_viBuyEquip)->num = _equipWindow->buyEquip_num;

				if ((*_viBuyEquip)->num == 0)
				{
					_click = CLICKE::NONE;
					_vEquip.erase(_viBuyEquip);
					SAFE_DELETE(*_viBuyEquip);
				}
			}
		}

		if (!(isExist))
		{
			tagEquipInfo* equip;
			equip = new tagEquipInfo;
			equip->name = _vEquip[6]->name;
			equip->detail = _vEquip[6]->detail;
			equip->kind = EQUIP_KIND::ARMOR;
			equip->money = _vEquip[6]->money;
			equip->num = _equipWindow->buyEquip_num;
			//equip->num += 1;
			equip->iconImg = _vEquip[6]->iconImg;
			equip->offensePower = _vEquip[6]->offensePower;
			equip->defense = _vEquip[6]->defense;
			equip->intellect = _vEquip[6]->intellect;
			equip->magicDrag = _vEquip[6]->magicDrag;
			equip->agility = _vEquip[6]->agility;
			_vEquip.push_back(equip);

			_vBuyEquip.push_back(equip);
		money -= (_vEquip[6]->money);
		}
	}

	if (_click == CLICKE::SELECT7 && money >= _vEquip[7]->money)
	{
		//�̹� �����ϴ��� �Ǻ�
		bool isExist = false;

		_viBuyEquip = _vBuyEquip.begin();
		for (_viBuyEquip; _viBuyEquip != _vBuyEquip.end(); ++_viBuyEquip)
		{
			if ((*_viBuyEquip)->name == _vEquip[7]->name)
			{
				isExist = true;
				(*_viBuyEquip)->num = _equipWindow->buyEquip_num;

				if ((*_viBuyEquip)->num == 0)
				{
					_click = CLICKE::NONE;
					_vEquip.erase(_viBuyEquip);
					SAFE_DELETE(*_viBuyEquip);
				}
			}
		}

		if (!(isExist))
		{
			tagEquipInfo* equip;
			equip = new tagEquipInfo;
			equip->name = _vEquip[7]->name;
			equip->detail = _vEquip[7]->detail;
			equip->kind = EQUIP_KIND::ARMOR;
			equip->money = _vEquip[7]->money;
			equip->num = _equipWindow->buyEquip_num;
			//equip->num += 1;
			equip->iconImg = _vEquip[7]->iconImg;
			equip->offensePower = _vEquip[7]->offensePower;
			equip->defense = _vEquip[7]->defense;
			equip->intellect = _vEquip[7]->intellect;
			equip->magicDrag = _vEquip[7]->magicDrag;
			equip->agility = _vEquip[7]->agility;
			_vEquip.push_back(equip);

			_vBuyEquip.push_back(equip);
		money -= (_vEquip[7]->money);
		}
	}
}




void equipStore::lightGrayDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(220, 220, 220));
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	FillRect(getMemDC(), &rc, brush);
	DeleteObject(brush);
}
void equipStore::shadowDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(051, 051, 051));
	RECT shadow = RectMake(rc.left + 3, rc.top + 3, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), shadow.left, shadow.top, shadow.right, shadow.bottom);
	FillRect(getMemDC(), &shadow, brush);
	DeleteObject(brush);
}
void equipStore::lightDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	RECT light = RectMake(rc.left - 1, rc.top - 1, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
	FillRect(getMemDC(), &light, brush);
	DeleteObject(brush);
}
