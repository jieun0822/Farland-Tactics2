#include "framework.h"
#include "itemStore.h"
#pragma warning (disable : 2664)

itemStore::itemStore()
{
}

itemStore::~itemStore()
{
}

HRESULT itemStore::init()
{
	//�� ���
	IMAGE->addImage("��_���", "images/itemStore_NPC.bmp", WINSIZEX - 10, WINSIZEY - 30, false, RGB(0, 0, 0));
	
	// �̹���
	IMAGE->addImage("�÷��̾�", "images/R_stand.bmp", 70, 112, true, RGB(255, 0, 255)); //����ũ�� 48*75
	
	////��ȭ���� ��ȭâ
	IMAGE->addImage("��ȭ_����", "images/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("��ȭ_����2", "images/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("�̹���_����", "images/face17a.bmp", 360, 250, true, RGB(255, 255, 255));
	
	//�÷��̾� ��ȭâ
	IMAGE->addImage("��ȭ_�÷��̾�", "images/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("��ȭ_�÷��̾�2", "images/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("�̹���_�÷��̾�", "images/face02a.bmp", 360, 250, true, RGB(255, 255, 255));

	//�ʱ�ȭ
	//gold	= 500;
	activeTime = 0;
	_activeTime = 0;
	isOpen	= false;
	_click	= CLICK::NONE;

	//â ����
	_itemWindow = new ItemWindow;
	_itemWindow->outLine = RectMake(270, 120, 500, 500);
	_itemWindow->isClosed = false;
	_itemWindow->isBuyButton = false;

	int outlineWidth	= _itemWindow->outLine.right - _itemWindow->outLine.left;
	int outlintHeight	= _itemWindow->outLine.bottom - _itemWindow->outLine.top;

	//â ����
	_itemWindow->windowName = RectMake(_itemWindow->outLine.left + 3, _itemWindow->outLine.top + 3, outlineWidth - 6, 30 - 6);

	//�޴� ����
	_itemWindow->itemMenu = RectMake(_itemWindow->outLine.left + 3, _itemWindow->outLine.top + 32, outlineWidth - 6, 30);
	
	//������ ����Ʈ
	_itemWindow->itemList = RectMake(_itemWindow->outLine.left + 3, _itemWindow->outLine.top + 70, outlineWidth - 6, 270);

	int itemListWidth = _itemWindow->itemList.right - _itemWindow->itemList.left;
	int itemListHeight = _itemWindow->itemList.bottom - _itemWindow->itemList.top;
	
	//������ �����
	_itemWindow->descriptionBox = RectMake(_itemWindow->outLine.left + 5, _itemWindow->outLine.top + 350, outlineWidth - 220, 140);
	
	//������ ǥ��â
	_itemWindow->goldBox = RectMake(_itemWindow->descriptionBox.right + 8, _itemWindow->descriptionBox.top, outlineWidth - 300, 27);
	
	int goldBoxWidth = _itemWindow->goldBox.right - _itemWindow->goldBox.left;
	int goldBoxHeight = _itemWindow->goldBox.bottom - _itemWindow->goldBox.top;

	//��ư
	//���� ��ư
	_itemWindow->buyButton = RectMake(_itemWindow->goldBox.left, _itemWindow->goldBox.bottom + 5, goldBoxWidth, goldBoxHeight);

	//���� ����
	_itemWindow->buyWindow = RectMake(_itemWindow->outLine.left + 115, _itemWindow->outLine.top + 150, 300, 150);
	_itemWindow->buyWin_name = RectMake(_itemWindow->buyWindow.left, _itemWindow->buyWindow.top, 300, 30);
	_itemWindow->buyWin_num = RectMake(_itemWindow->buyWindow.left + 60, _itemWindow->buyWin_name.bottom + 7, 85, 36);
	_itemWindow->buyWin_numUp = RectMake(_itemWindow->buyWindow.left + 115, _itemWindow->buyWin_name.bottom + 7, 30, 18);
	_itemWindow->buyWin_numDown = RectMake(_itemWindow->buyWindow.left + 115, _itemWindow->buyWin_name.bottom + 25, 30, 18);
	
	_itemWindow->buyWin_buyButton = RectMake(_itemWindow->buyWin_name.left + 185, _itemWindow->buyWin_name.bottom + 10, 100, 30);
	_itemWindow->buyWin_exitButton = RectMake(_itemWindow->buyWin_name.left + 185, _itemWindow->buyWin_name.bottom + 60, 100, 30);
	_itemWindow->buyItem_num = 1;

	//����Ʈ �϶�
	_itemWindow->unitButton = RectMake(_itemWindow->goldBox.left, _itemWindow->buyButton.bottom + 10, goldBoxWidth, goldBoxHeight);

	//�ݱ�
	_itemWindow->closeButton = RectMake(_itemWindow->goldBox.left, _itemWindow->unitButton.bottom + 10, goldBoxWidth, goldBoxHeight);

	//������ ���� �ڽ�
	_itemWindow->itemSelect[0] = RectMake(_itemWindow->itemList.left + 2, _itemWindow->itemList.top + 2, itemListWidth - 2, 30);
	_itemWindow->itemSelect[1] = RectMake(_itemWindow->itemList.left + 2, _itemWindow->itemList.top + 32, itemListWidth - 2, 30);
	_itemWindow->itemSelect[2] = RectMake(_itemWindow->itemList.left + 2, _itemWindow->itemList.top + 62, itemListWidth - 2, 30);
	_itemWindow->itemSelect[3] = RectMake(_itemWindow->itemList.left + 2, _itemWindow->itemList.top + 92, itemListWidth - 2, 30);
	_itemWindow->itemSelect[4] = RectMake(_itemWindow->itemList.left + 2, _itemWindow->itemList.top + 122, itemListWidth - 2, 30);
	_itemWindow->itemSelect[5] = RectMake(_itemWindow->itemList.left + 2, _itemWindow->itemList.top + 152, itemListWidth - 2, 30);
	_itemWindow->itemSelect[6] = RectMake(_itemWindow->itemList.left + 2, _itemWindow->itemList.top + 182, itemListWidth - 2, 30);
	_itemWindow->itemSelect[7] = RectMake(_itemWindow->itemList.left + 2, _itemWindow->itemList.top + 212, itemListWidth - 2, 30);
	/*
	0.���
	1.�ص���
	2.�����Ǵ���
	3.ȣ��������
	4.ȸ����
	5.ġ����
	6.����¾�
	7.����ī
	*/
	
	//������ �߰� (����)
	tagItemInfo* item = new tagItemInfo;

	item = new tagItemInfo;
	item->name = "���";
	item->money = 30;
	item->detail = "��𿡳� ���ִ� �Ϲ����� ����. \nü���� 20 ȸ���Ѵ�.";
	item->iconImg = IMAGE->addImage("���", "images/herb.bmp", 25, 23, true, RGB(255, 0, 255));
	item->num = 0;
	_vItem.push_back(item);

	item = new tagItemInfo;
	item->name = "�ص���";
	item->money = 40;
	item->detail = "ü���� ���� ��ȭ�ϴ� �ۿ��� �ִ�. \n���� ��������.";
	item->iconImg = IMAGE->addImage("�ص���", "images/antiPosion.bmp", 25, 23, true, RGB(255, 0, 255));
	item->num = 0;
	_vItem.push_back(item);

	item = new tagItemInfo;
	item->name = "������ ����";
	item->money = 60;
	item->detail = "���� �ױ⽺�� ���� �� ������, \r�������Լ� ���� �� �ֱ� ������, \r�̷��� �θ��� �ִ�. \nü���� 40, ������ 10 ȸ���ȴ�.";
	item->iconImg = IMAGE->addImage("�����Ǵ���", "images/fairy.bmp", 25, 23, true, RGB(255, 0, 255));
	item->num = 0;
	_vItem.push_back(item);

	item = new tagItemInfo;
	item->name = "ȣ���� ����";
	item->money = 90;
	item->detail = "���۾����ϰ�, ������ ����. \n�����ַ� ����. \nü���� 60 ȸ���ȴ�.";
	item->iconImg = IMAGE->addImage("ȣ��������", "images/pumpkin.bmp", 25, 23, true, RGB(255, 0, 255));
	item->num = 0;
	_vItem.push_back(item);

	item = new tagItemInfo;
	item->name = "ȸ����";
	item->money = 150;
	item->detail = "���� �ױ⽺�� ���� ������ ��. \nü���� 100 ȸ���ȴ�.";
	item->iconImg = IMAGE->addImage("ȸ����", "images/recovery2.bmp", 25, 23, true, RGB(255, 0, 255));
	item->num = 0;
	_vItem.push_back(item);

	item = new tagItemInfo;
	item->name = "����� ��";
	item->money = 70;
	item->detail = "�ּ����� �ϸ�Ͼ�. \r�ڰ� �ִ� ����̳�, ������ �ִ� \r����� �� ���� ������ �����.";
	item->iconImg = IMAGE->addImage("����¾�", "images/fairy.bmp", 25, 23, true, RGB(255, 0, 255));
	item->num = 0;
	_vItem.push_back(item);
	
	item = new tagItemInfo;
	item->name = "����ī";
	item->money = 300;
	item->detail = "���� ���� �߿� �������� \r��������� �ִ� ��. \n��� ���� ���, �� ������� ��ȿ. \n'����ī'��� ����, '����ī'��� �д´�. ü���� 100��ŭ, ������ ���� ȸ����Ų��.";
	item->iconImg = IMAGE->addImage("����ī", "images/vodka.bmp", 25, 23, true, RGB(255, 0, 255));
	item->num = 0;
	_vItem.push_back(item);


	item = new tagItemInfo;
	item->name = "�������";
	item->money = 500;
	item->detail = "�̰��� ����ϸ�, \n���� �̿��� ��� �����̻�� \nü���� ȸ���Ѵ�. \n���� ����� �� ����.";
	item->iconImg = IMAGE->addImage("�������", "images/eriqusa.bmp", 25, 23, true, RGB(255, 0, 255));
	item->num = 0;
	_vItem.push_back(item);


	//�̹���
	IMAGE->addImage("���_�޴�", "images/itemWindow_basic.bmp", _itemWindow->itemMenu.right - _itemWindow->itemMenu.left,
		_itemWindow->itemMenu.bottom - _itemWindow->itemMenu.top, true, RGB(255, 0, 255));
	IMAGE->addImage("���_������", "images/itemWindow_list.bmp", _itemWindow->itemList.right - _itemWindow->itemList.left,
		_itemWindow->itemList.bottom - _itemWindow->itemList.top, true, RGB(255, 0, 255));
	
	for (int i = 0; i < 7; i++)
	{
		IMAGE->addImage("���_Ŭ��", "images/backGround_blue.bmp", _itemWindow->itemSelect[i].right - _itemWindow->itemSelect[i].left,
			_itemWindow->itemSelect[i].bottom - _itemWindow->itemSelect[i].top, true, RGB(255, 0, 255));
	}

	//�����϶�
	//_unitList = new UnitList;
	//_unitList->init();

	town_active = false;
	itemStore_active = false;
	unitList_active = false;

	money = 0;

	return S_OK;
}

void itemStore::release()
{
	
}

void itemStore::update()
{

	if (activeTime >= 80 && !(unitList_active))
	{
		if (InputManager->isOnceKeyUp(VK_LBUTTON))
		{
			isOpen = true;

			//���� ��ư
			if (isOpen && PtInRect(&_itemWindow->closeButton, m_ptMouse) && !(_itemWindow->isBuyButton))
			{
				isOpen = !isOpen;
				_itemWindow->isClosed = true;
			}

			//���� ��ư
			if (!(_itemWindow->isClosed) && PtInRect(&_itemWindow->unitButton, m_ptMouse) && !(_itemWindow->isBuyButton))
			{
				unitList_active = true;
				//_unitList->setActive(true);
				//_unitList->setOpen(true);
			}

			if (!(_itemWindow->isBuyButton))
			{
				//Ŭ��
				if (PtInRect(&_itemWindow->itemSelect[0], m_ptMouse)) { _click = CLICK::SELECT; }
				if (PtInRect(&_itemWindow->itemSelect[1], m_ptMouse)) { _click = CLICK::SELECT1; }
				if (PtInRect(&_itemWindow->itemSelect[2], m_ptMouse)) { _click = CLICK::SELECT2; }
				if (PtInRect(&_itemWindow->itemSelect[3], m_ptMouse)) { _click = CLICK::SELECT3; }
				if (PtInRect(&_itemWindow->itemSelect[4], m_ptMouse)) { _click = CLICK::SELECT4; }
				if (PtInRect(&_itemWindow->itemSelect[5], m_ptMouse)) { _click = CLICK::SELECT5; }
				if (PtInRect(&_itemWindow->itemSelect[6], m_ptMouse)) { _click = CLICK::SELECT6; }
				if (PtInRect(&_itemWindow->itemSelect[7], m_ptMouse)) { _click = CLICK::SELECT7; }
			}

			//������ ���
			if (PtInRect(&_itemWindow->buyButton, m_ptMouse) && !_itemWindow->isClosed)
			{
				_itemWindow->isBuyButton = true;
			}

			//����â ����
			if (_itemWindow->isBuyButton)
			{
				//�����Ѵ�!
				if (PtInRect(&_itemWindow->buyWin_buyButton, m_ptMouse))
				{
					BuyItem();

					_itemWindow->isBuyButton = false;
				}

				//�� ���� ���� ����
				if (PtInRect(&_itemWindow->buyWin_numUp, m_ptMouse))
				{
					if (_click == CLICK::SELECT && money >= (_vItem[0]->money * _itemWindow->buyItem_num) + _vItem[0]->money) { _itemWindow->buyItem_num++; }
					if (_click == CLICK::SELECT1 && money >= (_vItem[1]->money * _itemWindow->buyItem_num) + _vItem[1]->money) { _itemWindow->buyItem_num++; }
					if (_click == CLICK::SELECT2 && money >= (_vItem[2]->money * _itemWindow->buyItem_num) + _vItem[2]->money) { _itemWindow->buyItem_num++; }
					if (_click == CLICK::SELECT3 && money >= (_vItem[3]->money * _itemWindow->buyItem_num) + _vItem[3]->money) { _itemWindow->buyItem_num++; }
					if (_click == CLICK::SELECT4 && money >= (_vItem[4]->money * _itemWindow->buyItem_num) + _vItem[4]->money) { _itemWindow->buyItem_num++; }
					if (_click == CLICK::SELECT5 && money >= (_vItem[5]->money * _itemWindow->buyItem_num) + _vItem[5]->money) { _itemWindow->buyItem_num++; }
					if (_click == CLICK::SELECT6 && money >= (_vItem[6]->money * _itemWindow->buyItem_num) + _vItem[6]->money) { _itemWindow->buyItem_num++; }
					if (_click == CLICK::SELECT7 && money >= (_vItem[7]->money * _itemWindow->buyItem_num) + _vItem[7]->money) { _itemWindow->buyItem_num++; }
				}
				if (PtInRect(&_itemWindow->buyWin_numDown, m_ptMouse))
				{
					if (_itemWindow->buyItem_num - 1 < 1) _itemWindow->buyItem_num = 1;
					else _itemWindow->buyItem_num--;
				}
				//���ư���
				if (PtInRect(&_itemWindow->buyWin_exitButton, m_ptMouse)) { _itemWindow->isBuyButton = false; }
			}
			if (!_itemWindow->isBuyButton) { _itemWindow->buyItem_num = 1; }
		}
	}

	//���� �϶�.
	//if (_unitList->getActive()) { _unitList->update(); }
}

void itemStore::render()
{
	//�� �� ĳ���� ����
	IMAGE->render("��_���", getMemDC());
	IMAGE->render("�÷��̾�", getMemDC(), WINSIZEX / 2 - 50, WINSIZEY / 2 - 50);
	//IMAGE->findImage("��_���")->render(getMemDC(), 0, 0);
	//IMAGE->findImage("�÷��̾�")->frameRender(getMemDC(), WINSIZEX / 2 - 50, WINSIZEY / 2 - 50);
	
	//���� �ð��� ������ ��ȭ���� ��ȭâ ����
	activeTime++;
	if (activeTime >= 30 && !(_itemWindow->isClosed))
	{
		IMAGE->render("��ȭ_����", getMemDC(), 0, WINSIZEY - 300);
		IMAGE->alphaRender("��ȭ_����2", getMemDC(), 0, WINSIZEY - 301, 170);
		IMAGE->render("�̹���_����", getMemDC(), 600, 470);
	
		HFONT font, oldfont;
		SetBkMode(getMemDC(), TRANSPARENT);
	
		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 50, WINSIZEY - 260, "��ȭ����", lstrlen("��ȭ����"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	
		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 48, WINSIZEY - 260, "��ȭ����", lstrlen("��ȭ����"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	
		font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 50, WINSIZEY - 225, "�� � ������! ��", lstrlen("�� � ������! ��"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);
	
		if (activeTime >= 80 && !(_itemWindow->isClosed))
		{
			IMAGE->render("��ȭ_�÷��̾�", getMemDC(), 0, 10);
			IMAGE->alphaRender("��ȭ_�÷��̾�2", getMemDC(), 0, 10, 170);
			IMAGE->render("�̹���_�÷��̾�", getMemDC(), 10, 12);
	
			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			TextOut(getMemDC(), 380, 55, "��", lstrlen("��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
	
			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(250, 244, 192));
			TextOut(getMemDC(), 380, 55, "��", lstrlen("��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
	
			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TCHAR strrr[128];
			wsprintf(strrr, "�� ����� ���� ���� ���� �Ĵ� ���̱���. ��");
			TextOut(getMemDC(), 385, 90, strrr, lstrlen(strrr));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}
	
	}

	HBRUSH brush;
	HBRUSH oldBrush;
	HPEN hpen;
	HPEN hpenOld;

	if (isOpen && !(_itemWindow->isClosed))
	{
		//��ü â �׸���
		brush = CreateSolidBrush(RGB(204, 204, 204));
		Rectangle(getMemDC(), _itemWindow->outLine.left, _itemWindow->outLine.top, _itemWindow->outLine.right, _itemWindow->outLine.bottom);
		FillRect(getMemDC(), &_itemWindow->outLine, brush);
		DeleteObject(brush);

		//��ǰ��� â ����
		brush = CreateSolidBrush(RGB(0, 0, 153));
		Rectangle(getMemDC(), _itemWindow->windowName.left, _itemWindow->windowName.top, _itemWindow->windowName.right, _itemWindow->windowName.bottom);
		FillRect(getMemDC(), &_itemWindow->windowName, brush);
		DeleteObject(brush);

		//��ǰ��� â �ؽ�Ʈ
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TCHAR str[10];
		SetBkMode(getMemDC(), TRANSPARENT);
		wsprintf(str, "��ǰ���");
		TextOut(getMemDC(), _itemWindow->windowName.left + 5, _itemWindow->windowName.top + 5, str, lstrlen(str));
		SetTextColor(getMemDC(), RGB(0, 0, 0));

		//�޴� ���� â
		hpen = CreatePen(PS_SOLID, 1, RGB(111, 111, 111));
		hpenOld = (HPEN)::SelectObject(getMemDC(), (HGDIOBJ)hpen);
		brush = CreateSolidBrush(RGB(204, 204, 204));
		oldBrush = (HBRUSH)::SelectObject(getMemDC(), brush);
		Rectangle(getMemDC(), _itemWindow->descriptionBox.left, _itemWindow->descriptionBox.top, _itemWindow->descriptionBox.right, _itemWindow->descriptionBox.bottom);
		hpen = (HPEN)::SelectObject(getMemDC(), hpenOld);
		brush = (HBRUSH)::SelectObject(getMemDC(), oldBrush);
		DeleteObject(hpen);
		DeleteObject(brush);


		//��ư �׸���
		brush = CreateSolidBrush(RGB(93, 93, 93));
		//����
		RECT shadow = RectMake(_itemWindow->buyButton.left + 3, _itemWindow->buyButton.top + 3, _itemWindow->buyButton.right - _itemWindow->buyButton.left, _itemWindow->buyButton.bottom - _itemWindow->buyButton.top);
		Rectangle(getMemDC(), shadow.left, shadow.top, shadow.right, shadow.bottom);
		FillRect(getMemDC(), &shadow, brush);
		//����Ʈ �϶�
		RECT shadow2 = RectMake(_itemWindow->unitButton.left + 3, _itemWindow->unitButton.top + 3, _itemWindow->unitButton.right - _itemWindow->unitButton.left, _itemWindow->unitButton.bottom - _itemWindow->unitButton.top);
		Rectangle(getMemDC(), shadow2.left, shadow2.top, shadow2.right, shadow2.bottom);
		FillRect(getMemDC(), &shadow2, brush);
		//�ݱ�
		RECT shadow3 = RectMake(_itemWindow->closeButton.left + 3, _itemWindow->closeButton.top + 3, _itemWindow->closeButton.right - _itemWindow->closeButton.left, _itemWindow->closeButton.bottom - _itemWindow->closeButton.top);
		Rectangle(getMemDC(), shadow3.left, shadow3.top, shadow3.right, shadow3.bottom);
		FillRect(getMemDC(), &shadow3, brush);
		DeleteObject(brush);

		//��ư �׵θ�
		brush = CreateSolidBrush(RGB(255, 255, 255));
		//����
		RECT light = RectMake(_itemWindow->buyButton.left - 1, _itemWindow->buyButton.top - 1, _itemWindow->buyButton.right - _itemWindow->buyButton.left, _itemWindow->buyButton.bottom - _itemWindow->buyButton.top);
		Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
		FillRect(getMemDC(), &light, brush);
		//����Ʈ �϶�
		RECT light2 = RectMake(_itemWindow->unitButton.left - 1, _itemWindow->unitButton.top - 1, _itemWindow->unitButton.right - _itemWindow->unitButton.left, _itemWindow->unitButton.bottom - _itemWindow->unitButton.top);
		Rectangle(getMemDC(), light2.left, light2.top, light2.right, light2.bottom);
		FillRect(getMemDC(), &light2, brush);
		//�ݱ�
		RECT light3 = RectMake(_itemWindow->closeButton.left - 1, _itemWindow->closeButton.top - 1, _itemWindow->closeButton.right - _itemWindow->closeButton.left, _itemWindow->closeButton.bottom - _itemWindow->closeButton.top);
		Rectangle(getMemDC(), light3.left, light3.top, light3.right, light3.bottom);
		FillRect(getMemDC(), &light3, brush);
		DeleteObject(brush);

		//��ư ����
		//CreateWindow(TEXT("button"), TEXT("����"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, _itemWindow->description.right + 10, _itemWindow->description.top + 30, 195, 25, m_hWnd, (HMENU)0, m_hInstance, NULL);
		brush = CreateSolidBrush(RGB(204, 204, 204));
		//����
		Rectangle(getMemDC(), _itemWindow->buyButton.left, _itemWindow->buyButton.top, _itemWindow->buyButton.right, _itemWindow->buyButton.bottom);
		FillRect(getMemDC(), &_itemWindow->buyButton, brush);
		//����Ʈ �϶�
		Rectangle(getMemDC(), _itemWindow->unitButton.left, _itemWindow->unitButton.top, _itemWindow->unitButton.right, _itemWindow->unitButton.bottom);
		FillRect(getMemDC(), &_itemWindow->unitButton, brush);
		//�ݱ�
		Rectangle(getMemDC(), _itemWindow->closeButton.left, _itemWindow->closeButton.top, _itemWindow->closeButton.right, _itemWindow->closeButton.bottom);
		FillRect(getMemDC(), &_itemWindow->closeButton, brush);
		DeleteObject(brush);


		//�̹��� ����
		IMAGE->findImage("���_�޴�")->render(getMemDC(), _itemWindow->itemMenu.left, _itemWindow->itemMenu.top);
		IMAGE->findImage("���_������")->render(getMemDC(), _itemWindow->itemList.left, _itemWindow->itemList.top);
		//���� �غ���... �� �� ������
		if (_click == CLICK::SELECT)	{ IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _itemWindow->itemSelect[0].left, _itemWindow->itemSelect[0].top); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT1)	{ IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _itemWindow->itemSelect[1].left, _itemWindow->itemSelect[1].top); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT2)	{ IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _itemWindow->itemSelect[2].left, _itemWindow->itemSelect[2].top); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT3)	{ IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _itemWindow->itemSelect[3].left, _itemWindow->itemSelect[3].top); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT4)	{ IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _itemWindow->itemSelect[4].left, _itemWindow->itemSelect[4].top); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT5)	{ IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _itemWindow->itemSelect[5].left, _itemWindow->itemSelect[5].top); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT6)	{ IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _itemWindow->itemSelect[6].left, _itemWindow->itemSelect[6].top); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT7)	{ IMAGE->findImage("���_Ŭ��")->render(getMemDC(), _itemWindow->itemSelect[7].left, _itemWindow->itemSelect[7].top); _click == CLICK::NONE; }
		IMAGE->findImage("���")->render(getMemDC(), _itemWindow->itemSelect[0]. left+ 18, _itemWindow->itemSelect[0].top + 5);
		IMAGE->findImage("�ص���")->render(getMemDC(), _itemWindow->itemSelect[1].left + 18, _itemWindow->itemSelect[1].top + 5);
		IMAGE->findImage("�����Ǵ���")->render(getMemDC(), _itemWindow->itemSelect[2].left + 18, _itemWindow->itemSelect[2].top + 5);
		IMAGE->findImage("ȣ��������")->render(getMemDC(), _itemWindow->itemSelect[3].left + 18, _itemWindow->itemSelect[3].top + 5);
		IMAGE->findImage("ȸ����")->render(getMemDC(), _itemWindow->itemSelect[4].left + 18, _itemWindow->itemSelect[4].top + 5);
		IMAGE->findImage("����¾�")->render(getMemDC(), _itemWindow->itemSelect[5].left + 18, _itemWindow->itemSelect[5].top + 5);
		IMAGE->findImage("����ī")->render(getMemDC(), _itemWindow->itemSelect[6].left + 18, _itemWindow->itemSelect[6].top + 5);
		IMAGE->findImage("�������")->render(getMemDC(), _itemWindow->itemSelect[7].left + 18, _itemWindow->itemSelect[7].top + 5);
	

		//�޴� �ؽ�Ʈ
		TCHAR str1[10], str2[10];
		wsprintf(str1, "��Ī");
		wsprintf(str2, "����");
		TextOut(getMemDC(), _itemWindow->itemMenu.left + 55, _itemWindow->itemMenu.top + 10, str1, lstrlen(str1));
		TextOut(getMemDC(), _itemWindow->itemMenu.left + 300, _itemWindow->itemMenu.top + 10, str2, lstrlen(str2));
		SetTextColor(getMemDC(), RGB(0, 0, 0));

		//��ư �ؽ�Ʈ
		TextOut(getMemDC(), _itemWindow->buyButton.left + 85, _itemWindow->buyButton.top + 5, "����", lstrlen("����"));
		TextOut(getMemDC(), _itemWindow->unitButton.left + 60, _itemWindow->unitButton.top + 5, "����Ʈ �϶�", lstrlen("����Ʈ �϶�"));
		TextOut(getMemDC(), _itemWindow->closeButton.left + 70, _itemWindow->closeButton.top + 5, "���ƿ���", lstrlen("���ƿ���"));


		//������ �ؽ�Ʈ
		for (int i = 0; i < ITEMMAX; i++)
		{
			TextOut(getMemDC(), _itemWindow->itemSelect[i].left + 50, _itemWindow->itemSelect[i].top + 10, _vItem[i]->name.c_str(), lstrlen(_vItem[i]->name.c_str()));
		}

		//���� �ؽ�Ʈ
		for (int i = 0; i < ITEMMAX; i++)
		{
			TextOut(getMemDC(), _itemWindow->itemSelect[i].left + 300, _itemWindow->itemSelect[i].top + 10, to_string(_vItem[i]->money).c_str(), lstrlen(to_string(_vItem[i]->money).c_str()));
		}
		
		//����â �ؽ�Ʈ
		RECT temp_des = RectMake(_itemWindow->descriptionBox.left + 2, _itemWindow->descriptionBox.top + 2, _itemWindow->descriptionBox.right - _itemWindow->descriptionBox.left - 2, _itemWindow->descriptionBox.bottom - _itemWindow->descriptionBox.top - 2);
		if (_click == CLICK::SELECT) 	{ DrawText(getMemDC(), _vItem[0]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT1)	{ DrawText(getMemDC(), _vItem[1]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT2)	{ DrawText(getMemDC(), _vItem[2]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT3)	{ DrawText(getMemDC(), _vItem[3]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT4)	{ DrawText(getMemDC(), _vItem[4]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT5)	{ DrawText(getMemDC(), _vItem[5]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT6)	{ DrawText(getMemDC(), _vItem[6]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); _click == CLICK::NONE; }
		if (_click == CLICK::SELECT7)	{ DrawText(getMemDC(), _vItem[7]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); _click == CLICK::NONE; }
		
		//������ �ؽ�Ʈ
		//���߿� ������ ���ķ� �ٽ� ������
		//SetTextAlign(hdc, TA_RIGHT);	//������ ����
		TextOut(getMemDC(), _itemWindow->descriptionBox.right + 10, _itemWindow->descriptionBox.top + 5, "������", lstrlen("������"));
		TextOut(getMemDC(), _itemWindow->descriptionBox.right + 140, _itemWindow->descriptionBox.top + 5, to_string(money).c_str(), lstrlen(to_string(money).c_str()));
		TextOut(getMemDC(), _itemWindow->descriptionBox.right + 180, _itemWindow->descriptionBox.top + 5, "G", lstrlen("G"));
	

	}

	if (_itemWindow->isBuyButton)
	{

		lightGrayDraw(_itemWindow->buyWindow);

		brush = CreateSolidBrush(RGB(0, 0, 153));
		Rectangle(getMemDC(), _itemWindow->buyWin_name.left, _itemWindow->buyWin_name.top, _itemWindow->buyWin_name.right, _itemWindow->buyWin_name.bottom);
		FillRect(getMemDC(), &_itemWindow->buyWin_name, brush);
		DeleteObject(brush);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), _itemWindow->buyWin_name.left + 3, _itemWindow->buyWin_name.top + 6, "�� �� ��ڽ��ϱ�?", lstrlen("�� �� ��ڽ��ϱ�?"));
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), _itemWindow->buyWin_name.left + 13, _itemWindow->buyWin_name.bottom + 12, "����", lstrlen("����"));

		Rectangle(getMemDC(), _itemWindow->buyWin_num.left, _itemWindow->buyWin_num.top, _itemWindow->buyWin_num.right, _itemWindow->buyWin_num.bottom);
		Rectangle(getMemDC(), _itemWindow->buyWin_numUp.left, _itemWindow->buyWin_numUp.top, _itemWindow->buyWin_numUp.right, _itemWindow->buyWin_numUp.bottom);
		TextOut(getMemDC(), _itemWindow->buyWin_numUp.left + 7, _itemWindow->buyWin_numUp.top, "��", lstrlen("��"));
		Rectangle(getMemDC(), _itemWindow->buyWin_numDown.left, _itemWindow->buyWin_numDown.top, _itemWindow->buyWin_numDown.right, _itemWindow->buyWin_numDown.bottom);
		TextOut(getMemDC(), _itemWindow->buyWin_numUp.left + 7, _itemWindow->buyWin_numDown.top, "��", lstrlen("��"));

		TCHAR str[20];
		wsprintf(str, "%d", _itemWindow->buyItem_num);
		TextOut(getMemDC(), _itemWindow->buyWin_num.left + 3, _itemWindow->buyWin_num.top + 7, str, lstrlen(str));
		
		TextOut(getMemDC(), _itemWindow->buyWin_name.left + 13, _itemWindow->buyWin_name.bottom + 52, "������", lstrlen("������"));
		wsprintf(str, "%d", money);
		TextOut(getMemDC(), _itemWindow->buyWin_name.left + 120, _itemWindow->buyWin_name.bottom + 52, str, lstrlen(str));
		
		/*
		0.���
		1.�ص���
		2.�����Ǵ���
		3.ȣ��������
		4.ȸ����
		5.ġ����
		6.����¾�
		7.����ī
		*/

		//�� ���� ���� ����
		TextOut(getMemDC(), _itemWindow->buyWin_name.left + 13, _itemWindow->buyWin_name.bottom + 84, "�ݾ�", lstrlen("�ݾ�"));
		if (_click == CLICK::SELECT)
		{
			_viItem = _vItem.begin();
			wsprintf(str, "%d", ((_vItem[0])->money) * _itemWindow->buyItem_num);
			TextOut(getMemDC(), _itemWindow->buyWin_name.left + 120, _itemWindow->buyWin_name.bottom + 84, str, lstrlen(str));
		}
		else if (_click == CLICK::SELECT1)
		{
			_viItem = _vItem.begin() + 1;
			wsprintf(str, "%d", ((_vItem[1])->money)* _itemWindow->buyItem_num);
			TextOut(getMemDC(), _itemWindow->buyWin_name.left + 120, _itemWindow->buyWin_name.bottom + 84, str, lstrlen(str));
		}
		else if (_click == CLICK::SELECT2)
		{
			_viItem = _vItem.begin() + 2;
			wsprintf(str, "%d", ((_vItem[2])->money) * _itemWindow->buyItem_num);
			TextOut(getMemDC(), _itemWindow->buyWin_name.left + 120, _itemWindow->buyWin_name.bottom + 84, str, lstrlen(str));
		}
		else if (_click == CLICK::SELECT3)
		{
			_viItem = _vItem.begin() + 3;
			wsprintf(str, "%d", ((_vItem[3])->money) * _itemWindow->buyItem_num);
			TextOut(getMemDC(), _itemWindow->buyWin_name.left + 120, _itemWindow->buyWin_name.bottom + 84, str, lstrlen(str));
		}
		else if (_click == CLICK::SELECT4)
		{
			_viItem = _vItem.begin() + 4;
			wsprintf(str, "%d", ((_vItem[4])->money) * _itemWindow->buyItem_num);
			TextOut(getMemDC(), _itemWindow->buyWin_name.left + 120, _itemWindow->buyWin_name.bottom + 84, str, lstrlen(str));
		}
		else if (_click == CLICK::SELECT5)
		{
			_viItem = _vItem.begin() + 5;
			wsprintf(str, "%d", ((_vItem[5])->money) * _itemWindow->buyItem_num);
			TextOut(getMemDC(), _itemWindow->buyWin_name.left + 120, _itemWindow->buyWin_name.bottom + 84, str, lstrlen(str));
		}
		else if (_click == CLICK::SELECT6)
		{
			_viItem = _vItem.begin() + 6;
			wsprintf(str, "%d", ((_vItem[6])->money) * _itemWindow->buyItem_num);
			TextOut(getMemDC(), _itemWindow->buyWin_name.left + 120, _itemWindow->buyWin_name.bottom + 84, str, lstrlen(str));
		}
		else if (_click == CLICK::SELECT7)
		{
			_viItem = _vItem.begin() + 7;
			wsprintf(str, "%d", ((_vItem[7])->money) * _itemWindow->buyItem_num);
			TextOut(getMemDC(), _itemWindow->buyWin_name.left + 120, _itemWindow->buyWin_name.bottom + 84, str, lstrlen(str));
		}

		
		shadowDraw(_itemWindow->buyWin_buyButton);
		lightDraw(_itemWindow->buyWin_buyButton);
		
		lightGrayDraw(_itemWindow->buyWin_buyButton);
		TextOut(getMemDC(), _itemWindow->buyWin_buyButton.left + 25, _itemWindow->buyWin_buyButton.top + 7, "�����Ѵ�!", lstrlen("�����Ѵ�!"));
		
		shadowDraw(_itemWindow->buyWin_exitButton);
		lightDraw(_itemWindow->buyWin_exitButton);
		
		lightGrayDraw(_itemWindow->buyWin_exitButton);
		TextOut(getMemDC(), _itemWindow->buyWin_exitButton.left + 19, _itemWindow->buyWin_exitButton.top + 7, "�׸�����", lstrlen("�׸�����"));
	
	}


	//���ƿ���
	if (_itemWindow->isClosed)
	{
		_activeTime++;

		if (_activeTime >= 0 && _activeTime < 70)
		{
			isOpen = false;

			IMAGE->render("��ȭ_����", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("��ȭ_����2", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("�̹���_����", getMemDC(), 600, 470);

			HFONT font, oldfont;
			SetBkMode(getMemDC(), TRANSPARENT);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			TextOut(getMemDC(), 50, WINSIZEY - 260, "��ȭ����", lstrlen("��ȭ����"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(250, 244, 192));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "��ȭ����", lstrlen("��ȭ����"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(36, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 225, "�� �� ������! ��", lstrlen("�� �� ������! ��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}
		
		if (_activeTime >= 70)
		{
			town_active = true;
			//itemStore_active = false;
			//SCENE->changeScene("townMap");
		}
	}

	//���� �϶�.
	//if (_unitList->getActive())_unitList->render();
}

void itemStore::BuyItem()
{
	if (_click == CLICK::SELECT && money >= _vItem[0]->money)
	{
		//�̹� �����ϴ��� �Ǻ�.
		bool isExist = false;

		_viTools = _vTools.begin();
		for (_viTools; _viTools != _vTools.end(); ++_viTools)
		{
			if ((*_viTools)->name == _vItem[0]->name)
			{
				isExist = true;
				(*_viTools)->num += _itemWindow->buyItem_num;

				if ((*_viTools)->num == 0)
				{
					_click = CLICK::NONE;
					_vTools.erase(_viTools);
					SAFE_DELETE(*_viTools);
				}
			}
		}

		if (!(isExist))
		{
			tagItemInfo* item;
			item = new tagItemInfo;
			item->name = _vItem[0]->name;
			item->detail = _vItem[0]->detail;
			item->num = _itemWindow->buyItem_num;
			item->money = _vItem[0]->money;
			item->iconImg = _vItem[0]->iconImg;

			_vTools.push_back(item);
		}
		
		_viItem = _vItem.begin();
		money -= ((_vItem[0]->money) * _itemWindow->buyItem_num);
	
		(_vItem[0])->num += _itemWindow->buyItem_num;
	
	}
	if (_click == CLICK::SELECT1 && money >= _vItem[1]->money)
	{
		//�̹� �����ϴ��� �Ǻ�.
		bool isExist = false;

		_viTools = _vTools.begin();
		for (_viTools; _viTools != _vTools.end(); ++_viTools)
		{
			if ((*_viTools)->name == _vItem[1]->name)
			{
				isExist = true;
				(*_viTools)->num += _itemWindow->buyItem_num;

				if ((*_viTools)->num == 0)
				{
					_click = CLICK::NONE;
					_vTools.erase(_viTools);
					SAFE_DELETE(*_viTools);
				}
			}
		}

		if (!(isExist))
		{
			tagItemInfo* item;
			item = new tagItemInfo;
			item->name = _vItem[1]->name;
			item->detail = _vItem[1]->detail;
			item->num = _itemWindow->buyItem_num;
			item->money = _vItem[1]->money;
			item->iconImg = _vItem[1]->iconImg;

			_vTools.push_back(item);
		}

		_viItem = _vItem.begin();
		money -= ((_vItem[1]->money) * _itemWindow->buyItem_num);
		//_unitList->setMoney(_unitList->getMoney() - ((_vItem[1]->money) * _itemWindow->buyItem_num));

		(_vItem[1])->num += _itemWindow->buyItem_num;

		if ((_vItem[1])->num == 0)
		{
			_click = CLICK::NONE;
			_vItem.erase(_viItem);
		}
	}
	else if (_click == CLICK::SELECT2 && money >= _vItem[2]->money)
	{
		//�̹� �����ϴ��� �Ǻ�.
		bool isExist = false;

		_viTools = _vTools.begin();
		for (_viTools; _viTools != _vTools.end(); ++_viTools)
		{
			if ((*_viTools)->name == _vItem[2]->name)
			{
				isExist = true;
				(*_viTools)->num += _itemWindow->buyItem_num;

				if ((*_viTools)->num == 0)
				{
					_click = CLICK::NONE;
					_vTools.erase(_viTools);
					SAFE_DELETE(*_viTools);
				}
			}
		}

		if (!(isExist))
		{
			tagItemInfo* item;
			item = new tagItemInfo;
			item->name = _vItem[2]->name;
			item->detail = _vItem[2]->detail;
			item->num = _itemWindow->buyItem_num;
			item->money = _vItem[2]->money;
			item->iconImg = _vItem[2]->iconImg;

			_vTools.push_back(item);
		}

		_viItem = _vItem.begin();
		money -= ((_vItem[2]->money) * _itemWindow->buyItem_num);
		//_unitList->setMoney(_unitList->getMoney() - ((_vItem[2]->money) * _itemWindow->buyItem_num));

		(_vItem[2])->num += _itemWindow->buyItem_num;

		if ((_vItem[2])->num == 0)
		{
			_click = CLICK::NONE;
			_vItem.erase(_viItem);
		}
	}
	else if (_click == CLICK::SELECT3 && money >= _vItem[3]->money)
	{
		//�̹� �����ϴ��� �Ǻ�.
		bool isExist = false;

		_viTools = _vTools.begin();
		for (_viTools; _viTools != _vTools.end(); ++_viTools)
		{
			if ((*_viTools)->name == _vItem[3]->name)
			{
				isExist = true;
				(*_viTools)->num += _itemWindow->buyItem_num;

				if ((*_viTools)->num == 0)
				{
					_click = CLICK::NONE;
					_vTools.erase(_viTools);
					SAFE_DELETE(*_viTools);
				}
			}
		}

		if (!(isExist))
		{
			tagItemInfo* item;
			item = new tagItemInfo;
			item->name = _vItem[3]->name;
			item->detail = _vItem[3]->detail;
			item->num = _itemWindow->buyItem_num;
			item->money = _vItem[3]->money;
			item->iconImg = _vItem[3]->iconImg;

			_vTools.push_back(item);
		}

		_viItem = _vItem.begin();
		money -= ((_vItem[3]->money) * _itemWindow->buyItem_num);
		//_unitList->setMoney(_unitList->getMoney() - ((_vItem[3]->money) * _itemWindow->buyItem_num));

		(_vItem[3])->num += _itemWindow->buyItem_num;

		if ((_vItem[3])->num == 0)
		{
			_click = CLICK::NONE;
			_vItem.erase(_viItem);
		}
	}
	else if (_click == CLICK::SELECT4 && money >= _vItem[4]->money)
	{
		//�̹� �����ϴ��� �Ǻ�.
		bool isExist = false;

		_viTools = _vTools.begin();
		for (_viTools; _viTools != _vTools.end(); ++_viTools)
		{
			if ((*_viTools)->name == _vItem[4]->name)
			{
				isExist = true;
				(*_viTools)->num += _itemWindow->buyItem_num;

				if ((*_viTools)->num == 0)
				{
					_click = CLICK::NONE;
					_vTools.erase(_viTools);
					SAFE_DELETE(*_viTools);
				}
			}
		}

		if (!(isExist))
		{
			tagItemInfo* item;
			item = new tagItemInfo;
			item->name = _vItem[4]->name;
			item->detail = _vItem[4]->detail;
			item->num = _itemWindow->buyItem_num;
			item->money = _vItem[4]->money;
			item->iconImg = _vItem[4]->iconImg;

			_vTools.push_back(item);
		}

		_viItem = _vItem.begin();
		money -= ((_vItem[4]->money) * _itemWindow->buyItem_num);
		//_unitList->setMoney(_unitList->getMoney() - ((_vItem[4]->money) * _itemWindow->buyItem_num));

		(_vItem[4])->num += _itemWindow->buyItem_num;

		if ((_vItem[4])->num == 0)
		{
			_click = CLICK::NONE;
			_vItem.erase(_viItem);
		}
	}
	else if (_click == CLICK::SELECT5 && money >= _vItem[5]->money)
	{
		//�̹� �����ϴ��� �Ǻ�.
		bool isExist = false;

		_viTools = _vTools.begin();
		for (_viTools; _viTools != _vTools.end(); ++_viTools)
		{
			if ((*_viTools)->name == _vItem[5]->name)
			{
				isExist = true;
				(*_viTools)->num += _itemWindow->buyItem_num;

				if ((*_viTools)->num == 0)
				{
					_click = CLICK::NONE;
					_vTools.erase(_viTools);
					SAFE_DELETE(*_viTools);
				}
			}
		}

		if (!(isExist))
		{
			tagItemInfo* item;
			item = new tagItemInfo;
			item->name = "ġ����";
			item->detail = _vItem[5]->detail;
			item->num = _itemWindow->buyItem_num;
			item->money = _vItem[5]->money;
			item->iconImg = _vItem[5]->iconImg;

			_vTools.push_back(item);
		}

		_viItem = _vItem.begin();
		money -= ((_vItem[5]->money) * _itemWindow->buyItem_num);
		//_unitList->setMoney(_unitList->getMoney() - ((_vItem[5]->money) * _itemWindow->buyItem_num));

		(_vItem[5])->num += _itemWindow->buyItem_num;

		if ((_vItem[5])->num == 0)
		{
			_click = CLICK::NONE;
			_vItem.erase(_viItem);
		}
	}
	else if (_click == CLICK::SELECT6 && money >= _vItem[6]->money)
	{
		//�̹� �����ϴ��� �Ǻ�.
		bool isExist = false;

		_viTools = _vTools.begin();
		for (_viTools; _viTools != _vTools.end(); ++_viTools)
		{
			if ((*_viTools)->name == _vItem[6]->name)
			{
				isExist = true;
				(*_viTools)->num += _itemWindow->buyItem_num;

				if ((*_viTools)->num == 0)
				{
					_click = CLICK::NONE;
					_vTools.erase(_viTools);
					SAFE_DELETE(*_viTools);
				}
			}
		}

		if (!(isExist))
		{
			tagItemInfo* item;
			item = new tagItemInfo;
			item->name = _vItem[6]->name;
			item->detail = _vItem[6]->detail;
			item->num = _itemWindow->buyItem_num;
			item->money = _vItem[6]->money;
			item->iconImg = _vItem[6]->iconImg;

			_vTools.push_back(item);
		}

		_viItem = _vItem.begin();
		money -= ((_vItem[6]->money) * _itemWindow->buyItem_num);
		//_unitList->setMoney(_unitList->getMoney() - ((_vItem[6]->money) * _itemWindow->buyItem_num));

		(_vItem[6])->num += _itemWindow->buyItem_num;

		if ((_vItem[6])->num == 0)
		{
			_click = CLICK::NONE;
			_vItem.erase(_viItem);
		}
	}
	else if (_click == CLICK::SELECT7 && money >= _vItem[7]->money)
	{
		//�̹� �����ϴ��� �Ǻ�.
		bool isExist = false;

		_viTools = _vTools.begin();
		for (_viTools; _viTools != _vTools.end(); ++_viTools)
		{
			if ((*_viTools)->name == _vItem[7]->name)
			{
				isExist = true;
				(*_viTools)->num += _itemWindow->buyItem_num;

				if ((*_viTools)->num == 0)
				{
					_click = CLICK::NONE;
					_vTools.erase(_viTools);
					SAFE_DELETE(*_viTools);
				}
			}
		}

		if (!(isExist))
		{
			tagItemInfo* item;
			item = new tagItemInfo;
			item->name = _vItem[7]->name;
			item->detail = _vItem[7]->detail;
			item->num = _itemWindow->buyItem_num;
			item->money = _vItem[7]->money;
			item->iconImg = _vItem[7]->iconImg;

			_vTools.push_back(item);
		}

		_viItem = _vItem.begin();
		money -= ((_vItem[7]->money) * _itemWindow->buyItem_num);
		//_unitList->setMoney(_unitList->getMoney() - ((_vItem[7]->money) * _itemWindow->buyItem_num));

		(_vItem[7])->num += _itemWindow->buyItem_num;

		if ((_vItem[7])->num == 0)
		{
			_click = CLICK::NONE;
			_vItem.erase(_viItem);
		}
	}
	
	//_unitList->_unit[0]._vTools = _vItem;
}

void itemStore::lightGrayDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(220, 220, 220));
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	FillRect(getMemDC(), &rc, brush);
	DeleteObject(brush);
}

void itemStore::shadowDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(051, 051, 051));
	RECT shadow = RectMake(rc.left + 3, rc.top + 3, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), shadow.left, shadow.top, shadow.right, shadow.bottom);
	FillRect(getMemDC(), &shadow, brush);
	DeleteObject(brush);
}

void itemStore::lightDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	RECT light = RectMake(rc.left - 1, rc.top - 1, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
	FillRect(getMemDC(), &light, brush);
	DeleteObject(brush);
}



