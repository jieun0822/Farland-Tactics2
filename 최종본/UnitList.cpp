#include "framework.h"
#include "UnitList.h"
//#include "itemStore.h"

UnitList::UnitList()
{
}

UnitList::~UnitList()
{
}

HRESULT UnitList::init()
{
	isOpen = false;
	isActive = false;

	_unitWindow = new UnitWindow;

	_unitWindow->isAttButton = false;
	_unitWindow->isEquipButton = false;
	_unitWindow->isMagicButton = false;
	_unitWindow->isToolButton = false;
	_unitWindow->isCloseButton = false;

	_unitWindow->outLine = RectMake(150, 100, 700, 500);

	int outlineWidth = _unitWindow->outLine.right - _unitWindow->outLine.left;
	int outlintHeight = _unitWindow->outLine.bottom - _unitWindow->outLine.top;
	//창제목
	_unitWindow->windowName = RectMake(_unitWindow->outLine.left + 3, _unitWindow->outLine.top + 3, outlineWidth - 6, 30 - 6);
	//왼쪽 캐릭터 리스트창
	int nameHeight = _unitWindow->windowName.bottom - _unitWindow->windowName.top;
	int interval = 3;
	_unitWindow->characterList = RectMake(_unitWindow->windowName.left + 1, _unitWindow->windowName.bottom + 3, outlineWidth / 2, 465);
	int listWidth = _unitWindow->characterList.right - _unitWindow->characterList.left;


	//////////능력창
	_unitWindow->abilityButton = RectMake(_unitWindow->characterList.right + 2 * interval, _unitWindow->characterList.top + interval, 70, 30);
	_unitWindow->equipButton = RectMake(_unitWindow->abilityButton.right + 2 * interval, _unitWindow->characterList.top + interval, 70, 30);
	_unitWindow->magicButton = RectMake(_unitWindow->equipButton.right + 2 * interval, _unitWindow->characterList.top + interval, 70, 30);
	_unitWindow->toolButton = RectMake(_unitWindow->magicButton.right + 2 * interval, _unitWindow->characterList.top + interval, 70, 30);


	_unitWindow->characterImg = RectMake(_unitWindow->abilityButton.left + 10, _unitWindow->abilityButton.bottom + 8, 320, 170);
	_unitWindow->characterInfo = RectMake(_unitWindow->abilityButton.left + 10, _unitWindow->characterImg.bottom + 5, 320, 30);
	_unitWindow->characterDetail = RectMake(_unitWindow->abilityButton.left + 10, _unitWindow->characterInfo.bottom + 5, 320 - 100, 170);

	_unitWindow->characterEXP = RectMake(_unitWindow->characterDetail.right + 10, _unitWindow->characterDetail.top,
		_unitWindow->characterInfo.right - (_unitWindow->characterDetail.right + 10), 70);
	_unitWindow->characterAttribute = RectMake(_unitWindow->characterEXP.left, _unitWindow->characterEXP.bottom + 5,
		_unitWindow->characterEXP.right - _unitWindow->characterEXP.left, _unitWindow->characterDetail.bottom - (_unitWindow->characterEXP.bottom + 5));

	_unitWindow->closeButton = RectMake(_unitWindow->characterDetail.left + 230, _unitWindow->characterDetail.bottom + 10, 90, 30);


	//능력창 캐릭터 정보
	_unit = new Unit[3];

	_unit[0]._ability.name = "알";
	_unit[0]._ability.job = "검사";
	_unit[0]._ability.state = "정상";
	_unit[0]._ability.level = 1;
	//_unit[0]._ability.HP = 71;
	//_unit[0]._ability.MP = 24;
	_unit[0]._ability.HP = 100;
	_unit[0]._ability.MP = 100;

	_unit[0]._ability.offensePower = 77;
	_unit[0]._ability.plus_offensePower = 0;

	_unit[0]._ability.defense = 59;
	_unit[0]._ability.plus_defense = 0;

	_unit[0]._ability.intellect = 35;
	_unit[0]._ability.plus_intellect = 0;

	_unit[0]._ability.magicDrag = 44;
	_unit[0]._ability.plus_magicDrag = 0;

	_unit[0]._ability.agility = 43;
	_unit[0]._ability.plus_agility = 0;

	_unit[0]._ability.EXP = 0;
	_unit[0]._ability.attributeIcon = Attribute::WIND;
	_unit[0]._ability.attribute = 5;

	float barWidth = 200;

	float hpWidth = static_cast<float>(_unit[0]._ability.HP) / 100 * barWidth;
	_unit[0]._ability.listRC = RectMake(_unitWindow->characterList.left, _unitWindow->characterList.top, listWidth, 130);

	float mpWidth = static_cast<float>(_unit[0]._ability.MP) / 100 * barWidth;

	_unit[0]._ability._hpBar = new progressBar;
	_unit[0]._ability._hpBar->init("images/hpBar1.bmp", "images/barBack3.bmp", _unit[0]._ability.listRC.left + 130, _unit[0]._ability.listRC.top + 40, barWidth, 20);
	_unit[0]._ability._hpBar->setGauge(_unit[0]._ability.HP, 100);

	_unit[0]._ability._mpBar = new progressBar;
	_unit[0]._ability._mpBar->init("images/mpBar1.bmp", "images/barBack3.bmp", _unit[0]._ability.listRC.left + 130, _unit[0]._ability.listRC.top + 80, barWidth, 20);
	_unit[0]._ability._mpBar->setGauge(_unit[0]._ability.MP, 100);

	_unit[0]._ability.iconImg = IMAGE->addImage("알_아이콘", "images/R_icon.bmp", 65 + 10, 63 + 10, true, RGB(255, 0, 255));

	//능력창 이미지들
	IMAGE->addImage("배경_블루", "images/backGround_blueLong.bmp", _unit[0]._ability.listRC.right - _unit[0]._ability.listRC.left,
		_unit[0]._ability.listRC.bottom - _unit[0]._ability.listRC.top, true, RGB(255, 0, 255));
	IMAGE->addImage("캐릭터리스트_배경", "images/backGround_whiteLong.bmp", _unitWindow->characterList.right - _unitWindow->characterList.left,
		_unitWindow->characterList.bottom - _unitWindow->characterList.top, true, RGB(255, 0, 255));
	IMAGE->addImage("캐릭터이미지_배경", "images/backGround_white.bmp", _unitWindow->characterImg.right - _unitWindow->characterImg.left,
		_unitWindow->characterImg.bottom - _unitWindow->characterImg.top, true, RGB(255, 0, 255));
	IMAGE->addImage("알", "images/알.bmp", 240 + 13, 155 + 13, true, RGB(255, 255, 255));
	IMAGE->addImage("속성_바람", "images/attribute_wind.bmp", 16, 15, true, RGB(128, 0, 128));

	////////장비창
	//tagEquipInfo* _equip = new tagEquipInfo;
	//_equip->name = "바스타드소드";
	//_equip->detail = "한 손과 양 손으로 모두 사용할 수 있는 검\n공격력이 높다\n알이 장비가능\n공격력 +20, 민첩성 -4";
	//_equip->money = 500;
	//_equip->kind = EQUIP_KIND::WEAPON;
	//_equip->offensePower = 20;
	//_equip->defense = 0;
	//_equip->intellect = 0;
	//_equip->magicDrag = 0;
	//_equip->agility = -4;
	//_unit[0]._vBelongings.push_back(_equip);

	_unit[0]._weapon = nullptr;
	_unit[0]._armor = nullptr;
	_unit[0]._equip1 = nullptr;
	_unit[0]._equip2 = nullptr;

	_unitWindow->weaponDisplay = RectMake(_unitWindow->equipButton.left, _unitWindow->equipButton.bottom + 18, 250, 30);
	_unitWindow->armorDisplay = RectMake(_unitWindow->equipButton.left, _unitWindow->equipButton.bottom + 63, 250, 30);
	_unitWindow->equipment1Display = RectMake(_unitWindow->equipButton.left, _unitWindow->equipButton.bottom + 110, 250, 30);
	_unitWindow->equipment2Display = RectMake(_unitWindow->equipButton.left, _unitWindow->equipButton.bottom + 155, 250, 30);
	_unitWindow->belongingsDisplay = RectMake(_unitWindow->equipButton.left, _unitWindow->equipButton.bottom + 205, 250, 60);
	_unitWindow->detailDisplay = RectMake(_unitWindow->abilityButton.left, _unitWindow->equipButton.bottom + 280, 326, 100);

	_unitWindow->belongingsList1 = RectMake(_unitWindow->belongingsDisplay.left, _unitWindow->belongingsDisplay.top, 250, 30);
	_unitWindow->belongingsList2 = RectMake(_unitWindow->belongingsDisplay.left, _unitWindow->belongingsDisplay.top + 30, 250, 30);

	_unitWindow->isDisarm_weapon = false;
	_unitWindow->isDisarm_armor = false;
	_unitWindow->isDisarm_equip1 = false;
	_unitWindow->isDisarm_equip2 = false;
	_unitWindow->optionList1_left = false;
	_unitWindow->optionList1_right = false;
	_unitWindow->optionList2_left = false;
	_unitWindow->optionList2_right = false;

	//장비창 이미지들
	IMAGE->addImage("장비리스트_배경", "images/backGround_white.bmp", 250, 30, true, RGB(255, 0, 255));
	IMAGE->addImage("소지품_배경", "images/backGround_white.bmp", 250, 60, true, RGB(255, 0, 255));
	IMAGE->addImage("소지품_클릭", "images/backGround_blue.bmp", 250, 30, true, RGB(255, 0, 255));

	/////마법창
	_unitWindow->magicName = RectMake(_unitWindow->abilityButton.left, _unitWindow->abilityButton.bottom + 10, 330, 30);
	_unitWindow->magidList = RectMake(_unitWindow->abilityButton.left, _unitWindow->abilityButton.bottom + 60, 330, 200);
	_unitWindow->magicDetail = RectMake(_unitWindow->abilityButton.left, _unitWindow->abilityButton.bottom + 280, 330, 100);

	//마법창 이미지들
	IMAGE->addImage("마법창이름_배경", "images/backGround_white.bmp", 330, 30, true, RGB(255, 0, 255));
	IMAGE->addImage("마법창리스트_배경", "images/backGround_white.bmp", 330, 200, true, RGB(255, 0, 255));

	/////도구창
	_unitWindow->toolName = RectMake(_unitWindow->abilityButton.left, _unitWindow->abilityButton.bottom + 10, 330, 30);
	_unitWindow->toolList = RectMake(_unitWindow->abilityButton.left, _unitWindow->abilityButton.bottom + 60, 330, 180);

	_unitWindow->toolList1 = RectMake(_unitWindow->toolList.left, _unitWindow->toolList.top, 330, 30);
	_unitWindow->toolList2 = RectMake(_unitWindow->toolList.left, _unitWindow->toolList.top + 30, 330, 30);
	_unitWindow->toolList3 = RectMake(_unitWindow->toolList.left, _unitWindow->toolList.top + 60, 330, 30);
	_unitWindow->toolList4 = RectMake(_unitWindow->toolList.left, _unitWindow->toolList.top + 90, 330, 30);
	_unitWindow->toolList5 = RectMake(_unitWindow->toolList.left, _unitWindow->toolList.top + 120, 330, 30);
	_unitWindow->toolList6 = RectMake(_unitWindow->toolList.left, _unitWindow->toolList.top + 150, 330, 30);

	_unitWindow->toolList1_clicked = false;
	_unitWindow->toolList2_clicked = false;
	_unitWindow->toolList3_clicked = false;
	_unitWindow->toolList4_clicked = false;
	_unitWindow->toolList5_clicked = false;
	_unitWindow->toolList6_clicked = false;

	_unitWindow->sellButton = RectMake(_unitWindow->abilityButton.left + 30, _unitWindow->abilityButton.bottom + 250, 85, 30);
	_unitWindow->toolDetail = RectMake(_unitWindow->abilityButton.left, _unitWindow->abilityButton.bottom + 295, 330, 85);
	_unitWindow->isSellButton = false;

	_unitWindow->sellWindow = RectMake(_unitWindow->abilityButton.left - 130, _unitWindow->abilityButton.bottom + 120, 300, 150);
	_unitWindow->sellWin_name = RectMake(_unitWindow->sellWindow.left, _unitWindow->sellWindow.top, 300, 30);
	_unitWindow->sellWin_num = RectMake(_unitWindow->sellWindow.left + 60, _unitWindow->sellWin_name.bottom + 7, 85, 36);
	_unitWindow->sellWin_numUp = RectMake(_unitWindow->sellWindow.left + 115, _unitWindow->sellWin_name.bottom + 7, 30, 18);
	_unitWindow->sellWin_numDown = RectMake(_unitWindow->sellWindow.left + 115, _unitWindow->sellWin_name.bottom + 25, 30, 18);

	_unitWindow->sellWin_sellButton = RectMake(_unitWindow->sellWin_name.left + 185, _unitWindow->sellWin_name.bottom + 10, 100, 30);
	_unitWindow->sellWin_exitButton = RectMake(_unitWindow->sellWin_name.left + 185, _unitWindow->sellWin_name.bottom + 60, 100, 30);
	_unitWindow->sellItem_num = 1;

	_unitWindow->scrollPos = 1;
	_unitWindow->scrollOutline = RectMake(811, 222, 30, 183);
	_unitWindow->scroll = RectMake(814, 225, 24, 172);

	_unitWindow->scrollPos1 = 1;
	_unitWindow->scrollOutline1 = RectMake(_unitWindow->belongingsDisplay.left + 222, _unitWindow->belongingsDisplay.top + 1, 26, _unitWindow->belongingsDisplay.bottom - _unitWindow->belongingsDisplay.top - 1);
	_unitWindow->scroll1 = RectMake(_unitWindow->belongingsDisplay.left + 224, _unitWindow->belongingsDisplay.top + 3, 22, _unitWindow->belongingsDisplay.bottom - _unitWindow->belongingsDisplay.top - 5);

	//잡화
	//Tool* _tool = new Tool;
	//tagItemInfo* _tool = new tagItemInfo;
	//_tool->name = "허브";
	//_tool->detail = "어디서나 자라고 있는 흔한 약초.\n체력을 20 회복시켜 준다.";
	//_tool->num = 2;
	//_tool->money = 30;
	//_unit[0]._vTools.push_back(_tool);

	//_tool = new Tool;
	//_tool->name = "해독초";
	//_tool->detail = "몸 속의 독을 해독시켜 준다.\n아주 쓰고 극심한 냄새가 난다.";
	//_tool->num = 2;
	//_tool->money = 40;
	//_unit[0]._vTools.push_back(_tool);

	//도구창 이미지들
	IMAGE->addImage("도구창_배경", "images/backGround_white.bmp", 330, 30, true, RGB(255, 0, 255));
	IMAGE->addImage("도구창리스트_배경", "images/backGround_white.bmp", 330, 180, true, RGB(255, 0, 255));
	IMAGE->addImage("도구창_클릭", "images/backGround_blue.bmp", 330, 30, true, RGB(255, 0, 255));

	_money = 10000;

	return S_OK;
}

void UnitList::release()
{

	//SAFE_DELETE(_unit);
	SAFE_DELETE(_unitWindow);
}

void UnitList::update()
{
	//바 업데이트.
	_unit[0]._ability._hpBar->setGauge(_unit[0]._ability.HP, 100);
	_unit[0]._ability._hpBar->update();
	_unit[0]._ability._mpBar->setGauge(_unit[0]._ability.MP, 100);
	_unit[0]._ability._mpBar->update();
	//왼쪽 마우스 클릭.
	if (InputManager->isOnceKeyUp(VK_LBUTTON)) // && isActive)
	{
		if (PtInRect(&_unitWindow->closeButton, m_ptMouse))
		{
			//도구창 스크롤 초기화.
			_unitWindow->scrollPos = 1;
			_unitWindow->scrollPos1 = 1;

			isOpen = !isOpen;
			isActive = false;
		}

		//버튼.
		if (PtInRect(&_unitWindow->abilityButton, m_ptMouse))
		{
			_unitWindow->isAttButton = !(_unitWindow->isAttButton);
			_unitWindow->isEquipButton = false;
			_unitWindow->isMagicButton = false;
			_unitWindow->isToolButton = false;

			_unitWindow->isSellButton = false;
			_unitWindow->optionList1_left = false;
			_unitWindow->optionList2_left = false;
			_unitWindow->toolList1_clicked = false;
			_unitWindow->toolList2_clicked = false;
			_unitWindow->toolList3_clicked = false;
			_unitWindow->toolList4_clicked = false;
			_unitWindow->toolList5_clicked = false;
			_unitWindow->toolList6_clicked = false;
		}
		else if (PtInRect(&_unitWindow->equipButton, m_ptMouse))
		{
			_unitWindow->isAttButton = false;
			_unitWindow->isEquipButton = !(_unitWindow->isEquipButton);
			_unitWindow->isMagicButton = false;
			_unitWindow->isToolButton = false;

			_unitWindow->isSellButton = false;
			_unitWindow->optionList1_left = false;
			_unitWindow->optionList2_left = false;
			_unitWindow->toolList1_clicked = false;
			_unitWindow->toolList2_clicked = false;
			_unitWindow->toolList3_clicked = false;
			_unitWindow->toolList4_clicked = false;
			_unitWindow->toolList5_clicked = false;
			_unitWindow->toolList6_clicked = false;
		}
		else if (PtInRect(&_unitWindow->magicButton, m_ptMouse))
		{
			_unitWindow->isAttButton = false;
			_unitWindow->isEquipButton = false;
			_unitWindow->isMagicButton = !(_unitWindow->isMagicButton);
			_unitWindow->isToolButton = false;

			_unitWindow->isSellButton = false;
			_unitWindow->optionList1_left = false;
			_unitWindow->optionList2_left = false;
			_unitWindow->toolList1_clicked = false;
			_unitWindow->toolList2_clicked = false;
			_unitWindow->toolList3_clicked = false;
			_unitWindow->toolList4_clicked = false;
			_unitWindow->toolList5_clicked = false;
			_unitWindow->toolList6_clicked = false;
		}
		else if (PtInRect(&_unitWindow->toolButton, m_ptMouse))
		{
			_unitWindow->isAttButton = false;
			_unitWindow->isEquipButton = false;
			_unitWindow->isMagicButton = false;
			_unitWindow->isToolButton = !(_unitWindow->isToolButton);

			_unitWindow->isSellButton = false;
			_unitWindow->optionList1_left = false;
			_unitWindow->optionList2_left = false;
			_unitWindow->toolList1_clicked = false;
			_unitWindow->toolList2_clicked = false;
			_unitWindow->toolList3_clicked = false;
			_unitWindow->toolList4_clicked = false;
			_unitWindow->toolList5_clicked = false;
			_unitWindow->toolList6_clicked = false;
		}

		//장비창.
		//해제하기
		if (PtInRect(&_unitWindow->disarmRC, m_ptMouse) && _unitWindow->isDisarm_weapon)
		{
			_unit[0]._vBelongings.push_back(_unit[0]._weapon);

			_unit[0]._ability.plus_offensePower = 0;
			_unit[0]._ability.plus_defense = 0;
			_unit[0]._ability.plus_intellect = 0;
			_unit[0]._ability.plus_magicDrag = 0;
			_unit[0]._ability.plus_agility = 0;

			_unit[0]._weapon = nullptr;
		}
		else if (PtInRect(&_unitWindow->disarmRC, m_ptMouse) && _unitWindow->isDisarm_armor)
		{
			_unit[0]._vBelongings.push_back(_unit[0]._armor);

			_unit[0]._ability.plus_offensePower = 0;
			_unit[0]._ability.plus_defense = 0;
			_unit[0]._ability.plus_intellect = 0;
			_unit[0]._ability.plus_magicDrag = 0;
			_unit[0]._ability.plus_agility = 0;

			_unit[0]._armor = nullptr;
		}
		else if (PtInRect(&_unitWindow->disarmRC, m_ptMouse) && _unitWindow->isDisarm_equip1)
		{
			_unit[0]._vBelongings.push_back(_unit[0]._equip1);

			_unit[0]._ability.plus_offensePower = 0;
			_unit[0]._ability.plus_defense = 0;
			_unit[0]._ability.plus_intellect = 0;
			_unit[0]._ability.plus_magicDrag = 0;
			_unit[0]._ability.plus_agility = 0;

			_unit[0]._equip1 = nullptr;
		}
		else if (PtInRect(&_unitWindow->disarmRC, m_ptMouse) && _unitWindow->isDisarm_equip2)
		{
			_unit[0]._vBelongings.push_back(_unit[0]._equip2);

			_unit[0]._ability.plus_offensePower = 0;
			_unit[0]._ability.plus_defense = 0;
			_unit[0]._ability.plus_intellect = 0;
			_unit[0]._ability.plus_magicDrag = 0;
			_unit[0]._ability.plus_agility = 0;

			_unit[0]._equip2 = nullptr;
		}

		//소지품
		//if (_unitWindow->scrollPos1 == 1)
		//{
		//	if (PtInRect(&_unitWindow->belongingsList1, m_ptMouse) && !(_unit[0]._vBelongings.empty()))
		//	{
		//		_unit[0]._viBelongings = _unit[0]._vBelongings.begin();
		//		if ((*_unit[0]._viBelongings)->num > 0)
		//		{
		//			_unitWindow->optionList2_left = false;
		//			_unitWindow->optionList1_left = true;
		//		}
		//		else
		//		{
		//			_unitWindow->optionList1_left = false;
		//			_unitWindow->optionList2_left = false;
		//		}
		//	}
		//	if (PtInRect(&_unitWindow->belongingsList2, m_ptMouse) && !(_unit[0]._vBelongings.empty()))
		//	{
		//		_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 1;
		//		if ((*_unit[0]._viBelongings)->num > 0)
		//		{
		//			_unitWindow->optionList1_left = false;
		//			_unitWindow->optionList2_left = true;
		//		}
		//		else
		//		{
		//			_unitWindow->optionList1_left = false;
		//			_unitWindow->optionList2_left = false;
		//		}
		//	}
		//}
		//if (_unitWindow->scrollPos1 == 2)
		//{
		//	if (PtInRect(&_unitWindow->belongingsList1, m_ptMouse) && !(_unit[0]._vBelongings.empty()))
		//	{
		//		_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 2;
		//		if ((*_unit[0]._viBelongings)->num > 0)
		//		{
		//			_unitWindow->optionList2_left = false;
		//			_unitWindow->optionList1_left = true;
		//		}
		//		else
		//		{
		//			_unitWindow->optionList1_left = false;
		//			_unitWindow->optionList2_left = false;
		//		}
		//	}
		//	if (PtInRect(&_unitWindow->belongingsList2, m_ptMouse) && !(_unit[0]._vBelongings.empty()))
		//	{
		//		_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 3;
		//		if ((*_unit[0]._viBelongings)->num > 0)
		//		{
		//			_unitWindow->optionList1_left = false;
		//			_unitWindow->optionList2_left = true;
		//		}
		//		else
		//		{
		//			_unitWindow->optionList1_left = false;
		//			_unitWindow->optionList2_left = false;
		//		}
		//	}
		//}
		//if (_unitWindow->scrollPos1 == 3)
		//{
		//	if (PtInRect(&_unitWindow->belongingsList1, m_ptMouse) && !(_unit[0]._vBelongings.empty()))
		//	{
		//		_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 4;
		//		if ((*_unit[0]._viBelongings)->num > 0)
		//		{
		//			_unitWindow->optionList2_left = false;
		//			_unitWindow->optionList1_left = true;
		//		}
		//		else
		//		{
		//			_unitWindow->optionList1_left = false;
		//			_unitWindow->optionList2_left = false;
		//		}
		//	}
		//	if (PtInRect(&_unitWindow->belongingsList2, m_ptMouse) && !(_unit[0]._vBelongings.empty()))
		//	{
		//		_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 5;
		//		if ((*_unit[0]._viBelongings)->num >= 0)
		//		{
		//			_unitWindow->optionList1_left = false;
		//			_unitWindow->optionList2_left = true;
		//		}
		//		else
		//		{
		//			_unitWindow->optionList1_left = false;
		//			_unitWindow->optionList2_left = false;
		//		}
		//	}
		//}
		//if (_unitWindow->scrollPos1 == 4)
		//{
		//	if (PtInRect(&_unitWindow->belongingsList1, m_ptMouse) && !(_unit[0]._vBelongings.empty()))
		//	{
		//		_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 6;
		//		if ((*_unit[0]._viBelongings)->num > 0)
		//		{
		//			_unitWindow->optionList2_left = false;
		//			_unitWindow->optionList1_left = true;
		//		}
		//		else
		//		{
		//			_unitWindow->optionList1_left = false;
		//			_unitWindow->optionList2_left = false;
		//		}
		//	}
		//	if (PtInRect(&_unitWindow->belongingsList2, m_ptMouse) && !(_unit[0]._vBelongings.empty()))
		//	{
		//		_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 7;
		//		if ((*_unit[0]._viBelongings)->num > 0)
		//		{
		//			_unitWindow->optionList1_left = false;
		//			_unitWindow->optionList2_left = true;
		//		}
		//		else
		//		{
		//			_unitWindow->optionList1_left = false;
		//			_unitWindow->optionList2_left = false;
		//		}
		//	}
		//}

		_unit[0]._viBelongings = _unit[0]._vBelongings.begin();
		for (_unit[0]._viBelongings; _unit[0]._viBelongings != _unit[0]._vBelongings.end(); ++_unit[0]._viBelongings)
		{
			if ((*_unit[0]._viBelongings)->num > 0)
			{
				if (PtInRect(&_unitWindow->belongingsList1, m_ptMouse))
				{
					_unitWindow->optionList1_left = true;
					_unitWindow->optionList2_left = false;
				}
				if (PtInRect(&_unitWindow->belongingsList2, m_ptMouse))
				{
					_unitWindow->optionList2_left = true;
					_unitWindow->optionList1_left = false;
				}
			}
			else
			{
				_unitWindow->optionList1_left = false;
				_unitWindow->optionList2_left = false;
				_unitWindow->optionList1_right = false;
				_unitWindow->optionList2_right = false;
			}
		}


		//장비하기.
		if (_unitWindow->optionList1_right && PtInRect(&_unitWindow->option_equip, m_ptMouse))
		{
			_unitWindow->optionList1_left = false;
			if (!_unit[0]._vBelongings.empty())
			{
				_unit[0]._viBelongings = _unit[0]._vBelongings.begin();
				if ((*_unit[0]._viBelongings)->kind == EQUIP_KIND::WEAPON)
				{
					_unit[0]._weapon = (*_unit[0]._viBelongings);
					_unit[0]._ability.plus_offensePower = _unit[0]._weapon->offensePower;
					_unit[0]._ability.plus_defense = _unit[0]._weapon->defense;
					_unit[0]._ability.plus_intellect = _unit[0]._weapon->intellect;
					_unit[0]._ability.plus_magicDrag = _unit[0]._weapon->magicDrag;
					_unit[0]._ability.plus_agility = _unit[0]._weapon->agility;

					_unit[0]._vBelongings.erase(_unit[0]._vBelongings.begin());
				}
				else if ((*_unit[0]._viBelongings)->kind == EQUIP_KIND::ARMOR)
				{
					_unit[0]._armor = (*_unit[0]._viBelongings);
					_unit[0]._ability.plus_offensePower = _unit[0]._armor->offensePower;
					_unit[0]._ability.plus_defense = _unit[0]._armor->defense;
					_unit[0]._ability.plus_intellect = _unit[0]._armor->intellect;
					_unit[0]._ability.plus_magicDrag = _unit[0]._armor->magicDrag;
					_unit[0]._ability.plus_agility = _unit[0]._armor->agility;

					_unit[0]._vBelongings.erase(_unit[0]._vBelongings.begin());
				}
			}
		}



		if (_unitWindow->optionList2_right && PtInRect(&_unitWindow->option_equip, m_ptMouse))
		{
			_unitWindow->optionList2_left = false;
			if (!_unit[0]._vBelongings.empty())
			{
				_unit[0]._viBelongings = _unit[0]._vBelongings.begin();
				if ((*_unit[0]._viBelongings)->kind == EQUIP_KIND::WEAPON)
				{
					_unit[0]._weapon = (*_unit[0]._viBelongings);
					_unit[0]._ability.plus_offensePower = _unit[0]._weapon->offensePower;
					_unit[0]._ability.plus_defense = _unit[0]._weapon->defense;
					_unit[0]._ability.plus_intellect = _unit[0]._weapon->intellect;
					_unit[0]._ability.plus_magicDrag = _unit[0]._weapon->magicDrag;
					_unit[0]._ability.plus_agility = _unit[0]._weapon->agility;

					_unit[0]._vBelongings.erase(_unit[0]._vBelongings.begin());
				}
				else if ((*_unit[0]._viBelongings)->kind == EQUIP_KIND::ARMOR)
				{
					_unit[0]._armor = (*_unit[0]._viBelongings);
					_unit[0]._ability.plus_offensePower = _unit[0]._armor->offensePower;
					_unit[0]._ability.plus_defense = _unit[0]._armor->defense;
					_unit[0]._ability.plus_intellect = _unit[0]._armor->intellect;
					_unit[0]._ability.plus_magicDrag = _unit[0]._armor->magicDrag;
					_unit[0]._ability.plus_agility = _unit[0]._armor->agility;

					_unit[0]._vBelongings.erase(_unit[0]._vBelongings.begin());
				}
			}
		}
		//되팔기.
		if (_unitWindow->optionList1_right && PtInRect(&_unitWindow->option_sell, m_ptMouse))
		{
			_unit[0]._viBelongings = _unit[0]._vBelongings.begin();
			_money += (*_unit[0]._viBelongings)->money / 2;
			_unit[0]._vBelongings.erase(_unit[0]._vBelongings.begin());
		}
		if (_unitWindow->optionList2_right && PtInRect(&_unitWindow->option_sell, m_ptMouse))
		{
			_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 1;
			_money += (*_unit[0]._viBelongings)->money / 2;
			_unit[0]._vBelongings.erase(_unit[0]._vBelongings.begin() + 1);
		}

		_unitWindow->optionList1_right = false;
		_unitWindow->optionList2_right = false;
		_unitWindow->isDisarm_weapon = false;
		_unitWindow->isDisarm_armor = false;
		_unitWindow->isDisarm_equip1 = false;
		_unitWindow->isDisarm_equip2 = false;


		//도구창
		if (PtInRect(&_unitWindow->toolList1, m_ptMouse) && !(_unit[0]._vTools.empty()))
		{
			_unit[0]._viTools = _unit[0]._vTools.begin();
			if ((*_unit[0]._viTools)->num > 0 && !_unitWindow->isSellButton)
			{
				_unitWindow->toolList1_clicked = true;
				_unitWindow->toolList2_clicked = false;
				_unitWindow->toolList3_clicked = false;
				_unitWindow->toolList4_clicked = false;
				_unitWindow->toolList5_clicked = false;
				_unitWindow->toolList6_clicked = false;
			}
		}
		if (PtInRect(&_unitWindow->toolList2, m_ptMouse) && _unit[0]._vTools.size() >= 2)
		{
			_unit[0]._viTools = _unit[0]._vTools.begin() + 1;
			if ((*_unit[0]._viTools)->num > 0 && !_unitWindow->isSellButton)
			{
				_unitWindow->toolList1_clicked = false;
				_unitWindow->toolList2_clicked = true;
				_unitWindow->toolList3_clicked = false;
				_unitWindow->toolList4_clicked = false;
				_unitWindow->toolList5_clicked = false;
				_unitWindow->toolList6_clicked = false;
			}
		}
		if (PtInRect(&_unitWindow->toolList3, m_ptMouse) && _unit[0]._vTools.size() >= 3)
		{
			_unit[0]._viTools = _unit[0]._vTools.begin() + 2;
			if ((*_unit[0]._viTools)->num > 0 && !_unitWindow->isSellButton)
			{
				_unitWindow->toolList1_clicked = false;
				_unitWindow->toolList2_clicked = false;
				_unitWindow->toolList3_clicked = true;
				_unitWindow->toolList4_clicked = false;
				_unitWindow->toolList5_clicked = false;
				_unitWindow->toolList6_clicked = false;
			}
		}
		if (PtInRect(&_unitWindow->toolList4, m_ptMouse) && _unit[0]._vTools.size() >= 4)
		{
			_unit[0]._viTools = _unit[0]._vTools.begin() + 3;
			if ((*_unit[0]._viTools)->num > 0 && !_unitWindow->isSellButton)
			{
				_unitWindow->toolList1_clicked = false;
				_unitWindow->toolList2_clicked = false;
				_unitWindow->toolList3_clicked = false;
				_unitWindow->toolList4_clicked = true;
				_unitWindow->toolList5_clicked = false;
				_unitWindow->toolList6_clicked = false;
			}
		}
		if (PtInRect(&_unitWindow->toolList5, m_ptMouse) && _unit[0]._vTools.size() >= 5)
		{
			_unit[0]._viTools = _unit[0]._vTools.begin() + 4;
			if ((*_unit[0]._viTools)->num > 0 && !_unitWindow->isSellButton)
			{
				_unitWindow->toolList1_clicked = false;
				_unitWindow->toolList2_clicked = false;
				_unitWindow->toolList3_clicked = false;
				_unitWindow->toolList4_clicked = false;
				_unitWindow->toolList5_clicked = true;
				_unitWindow->toolList6_clicked = false;
			}
		}
		if (PtInRect(&_unitWindow->toolList6, m_ptMouse) && _unit[0]._vTools.size() >= 6)
		{
			_unit[0]._viTools = _unit[0]._vTools.begin() + 5;
			if ((*_unit[0]._viTools)->num > 0 && !_unitWindow->isSellButton)
			{
				_unitWindow->toolList1_clicked = false;
				_unitWindow->toolList2_clicked = false;
				_unitWindow->toolList3_clicked = false;
				_unitWindow->toolList4_clicked = false;
				_unitWindow->toolList5_clicked = false;
				_unitWindow->toolList6_clicked = true;
			}
		}

		//도구창->판매창.
		if (PtInRect(&_unitWindow->sellWin_sellButton, m_ptMouse) && _unitWindow->isSellButton)
		{
			if (_unitWindow->toolList1_clicked)
			{
				_unit[0]._viTools = _unit[0]._vTools.begin();
				_unitWindow->plusMoney = ((*_unit[0]._viTools)->money / 2) * _unitWindow->sellItem_num;

				(*_unit[0]._viTools)->num -= _unitWindow->sellItem_num;

				if ((*_unit[0]._viTools)->num == 0)
				{
					_unitWindow->toolList1_clicked = false;
					_unit[0]._vTools.erase(_unit[0]._viTools);
				}

				_money += _unitWindow->plusMoney;
			}
			else if (_unitWindow->toolList2_clicked)
			{
				_unit[0]._viTools = _unit[0]._vTools.begin() + 1;
				_unitWindow->plusMoney = ((*_unit[0]._viTools)->money / 2) * _unitWindow->sellItem_num;

				(*_unit[0]._viTools)->num -= _unitWindow->sellItem_num;
				if ((*_unit[0]._viTools)->num == 0)
				{
					_unitWindow->toolList2_clicked = false;
					_unit[0]._vTools.erase(_unit[0]._viTools);
				}
				_money += _unitWindow->plusMoney;
			}
			else if (_unitWindow->toolList3_clicked)
			{
				_unit[0]._viTools = _unit[0]._vTools.begin() + 2;
				_unitWindow->plusMoney = ((*_unit[0]._viTools)->money / 2) * _unitWindow->sellItem_num;

				(*_unit[0]._viTools)->num -= _unitWindow->sellItem_num;
				if ((*_unit[0]._viTools)->num == 0)
				{
					_unitWindow->toolList3_clicked = false;
					_unit[0]._vTools.erase(_unit[0]._viTools);
				}
				_money += _unitWindow->plusMoney;
			}
			else if (_unitWindow->toolList4_clicked)
			{
				_unit[0]._viTools = _unit[0]._vTools.begin() + 3;
				_unitWindow->plusMoney = ((*_unit[0]._viTools)->money / 2) * _unitWindow->sellItem_num;

				(*_unit[0]._viTools)->num -= _unitWindow->sellItem_num;
				if ((*_unit[0]._viTools)->num == 0)
				{
					_unitWindow->toolList4_clicked = false;
					_unit[0]._vTools.erase(_unit[0]._viTools);
				}
				_money += _unitWindow->plusMoney;
			}
			else if (_unitWindow->toolList5_clicked)
			{
				_unit[0]._viTools = _unit[0]._vTools.begin() + 4;
				_unitWindow->plusMoney = ((*_unit[0]._viTools)->money / 2) * _unitWindow->sellItem_num;

				(*_unit[0]._viTools)->num -= _unitWindow->sellItem_num;
				if ((*_unit[0]._viTools)->num == 0)
				{
					_unitWindow->toolList5_clicked = false;
					_unit[0]._vTools.erase(_unit[0]._viTools);
				}
				_money += _unitWindow->plusMoney;
			}
			else if (_unitWindow->toolList6_clicked)
			{
				_unit[0]._viTools = _unit[0]._vTools.begin() + 5;
				_unitWindow->plusMoney = ((*_unit[0]._viTools)->money / 2) * _unitWindow->sellItem_num;

				(*_unit[0]._viTools)->num -= _unitWindow->sellItem_num;
				if ((*_unit[0]._viTools)->num == 0)
				{
					_unitWindow->toolList6_clicked = false;
					_unit[0]._vTools.erase(_unit[0]._viTools);
				}
				_money += _unitWindow->plusMoney;
			}

			_unitWindow->sellItem_num = 1;
		}

		if (PtInRect(&_unitWindow->sellWin_exitButton, m_ptMouse)) _unitWindow->isSellButton = false;
		if (_unitWindow->isSellButton == false)_unitWindow->sellItem_num = 1;

		//팔 물건 갯수 조절.
		if (PtInRect(&_unitWindow->sellWin_numUp, m_ptMouse))
		{
			if (_unitWindow->toolList1_clicked)
			{
				_unit[0]._viTools = _unit[0]._vTools.begin();
				if ((*_unit[0]._viTools)->num > _unitWindow->sellItem_num) _unitWindow->sellItem_num++;
			}
			if (_unitWindow->toolList2_clicked)
			{
				_unit[0]._viTools = _unit[0]._vTools.begin() + 1;
				if ((*_unit[0]._viTools)->num > _unitWindow->sellItem_num) _unitWindow->sellItem_num++;
			}
			if (_unitWindow->toolList3_clicked)
			{
				_unit[0]._viTools = _unit[0]._vTools.begin() + 2;
				if ((*_unit[0]._viTools)->num > _unitWindow->sellItem_num) _unitWindow->sellItem_num++;
			}
			if (_unitWindow->toolList4_clicked)
			{
				_unit[0]._viTools = _unit[0]._vTools.begin() + 3;
				if ((*_unit[0]._viTools)->num > _unitWindow->sellItem_num) _unitWindow->sellItem_num++;
			}
			if (_unitWindow->toolList5_clicked)
			{
				_unit[0]._viTools = _unit[0]._vTools.begin() + 4;
				if ((*_unit[0]._viTools)->num > _unitWindow->sellItem_num) _unitWindow->sellItem_num++;
			}
			if (_unitWindow->toolList6_clicked)
			{
				_unit[0]._viTools = _unit[0]._vTools.begin() + 5;
				if ((*_unit[0]._viTools)->num > _unitWindow->sellItem_num) _unitWindow->sellItem_num++;
			}
		}
		if (PtInRect(&_unitWindow->sellWin_numDown, m_ptMouse))
		{
			if (_unitWindow->sellItem_num - 1 < 1)_unitWindow->sellItem_num = 1;
			else _unitWindow->sellItem_num--;
		}


		if (PtInRect(&_unitWindow->sellButton, m_ptMouse)) _unitWindow->isSellButton = !(_unitWindow->isSellButton);
	}

	//오른쪽 마우스 클릭.
	if (InputManager->isOnceKeyUp(VK_RBUTTON))
	{
		//장비창.
		if (PtInRect(&_unitWindow->weaponDisplay, m_ptMouse) && _unit[0]._weapon != nullptr)
		{
			_unitWindow->disarmRC = RectMake(m_ptMouse.x, m_ptMouse.y, 100, 25);
			_unitWindow->isDisarm_weapon = true;
			_unitWindow->isDisarm_armor = false;
			_unitWindow->isDisarm_equip1 = false;
			_unitWindow->isDisarm_equip2 = false;
			_unitWindow->optionList1_right = false;
			_unitWindow->optionList2_right = false;
		}
		else if (PtInRect(&_unitWindow->armorDisplay, m_ptMouse) && _unit[0]._armor != nullptr)
		{
			_unitWindow->disarmRC = RectMake(m_ptMouse.x, m_ptMouse.y, 100, 25);
			_unitWindow->isDisarm_weapon = false;
			_unitWindow->isDisarm_armor = true;
			_unitWindow->isDisarm_equip1 = false;
			_unitWindow->isDisarm_equip2 = false;
			_unitWindow->optionList1_right = false;
			_unitWindow->optionList2_right = false;
		}
		else if (PtInRect(&_unitWindow->equipment1Display, m_ptMouse) && _unit[0]._equip1 != nullptr)
		{
			_unitWindow->disarmRC = RectMake(m_ptMouse.x, m_ptMouse.y, 100, 25);
			_unitWindow->isDisarm_weapon = false;
			_unitWindow->isDisarm_armor = false;
			_unitWindow->isDisarm_equip1 = true;
			_unitWindow->isDisarm_equip2 = false;
			_unitWindow->optionList1_right = false;
			_unitWindow->optionList2_right = false;
		}
		else if (PtInRect(&_unitWindow->equipment2Display, m_ptMouse) && _unit[0]._equip2 != nullptr)
		{
			_unitWindow->disarmRC = RectMake(m_ptMouse.x, m_ptMouse.y, 100, 25);
			_unitWindow->isDisarm_weapon = false;
			_unitWindow->isDisarm_armor = false;
			_unitWindow->isDisarm_equip1 = false;
			_unitWindow->isDisarm_equip2 = true;
			_unitWindow->optionList1_right = false;
			_unitWindow->optionList2_right = false;
		}

		if (PtInRect(&_unitWindow->belongingsList1, m_ptMouse) && !(_unit[0]._vBelongings.empty()))
		{
			_unitWindow->isDisarm_weapon = false;
			_unitWindow->isDisarm_armor = false;
			_unitWindow->isDisarm_equip1 = false;
			_unitWindow->isDisarm_equip2 = false;
			_unitWindow->optionList1_right = true;
			_unitWindow->optionList2_right = false;

			//오른쪽 마우스 누를때 뜨는것들.
			_unitWindow->option = RectMake(m_ptMouse.x, m_ptMouse.y, 100, 50);
			_unitWindow->option_equip = RectMake(_unitWindow->option.left, _unitWindow->option.top, 100, 25);
			_unitWindow->option_sell = RectMake(_unitWindow->option.left, _unitWindow->option.top + 25, 100, 25);
		}
		if (PtInRect(&_unitWindow->belongingsList2, m_ptMouse) && !(_unit[0]._vBelongings.empty()))
		{
			_unitWindow->isDisarm_weapon = false;
			_unitWindow->isDisarm_armor = false;
			_unitWindow->isDisarm_equip1 = false;
			_unitWindow->isDisarm_equip2 = false;
			_unitWindow->optionList1_right = false;
			_unitWindow->optionList2_right = true;

			//오른쪽 마우스 누를때 뜨는것들.
			_unitWindow->option = RectMake(m_ptMouse.x, m_ptMouse.y, 100, 50);
			_unitWindow->option_equip = RectMake(_unitWindow->option.left, _unitWindow->option.top, 100, 25);
			_unitWindow->option_sell = RectMake(_unitWindow->option.left, _unitWindow->option.top + 25, 100, 25);
		}
	}//오른쪽 마우스 클릭 end
	//if (zDelta > 0) // scroll up
	//{
	//	if (_unitWindow->scrollPos1 == 1)
	//	{
	//		return;
	//	}
	//	if (_unitWindow->scrollPos1 == 2)
	//	{
	//	}
	//	if (_unitWindow->scrollPos1 == 3)
	//	{
	//	}
	//	_unitWindow->scrollPos1--;
	//}
	//else if (zDelta < 0)//scroll down
	//{
	//	if (_unitWindow->scrollPos1 == 4)
	//	{
	//		return;
	//	}
	//	if (_unitWindow->scrollPos1 == 3)
	//	{
	//	}
	//	if (_unitWindow->scrollPos1 == 2)
	//	{
	//	}
	//	if (_unit[0]._vBelongings.size() == 3) { _unitWindow->scrollPos1 = 2; }
	//	if (_unit[0]._vBelongings.size() == 4) {}
	//	if (_unit[0]._vBelongings.size() == 5) { _unitWindow->scrollPos1++; }
	//	if (_unit[0]._vBelongings.size() == 6) {}
	//	if (_unit[0]._vBelongings.size() == 7) { _unitWindow->scrollPos1++; }
	//	//if (_unit[0]._vBelongings.size() == 3) { _unitWindow->scrollPos1 = 2; }
	//	//if (_unit[0]._vBelongings.size() == 4) { _unitWindow->scrollPos1++; }	
	//	//if (_unit[0]._vBelongings.size() == 8) { _unitWindow->scrollPos1++; } 
	//}

	//스크롤 조절.
	//아이템 리스트 스크롤.
	if (zDelta > 0) // scroll up
	{
		if (_unitWindow->scrollPos == 1)
		{
			return;
		}
		if (_unitWindow->scrollPos == 2)
		{
		}
		_unitWindow->scrollPos--;
	}
	else if (zDelta < 0)//scroll down
	{
		if (_unitWindow->scrollPos == 3)
		{
			return;
		}
		if (_unitWindow->scrollPos == 2)
		{
		}
		if (_unit[0]._vTools.size() == 7)_unitWindow->scrollPos = 2;
		if (_unit[0]._vTools.size() == 8)_unitWindow->scrollPos++;
	}

	////소지품 스크롤
	if (zDelta > 0) // scroll up
	{
		if (_unitWindow->scrollPos1 == 1)
		{
			return;
		}
		if (_unitWindow->scrollPos1 == 2)
		{
		}
		if (_unitWindow->scrollPos1 == 3)
		{
		}
		_unitWindow->scrollPos1--;
	}
	else if (zDelta < 0)//scroll down
	{
		if (_unitWindow->scrollPos1 == 4)
		{
			return;
		}
		if (_unitWindow->scrollPos1 == 3)
		{
		}
		if (_unitWindow->scrollPos1 == 2)
		{
		}
		if (_unit[0]._vBelongings.size() == 3) { _unitWindow->scrollPos1 = 2; }
		if (_unit[0]._vBelongings.size() == 4) {}
		if (_unit[0]._vBelongings.size() == 5) { _unitWindow->scrollPos1++; }
		if (_unit[0]._vBelongings.size() == 6) {}
		if (_unit[0]._vBelongings.size() == 7) { _unitWindow->scrollPos1++; }
		//if (_unit[0]._vBelongings.size() == 3) { _unitWindow->scrollPos1 = 2; }
		//if (_unit[0]._vBelongings.size() == 4) { _unitWindow->scrollPos1++; }	
		//if (_unit[0]._vBelongings.size() == 8) { _unitWindow->scrollPos1++; } 
	}
}

void UnitList::render()
{
	HBRUSH brush;
	HBRUSH oldBrush;
	HPEN hpen;
	HPEN hpenOld;

	if (isOpen)
	{
		//창
		grayDraw(_unitWindow->outLine);

		brush = CreateSolidBrush(RGB(0, 0, 153));
		Rectangle(getMemDC(), _unitWindow->windowName.left, _unitWindow->windowName.top, _unitWindow->windowName.right, _unitWindow->windowName.bottom);
		FillRect(getMemDC(), &_unitWindow->windowName, brush);
		DeleteObject(brush);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		TCHAR str[20];
		SetBkMode(getMemDC(), TRANSPARENT);
		wsprintf(str, "유닛 일람");
		TextOut(getMemDC(), _unitWindow->windowName.left + 5, _unitWindow->windowName.top + 5, str, lstrlen(str));
		SetTextColor(getMemDC(), RGB(0, 0, 0));


		//Rectangle(getMemDC(), _unitWindow->characterList.left, _unitWindow->characterList.top, _unitWindow->characterList.right, _unitWindow->characterList.bottom);
		IMAGE->findImage("캐릭터리스트_배경")->render(getMemDC(), _unitWindow->characterList.left, _unitWindow->characterList.top);

		//R의 왼쪽 상태창
		//Rectangle(getMemDC(), _unit[0]._ability.listRC.left, _unit[0]._ability.listRC.top, _unit[0]._ability.listRC.right, _unit[0]._ability.listRC.bottom);
		IMAGE->findImage("배경_블루")->render(getMemDC(), _unit[0]._ability.listRC.left, _unit[0]._ability.listRC.top);

		TextOut(getMemDC(), _unit[0]._ability.listRC.left + 95, _unit[0]._ability.listRC.top + 15, _unit[0]._ability.name.c_str(), lstrlen(_unit[0]._ability.name.c_str()));
		TextOut(getMemDC(), _unit[0]._ability.listRC.left + 235, _unit[0]._ability.listRC.top + 15, _unit[0]._ability.state.c_str(), lstrlen(_unit[0]._ability.state.c_str()));
		TextOut(getMemDC(), _unit[0]._ability.listRC.left + 95, _unit[0]._ability.listRC.top + 45, "HP", lstrlen("HP"));
		TextOut(getMemDC(), _unit[0]._ability.listRC.left + 95, _unit[0]._ability.listRC.top + 85, "MP", lstrlen("MP"));
		Rectangle(getMemDC(), _unit[0]._ability.hpBackBar.left, _unit[0]._ability.hpBackBar.top, _unit[0]._ability.hpBackBar.right, _unit[0]._ability.hpBackBar.bottom);
		_unit[0]._ability.iconImg->render(getMemDC(), _unit[0]._ability.listRC.left + 5, _unit[0]._ability.listRC.top + 35);

		_unit[0]._ability._hpBar->render();
		_unit[0]._ability._mpBar->render();

		///버튼
		shadowDraw(_unitWindow->abilityButton);
		shadowDraw(_unitWindow->equipButton);
		shadowDraw(_unitWindow->magicButton);
		shadowDraw(_unitWindow->toolButton);

		lightDraw(_unitWindow->abilityButton);
		lightDraw(_unitWindow->equipButton);
		lightDraw(_unitWindow->magicButton);
		lightDraw(_unitWindow->toolButton);

		//클릭 안했을 때.
		if (!(_unitWindow->isAttButton)) grayDraw(_unitWindow->abilityButton);
		if (!(_unitWindow->isEquipButton)) grayDraw(_unitWindow->equipButton);
		if (!(_unitWindow->isMagicButton)) grayDraw(_unitWindow->magicButton);
		if (!(_unitWindow->isToolButton)) grayDraw(_unitWindow->toolButton);

		//클릭 했을 때.
		if (_unitWindow->isAttButton) clickedColor(_unitWindow->abilityButton);
		if (_unitWindow->isEquipButton) clickedColor(_unitWindow->equipButton);
		if (_unitWindow->isMagicButton) clickedColor(_unitWindow->magicButton);
		if (_unitWindow->isToolButton) clickedColor(_unitWindow->toolButton);

		wsprintf(str, "능력");
		TextOut(getMemDC(), _unitWindow->abilityButton.left + 5, _unitWindow->abilityButton.top + 5, str, lstrlen(str));
		wsprintf(str, "장비");
		TextOut(getMemDC(), _unitWindow->equipButton.left + 5, _unitWindow->equipButton.top + 5, str, lstrlen(str));
		wsprintf(str, "마법");
		TextOut(getMemDC(), _unitWindow->magicButton.left + 5, _unitWindow->magicButton.top + 5, str, lstrlen(str));
		wsprintf(str, "도구");
		TextOut(getMemDC(), _unitWindow->toolButton.left + 5, _unitWindow->toolButton.top + 5, str, lstrlen(str));

		shadowDraw(_unitWindow->closeButton);
		lightDraw(_unitWindow->closeButton);

		grayDraw(_unitWindow->closeButton);
		wsprintf(str, "닫기");
		TextOut(getMemDC(), _unitWindow->closeButton.left + 27, _unitWindow->closeButton.top + 5, str, lstrlen(str));

		//능력창.
		if (_unitWindow->isAttButton)
		{
			//오른쪽
			hpen = CreatePen(PS_NULL, 1, RGB(153, 153, 153));
			hpenOld = (HPEN)::SelectObject(getMemDC(), (HGDIOBJ)hpen);
			//Rectangle(getMemDC(), _unitWindow->characterImg.left, _unitWindow->characterImg.top, _unitWindow->characterImg.right, _unitWindow->characterImg.bottom);
			IMAGE->findImage("캐릭터이미지_배경")->render(getMemDC(), _unitWindow->characterImg.left, _unitWindow->characterImg.top);
			IMAGE->findImage("알")->render(getMemDC(), _unitWindow->characterImg.left + 45, _unitWindow->characterImg.top + 1);
			hpen = (HPEN)::SelectObject(getMemDC(), hpenOld);
			DeleteObject(hpen);

			brush = (HBRUSH)::GetStockObject(NULL_BRUSH);
			oldBrush = (HBRUSH)::SelectObject(getMemDC(), brush);
			hpen = CreatePen(PS_SOLID, 1, RGB(153, 153, 153)); // 선 스타일, 굵기, 색상
			hpenOld = (HPEN)::SelectObject(getMemDC(), (HGDIOBJ)hpen); // 펜 선택
			Rectangle(getMemDC(), _unitWindow->characterInfo.left, _unitWindow->characterInfo.top, _unitWindow->characterInfo.right, _unitWindow->characterInfo.bottom);
			Rectangle(getMemDC(), _unitWindow->characterDetail.left, _unitWindow->characterDetail.top, _unitWindow->characterDetail.right, _unitWindow->characterDetail.bottom);
			Rectangle(getMemDC(), _unitWindow->characterEXP.left, _unitWindow->characterEXP.top, _unitWindow->characterEXP.right, _unitWindow->characterEXP.bottom);
			Rectangle(getMemDC(), _unitWindow->characterAttribute.left, _unitWindow->characterAttribute.top, _unitWindow->characterAttribute.right, _unitWindow->characterAttribute.bottom);
			Rectangle(getMemDC(), _unitWindow->characterAttribute.left, _unitWindow->characterAttribute.top, _unitWindow->characterAttribute.right, _unitWindow->characterAttribute.bottom);
			hpen = (HPEN)::SelectObject(getMemDC(), hpenOld); // 기존의 펜 선택 
			DeleteObject(hpen); // 생성한 펜 삭제
			brush = (HBRUSH)::SelectObject(getMemDC(), oldBrush);
			DeleteObject(brush);

			//캐릭터 정보
			TextOut(getMemDC(), _unitWindow->characterInfo.left + 10, _unitWindow->characterInfo.top + 5, _unit[0]._ability.name.c_str(), lstrlen(_unit[0]._ability.name.c_str()));
			TextOut(getMemDC(), _unitWindow->characterInfo.left + 200, _unitWindow->characterInfo.top + 5, _unit[0]._ability.job.c_str(), lstrlen(_unit[0]._ability.job.c_str()));

			string _level = "L" + to_string(_unit[0]._ability.level);
			TextOut(getMemDC(), _unitWindow->characterInfo.left + 290, _unitWindow->characterInfo.top + 5, _level.c_str(), lstrlen(_level.c_str()));
			//체력
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 5, _unitWindow->characterDetail.top + 5, "체력(HP)", lstrlen("체력(HP)"));
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 100, _unitWindow->characterDetail.top + 5, to_string(static_cast<int>(_unit[0]._ability.HP)).c_str(), lstrlen(to_string(static_cast<int>(_unit[0]._ability.HP)).c_str()));
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 130, _unitWindow->characterDetail.top + 5, "/ 100", lstrlen("/ 100"));
			//마력
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 5, _unitWindow->characterDetail.top + 25, "마력(MP)", lstrlen("마력(MP)"));
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 100, _unitWindow->characterDetail.top + 25, to_string(static_cast<int>(_unit[0]._ability.MP)).c_str(), lstrlen(to_string(static_cast<int>(_unit[0]._ability.MP)).c_str()));
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 130, _unitWindow->characterDetail.top + 25, "/ 100", lstrlen("/ 100"));
			//공격력
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 5, _unitWindow->characterDetail.top + 45, "공격력", lstrlen("공격력"));
			int result = _unit[0]._ability.offensePower + _unit[0]._ability.plus_offensePower;
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 100, _unitWindow->characterDetail.top + 45, to_string(result).c_str(), lstrlen(to_string(result).c_str()));
			string _plus = "(+" + to_string(_unit[0]._ability.plus_offensePower) + ")";
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 130, _unitWindow->characterDetail.top + 45, _plus.c_str(), lstrlen(_plus.c_str()));
			//방어력
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 5, _unitWindow->characterDetail.top + 65, "방어력", lstrlen("방어력"));
			result = _unit[0]._ability.defense + _unit[0]._ability.plus_defense;
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 100, _unitWindow->characterDetail.top + 65, to_string(result).c_str(), lstrlen(to_string(result).c_str()));
			_plus = "(+" + to_string(_unit[0]._ability.plus_defense) + ")";
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 130, _unitWindow->characterDetail.top + 65, _plus.c_str(), lstrlen(_plus.c_str()));
			//지력
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 5, _unitWindow->characterDetail.top + 85, "지력", lstrlen("지력"));
			result = _unit[0]._ability.intellect + _unit[0]._ability.plus_intellect;
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 100, _unitWindow->characterDetail.top + 85, to_string(result).c_str(), lstrlen(to_string(result).c_str()));
			_plus = "(+" + to_string(_unit[0]._ability.plus_intellect) + ")";
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 130, _unitWindow->characterDetail.top + 85, _plus.c_str(), lstrlen(_plus.c_str()));
			//마항력
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 5, _unitWindow->characterDetail.top + 105, "마항력", lstrlen("마항력"));
			result = _unit[0]._ability.magicDrag + _unit[0]._ability.plus_magicDrag;
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 100, _unitWindow->characterDetail.top + 105, to_string(result).c_str(), lstrlen(to_string(result).c_str()));
			_plus = "(+" + to_string(_unit[0]._ability.plus_magicDrag) + ")";
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 130, _unitWindow->characterDetail.top + 105, _plus.c_str(), lstrlen(_plus.c_str()));
			//민첩성
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 5, _unitWindow->characterDetail.top + 125, "민첩성", lstrlen("민첩성"));
			result = _unit[0]._ability.agility + _unit[0]._ability.plus_agility;
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 100, _unitWindow->characterDetail.top + 125, to_string(result).c_str(), lstrlen(to_string(result).c_str()));
			if (_unit[0]._ability.plus_agility >= 0) _plus = "(+" + to_string(_unit[0]._ability.plus_agility) + ")";
			else _plus = "(-" + to_string(abs(_unit[0]._ability.plus_agility)) + ")";
			TextOut(getMemDC(), _unitWindow->characterDetail.left + 130, _unitWindow->characterDetail.top + 125, _plus.c_str(), lstrlen(_plus.c_str()));

			//경험치
			TextOut(getMemDC(), _unitWindow->characterEXP.left + 5, _unitWindow->characterEXP.top + 5, "경험치", lstrlen("경험치"));
			TextOut(getMemDC(), _unitWindow->characterEXP.left + 55, _unitWindow->characterEXP.top + 25, to_string(static_cast<int>(_unit[0]._ability.EXP)).c_str(), lstrlen(to_string(static_cast<int>(_unit[0]._ability.EXP)).c_str()));
			//속성
			TextOut(getMemDC(), _unitWindow->characterAttribute.left + 5, _unitWindow->characterAttribute.top + 5, "속성", lstrlen("속성"));
			IMAGE->findImage("속성_바람")->render(getMemDC(), _unitWindow->characterAttribute.left + 11, _unitWindow->characterAttribute.top + 28);
			TextOut(getMemDC(), _unitWindow->characterAttribute.left + 55, _unitWindow->characterAttribute.top + 25, to_string(_unit[0]._ability.attribute).c_str(), lstrlen(to_string(_unit[0]._ability.attribute).c_str()));
		}//능력창end

		//////장비창
		if (_unitWindow->isEquipButton)
		{
			wsprintf(str, "무기");
			TextOut(getMemDC(), _unitWindow->abilityButton.left + 10, _unitWindow->abilityButton.bottom + 25, str, lstrlen(str));

			wsprintf(str, "방어구");
			TextOut(getMemDC(), _unitWindow->abilityButton.left + 10, _unitWindow->abilityButton.bottom + 70, str, lstrlen(str));

			wsprintf(str, "장비1");
			TextOut(getMemDC(), _unitWindow->abilityButton.left + 10, _unitWindow->abilityButton.bottom + 115, str, lstrlen(str));

			wsprintf(str, "장비2");
			TextOut(getMemDC(), _unitWindow->abilityButton.left + 10, _unitWindow->abilityButton.bottom + 160, str, lstrlen(str));

			wsprintf(str, "소지품");
			TextOut(getMemDC(), _unitWindow->abilityButton.left + 10, _unitWindow->abilityButton.bottom + 205, str, lstrlen(str));

			shadowDraw_reverse(_unitWindow->weaponDisplay);
			lightDraw_reverse(_unitWindow->weaponDisplay);
			IMAGE->findImage("장비리스트_배경")->render(getMemDC(), _unitWindow->weaponDisplay.left, _unitWindow->weaponDisplay.top);

			shadowDraw_reverse(_unitWindow->armorDisplay);
			lightDraw_reverse(_unitWindow->armorDisplay);
			IMAGE->findImage("장비리스트_배경")->render(getMemDC(), _unitWindow->armorDisplay.left, _unitWindow->armorDisplay.top);

			shadowDraw_reverse(_unitWindow->equipment1Display);
			lightDraw_reverse(_unitWindow->equipment1Display);
			IMAGE->findImage("장비리스트_배경")->render(getMemDC(), _unitWindow->equipment1Display.left, _unitWindow->equipment1Display.top);

			shadowDraw_reverse(_unitWindow->equipment2Display);
			lightDraw_reverse(_unitWindow->equipment2Display);
			IMAGE->findImage("장비리스트_배경")->render(getMemDC(), _unitWindow->equipment2Display.left, _unitWindow->equipment2Display.top);

			shadowDraw_reverse(_unitWindow->belongingsDisplay);
			lightDraw_reverse(_unitWindow->belongingsDisplay);
			IMAGE->findImage("소지품_배경")->render(getMemDC(), _unitWindow->belongingsDisplay.left, _unitWindow->belongingsDisplay.top);

			shadowDraw_reverse(_unitWindow->detailDisplay);
			lightDraw_reverse(_unitWindow->detailDisplay);
			grayDraw(_unitWindow->detailDisplay);

			if (_unitWindow->optionList1_left)
			{
				IMAGE->findImage("소지품_클릭")->render(getMemDC(), _unitWindow->belongingsList1.left, _unitWindow->belongingsList1.top);
			}

			if (_unitWindow->optionList2_left)
			{
				IMAGE->findImage("소지품_클릭")->render(getMemDC(), _unitWindow->belongingsList2.left, _unitWindow->belongingsList2.top);
			}

			//무기
			if (_unit[0]._weapon != nullptr) TextOut(getMemDC(), _unitWindow->weaponDisplay.left + 3, _unitWindow->weaponDisplay.top + 6, _unit[0]._weapon->name.c_str(), lstrlen(_unit[0]._weapon->name.c_str()));
			else TextOut(getMemDC(), _unitWindow->weaponDisplay.left + 33, _unitWindow->weaponDisplay.top + 6, "없음", lstrlen("없음"));
			//방어구
			if (_unit[0]._armor != nullptr) TextOut(getMemDC(), _unitWindow->armorDisplay.left + 3, _unitWindow->armorDisplay.top + 6, _unit[0]._armor->name.c_str(), lstrlen(_unit[0]._armor->name.c_str()));
			else TextOut(getMemDC(), _unitWindow->armorDisplay.left + 33, _unitWindow->armorDisplay.top + 6, "없음", lstrlen("없음"));
			//장비1
			if (_unit[0]._equip1 != nullptr) TextOut(getMemDC(), _unitWindow->equipment1Display.left + 3, _unitWindow->equipment1Display.top + 6, _unit[0]._equip1->name.c_str(), lstrlen(_unit[0]._equip1->name.c_str()));
			else TextOut(getMemDC(), _unitWindow->equipment1Display.left + 33, _unitWindow->equipment1Display.top + 6, "없음", lstrlen("없음"));
			//장비2
			if (_unit[0]._equip2 != nullptr) TextOut(getMemDC(), _unitWindow->equipment2Display.left + 3, _unitWindow->equipment2Display.top + 6, _unit[0]._equip2->name.c_str(), lstrlen(_unit[0]._equip2->name.c_str()));
			else TextOut(getMemDC(), _unitWindow->equipment2Display.left + 33, _unitWindow->equipment2Display.top + 6, "없음", lstrlen("없음"));

			lightGrayDraw(_unitWindow->scrollOutline1);
			HBRUSH brush = CreateSolidBrush(RGB(190, 190, 190));
			Rectangle(getMemDC(), _unitWindow->scroll1.left, _unitWindow->scroll1.top, _unitWindow->scroll1.right, _unitWindow->scroll1.bottom);
			FillRect(getMemDC(), &_unitWindow->scroll1, brush);
			DeleteObject(brush);

			//소지품
			//스크롤해보는중
			if (_unitWindow->scrollPos1 == 1)
			{
				_unitWindow->scroll1 = RectMake(_unitWindow->belongingsDisplay.left + 224, _unitWindow->belongingsDisplay.top + 3, 22, _unitWindow->belongingsDisplay.bottom - _unitWindow->belongingsDisplay.top - 40);

				if (!_unit[0]._vBelongings.empty())
				{
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin();
					TextOut(getMemDC(), _unitWindow->belongingsList1.left + 3, _unitWindow->belongingsList1.top + 3, (*_unit[0]._viBelongings)->name.c_str(), lstrlen((*_unit[0]._viBelongings)->name.c_str()));
					if (_unitWindow->optionList1_left)
					{
						_unit[0]._viBelongings = _unit[0]._vBelongings.begin();
						DrawText(getMemDC(), (*_unit[0]._viBelongings)->detail.c_str(), ::strlen((*_unit[0]._viBelongings)->detail.c_str()), &_unitWindow->detailDisplay, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
					}


					if (_unit[0]._vBelongings.size() >= 2)
					{
						_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 1;
						TextOut(getMemDC(), _unitWindow->belongingsList2.left + 3, _unitWindow->belongingsList2.top + 3, (*_unit[0]._viBelongings)->name.c_str(), lstrlen((*_unit[0]._viBelongings)->name.c_str()));
						if (_unitWindow->optionList2_left)
						{
							_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 1;
							DrawText(getMemDC(), (*_unit[0]._viBelongings)->detail.c_str(), ::strlen((*_unit[0]._viBelongings)->detail.c_str()), &_unitWindow->detailDisplay, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
						}
					}
				}
			}

			if (_unitWindow->scrollPos1 == 2)
			{
				_unitWindow->scroll1 = RectMake(_unitWindow->belongingsDisplay.left + 224, _unitWindow->belongingsDisplay.top + 15, 22, _unitWindow->belongingsDisplay.bottom - _unitWindow->belongingsDisplay.top - 40);

				if (_unit[0]._vBelongings.size() >= 3)
				{
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 2;
					TextOut(getMemDC(), _unitWindow->belongingsList1.left + 3, _unitWindow->belongingsList1.top + 3, (*_unit[0]._viBelongings)->name.c_str(), lstrlen((*_unit[0]._viBelongings)->name.c_str()));
					if (_unitWindow->optionList1_left)
					{
						_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 2;
						DrawText(getMemDC(), (*_unit[0]._viBelongings)->detail.c_str(), ::strlen((*_unit[0]._viBelongings)->detail.c_str()), &_unitWindow->detailDisplay, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
					}
				}

				if (_unit[0]._vBelongings.size() >= 4)
				{
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 3;
					TextOut(getMemDC(), _unitWindow->belongingsList2.left + 3, _unitWindow->belongingsList2.top + 3, (*_unit[0]._viBelongings)->name.c_str(), lstrlen((*_unit[0]._viBelongings)->name.c_str()));
					if (_unitWindow->optionList2_left)
					{
						_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 3;
						DrawText(getMemDC(), (*_unit[0]._viBelongings)->detail.c_str(), ::strlen((*_unit[0]._viBelongings)->detail.c_str()), &_unitWindow->detailDisplay, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
					}
				}
				//}
			}


			if (_unitWindow->scrollPos1 == 3)
			{
				_unitWindow->scroll1 = RectMake(_unitWindow->belongingsDisplay.left + 224, _unitWindow->belongingsDisplay.top + 26, 22, _unitWindow->belongingsDisplay.bottom - _unitWindow->belongingsDisplay.top - 40);

				if (_unit[0]._vBelongings.size() >= 5)
				{
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 4;
					TextOut(getMemDC(), _unitWindow->belongingsList1.left + 3, _unitWindow->belongingsList1.top + 3, (*_unit[0]._viBelongings)->name.c_str(), lstrlen((*_unit[0]._viBelongings)->name.c_str()));
					if (_unitWindow->optionList1_left)
					{
						_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 4;
						DrawText(getMemDC(), (*_unit[0]._viBelongings)->detail.c_str(), ::strlen((*_unit[0]._viBelongings)->detail.c_str()), &_unitWindow->detailDisplay, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
					}

				}
				if (_unit[0]._vBelongings.size() >= 6)
				{
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 5;
					TextOut(getMemDC(), _unitWindow->belongingsList2.left + 3, _unitWindow->belongingsList2.top + 3, (*_unit[0]._viBelongings)->name.c_str(), lstrlen((*_unit[0]._viBelongings)->name.c_str()));
					if (_unitWindow->optionList2_left)
					{
						_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 5;
						DrawText(getMemDC(), (*_unit[0]._viBelongings)->detail.c_str(), ::strlen((*_unit[0]._viBelongings)->detail.c_str()), &_unitWindow->detailDisplay, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
					}
				}
				//}
			}


			if (_unitWindow->scrollPos1 == 4)
			{
				_unitWindow->scroll1 = RectMake(_unitWindow->belongingsDisplay.left + 224, _unitWindow->belongingsDisplay.top + 35, 22, _unitWindow->belongingsDisplay.bottom - _unitWindow->belongingsDisplay.top - 40);
				if (_unit[0]._vBelongings.size() >= 7)
				{
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 6;
					TextOut(getMemDC(), _unitWindow->belongingsList1.left + 3, _unitWindow->belongingsList1.top + 3, (*_unit[0]._viBelongings)->name.c_str(), lstrlen((*_unit[0]._viBelongings)->name.c_str()));
					if (_unitWindow->optionList1_left)
					{
						_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 6;
						DrawText(getMemDC(), (*_unit[0]._viBelongings)->detail.c_str(), ::strlen((*_unit[0]._viBelongings)->detail.c_str()), &_unitWindow->detailDisplay, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
					}
				}

				if (_unit[0]._vBelongings.size() >= 8)
				{
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 7;
					TextOut(getMemDC(), _unitWindow->belongingsList2.left + 3, _unitWindow->belongingsList2.top + 3, (*_unit[0]._viBelongings)->name.c_str(), lstrlen((*_unit[0]._viBelongings)->name.c_str()));
					if (_unitWindow->optionList2_left)
					{
						_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 7;
						DrawText(getMemDC(), (*_unit[0]._viBelongings)->detail.c_str(), ::strlen((*_unit[0]._viBelongings)->detail.c_str()), &_unitWindow->detailDisplay, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
					}
				}
				//}
			}


			if (_unitWindow->isDisarm_weapon)
			{
				lightGrayDraw(_unitWindow->disarmRC);
				TextOut(getMemDC(), _unitWindow->disarmRC.left + 3, _unitWindow->disarmRC.top + 3, "해제", lstrlen("해제"));
			}
			else if (_unitWindow->isDisarm_armor)
			{
				lightGrayDraw(_unitWindow->disarmRC);
				TextOut(getMemDC(), _unitWindow->disarmRC.left + 3, _unitWindow->disarmRC.top + 3, "해제", lstrlen("해제"));
			}
			else if (_unitWindow->isDisarm_equip1)
			{
				lightGrayDraw(_unitWindow->disarmRC);
				TextOut(getMemDC(), _unitWindow->disarmRC.left + 3, _unitWindow->disarmRC.top + 3, "해제", lstrlen("해제"));
			}
			else if (_unitWindow->isDisarm_equip2)
			{
				lightGrayDraw(_unitWindow->disarmRC);
				TextOut(getMemDC(), _unitWindow->disarmRC.left + 3, _unitWindow->disarmRC.top + 3, "해제", lstrlen("해제"));
			}

			//소지품 우클릭
			if (_unitWindow->scrollPos1 == 1)
			{
				if (_unitWindow->optionList1_right)
				{
					Rectangle(getMemDC(), _unitWindow->option.left, _unitWindow->option.top, _unitWindow->option.right, _unitWindow->option.bottom);
					lightGrayDraw(_unitWindow->option_equip);
					TextOut(getMemDC(), _unitWindow->option_equip.left + 3, _unitWindow->option_equip.top + 3, "장비하다", lstrlen("장비하다"));
					lightGrayDraw(_unitWindow->option_sell);
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin();
					wsprintf(str, "%d에 판다", (*_unit[0]._viBelongings)->money / 2);
					TextOut(getMemDC(), _unitWindow->option_sell.left + 3, _unitWindow->option_sell.top + 3, str, lstrlen(str));
				}
				if (_unitWindow->optionList2_right)
				{
					Rectangle(getMemDC(), _unitWindow->option.left, _unitWindow->option.top, _unitWindow->option.right, _unitWindow->option.bottom);
					lightGrayDraw(_unitWindow->option_equip);
					TextOut(getMemDC(), _unitWindow->option_equip.left + 3, _unitWindow->option_equip.top + 3, "장비하다", lstrlen("장비하다"));
					lightGrayDraw(_unitWindow->option_sell);
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 1;
					wsprintf(str, "%d에 판다", (*_unit[0]._viBelongings)->money / 2);
					TextOut(getMemDC(), _unitWindow->option_sell.left + 3, _unitWindow->option_sell.top + 3, str, lstrlen(str));
				}
			}
			if (_unitWindow->scrollPos1 == 2)
			{
				if (_unitWindow->optionList1_right)
				{
					Rectangle(getMemDC(), _unitWindow->option.left, _unitWindow->option.top, _unitWindow->option.right, _unitWindow->option.bottom);
					lightGrayDraw(_unitWindow->option_equip);
					TextOut(getMemDC(), _unitWindow->option_equip.left + 3, _unitWindow->option_equip.top + 3, "장비하다", lstrlen("장비하다"));
					lightGrayDraw(_unitWindow->option_sell);
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 2;
					wsprintf(str, "%d에 판다", (*_unit[0]._viBelongings)->money / 2);
					TextOut(getMemDC(), _unitWindow->option_sell.left + 3, _unitWindow->option_sell.top + 3, str, lstrlen(str));
				}
				if (_unitWindow->optionList2_right)
				{
					Rectangle(getMemDC(), _unitWindow->option.left, _unitWindow->option.top, _unitWindow->option.right, _unitWindow->option.bottom);
					lightGrayDraw(_unitWindow->option_equip);
					TextOut(getMemDC(), _unitWindow->option_equip.left + 3, _unitWindow->option_equip.top + 3, "장비하다", lstrlen("장비하다"));
					lightGrayDraw(_unitWindow->option_sell);
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 3;
					wsprintf(str, "%d에 판다", (*_unit[0]._viBelongings)->money / 2);
					TextOut(getMemDC(), _unitWindow->option_sell.left + 3, _unitWindow->option_sell.top + 3, str, lstrlen(str));
				}
			}
			if (_unitWindow->scrollPos1 == 3)
			{
				if (_unitWindow->optionList1_right)
				{
					Rectangle(getMemDC(), _unitWindow->option.left, _unitWindow->option.top, _unitWindow->option.right, _unitWindow->option.bottom);
					lightGrayDraw(_unitWindow->option_equip);
					TextOut(getMemDC(), _unitWindow->option_equip.left + 3, _unitWindow->option_equip.top + 3, "장비하다", lstrlen("장비하다"));
					lightGrayDraw(_unitWindow->option_sell);
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 4;
					wsprintf(str, "%d에 판다", (*_unit[0]._viBelongings)->money / 2);
					TextOut(getMemDC(), _unitWindow->option_sell.left + 3, _unitWindow->option_sell.top + 3, str, lstrlen(str));
				}
				if (_unitWindow->optionList2_right)
				{
					Rectangle(getMemDC(), _unitWindow->option.left, _unitWindow->option.top, _unitWindow->option.right, _unitWindow->option.bottom);
					lightGrayDraw(_unitWindow->option_equip);
					TextOut(getMemDC(), _unitWindow->option_equip.left + 3, _unitWindow->option_equip.top + 3, "장비하다", lstrlen("장비하다"));
					lightGrayDraw(_unitWindow->option_sell);
					_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 5;
					wsprintf(str, "%d에 판다", (*_unit[0]._viBelongings)->money / 2);
					TextOut(getMemDC(), _unitWindow->option_sell.left + 3, _unitWindow->option_sell.top + 3, str, lstrlen(str));
				}
				if (_unitWindow->scrollPos1 == 4)
				{
					if (_unitWindow->optionList1_right)
					{
						Rectangle(getMemDC(), _unitWindow->option.left, _unitWindow->option.top, _unitWindow->option.right, _unitWindow->option.bottom);
						lightGrayDraw(_unitWindow->option_equip);
						TextOut(getMemDC(), _unitWindow->option_equip.left + 3, _unitWindow->option_equip.top + 3, "장비하다", lstrlen("장비하다"));
						lightGrayDraw(_unitWindow->option_sell);
						_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 6;
						wsprintf(str, "%d에 판다", (*_unit[0]._viBelongings)->money / 2);
						TextOut(getMemDC(), _unitWindow->option_sell.left + 3, _unitWindow->option_sell.top + 3, str, lstrlen(str));
					}
					if (_unitWindow->optionList2_right)
					{
						Rectangle(getMemDC(), _unitWindow->option.left, _unitWindow->option.top, _unitWindow->option.right, _unitWindow->option.bottom);
						lightGrayDraw(_unitWindow->option_equip);
						TextOut(getMemDC(), _unitWindow->option_equip.left + 3, _unitWindow->option_equip.top + 3, "장비하다", lstrlen("장비하다"));
						lightGrayDraw(_unitWindow->option_sell);
						_unit[0]._viBelongings = _unit[0]._vBelongings.begin() + 7;
						wsprintf(str, "%d에 판다", (*_unit[0]._viBelongings)->money / 2);
						TextOut(getMemDC(), _unitWindow->option_sell.left + 3, _unitWindow->option_sell.top + 3, str, lstrlen(str));
					}
				}
			}
		}//장비창 end

		///마법창
		if (_unitWindow->isMagicButton)
		{
			shadowDraw_reverse(_unitWindow->magicName);
			lightDraw_reverse(_unitWindow->magicName);
			IMAGE->findImage("마법창이름_배경")->render(getMemDC(), _unitWindow->magicName.left, _unitWindow->magicName.top);

			TextOut(getMemDC(), _unitWindow->magicName.left + 30, _unitWindow->magicName.top + 7, "명칭", lstrlen("명칭"));
			TextOut(getMemDC(), _unitWindow->magicName.left + 200, _unitWindow->magicName.top + 7, "갯수", lstrlen("갯수"));

			shadowDraw_reverse(_unitWindow->magidList);
			lightDraw_reverse(_unitWindow->magidList);
			IMAGE->findImage("마법창리스트_배경")->render(getMemDC(), _unitWindow->magidList.left, _unitWindow->magidList.top);

			shadowDraw_reverse(_unitWindow->magicDetail);
			lightDraw_reverse(_unitWindow->magicDetail);
			grayDraw(_unitWindow->magicDetail);
		}//마법창 end

		///도구창
		if (_unitWindow->isToolButton)
		{
			shadowDraw_reverse(_unitWindow->toolName);
			lightDraw_reverse(_unitWindow->toolName);
			IMAGE->findImage("도구창_배경")->render(getMemDC(), _unitWindow->toolName.left, _unitWindow->toolName.top);

			TextOut(getMemDC(), _unitWindow->toolName.left + 30, _unitWindow->toolName.top + 7, "명칭", lstrlen("명칭"));
			TextOut(getMemDC(), _unitWindow->toolName.left + 200, _unitWindow->toolName.top + 7, "갯수", lstrlen("갯수"));

			shadowDraw_reverse(_unitWindow->toolList);
			lightDraw_reverse(_unitWindow->toolList);
			IMAGE->findImage("도구창리스트_배경")->render(getMemDC(), _unitWindow->toolList.left, _unitWindow->toolList.top);

			if (!(_unitWindow->toolList1_clicked)) IMAGE->findImage("도구창_배경")->render(getMemDC(), _unitWindow->toolList1.left, _unitWindow->toolList1.top);
			else IMAGE->findImage("도구창_클릭")->render(getMemDC(), _unitWindow->toolList1.left, _unitWindow->toolList1.top);

			if (!(_unitWindow->toolList2_clicked))IMAGE->findImage("도구창_배경")->render(getMemDC(), _unitWindow->toolList2.left, _unitWindow->toolList2.top);
			else IMAGE->findImage("도구창_클릭")->render(getMemDC(), _unitWindow->toolList2.left, _unitWindow->toolList2.top);

			if (!(_unitWindow->toolList3_clicked)) IMAGE->findImage("도구창_배경")->render(getMemDC(), _unitWindow->toolList3.left, _unitWindow->toolList3.top);
			else IMAGE->findImage("도구창_클릭")->render(getMemDC(), _unitWindow->toolList3.left, _unitWindow->toolList3.top);

			if (!(_unitWindow->toolList4_clicked)) IMAGE->findImage("도구창_배경")->render(getMemDC(), _unitWindow->toolList4.left, _unitWindow->toolList4.top);
			else IMAGE->findImage("도구창_클릭")->render(getMemDC(), _unitWindow->toolList4.left, _unitWindow->toolList4.top);

			if (!(_unitWindow->toolList5_clicked)) IMAGE->findImage("도구창_배경")->render(getMemDC(), _unitWindow->toolList5.left, _unitWindow->toolList5.top);
			else IMAGE->findImage("도구창_클릭")->render(getMemDC(), _unitWindow->toolList5.left, _unitWindow->toolList5.top);

			if (!(_unitWindow->toolList6_clicked)) IMAGE->findImage("도구창_배경")->render(getMemDC(), _unitWindow->toolList6.left, _unitWindow->toolList6.top);
			else IMAGE->findImage("도구창_클릭")->render(getMemDC(), _unitWindow->toolList6.left, _unitWindow->toolList6.top);

			//도구창수정
			//스크롤 구현.
			if (_unitWindow->scrollPos == 1)
			{
				_unitWindow->scroll = RectMake(814, 225, 24, 103);

				if (!(_unit[0]._vTools.empty()))	//vTools가 empty 상태가 아닐때
				{
					_unit[0]._viTools = _unit[0]._vTools.begin();
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList1.left + 3, _unitWindow->toolList1.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList1.left + 200, _unitWindow->toolList1.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}


					if (_unit[0]._vTools.size() >= 2)
					{
						_unit[0]._viTools = _unit[0]._vTools.begin() + 1;
						if ((*_unit[0]._viTools)->num > 0)
						{
							TextOut(getMemDC(), _unitWindow->toolList2.left + 3, _unitWindow->toolList2.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
							TextOut(getMemDC(), _unitWindow->toolList2.left + 200, _unitWindow->toolList2.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
						}
					}
				}
				if (_unit[0]._vTools.size() >= 3)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 2;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList3.left + 3, _unitWindow->toolList3.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList3.left + 200, _unitWindow->toolList3.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}
				}
				if (_unit[0]._vTools.size() >= 4)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 3;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList4.left + 3, _unitWindow->toolList4.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList4.left + 200, _unitWindow->toolList4.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}
				}
				if (_unit[0]._vTools.size() >= 5)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 4;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList5.left + 3, _unitWindow->toolList5.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList5.left + 200, _unitWindow->toolList5.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}
				}
				if (_unit[0]._vTools.size() >= 6)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 5;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList6.left + 3, _unitWindow->toolList6.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList6.left + 200, _unitWindow->toolList6.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}
				}
			}

			else if (_unitWindow->scrollPos == 2)
			{
				_unitWindow->scroll = RectMake(814, 270, 24, 103);

				if (!(_unit[0]._vTools.empty()))	//vTools가 empty 상태가 아닐때
				{


					_unit[0]._viTools = _unit[0]._vTools.begin() + 1;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList1.left + 3, _unitWindow->toolList1.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList1.left + 200, _unitWindow->toolList1.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}


					if (_unit[0]._vTools.size() >= 3)
					{
						_unit[0]._viTools = _unit[0]._vTools.begin() + 2;
						if ((*_unit[0]._viTools)->num > 0)
						{
							TextOut(getMemDC(), _unitWindow->toolList2.left + 3, _unitWindow->toolList2.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
							TextOut(getMemDC(), _unitWindow->toolList2.left + 200, _unitWindow->toolList2.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
						}
					}
				}
				if (_unit[0]._vTools.size() >= 4)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 3;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList3.left + 3, _unitWindow->toolList3.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList3.left + 200, _unitWindow->toolList3.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}
				}
				if (_unit[0]._vTools.size() >= 5)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 4;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList4.left + 3, _unitWindow->toolList4.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList4.left + 200, _unitWindow->toolList4.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}
				}
				if (_unit[0]._vTools.size() >= 6)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 5;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList5.left + 3, _unitWindow->toolList5.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList5.left + 200, _unitWindow->toolList5.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}
				}
				if (_unit[0]._vTools.size() >= 7)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 6;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList6.left + 3, _unitWindow->toolList6.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList6.left + 200, _unitWindow->toolList6.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}
				}
			}

			else if (_unitWindow->scrollPos == 3)
			{
				_unitWindow->scroll = RectMake(814, 299, 24, 103);

				if (!(_unit[0]._vTools.empty()))	//vTools가 empty 상태가 아닐때
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 2;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList1.left + 3, _unitWindow->toolList1.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList1.left + 200, _unitWindow->toolList1.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}

					if (_unit[0]._vTools.size() >= 4)
					{
						_unit[0]._viTools = _unit[0]._vTools.begin() + 3;
						if ((*_unit[0]._viTools)->num > 0)
						{
							TextOut(getMemDC(), _unitWindow->toolList2.left + 3, _unitWindow->toolList2.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
							TextOut(getMemDC(), _unitWindow->toolList2.left + 200, _unitWindow->toolList2.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
						}
					}
				}
				if (_unit[0]._vTools.size() >= 5)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 4;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList3.left + 3, _unitWindow->toolList3.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList3.left + 200, _unitWindow->toolList3.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}
				}
				if (_unit[0]._vTools.size() >= 6)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 5;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList4.left + 3, _unitWindow->toolList4.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList4.left + 200, _unitWindow->toolList4.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}
				}
				if (_unit[0]._vTools.size() >= 7)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 6;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList5.left + 3, _unitWindow->toolList5.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList5.left + 200, _unitWindow->toolList5.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}
				}
				if (_unit[0]._vTools.size() >= 8)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 7;
					if ((*_unit[0]._viTools)->num > 0)
					{
						TextOut(getMemDC(), _unitWindow->toolList6.left + 3, _unitWindow->toolList6.top + 6, (*_unit[0]._viTools)->name.c_str(), lstrlen((*_unit[0]._viTools)->name.c_str()));
						TextOut(getMemDC(), _unitWindow->toolList6.left + 200, _unitWindow->toolList6.top + 6, to_string((*_unit[0]._viTools)->num).c_str(), lstrlen(to_string((*_unit[0]._viTools)->num).c_str()));
					}
				}
			}

			//TCHAR zDelta_str[20];
			//wsprintf(zDelta_str, "zDelta : %d", _unitWindow->scrollPos);
			//TextOut(getMemDC(), 100, 100, zDelta_str, lstrlen(zDelta_str));

			//스크롤 RECT.
			//Rectangle(getMemDC(), _unitWindow->scrollOutline.left, _unitWindow->scrollOutline.top, _unitWindow->scrollOutline.right, _unitWindow->scrollOutline.bottom);
			//Rectangle(getMemDC(), _unitWindow->scroll.left, _unitWindow->scroll.top, _unitWindow->scroll.right, _unitWindow->scroll.bottom);
			lightGrayDraw(_unitWindow->scrollOutline);

			//grayDraw(_unitWindow->scroll);
			HBRUSH brush = CreateSolidBrush(RGB(190, 190, 190));
			Rectangle(getMemDC(), _unitWindow->scroll.left, _unitWindow->scroll.top, _unitWindow->scroll.right, _unitWindow->scroll.bottom);
			FillRect(getMemDC(), &_unitWindow->scroll, brush);
			DeleteObject(brush);





			shadowDraw_reverse(_unitWindow->toolDetail);
			lightDraw_reverse(_unitWindow->toolDetail);
			grayDraw(_unitWindow->toolDetail);


			if (_unitWindow->scrollPos == 1)
			{
				if (_unitWindow->toolList1_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin();
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList2_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 1;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList3_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 2;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList4_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 3;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList5_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 4;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList6_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 5;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
			}
			else if (_unitWindow->scrollPos == 2)
			{
				if (_unitWindow->toolList1_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 1;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList2_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 2;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList3_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 3;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList4_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 4;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList5_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 5;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList6_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 6;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
			}
			else if (_unitWindow->scrollPos == 3)
			{
				if (_unitWindow->toolList1_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 2;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList2_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 3;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList3_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 4;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList4_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 5;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList5_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 6;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
				else if (_unitWindow->toolList6_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 7;
					DrawText(getMemDC(), (*_unit[0]._viTools)->detail.c_str(), ::strlen((*_unit[0]._viTools)->detail.c_str()), &_unitWindow->toolDetail, DT_LEFT | DT_EXTERNALLEADING | DT_WORDBREAK);
				}
			}

			shadowDraw(_unitWindow->sellButton);
			lightDraw(_unitWindow->sellButton);
			if (!(_unitWindow->isSellButton)) grayDraw(_unitWindow->sellButton);
			else clickedColor(_unitWindow->sellButton);

			wsprintf(str, "팔기");
			TextOut(getMemDC(), _unitWindow->sellButton.left + 25, _unitWindow->sellButton.top + 5, str, lstrlen(str));

			TextOut(getMemDC(), _unitWindow->sellButton.right + 75, _unitWindow->sellButton.top + 8, "소지금", lstrlen("소지금"));

			wsprintf(str, "%d", _money);
			TextOut(getMemDC(), _unitWindow->sellButton.right + 150, _unitWindow->sellButton.top + 8, str, lstrlen(str));

			//판매창
			if (_unitWindow->isSellButton)
			{
				lightGrayDraw(_unitWindow->sellWindow);

				brush = CreateSolidBrush(RGB(153, 204, 255));
				Rectangle(getMemDC(), _unitWindow->sellWin_name.left, _unitWindow->sellWin_name.top, _unitWindow->sellWin_name.right, _unitWindow->sellWin_name.bottom);
				FillRect(getMemDC(), &_unitWindow->sellWin_name, brush);
				DeleteObject(brush);
				TextOut(getMemDC(), _unitWindow->sellWin_name.left + 3, _unitWindow->sellWin_name.top + 6, "몇개 팔았습니까?", lstrlen("몇개 팔았습니까?"));

				TextOut(getMemDC(), _unitWindow->sellWin_name.left + 13, _unitWindow->sellWin_name.bottom + 12, "갯수", lstrlen("갯수"));
				Rectangle(getMemDC(), _unitWindow->sellWin_num.left, _unitWindow->sellWin_num.top, _unitWindow->sellWin_num.right, _unitWindow->sellWin_num.bottom);
				Rectangle(getMemDC(), _unitWindow->sellWin_numUp.left, _unitWindow->sellWin_numUp.top, _unitWindow->sellWin_numUp.right, _unitWindow->sellWin_numUp.bottom);
				TextOut(getMemDC(), _unitWindow->sellWin_numUp.left + 7, _unitWindow->sellWin_numUp.top, "▲", lstrlen("▲"));
				Rectangle(getMemDC(), _unitWindow->sellWin_numDown.left, _unitWindow->sellWin_numDown.top, _unitWindow->sellWin_numDown.right, _unitWindow->sellWin_numDown.bottom);
				TextOut(getMemDC(), _unitWindow->sellWin_numUp.left + 7, _unitWindow->sellWin_numDown.top, "▼", lstrlen("▼"));

				wsprintf(str, "%d", _unitWindow->sellItem_num);
				TextOut(getMemDC(), _unitWindow->sellWin_num.left + 3, _unitWindow->sellWin_num.top + 7, str, lstrlen(str));

				TextOut(getMemDC(), _unitWindow->sellWin_name.left + 13, _unitWindow->sellWin_name.bottom + 52, "소지금", lstrlen("소지금"));
				wsprintf(str, "%d", _money);
				TextOut(getMemDC(), _unitWindow->sellWin_name.left + 120, _unitWindow->sellWin_name.bottom + 52, str, lstrlen(str));

				TextOut(getMemDC(), _unitWindow->sellWin_name.left + 13, _unitWindow->sellWin_name.bottom + 84, "금액", lstrlen("금액"));
				if (_unitWindow->toolList1_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin();
					wsprintf(str, "%d", ((*_unit[0]._viTools)->money / 2) * _unitWindow->sellItem_num);
					TextOut(getMemDC(), _unitWindow->sellWin_name.left + 120, _unitWindow->sellWin_name.bottom + 84, str, lstrlen(str));
				}
				else if (_unitWindow->toolList2_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 1;
					wsprintf(str, "%d", ((*_unit[0]._viTools)->money / 2) * _unitWindow->sellItem_num);
					TextOut(getMemDC(), _unitWindow->sellWin_name.left + 120, _unitWindow->sellWin_name.bottom + 84, str, lstrlen(str));
				}
				else if (_unitWindow->toolList3_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 2;
					wsprintf(str, "%d", ((*_unit[0]._viTools)->money / 2) * _unitWindow->sellItem_num);
					TextOut(getMemDC(), _unitWindow->sellWin_name.left + 120, _unitWindow->sellWin_name.bottom + 84, str, lstrlen(str));
				}
				else if (_unitWindow->toolList4_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 3;
					wsprintf(str, "%d", ((*_unit[0]._viTools)->money / 2) * _unitWindow->sellItem_num);
					TextOut(getMemDC(), _unitWindow->sellWin_name.left + 120, _unitWindow->sellWin_name.bottom + 84, str, lstrlen(str));
				}
				else if (_unitWindow->toolList5_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 4;
					wsprintf(str, "%d", ((*_unit[0]._viTools)->money / 2) * _unitWindow->sellItem_num);
					TextOut(getMemDC(), _unitWindow->sellWin_name.left + 120, _unitWindow->sellWin_name.bottom + 84, str, lstrlen(str));
				}
				else if (_unitWindow->toolList6_clicked)
				{
					_unit[0]._viTools = _unit[0]._vTools.begin() + 5;
					wsprintf(str, "%d", ((*_unit[0]._viTools)->money / 2) * _unitWindow->sellItem_num);
					TextOut(getMemDC(), _unitWindow->sellWin_name.left + 120, _unitWindow->sellWin_name.bottom + 84, str, lstrlen(str));
				}

				shadowDraw(_unitWindow->sellWin_sellButton);
				lightDraw(_unitWindow->sellWin_sellButton);

				lightGrayDraw(_unitWindow->sellWin_sellButton);
				TextOut(getMemDC(), _unitWindow->sellWin_sellButton.left + 25, _unitWindow->sellWin_sellButton.top + 7, "팔았다!", lstrlen("팔았다!"));

				shadowDraw(_unitWindow->sellWin_exitButton);
				lightDraw(_unitWindow->sellWin_exitButton);

				lightGrayDraw(_unitWindow->sellWin_exitButton);
				TextOut(getMemDC(), _unitWindow->sellWin_exitButton.left + 19, _unitWindow->sellWin_exitButton.top + 7, "그만두자", lstrlen("그만두자"));
			}//판매창 end
		}//도구창 end
	}//유닛 일람end

	TCHAR please1[100];
	wsprintf(please1, "scrollPos1 : %d", _unitWindow->scrollPos1);
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	TextOut(getMemDC(), 100, 0, please1, lstrlen(please1));

	TCHAR please2[100];
	wsprintf(please2, "scrollPos : %d", _unitWindow->scrollPos);
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	TextOut(getMemDC(), 0, 0, please2, lstrlen(please2));
}

void UnitList::shadowDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(051, 051, 051));
	RECT shadow = RectMake(rc.left + 3, rc.top + 3, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), shadow.left, shadow.top, shadow.right, shadow.bottom);
	FillRect(getMemDC(), &shadow, brush);
	DeleteObject(brush);
}

void UnitList::lightDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	RECT light = RectMake(rc.left - 1, rc.top - 1, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
	FillRect(getMemDC(), &light, brush);
	DeleteObject(brush);
}

void UnitList::grayDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(204, 204, 204));
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	FillRect(getMemDC(), &rc, brush);
	DeleteObject(brush);
}

void UnitList::lightGrayDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(220, 220, 220));
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	FillRect(getMemDC(), &rc, brush);
	DeleteObject(brush);
}

void UnitList::clickedColor(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(240, 240, 240));
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	FillRect(getMemDC(), &rc, brush);
	DeleteObject(brush);
}

void UnitList::shadowDraw_reverse(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(051, 051, 051));
	RECT shadow = RectMake(rc.left - 1, rc.top - 1, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), shadow.left, shadow.top, shadow.right, shadow.bottom);
	FillRect(getMemDC(), &shadow, brush);
	DeleteObject(brush);
}

void UnitList::lightDraw_reverse(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	RECT light = RectMake(rc.left + 1, rc.top + 1, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
	FillRect(getMemDC(), &light, brush);
	DeleteObject(brush);
}