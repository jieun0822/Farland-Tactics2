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
	IMAGE->addFrameImage("상인", "images/npc_02.bmp", 589, 120, 7, 1, true, RGB(255, 0, 255));

	////상점주인,플레이어 일러스트
	IMAGE->addImage("이미지_무기상인", "images/face16b.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("이미지_플레이어2", "images/face02b.bmp", 360, 250, true, RGB(255, 255, 255));

	//실험용초기화
	_unitListEx = new UnitList;
	_unitListEx->init();


	//창 생성
	_equipWindow = new EquipWindow;
	_equipWindow->outLine = RectMake(270, 120, 500, 500);
	_equipWindow->isClosed = false;
	//_equipWindow->isBuyButton = false;
	_equipWindow->warning = RectMake(_equipWindow->outLine.right / 2, _equipWindow->outLine.bottom / 2, 150, 100);//실험용 경고창

	int outlineWidth = _equipWindow->outLine.right - _equipWindow->outLine.left;
	int outlintHeight = _equipWindow->outLine.bottom - _equipWindow->outLine.top;

	//창 제목
	_equipWindow->windowName = RectMake(_equipWindow->outLine.left + 3, _equipWindow->outLine.top + 3, outlineWidth - 6, 30 - 6);

	//메뉴 구분
	_equipWindow->equipMenu = RectMake(_equipWindow->outLine.left + 3, _equipWindow->outLine.top + 32, outlineWidth - 6, 30);

	//아이템 리스트
	_equipWindow->equipList = RectMake(_equipWindow->outLine.left + 3, _equipWindow->outLine.top + 70, outlineWidth - 6, 270);

	int equipListWidth = _equipWindow->equipList.right - _equipWindow->equipList.left;
	int equipListHeight = _equipWindow->equipList.bottom - _equipWindow->equipList.top;

	//아이템 설명란
	_equipWindow->descriptionBox = RectMake(_equipWindow->outLine.left + 5, _equipWindow->outLine.top + 350, outlineWidth - 220, 140);

	//소지금 표시창
	_equipWindow->goldBox = RectMake(_equipWindow->descriptionBox.right + 8, _equipWindow->descriptionBox.top, outlineWidth - 300, 27);

	int goldBoxWidth = _equipWindow->goldBox.right - _equipWindow->goldBox.left;
	int goldBoxHeight = _equipWindow->goldBox.bottom - _equipWindow->goldBox.top;

	//버튼
	//구매 버튼
	_equipWindow->buyButton = RectMake(_equipWindow->goldBox.left, _equipWindow->goldBox.bottom + 5, goldBoxWidth, goldBoxHeight);

	//유니트 일람
	_equipWindow->unitButton = RectMake(_equipWindow->goldBox.left, _equipWindow->buyButton.bottom + 10, goldBoxWidth, goldBoxHeight);

	//닫기
	_equipWindow->closeButton = RectMake(_equipWindow->goldBox.left, _equipWindow->unitButton.bottom + 10, goldBoxWidth, goldBoxHeight);


	//아이템 선택 박스
	_equipWindow->itemSelect[0] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 2, equipListWidth - 2, 30);
	_equipWindow->itemSelect[1] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 32, equipListWidth - 2, 30);
	_equipWindow->itemSelect[2] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 62, equipListWidth - 2, 30);
	_equipWindow->itemSelect[3] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 92, equipListWidth - 2, 30);
	_equipWindow->itemSelect[4] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 122, equipListWidth - 2, 30);
	_equipWindow->itemSelect[5] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 152, equipListWidth - 2, 30);
	_equipWindow->itemSelect[6] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 182, equipListWidth - 2, 30);
	_equipWindow->itemSelect[7] = RectMake(_equipWindow->equipList.left + 2, _equipWindow->equipList.top + 212, equipListWidth - 2, 30);

	//아이템 추가 (벡터)
	///무기
	tagEquipInfo* equip = new tagEquipInfo;

	equip = new tagEquipInfo;
	equip->name = "브로드소드";
	equip->detail = "폭이 넓은 검. \n롱소드보다 조금 더 강하다. \n공격력 + 10";
	equip->money = 150;
	equip->kind = EQUIP_KIND::WEAPON;
	equip->num = 0;
	equip->iconImg = IMAGE->addImage("무기", "images/sword.bmp", 19, 19, true, RGB(128, 0, 128));
	equip->offensePower = 10;
	equip->defense = 0;
	equip->intellect = 0;
	equip->magicDrag = 0;
	equip->agility = 0;
	_vEquip.push_back(equip);

	equip = new tagEquipInfo;
	equip->name = "크레이모어";
	equip->detail = "한손으로도 양손으로도 \n사용 가능한 검. \n위력이 높아서, 초심자가 다루기에는 \n무리가 있다. \n공격력 + 20";
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
	equip->name = "그레이트소드";
	equip->detail = "양손검 중에서 가장 오랫동안 사용되었다. \n무겁지만 강력하다. \n공격력 + 45";
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
	equip->name = "플란벨쥬";
	equip->detail = "숙련된 대장장이가 심혈을 기울여 \n만들었다고 전해지는 \n전설의 대검. \n공격력 + 50";
	equip->kind = EQUIP_KIND::WEAPON;
	equip->money = 1000;
	equip->num = 0;
	equip->offensePower = 50;
	equip->defense = 0;
	equip->intellect = 0;
	equip->magicDrag = 0;
	equip->agility = -5;
	_vEquip.push_back(equip);

	/// 방어구
	equip = new tagEquipInfo;
	equip->name = "레더 프로텍터";
	equip->detail = "범용성과 편한 착용감이 \n장점인 가죽갑옷. \n방어력이 거의 없으니, \n큰 기대는 하지 않는 것이 좋다. \n방어력 +8";
	equip->kind = EQUIP_KIND::ARMOR;
	equip->money = 90;
	equip->num = 0;
	equip->iconImg = IMAGE->addImage("방어구", "images/armor.bmp", 19, 19, true, RGB(128, 0, 128));
	equip->offensePower = 0;
	equip->defense = 8;
	equip->intellect = 0;
	equip->magicDrag = 0;
	equip->agility = -1;
	_vEquip.push_back(equip);

	equip = new tagEquipInfo;
	equip->name = "링메일";
	equip->detail = "금속제 아머의 표면에, 급소를 \n보호해주는 링이 부착된 것. \n방어력 +20, 마항력 +2";
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
	equip->name = "프레스트아머";
	equip->detail = "다양한 소재를 사용하여 \n방어구의 성능을 향상시킨 갑옷. \n다소의 공격으로는 꿈쩍도 하지 않는다. 방어력 +32, 마항력 +5";
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
	equip->name = "드래고닉하트";
	equip->detail = "귀중한 용소재로 제작되었다. \n희소성이 큰 갑옷이므로, 이것을 입으면 무척 눈에 띈다. \n방어력 +45, 마항력 +10";
	equip->kind = EQUIP_KIND::ARMOR;
	equip->money = 800;
	equip->num = 0;
	equip->offensePower = 0;
	equip->defense = 45;
	equip->intellect = 0;
	equip->magicDrag = 10;
	equip->agility = -8;
	_vEquip.push_back(equip);

	//이미지
	IMAGE->addImage("배경_메뉴", "images/itemWindow_basic.bmp", _equipWindow->equipMenu.right - _equipWindow->equipMenu.left,
		_equipWindow->equipMenu.bottom - _equipWindow->equipMenu.top, true, RGB(255, 0, 255));
	IMAGE->addImage("배경_아이템", "images/itemWindow_list.bmp", _equipWindow->equipList.right - _equipWindow->equipList.left,
		_equipWindow->equipList.bottom - _equipWindow->equipList.top, true, RGB(255, 0, 255));

	for (int i = 0; i < 7; i++)
	{
		IMAGE->addImage("배경_클릭", "images/backGround_blue.bmp", _equipWindow->itemSelect[i].right - _equipWindow->itemSelect[i].left,
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

			//돌아오기
			if (PtInRect(&_equipWindow->closeButton, m_ptMouse) && isOpen)
			{
				isOpen = !isOpen;
				_equipWindow->isClosed = true;
			}

			//유닛일람
			if (PtInRect(&_equipWindow->unitButton, m_ptMouse))
			{
				unitList_active = true;
			}

			if (PtInRect(&_equipWindow->buyButton, m_ptMouse))
			{
				BuyEquip();
			}

			//열렸을때
			if (isOpen && !(_equipWindow->isClosed))
			{
				//아이템 선택 시
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
	IMAGE->frameRender("상인", getMemDC(), 285, 255);

	HFONT font, oldfont;
	SetBkMode(getMemDC(), TRANSPARENT);

	
	activeTime++;
	if (activeTime >= 30 && !(_equipWindow->isClosed))
	{
		IMAGE->render("대화_상인", getMemDC(), 0, 10);
		IMAGE->alphaRender("대화_상인2", getMemDC(), 0, 10, 170);
		IMAGE->render("이미지_무기상인", getMemDC(), 15, 12);



		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 380, 55, "근육 아저씨", lstrlen("근육 아저씨"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(250, 244, 192));
		TextOut(getMemDC(), 380, 55, "근육 아저씨", lstrlen("근육 아저씨"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(42, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 385, 90, "「 어서 오세요.", lstrlen("「 어서 오세요."));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);

		font = CreateFont(30, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
		oldfont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TextOut(getMemDC(), 385, 150, "　　좋은 무기가 다 있어요! 」", lstrlen("　　좋은 무기가 다 있어요! 」"));
		SelectObject(getMemDC(), oldfont);
		DeleteObject(font);


		if (activeTime >= 80)
		{
			//좌표 저장용 복사
			IMAGE->render("대화_플레이어", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("대화_플레이어2", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("이미지_플레이어2", getMemDC(), 622, 450);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			TextOut(getMemDC(), 50, WINSIZEY - 260, "알", lstrlen("알"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(250, 244, 192));
			TextOut(getMemDC(), 50, WINSIZEY - 260, "알", lstrlen("알"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 225, "「 기운이 넘치는 아저씨네. 」", lstrlen("「 기운이 넘치는 아저씨네. 」"));
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
		//전체 창 그리기
		brush = CreateSolidBrush(RGB(204, 204, 204));
		Rectangle(getMemDC(), _equipWindow->outLine.left, _equipWindow->outLine.top, _equipWindow->outLine.right, _equipWindow->outLine.bottom);
		FillRect(getMemDC(), &_equipWindow->outLine, brush);
		DeleteObject(brush);

		//물품목록 창 제목
		brush = CreateSolidBrush(RGB(0, 0, 153));
		Rectangle(getMemDC(), _equipWindow->windowName.left, _equipWindow->windowName.top, _equipWindow->windowName.right, _equipWindow->windowName.bottom);
		FillRect(getMemDC(), &_equipWindow->windowName, brush);
		DeleteObject(brush);

		//물품목록 창 텍스트
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TCHAR str[10];
		SetBkMode(getMemDC(), TRANSPARENT);
		wsprintf(str, "물품목록");
		TextOut(getMemDC(), _equipWindow->windowName.left + 5, _equipWindow->windowName.top + 5, str, lstrlen(str));
		SetTextColor(getMemDC(), RGB(0, 0, 0));

		//메뉴 구분 창
		hpen = CreatePen(PS_SOLID, 1, RGB(111, 111, 111));
		hpenOld = (HPEN)::SelectObject(getMemDC(), (HGDIOBJ)hpen);
		brush = CreateSolidBrush(RGB(204, 204, 204));
		oldBrush = (HBRUSH)::SelectObject(getMemDC(), brush);
		Rectangle(getMemDC(), _equipWindow->descriptionBox.left, _equipWindow->descriptionBox.top, _equipWindow->descriptionBox.right, _equipWindow->descriptionBox.bottom);
		hpen = (HPEN)::SelectObject(getMemDC(), hpenOld);
		brush = (HBRUSH)::SelectObject(getMemDC(), oldBrush);
		DeleteObject(hpen);
		DeleteObject(brush);


		//버튼 그림자
		brush = CreateSolidBrush(RGB(93, 93, 93));
		//구매
		RECT shadow = RectMake(_equipWindow->buyButton.left + 3, _equipWindow->buyButton.top + 3, _equipWindow->buyButton.right - _equipWindow->buyButton.left, _equipWindow->buyButton.bottom - _equipWindow->buyButton.top);
		Rectangle(getMemDC(), shadow.left, shadow.top, shadow.right, shadow.bottom);
		FillRect(getMemDC(), &shadow, brush);
		//유니트 일람
		RECT shadow2 = RectMake(_equipWindow->unitButton.left + 3, _equipWindow->unitButton.top + 3, _equipWindow->unitButton.right - _equipWindow->unitButton.left, _equipWindow->unitButton.bottom - _equipWindow->unitButton.top);
		Rectangle(getMemDC(), shadow2.left, shadow2.top, shadow2.right, shadow2.bottom);
		FillRect(getMemDC(), &shadow2, brush);
		//닫기
		RECT shadow3 = RectMake(_equipWindow->closeButton.left + 3, _equipWindow->closeButton.top + 3, _equipWindow->closeButton.right - _equipWindow->closeButton.left, _equipWindow->closeButton.bottom - _equipWindow->closeButton.top);
		Rectangle(getMemDC(), shadow3.left, shadow3.top, shadow3.right, shadow3.bottom);
		FillRect(getMemDC(), &shadow3, brush);
		DeleteObject(brush);

		//버튼 테두리
		brush = CreateSolidBrush(RGB(255, 255, 255));
		//구매
		RECT light = RectMake(_equipWindow->buyButton.left - 1, _equipWindow->buyButton.top - 1, _equipWindow->buyButton.right - _equipWindow->buyButton.left, _equipWindow->buyButton.bottom - _equipWindow->buyButton.top);
		Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
		FillRect(getMemDC(), &light, brush);
		//유니트 일람
		RECT light2 = RectMake(_equipWindow->unitButton.left - 1, _equipWindow->unitButton.top - 1, _equipWindow->unitButton.right - _equipWindow->unitButton.left, _equipWindow->unitButton.bottom - _equipWindow->unitButton.top);
		Rectangle(getMemDC(), light2.left, light2.top, light2.right, light2.bottom);
		FillRect(getMemDC(), &light2, brush);
		//닫기
		RECT light3 = RectMake(_equipWindow->closeButton.left - 1, _equipWindow->closeButton.top - 1, _equipWindow->closeButton.right - _equipWindow->closeButton.left, _equipWindow->closeButton.bottom - _equipWindow->closeButton.top);
		Rectangle(getMemDC(), light3.left, light3.top, light3.right, light3.bottom);
		FillRect(getMemDC(), &light3, brush);
		DeleteObject(brush);

		//버튼 생성
		//CreateWindow(TEXT("button"), TEXT("구매"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, _equipWindow->description.right + 10, _equipWindow->description.top + 30, 195, 25, m_hWnd, (HMENU)0, m_hInstance, NULL);
		brush = CreateSolidBrush(RGB(204, 204, 204));
		//구매
		Rectangle(getMemDC(), _equipWindow->buyButton.left, _equipWindow->buyButton.top, _equipWindow->buyButton.right, _equipWindow->buyButton.bottom);
		FillRect(getMemDC(), &_equipWindow->buyButton, brush);
		//유니트 일람
		Rectangle(getMemDC(), _equipWindow->unitButton.left, _equipWindow->unitButton.top, _equipWindow->unitButton.right, _equipWindow->unitButton.bottom);
		FillRect(getMemDC(), &_equipWindow->unitButton, brush);
		//닫기
		Rectangle(getMemDC(), _equipWindow->closeButton.left, _equipWindow->closeButton.top, _equipWindow->closeButton.right, _equipWindow->closeButton.bottom);
		FillRect(getMemDC(), &_equipWindow->closeButton, brush);
		DeleteObject(brush);

		IMAGE->findImage("배경_메뉴")->render(getMemDC(), _equipWindow->equipMenu.left, _equipWindow->equipMenu.top);
		IMAGE->findImage("배경_아이템")->render(getMemDC(), _equipWindow->equipList.left, _equipWindow->equipList.top);

		//메뉴 텍스트
		TCHAR str1[10], str2[10];
		wsprintf(str1, "명칭");
		wsprintf(str2, "가격");
		TextOut(getMemDC(), _equipWindow->equipMenu.left + 55, _equipWindow->equipMenu.top + 10, str1, lstrlen(str1));
		TextOut(getMemDC(), _equipWindow->equipMenu.left + 300, _equipWindow->equipMenu.top + 10, str2, lstrlen(str2));
		SetTextColor(getMemDC(), RGB(0, 0, 0));

		//버튼 텍스트
		TextOut(getMemDC(), _equipWindow->buyButton.left + 85, _equipWindow->buyButton.top + 5, "구매", lstrlen("구매"));
		TextOut(getMemDC(), _equipWindow->unitButton.left + 60, _equipWindow->unitButton.top + 5, "유니트 일람", lstrlen("유니트 일람"));
		TextOut(getMemDC(), _equipWindow->closeButton.left + 70, _equipWindow->closeButton.top + 5, "돌아오기", lstrlen("돌아오기"));


		//파란배경 렌더
		if (_click == CLICKE::SELECT) { IMAGE->findImage("배경_클릭")->render(getMemDC(), _equipWindow->itemSelect[0].left, _equipWindow->itemSelect[0].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT1) { IMAGE->findImage("배경_클릭")->render(getMemDC(), _equipWindow->itemSelect[1].left, _equipWindow->itemSelect[1].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT2) { IMAGE->findImage("배경_클릭")->render(getMemDC(), _equipWindow->itemSelect[2].left, _equipWindow->itemSelect[2].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT3) { IMAGE->findImage("배경_클릭")->render(getMemDC(), _equipWindow->itemSelect[3].left, _equipWindow->itemSelect[3].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT4) { IMAGE->findImage("배경_클릭")->render(getMemDC(), _equipWindow->itemSelect[4].left, _equipWindow->itemSelect[4].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT5) { IMAGE->findImage("배경_클릭")->render(getMemDC(), _equipWindow->itemSelect[5].left, _equipWindow->itemSelect[5].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT6) { IMAGE->findImage("배경_클릭")->render(getMemDC(), _equipWindow->itemSelect[6].left, _equipWindow->itemSelect[6].top); _click == CLICKE::NONE; }
		if (_click == CLICKE::SELECT7) { IMAGE->findImage("배경_클릭")->render(getMemDC(), _equipWindow->itemSelect[7].left, _equipWindow->itemSelect[7].top); _click == CLICKE::NONE; }
		
		//아이템 렌더
		for (int k = 0; k < 4; k++)
		{
			IMAGE->findImage("무기")->render(getMemDC(), _equipWindow->itemSelect[k].left + 18, _equipWindow->itemSelect[k].top + 8);
		}
		for (int i = 4; i < 8; i++)
		{
			IMAGE->findImage("방어구")->render(getMemDC(), _equipWindow->itemSelect[i].left + 18, _equipWindow->itemSelect[i].top + 7);
		}

		//아이템 텍스트
		for (int i = 0; i < ITEMMAX; i++)
		{
			TextOut(getMemDC(), _equipWindow->itemSelect[i].left + 50, _equipWindow->itemSelect[i].top + 10, _vEquip[i]->name.c_str(), lstrlen(_vEquip[i]->name.c_str()));
		 }
		//가격 텍스트
		for (int i = 0; i < ITEMMAX; i++)
		{
			TextOut(getMemDC(), _equipWindow->itemSelect[i].left + 300, _equipWindow->itemSelect[i].top + 10, to_string(_vEquip[i]->money).c_str(), lstrlen(to_string(_vEquip[i]->money).c_str()));
		}


		//설명창 텍스트
		RECT temp_des = RectMake(_equipWindow->descriptionBox.left + 2, _equipWindow->descriptionBox.top + 2, _equipWindow->descriptionBox.right - _equipWindow->descriptionBox.left - 2, _equipWindow->descriptionBox.bottom - _equipWindow->descriptionBox.top - 2);
		if (_click == CLICKE::SELECT) { DrawText(getMemDC(), _vEquip[0]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT1) { DrawText(getMemDC(), _vEquip[1]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT2) { DrawText(getMemDC(), _vEquip[2]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT3) { DrawText(getMemDC(), _vEquip[3]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT4) { DrawText(getMemDC(), _vEquip[4]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT5) { DrawText(getMemDC(), _vEquip[5]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT6) { DrawText(getMemDC(), _vEquip[6]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }
		if (_click == CLICKE::SELECT7) { DrawText(getMemDC(), _vEquip[7]->detail.c_str(), -1, &temp_des, DT_LEFT | DT_WORDBREAK | DT_EDITCONTROL); } //_click == CLICK::NONE; }

		
		//경고창
		//brush = CreateSolidBrush(RGB(204, 204, 204));
		//Rectangle(getMemDC(), _equipWindow->warning.left, _equipWindow->warning.top, _equipWindow->warning.right, _equipWindow->warning.bottom);
		//FillRect(getMemDC(), &_equipWindow->warning, brush);
		//DeleteObject(brush);


		//_viBuyEquip = _vBuyEquip.begin();
		//for (_viBuyEquip; _viBuyEquip != _vBuyEquip.end(); ++_viBuyEquip)
		//{
		//	if ((*_viBuyEquip)->num >= 1)
		//	{
		//		//TextOut(getMemDC(), _equipWindow->itemSelect[0].left + 380, _equipWindow->itemSelect[0].top + 10, "구매횟수 초과", lstrlen("구매횟수 초과"));
		//
		//		//brush = CreateSolidBrush(RGB(204, 204, 204));
		//		//Rectangle(getMemDC(), _equipWindow->warning.left, _equipWindow->warning.top, _equipWindow->warning.right, _equipWindow->warning.bottom);
		//		//FillRect(getMemDC(), &_equipWindow->warning, brush);
		//		//DeleteObject(brush);
		//		if (_click == CLICKE::SELECT) TextOut(getMemDC(), _equipWindow->itemSelect[0].left + 380, _equipWindow->itemSelect[0].top + 10, "구매횟수 초과", lstrlen("구매횟수 초과"));
		//		if (_click == CLICKE::SELECT1) TextOut(getMemDC(), _equipWindow->itemSelect[1].left + 380, _equipWindow->itemSelect[1].top + 10, "구매횟수 초과", lstrlen("구매횟수 초과"));
		//		if (_click == CLICKE::SELECT2) TextOut(getMemDC(), _equipWindow->itemSelect[2].left + 380, _equipWindow->itemSelect[2].top + 10, "구매횟수 초과", lstrlen("구매횟수 초과"));
		//		if (_click == CLICKE::SELECT3) TextOut(getMemDC(), _equipWindow->itemSelect[3].left + 380, _equipWindow->itemSelect[3].top + 10, "구매횟수 초과", lstrlen("구매횟수 초과"));
		//		if (_click == CLICKE::SELECT4) TextOut(getMemDC(), _equipWindow->itemSelect[4].left + 380, _equipWindow->itemSelect[4].top + 10, "구매횟수 초과", lstrlen("구매횟수 초과"));
		//		if (_click == CLICKE::SELECT5) TextOut(getMemDC(), _equipWindow->itemSelect[5].left + 380, _equipWindow->itemSelect[5].top + 10, "구매횟수 초과", lstrlen("구매횟수 초과"));
		//		if (_click == CLICKE::SELECT6) TextOut(getMemDC(), _equipWindow->itemSelect[6].left + 380, _equipWindow->itemSelect[6].top + 10, "구매횟수 초과", lstrlen("구매횟수 초과"));
		//		if (_click == CLICKE::SELECT7) TextOut(getMemDC(), _equipWindow->itemSelect[7].left + 380, _equipWindow->itemSelect[7].top + 10, "구매횟수 초과", lstrlen("구매횟수 초과"));
		//	}
		//}


		
		//소지금 텍스트
		TextOut(getMemDC(), _equipWindow->descriptionBox.right + 10, _equipWindow->descriptionBox.top + 5, "소지금", lstrlen("소지금"));
		TextOut(getMemDC(), _equipWindow->descriptionBox.right + 140, _equipWindow->descriptionBox.top + 5, to_string(money).c_str(), lstrlen(to_string(money).c_str()));
		TextOut(getMemDC(), _equipWindow->descriptionBox.right + 180, _equipWindow->descriptionBox.top + 5, "G", lstrlen("G"));

	}


	if (_equipWindow->isClosed)
	{
		_activeTime++;

		if (_activeTime <= 100)
		{
			IMAGE->render("대화_상인", getMemDC(), 0, 10);
			IMAGE->alphaRender("대화_상인2", getMemDC(), 0, 10, 170);
			IMAGE->render("이미지_무기상인", getMemDC(), 15, 12);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			TextOut(getMemDC(), 380, 55, "근육 아저씨", lstrlen("근육 아저씨"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(250, 244, 192));
			TextOut(getMemDC(), 380, 55, "근육 아저씨", lstrlen("근육 아저씨"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(42, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 385, 90, "「 앗! 가시려고요?", lstrlen("「 앗! 가시려고요?"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(30, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "바탕");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 385, 150, "　　다시 오기를 기다릴게요~ 」", lstrlen("　　다시 오기를 기다릴게요~ 」"));
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
		//이미 존재하는지 판별
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
		//이미 존재하는지 판별
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
		//이미 존재하는지 판별
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
		//이미 존재하는지 판별
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
		//이미 존재하는지 판별
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
		//이미 존재하는지 판별
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
		//이미 존재하는지 판별
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
		//이미 존재하는지 판별
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
