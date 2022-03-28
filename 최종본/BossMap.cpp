#include "framework.h"
#include "BossMap.h"

BossMap::BossMap()
{
}

BossMap::~BossMap()
{
}

HRESULT BossMap::init()
{
	_player = new bossMap_player;
	_player->init();

	_monster = new bossMap_monster;
	_monster->init();

	//IMAGE->addImage("forestMap", "images/battleMap_forestVersion.bmp", 2020, 599, true, RGB(255, 255, 255));
	IMAGE->addImage("보스맵_배경화면", "images/boss/보스맵_배경화면_1.bmp", WINSIZEX, WINSIZEY + 5, true, RGB(255, 255, 255));
	//IMAGE->addImage("interface", "images/interface.bmp", 250, 100, true, RGB(255, 0, 255));
	IMAGE->addImage("interface", "images/interface3.bmp", 286, 99, true, RGB(255, 0, 255));

	m_index = 0;
	m_count = 0;
	//m_camera = 0;
	isLeft = false;
	inventory_active = false;

	money = 0;

	inventory_name = RectMake(Menu_RC.left, Menu_RC.top, Menu_RC.right - Menu_RC.left, 20);
	inventory_close = RectMake(Menu_RC.right - 20, Menu_RC.top, 20, 20);
	inventory_money = RectMake(Menu_RC.left, Menu_RC.bottom - 30, Menu_RC.right - Menu_RC.left, 30);

	//단축키.
	//key_Q = RectMake(920, 150, 50, 50);
	//key_W = RectMake(920, 220, 50, 50);
	//key_E = RectMake(920, 290, 50, 50);
	key_Q = RectMake(809, 123, 35, 40);
	key_W = RectMake(863, 123, 35, 40);
	key_E = RectMake(915, 123, 35, 40);

	Qkey_itemInfo = nullptr;
	Wkey_itemInfo = nullptr;
	Ekey_itemInfo = nullptr;

	//마을.
	//townButton = RectMake(10, 600, 150, 30);
	//town_active = false;

	return S_OK;
}

void BossMap::release()
{
	SAFE_DELETE(_player);
	SAFE_DELETE(_monster);
}

void BossMap::update()
{
	_player->update();
	//m_camera = _player->getCamera();

	//_monster->setCamera(m_camera);
	_monster->setPlayerX(_player->getPlayerX());
	_monster->setPlayerY(_player->getPlayerY());

	_monster->update();
	_vMonster = _monster->getVMonster();
	_vDevil = _monster->getVDevil();

	_vMeteor = _monster->getVMeteor();
	lightning = _monster->getLightning();
	_vFlame = _monster->getVFlame();
	//마을.
	if (InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		//if (PtInRect(&townButton, m_ptMouse))
		//{
		//	town_active = true;
		//
		//	SOUND->stop("전투");
		//}
	}

	//인벤토리.
	if (InputManager->isOnceKeyDown('I'))inventory_active = !inventory_active;

	if (inventory_active)
	{
		inventory_name = RectMake(Menu_RC.left, Menu_RC.top, Menu_RC.right - Menu_RC.left, 20);
		inventory_close = RectMake(Menu_RC.right - 20, Menu_RC.top, 20, 20);
		inventory_money = RectMake(Menu_RC.left, Menu_RC.bottom - 30, Menu_RC.right - Menu_RC.left, 30);
	}

	if (isDoubleClick)
	{
		if (PtInRect(&invenPos1_RC, m_ptMouse) && !_vTools.empty())
		{
			_viTools = _vTools.begin();
			(*_viTools)->num--;
			if ((*_viTools)->num <= 0)
			{
				if (Qkey_itemInfo != nullptr && (*_viTools)->name == Qkey_itemInfo->name) Qkey_itemInfo = nullptr;
				if (Wkey_itemInfo != nullptr && (*_viTools)->name == Wkey_itemInfo->name) Wkey_itemInfo = nullptr;
				if (Ekey_itemInfo != nullptr && (*_viTools)->name == Ekey_itemInfo->name) Ekey_itemInfo = nullptr;
				_vTools.erase(_viTools);

			}
		}
		else if (PtInRect(&invenPos2_RC, m_ptMouse) && _vTools.size() > 1)
		{
			_viTools = _vTools.begin() + 1;
			(*_viTools)->num--;
			if ((*_viTools)->num <= 0)
			{
				if (Qkey_itemInfo != nullptr && (*_viTools)->name == Qkey_itemInfo->name) Qkey_itemInfo = nullptr;
				if (Wkey_itemInfo != nullptr && (*_viTools)->name == Wkey_itemInfo->name) Wkey_itemInfo = nullptr;
				if (Ekey_itemInfo != nullptr && (*_viTools)->name == Ekey_itemInfo->name) Ekey_itemInfo = nullptr;
				_vTools.erase(_viTools);
			}
		}
		else if (PtInRect(&invenPos3_RC, m_ptMouse) && _vTools.size() > 2)
		{
			_viTools = _vTools.begin() + 2;
			(*_viTools)->num--;
			if ((*_viTools)->num <= 0)
			{
				if (Qkey_itemInfo != nullptr && (*_viTools)->name == Qkey_itemInfo->name) Qkey_itemInfo = nullptr;
				if (Wkey_itemInfo != nullptr && (*_viTools)->name == Wkey_itemInfo->name) Wkey_itemInfo = nullptr;
				if (Ekey_itemInfo != nullptr && (*_viTools)->name == Ekey_itemInfo->name) Ekey_itemInfo = nullptr;
				_vTools.erase(_viTools);
			}
		}
		else if (PtInRect(&invenPos4_RC, m_ptMouse) && _vTools.size() > 3)
		{
			_viTools = _vTools.begin() + 3;
			(*_viTools)->num--;
			if ((*_viTools)->num <= 0)
			{
				if (Qkey_itemInfo != nullptr && (*_viTools)->name == Qkey_itemInfo->name) Qkey_itemInfo = nullptr;
				if (Wkey_itemInfo != nullptr && (*_viTools)->name == Wkey_itemInfo->name) Wkey_itemInfo = nullptr;
				if (Ekey_itemInfo != nullptr && (*_viTools)->name == Ekey_itemInfo->name) Ekey_itemInfo = nullptr;
				_vTools.erase(_viTools);
			}
		}
		else if (PtInRect(&invenPos5_RC, m_ptMouse) && _vTools.size() > 4)
		{
			_viTools = _vTools.begin() + 4;
			(*_viTools)->num--;
			if ((*_viTools)->num <= 0)
			{
				if (Qkey_itemInfo != nullptr && (*_viTools)->name == Qkey_itemInfo->name) Qkey_itemInfo = nullptr;
				if (Wkey_itemInfo != nullptr && (*_viTools)->name == Wkey_itemInfo->name) Wkey_itemInfo = nullptr;
				if (Ekey_itemInfo != nullptr && (*_viTools)->name == Ekey_itemInfo->name) Ekey_itemInfo = nullptr;
				_vTools.erase(_viTools);
			}
		}
		else if (PtInRect(&invenPos6_RC, m_ptMouse) && _vTools.size() > 5)
		{
			_viTools = _vTools.begin() + 5;
			(*_viTools)->num--;
			if ((*_viTools)->num <= 0)
			{
				if (Qkey_itemInfo != nullptr && (*_viTools)->name == Qkey_itemInfo->name) Qkey_itemInfo = nullptr;
				if (Wkey_itemInfo != nullptr && (*_viTools)->name == Wkey_itemInfo->name) Wkey_itemInfo = nullptr;
				if (Ekey_itemInfo != nullptr && (*_viTools)->name == Ekey_itemInfo->name) Ekey_itemInfo = nullptr;
				_vTools.erase(_viTools);
			}
		}
		else if (PtInRect(&invenPos7_RC, m_ptMouse) && _vTools.size() > 6)
		{
			_viTools = _vTools.begin() + 6;
			(*_viTools)->num--;
			if ((*_viTools)->num <= 0)
			{
				if (Qkey_itemInfo != nullptr && (*_viTools)->name == Qkey_itemInfo->name) Qkey_itemInfo = nullptr;
				if (Wkey_itemInfo != nullptr && (*_viTools)->name == Wkey_itemInfo->name) Wkey_itemInfo = nullptr;
				if (Ekey_itemInfo != nullptr && (*_viTools)->name == Ekey_itemInfo->name) Ekey_itemInfo = nullptr;
				_vTools.erase(_viTools);
			}
		}
		else if (PtInRect(&invenPos8_RC, m_ptMouse) && _vTools.size() > 7)
		{
			_viTools = _vTools.begin() + 7;
			(*_viTools)->num--;
			if ((*_viTools)->num <= 0)
			{
				if (Qkey_itemInfo != nullptr && (*_viTools)->name == Qkey_itemInfo->name) Qkey_itemInfo = nullptr;
				if (Wkey_itemInfo != nullptr && (*_viTools)->name == Wkey_itemInfo->name) Wkey_itemInfo = nullptr;
				if (Ekey_itemInfo != nullptr && (*_viTools)->name == Ekey_itemInfo->name) Ekey_itemInfo = nullptr;
				_vTools.erase(_viTools);
			}
		}
		else if (PtInRect(&invenPos9_RC, m_ptMouse) && _vTools.size() > 8)
		{
			_viTools = _vTools.begin() + 8;
			(*_viTools)->num--;
			if ((*_viTools)->num <= 0)
			{
				if (Qkey_itemInfo != nullptr && (*_viTools)->name == Qkey_itemInfo->name) Qkey_itemInfo = nullptr;
				if (Wkey_itemInfo != nullptr && (*_viTools)->name == Wkey_itemInfo->name) Wkey_itemInfo = nullptr;
				if (Ekey_itemInfo != nullptr && (*_viTools)->name == Ekey_itemInfo->name) Ekey_itemInfo = nullptr;
				_vTools.erase(_viTools);
			}
		}
	}


	//왼쪽 클릭.
	if (InputManager->isOnceKeyUp(VK_LBUTTON))
	{
		//if (PtInRect(&_monster->getKidRC(), m_ptMouse)) town_active = true;

		//단축키.
		changeKey();

		if (inventory_active)
		{
			if (PtInRect(&inventory_close, m_ptMouse)) inventory_active = !inventory_active;

			invenPos1_RC = RectMake(Menu_RC.left + 10, Menu_RC.top + 35, 50, 50);
			invenPos2_RC = RectMake(Menu_RC.left + 70, Menu_RC.top + 35, 50, 50);
			invenPos3_RC = RectMake(Menu_RC.left + 130, Menu_RC.top + 35, 50, 50);
			invenPos4_RC = RectMake(Menu_RC.left + 10, Menu_RC.top + 95, 50, 50);
			invenPos5_RC = RectMake(Menu_RC.left + 70, Menu_RC.top + 95, 50, 50);
			invenPos6_RC = RectMake(Menu_RC.left + 130, Menu_RC.top + 95, 50, 50);
			invenPos7_RC = RectMake(Menu_RC.left + 10, Menu_RC.top + 155, 50, 50);
			invenPos8_RC = RectMake(Menu_RC.left + 70, Menu_RC.top + 155, 50, 50);
			invenPos9_RC = RectMake(Menu_RC.left + 130, Menu_RC.top + 155, 50, 50);
		}
	}

	//단축키 아이템 사용.
	if (InputManager->isOnceKeyDown('Q') && Qkey_itemInfo != nullptr)
	{
		Qkey_itemInfo->num--;
		_viTools = _vTools.begin();
		for (_viTools; _viTools != _vTools.end(); ++_viTools)
		{
			if ((*_viTools)->name == Qkey_itemInfo->name)
			{
				if (Qkey_itemInfo->num <= 0)
				{
					//if (Wkey_itemInfo->name == Qkey_itemInfo->name)
					//{
					//	Wkey_itemInfo = nullptr;
					//}
					//if (Ekey_itemInfo->name == Qkey_itemInfo->name)
					//{
					//	Ekey_itemInfo = nullptr;
					//}

					Qkey_itemInfo = nullptr;

					_vTools.erase(_viTools);
					break;
				}
				else (*_viTools)->num = Qkey_itemInfo->num;
			}
		}
	}
	if (InputManager->isOnceKeyDown('W') && Wkey_itemInfo != nullptr)
	{
		Wkey_itemInfo->num--;
		_viTools = _vTools.begin();
		for (_viTools; _viTools != _vTools.end(); ++_viTools)
		{
			if ((*_viTools)->name == Wkey_itemInfo->name)
			{
				if (Wkey_itemInfo->num <= 0)
				{
					//if (Qkey_itemInfo->name == Wkey_itemInfo->name)
					//{
					//	Qkey_itemInfo = nullptr;
					//}
					//if (Ekey_itemInfo->name == Wkey_itemInfo->name)
					//{
					//	Ekey_itemInfo = nullptr;
					//}

					Wkey_itemInfo = nullptr;
					_vTools.erase(_viTools);
					break;
				}
				else (*_viTools)->num = Wkey_itemInfo->num;
			}
		}
	}
	if (InputManager->isOnceKeyDown('E') && Ekey_itemInfo != nullptr)
	{
		Ekey_itemInfo->num--;
		_viTools = _vTools.begin();
		for (_viTools; _viTools != _vTools.end(); ++_viTools)
		{
			if ((*_viTools)->name == Ekey_itemInfo->name)
			{
				if (Ekey_itemInfo->num <= 0)
				{
					//if (Qkey_itemInfo->name == Ekey_itemInfo->name)
					//{
					//	Qkey_itemInfo = nullptr;
					//}
					//if (Wkey_itemInfo->name == Ekey_itemInfo->name)
					//{
					//	Wkey_itemInfo = nullptr;
					//}

					Ekey_itemInfo = nullptr;
					_vTools.erase(_viTools);
					break;
				}
				else (*_viTools)->num = Ekey_itemInfo->num;
			}
		}
	}

	bool playerCollide = false;
	vector<monsterInfo*>::iterator _viMonster;
	for (_viMonster = _vMonster.begin(); _viMonster != _vMonster.end(); ++_viMonster)
	{
		RECT temp;
		if (IntersectRect(&temp, &(*_viMonster)->rc, &_player->getRect()))
		{
			playerCollide = true;
			(*_viMonster)->isCollide = true;
			if ((*_viMonster)->currentState == MONSTER_STATE::ATTACK &&
				!(_player->getCurrentState() == PLAYER_STATE::ATTACK1 || _player->getCurrentState() == PLAYER_STATE::ATTACK2))
			{
				_player->setCurrentState(PLAYER_STATE::DAMAGE);
				//_player->setHP(_player->getHP() - 0.01f);
			}

			if ((_player->getCurrentState() == PLAYER_STATE::ATTACK1 || _player->getCurrentState() == PLAYER_STATE::ATTACK2))
			{
				(*_viMonster)->currentState = MONSTER_STATE::DAMAGE;
				(*_viMonster)->hp -= 1;
				_player->setEXP(_player->getEXP() + 0.1f);

				//=======================
				// 	   애기추가쓰
				// 랜덤확률(4퍼?5퍼?)로 애기드랍
				//if ((*_viMonster)->hp <= 0) (*_viMonster)->isExist = false;
				if ((*_viMonster)->hp <= 0)
				{
					if ((*_viMonster)->name == "boss")
					{
						//town_active = true;
						ending_active = true;
						SOUND->stop("마을");
						break;
					}

					(*_viMonster)->isExist = false;
					if (RND->getFromIntTo(0, 100) > 5 && (*_viMonster)->x > 50 && (*_viMonster)->x < WINSIZEX - 50 && !_monster->getIsKid())
					{
						_monster->setIsKid(true);
						if ((*_viMonster)->isLeft) { _monster->setKidPosX((*_viMonster)->x + 5); }
						else { _monster->setKidPosX((*_viMonster)->x - 5); }
						_monster->setKidPosY((*_viMonster)->y + 10);
					}
				}
				//=======================
			}
			//플레이어 스킬 사용시
			if ((_player->getCurrentState() == PLAYER_STATE::SKILL))
			{
				(*_viMonster)->currentState = MONSTER_STATE::DAMAGE;
				(*_viMonster)->hp -= 5;
				_player->setEXP(_player->getEXP() + 0.1f);
				_player->setMP(_player->getMP() - 10);

				//=======================
				// 	   애기추가쓰
				// 랜덤확률(4퍼?5퍼?)로 애기드랍
				//if ((*_viMonster)->hp <= 0) (*_viMonster)->isExist = false;
				if ((*_viMonster)->hp <= 0)
				{
					(*_viMonster)->isExist = false;
					if (RND->getFromIntTo(0, 100) > 5 && (*_viMonster)->x > 50 && (*_viMonster)->x < WINSIZEX - 50 && !_monster->getIsKid())
					{
						_monster->setIsKid(true);
						if ((*_viMonster)->isLeft) { _monster->setKidPosX((*_viMonster)->x + 5); }
						else { _monster->setKidPosX((*_viMonster)->x - 5); }
						_monster->setKidPosY((*_viMonster)->y + 10);
					}
				}
				//=======================
			}
		}
		//스킬 렉트와 충돌시
		else if (IntersectRect(&temp, &(*_viMonster)->rc, &_player->getSkillRect()) && _player->getCurrentState() == PLAYER_STATE::SKILL)
		{
			(*_viMonster)->currentState = MONSTER_STATE::DAMAGE;
			(*_viMonster)->hp -= 5;
			_player->setEXP(_player->getEXP() + 0.1f);

			if ((*_viMonster)->hp <= 0)(*_viMonster)->isExist = false;
		}
		else (*_viMonster)->isCollide = false;
	}
	_monster->setVMonster(_vMonster);

	//데빌.
	bool playerCollide_devil = false;
	vector<monsterInfo*>::iterator _viDevil;
	for (_viDevil = _vDevil.begin(); _viDevil != _vDevil.end(); ++_viDevil)
	{
		RECT temp;
		if (IntersectRect(&temp, &(*_viDevil)->rc, &_player->getRect()))
		{
			playerCollide_devil = true;
			(*_viDevil)->isCollide = true;
			if ((*_viDevil)->currentState == MONSTER_STATE::ATTACK &&
				!(_player->getCurrentState() == PLAYER_STATE::ATTACK1 || _player->getCurrentState() == PLAYER_STATE::ATTACK2))
			{
				_player->setCurrentState(PLAYER_STATE::DAMAGE);
				//_player->setHP(_player->getHP() - 0.01f);
			}

			if ((_player->getCurrentState() == PLAYER_STATE::ATTACK1 || _player->getCurrentState() == PLAYER_STATE::ATTACK2))
			{
				(*_viDevil)->currentState = MONSTER_STATE::DAMAGE;
				(*_viDevil)->hp -= 1;
				_player->setEXP(_player->getEXP() + 0.1f);

				if ((*_viDevil)->hp <= 0)
				{
					(*_viDevil)->isExist = false;
				}
			}
			//플레이어 스킬 사용시
			if ((_player->getCurrentState() == PLAYER_STATE::SKILL))
			{
				(*_viDevil)->currentState = MONSTER_STATE::DAMAGE;
				(*_viDevil)->hp -= 5;
				_player->setEXP(_player->getEXP() + 0.1f);
				_player->setMP(_player->getMP() - 10);


				if ((*_viDevil)->hp <= 0)
				{
					(*_viDevil)->isExist = false;
				}
			}
		}
		//스킬 렉트와 충돌시
		else if (IntersectRect(&temp, &(*_viDevil)->rc, &_player->getSkillRect()) && _player->getCurrentState() == PLAYER_STATE::SKILL)
		{
			(*_viDevil)->currentState = MONSTER_STATE::DAMAGE;
			(*_viDevil)->hp -= 5;
			_player->setEXP(_player->getEXP() + 0.1f);

			if ((*_viDevil)->hp <= 0)(*_viDevil)->isExist = false;
		}
		else (*_viDevil)->isCollide = false;
	}
	_monster->setVDevil(_vDevil);

	//운석.
	_viMeteor = _vMeteor.begin();
	for (_viMeteor; _viMeteor != _vMeteor.end(); ++_viMeteor)
	{
		RECT temp;
		if (IntersectRect(&temp, &_player->getRect(), &(*_viMeteor)->rc))
		{
			_player->setCurrentState(PLAYER_STATE::DAMAGE);
			//_player->setHP(_player->getHP() - 0.01f);
			(*_viMeteor)->isExist = false;
			//(*_viMeteor)->x = RND->getFromIntTo()
		}
	}
	_monster->setVMeteor(_vMeteor);
	//번개.
	RECT temp;
	if (IntersectRect(&temp, &lightning->rc, &_player->getRect()))
	{
		if (lightning->isExist) _player->setCurrentState(PLAYER_STATE::DAMAGE);
	}

	//불꽃기둥.
	_viFlame = _vFlame.begin();
	for (_viFlame; _viFlame != _vFlame.end(); ++_viFlame)
	{
		RECT temp;
		if (IntersectRect(&temp, &_player->getRect(), &(*_viFlame)->rc))
		{
			//_player->setCurrentState(PLAYER_STATE::DAMAGE);
			//_player->setHP(_player->getHP() - 0.01f);
			//(*_viFlame)->isExist = false;
			//(*_viMeteor)->x = RND->getFromIntTo()
		}
	}
	_monster->setVFlame(_vFlame);

	if (playerCollide || playerCollide_devil)_player->setCollide(true);
	else _player->setCollide(false);

	//=======================
	// 	   애기추가쓰

	//RECT temp;
	//if (IntersectRect(&temp, &_player->getRect(), &_monster->getKidRC()))
	//{
	//	activeTime++;
		//액티브타임얼마이상이면
		//타운액티브
	//}

	//여기봐줘
	//if (InputManager->isOnceKeyDown(VK_LBUTTON))
	//{
	//	if (PtInRect(&_monster->getKidRC(), m_ptMouse)) town_active = true;
	//}

	//=======================


	//mini_rc = RectMakeCenter(100 + _player->getImg()->getX() / 10 - m_camera / 10, 50 + _player->getImg()->getY() / 10, 10, 10);

	if (InputManager->isOnceKeyDown('2')) isDebug = !isDebug;
}

void BossMap::render()
{
	SetBkMode(getMemDC(), TRANSPARENT);

	IMAGE->findImage("보스맵_배경화면")->render(getMemDC(), 0, 0);
	//IMAGE->findImage("interface")->render(getMemDC(), WINSIZEX / 2 - 80, WINSIZEY - 220);
	IMAGE->findImage("interface")->render(getMemDC(), 20, 20);
	_monster->render();
	_player->render();

	if (lightning->isExist) lightning->img->frameRender(getMemDC(), lightning->x, lightning->y);

	TCHAR str[30];
	//wsprintf(str, "isDoubleClick: %d", isDoubleClick);
	//TextOut(getMemDC(), 10, 480, str, lstrlen(str));

	if (isDebug)
	{
		//캐릭터 좌표
		TCHAR str[30];
		wsprintf(str, "player x : %d, y : %d", _player->getPlayerX(), _player->getPlayerY());
		TextOut(getMemDC(), 10, 480, str, lstrlen(str));

		Rectangle(getMemDC(), mini_rc.left, mini_rc.top, mini_rc.right, mini_rc.bottom);
	}

	if (InputManager->isStayKeyDown(VK_LBUTTON))
	{
		if (inventory_active)
		{
			if (!(isDoubleClick))
			{
				if (PtInRect(&invenPos1_RC, m_ptMouse) && !_vTools.empty()) Rectangle(getMemDC(), invenPos1_RC.left, invenPos1_RC.top, invenPos1_RC.right, invenPos1_RC.bottom);
				if (PtInRect(&invenPos2_RC, m_ptMouse) && _vTools.size() > 1) Rectangle(getMemDC(), invenPos2_RC.left, invenPos2_RC.top, invenPos2_RC.right, invenPos2_RC.bottom);
				if (PtInRect(&invenPos3_RC, m_ptMouse) && _vTools.size() > 2) Rectangle(getMemDC(), invenPos3_RC.left, invenPos3_RC.top, invenPos3_RC.right, invenPos3_RC.bottom);
				if (PtInRect(&invenPos4_RC, m_ptMouse) && _vTools.size() > 3) Rectangle(getMemDC(), invenPos4_RC.left, invenPos4_RC.top, invenPos4_RC.right, invenPos4_RC.bottom);
				if (PtInRect(&invenPos5_RC, m_ptMouse) && _vTools.size() > 4) Rectangle(getMemDC(), invenPos5_RC.left, invenPos5_RC.top, invenPos5_RC.right, invenPos5_RC.bottom);
				if (PtInRect(&invenPos6_RC, m_ptMouse) && _vTools.size() > 5) Rectangle(getMemDC(), invenPos6_RC.left, invenPos6_RC.top, invenPos6_RC.right, invenPos6_RC.bottom);
				if (PtInRect(&invenPos7_RC, m_ptMouse) && _vTools.size() > 6) Rectangle(getMemDC(), invenPos7_RC.left, invenPos7_RC.top, invenPos7_RC.right, invenPos7_RC.bottom);
				if (PtInRect(&invenPos8_RC, m_ptMouse) && _vTools.size() > 7) Rectangle(getMemDC(), invenPos8_RC.left, invenPos8_RC.top, invenPos8_RC.right, invenPos8_RC.bottom);
				if (PtInRect(&invenPos9_RC, m_ptMouse) && _vTools.size() > 8) Rectangle(getMemDC(), invenPos9_RC.left, invenPos9_RC.top, invenPos9_RC.right, invenPos9_RC.bottom);
			}
		}
	}

	//아이템 display.
	if (inventory_active)
	{
		Rectangle(getMemDC(), Menu_RC.left, Menu_RC.top, Menu_RC.right, Menu_RC.bottom);

		RectangleMake(getMemDC(), Menu_RC.left + 10, Menu_RC.top + 35, 50, 50);//1.
		RectangleMake(getMemDC(), Menu_RC.left + 70, Menu_RC.top + 35, 50, 50);//2.
		RectangleMake(getMemDC(), Menu_RC.left + 130, Menu_RC.top + 35, 50, 50);//3.
		RectangleMake(getMemDC(), Menu_RC.left + 10, Menu_RC.top + 95, 50, 50);
		RectangleMake(getMemDC(), Menu_RC.left + 70, Menu_RC.top + 95, 50, 50);
		RectangleMake(getMemDC(), Menu_RC.left + 130, Menu_RC.top + 95, 50, 50);
		RectangleMake(getMemDC(), Menu_RC.left + 10, Menu_RC.top + 155, 50, 50);
		RectangleMake(getMemDC(), Menu_RC.left + 70, Menu_RC.top + 155, 50, 50);
		RectangleMake(getMemDC(), Menu_RC.left + 130, Menu_RC.top + 155, 50, 50);

		SetTextColor(getMemDC(), RGB(0, 0, 0));
		Rectangle(getMemDC(), inventory_name.left, inventory_name.top, inventory_name.right, inventory_name.bottom);
		TextOut(getMemDC(), inventory_name.left + 3, inventory_name.top + 3, "inventory", lstrlen("inventory"));


		Rectangle(getMemDC(), inventory_close.left, inventory_close.top, inventory_close.right, inventory_close.bottom);
		TextOut(getMemDC(), inventory_close.left + 6, inventory_close.top + 3, "X", lstrlen("X"));

		Rectangle(getMemDC(), inventory_money.left, inventory_money.top, inventory_money.right, inventory_money.bottom);
		wsprintf(str, "GOLD : %d", money);
		TextOut(getMemDC(), inventory_money.left + 3, inventory_money.top + 6, str, lstrlen(str));

		if (!_vTools.empty())
		{
			_viTools = _vTools.begin();
			//TextOut(getMemDC(), Menu_RC.left + 10, Menu_RC.top + 35, (*_viTools)->name.c_str(), lstrlen((*_viTools)->name.c_str()));
			(*_viTools)->iconImg->render(getMemDC(), Menu_RC.left + 10 + 10, Menu_RC.top + 35 + 15);
			TextOut(getMemDC(), Menu_RC.left + 10 + 40, Menu_RC.top + 35 + 35, to_string((*_viTools)->num).c_str(), lstrlen(to_string((*_viTools)->num).c_str()));
		}

		if (_vTools.size() > 1)
		{
			_viTools = _vTools.begin() + 1;
			//TextOut(getMemDC(), Menu_RC.left + 70, Menu_RC.top + 35, (*_viTools)->name.c_str(), lstrlen((*_viTools)->name.c_str()));
			(*_viTools)->iconImg->render(getMemDC(), Menu_RC.left + 70 + 10, Menu_RC.top + 35 + 15);
			TextOut(getMemDC(), Menu_RC.left + 70 + 40, Menu_RC.top + 35 + 35, to_string((*_viTools)->num).c_str(), lstrlen(to_string((*_viTools)->num).c_str()));
		}

		if (_vTools.size() > 2)
		{
			_viTools = _vTools.begin() + 2;
			//TextOut(getMemDC(), Menu_RC.left + 130, Menu_RC.top + 35, (*_viTools)->name.c_str(), lstrlen((*_viTools)->name.c_str()));
			(*_viTools)->iconImg->render(getMemDC(), Menu_RC.left + 130 + 10, Menu_RC.top + 35 + 15);
			TextOut(getMemDC(), Menu_RC.left + 130 + 40, Menu_RC.top + 35 + 35, to_string((*_viTools)->num).c_str(), lstrlen(to_string((*_viTools)->num).c_str()));
		}

		if (_vTools.size() > 3)
		{
			_viTools = _vTools.begin() + 3;
			//TextOut(getMemDC(), Menu_RC.left + 10, Menu_RC.top + 95, (*_viTools)->name.c_str(), lstrlen((*_viTools)->name.c_str()));
			(*_viTools)->iconImg->render(getMemDC(), Menu_RC.left + 10 + 10, Menu_RC.top + 95 + 15);
			TextOut(getMemDC(), Menu_RC.left + 10 + 40, Menu_RC.top + 95 + 35, to_string((*_viTools)->num).c_str(), lstrlen(to_string((*_viTools)->num).c_str()));
		}

		if (_vTools.size() > 4)
		{
			_viTools = _vTools.begin() + 4;
			//TextOut(getMemDC(), Menu_RC.left + 70, Menu_RC.top + 95, (*_viTools)->name.c_str(), lstrlen((*_viTools)->name.c_str()));
			(*_viTools)->iconImg->render(getMemDC(), Menu_RC.left + 70 + 10, Menu_RC.top + 95 + 15);
			TextOut(getMemDC(), Menu_RC.left + 70 + 40, Menu_RC.top + 95 + 35, to_string((*_viTools)->num).c_str(), lstrlen(to_string((*_viTools)->num).c_str()));
		}

		if (_vTools.size() > 5)
		{
			_viTools = _vTools.begin() + 5;
			//TextOut(getMemDC(), Menu_RC.left + 130, Menu_RC.top + 95, (*_viTools)->name.c_str(), lstrlen((*_viTools)->name.c_str()));
			(*_viTools)->iconImg->render(getMemDC(), Menu_RC.left + 130 + 10, Menu_RC.top + 95 + 15);
			TextOut(getMemDC(), Menu_RC.left + 130 + 40, Menu_RC.top + 95 + 35, to_string((*_viTools)->num).c_str(), lstrlen(to_string((*_viTools)->num).c_str()));
		}

		if (_vTools.size() > 6)
		{
			_viTools = _vTools.begin() + 6;
			//TextOut(getMemDC(), Menu_RC.left + 10, Menu_RC.top + 155, (*_viTools)->name.c_str(), lstrlen((*_viTools)->name.c_str()));
			(*_viTools)->iconImg->render(getMemDC(), Menu_RC.left + 10 + 10, Menu_RC.top + 155 + 15);
			TextOut(getMemDC(), Menu_RC.left + 10 + 40, Menu_RC.top + 155 + 35, to_string((*_viTools)->num).c_str(), lstrlen(to_string((*_viTools)->num).c_str()));
		}

		if (_vTools.size() > 7)
		{
			_viTools = _vTools.begin() + 7;
			//TextOut(getMemDC(), Menu_RC.left + 70, Menu_RC.top + 155, (*_viTools)->name.c_str(), lstrlen((*_viTools)->name.c_str()));
			(*_viTools)->iconImg->render(getMemDC(), Menu_RC.left + 70 + 10, Menu_RC.top + 155 + 15);
			TextOut(getMemDC(), Menu_RC.left + 70 + 40, Menu_RC.top + 155 + 35, to_string((*_viTools)->num).c_str(), lstrlen(to_string((*_viTools)->num).c_str()));
		}

		if (_vTools.size() > 8)
		{
			_viTools = _vTools.begin() + 8;
			//TextOut(getMemDC(), Menu_RC.left + 130, Menu_RC.top + 155, (*_viTools)->name.c_str(), lstrlen((*_viTools)->name.c_str()));
			(*_viTools)->iconImg->render(getMemDC(), Menu_RC.left + 130 + 10, Menu_RC.top + 155 + 15);
			TextOut(getMemDC(), Menu_RC.left + 130 + 40, Menu_RC.top + 155 + 35, to_string((*_viTools)->num).c_str(), lstrlen(to_string((*_viTools)->num).c_str()));
		}
	}

	//단축키.
	//Rectangle(getMemDC(), key_Q.left, key_Q.top, key_Q.right, key_Q.bottom);
	//TextOut(getMemDC(), key_Q.left + 3, key_Q.top + 3, "Q", lstrlen("Q"));
	//
	//Rectangle(getMemDC(), key_W.left, key_W.top, key_W.right, key_W.bottom);
	//TextOut(getMemDC(), key_W.left + 3, key_W.top + 3, "W", lstrlen("W"));
	//
	//Rectangle(getMemDC(), key_E.left, key_E.top, key_E.right, key_E.bottom);
	//TextOut(getMemDC(), key_E.left + 3, key_E.top + 3, "E", lstrlen("E"));
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	if (Qkey_itemInfo != nullptr)
	{
		Qkey_itemInfo->iconImg->render(getMemDC(), key_Q.left + 7, key_Q.top + 13);
		TextOut(getMemDC(), key_Q.right - 10, key_Q.top + 28, to_string(Qkey_itemInfo->num).c_str(), lstrlen(to_string(Qkey_itemInfo->num).c_str()));
	}
	//else TextOut(getMemDC(), key_Q.left + 3, key_Q.top + 20, "비어있음", lstrlen("비어있음"));

	if (Wkey_itemInfo != nullptr)
	{
		Wkey_itemInfo->iconImg->render(getMemDC(), key_W.left + 7, key_W.top + 13);
		TextOut(getMemDC(), key_W.right - 10, key_W.top + 28, to_string(Wkey_itemInfo->num).c_str(), lstrlen(to_string(Wkey_itemInfo->num).c_str()));
	}
	//else TextOut(getMemDC(), key_W.left + 3, key_W.top + 20, "비어있음", lstrlen("비어있음"));

	if (Ekey_itemInfo != nullptr)
	{
		Ekey_itemInfo->iconImg->render(getMemDC(), key_E.left + 7, key_E.top + 13);
		TextOut(getMemDC(), key_E.right - 10, key_E.top + 28, to_string(Ekey_itemInfo->num).c_str(), lstrlen(to_string(Ekey_itemInfo->num).c_str()));
	}
	//else TextOut(getMemDC(), key_E.left + 3, key_E.top + 20, "비어있음", lstrlen("비어있음"));

	//마을.
	//Rectangle(getMemDC(), townButton.left, townButton.top, townButton.right, townButton.bottom);
	//shadowDraw(townButton);
	//lightGrayDraw(townButton);
	//SetTextColor(getMemDC(), RGB(0, 0, 0));
	//TextOut(getMemDC(), townButton.left + 17, townButton.top + 8, "마을로 돌아가기", lstrlen("마을로 돌아가기"));


}//render end.

void BossMap::changeKey()
{
	RECT temp;
	if (IntersectRect(&temp, &invenPos1_RC, &key_Q))
	{
		if (!_vTools.empty())
		{
			_viTools = _vTools.begin();
			Qkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos2_RC, &key_Q))
	{
		if (_vTools.size() > 1)
		{
			_viTools = _vTools.begin() + 1;
			Qkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos3_RC, &key_Q))
	{
		if (_vTools.size() > 2)
		{
			_viTools = _vTools.begin() + 2;
			Qkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos4_RC, &key_Q))
	{
		if (_vTools.size() > 3)
		{
			_viTools = _vTools.begin() + 3;
			Qkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos5_RC, &key_Q))
	{
		if (_vTools.size() > 4)
		{
			_viTools = _vTools.begin() + 4;
			Qkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos6_RC, &key_Q))
	{
		if (_vTools.size() > 5)
		{
			_viTools = _vTools.begin() + 5;
			Qkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos7_RC, &key_Q))
	{
		if (_vTools.size() > 6)
		{
			_viTools = _vTools.begin() + 6;
			Qkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos8_RC, &key_Q))
	{
		if (_vTools.size() > 7)
		{
			_viTools = _vTools.begin() + 7;
			Qkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos9_RC, &key_Q))
	{
		if (_vTools.size() > 8)
		{
			_viTools = _vTools.begin() + 8;
			Qkey_itemInfo = (*_viTools);
		}
	}

	//W.
	else if (IntersectRect(&temp, &invenPos1_RC, &key_W))
	{
		if (!_vTools.empty())
		{
			_viTools = _vTools.begin();
			Wkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos2_RC, &key_W))
	{
		if (_vTools.size() > 1)
		{
			_viTools = _vTools.begin() + 1;
			Wkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos3_RC, &key_W))
	{
		if (_vTools.size() > 2)
		{
			_viTools = _vTools.begin() + 2;
			Wkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos4_RC, &key_W))
	{
		if (_vTools.size() > 3)
		{
			_viTools = _vTools.begin() + 3;
			Wkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos5_RC, &key_W))
	{
		if (_vTools.size() > 4)
		{
			_viTools = _vTools.begin() + 4;
			Wkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos6_RC, &key_W))
	{
		if (_vTools.size() > 5)
		{
			_viTools = _vTools.begin() + 5;
			Wkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos7_RC, &key_W))
	{
		if (_vTools.size() > 6)
		{
			_viTools = _vTools.begin() + 6;
			Wkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos8_RC, &key_W))
	{
		if (_vTools.size() > 7)
		{
			_viTools = _vTools.begin() + 7;
			Wkey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos9_RC, &key_W))
	{
		if (_vTools.size() > 8)
		{
			_viTools = _vTools.begin() + 8;
			Wkey_itemInfo = (*_viTools);
		}
	}

	//E.
	else if (IntersectRect(&temp, &invenPos1_RC, &key_E))
	{
		if (!_vTools.empty())
		{
			_viTools = _vTools.begin();
			Ekey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos2_RC, &key_E))
	{
		if (_vTools.size() > 1)
		{
			_viTools = _vTools.begin() + 1;
			Ekey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos3_RC, &key_E))
	{
		if (_vTools.size() > 2)
		{
			_viTools = _vTools.begin() + 2;
			Ekey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos4_RC, &key_E))
	{
		if (_vTools.size() > 3)
		{
			_viTools = _vTools.begin() + 3;
			Ekey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos5_RC, &key_E))
	{
		if (_vTools.size() > 4)
		{
			_viTools = _vTools.begin() + 4;
			Ekey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos6_RC, &key_E))
	{
		if (_vTools.size() > 5)
		{
			_viTools = _vTools.begin() + 5;
			Ekey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos7_RC, &key_E))
	{
		if (_vTools.size() > 6)
		{
			_viTools = _vTools.begin() + 6;
			Ekey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos8_RC, &key_E))
	{
		if (_vTools.size() > 7)
		{
			_viTools = _vTools.begin() + 7;
			Ekey_itemInfo = (*_viTools);
		}
	}
	else if (IntersectRect(&temp, &invenPos9_RC, &key_E))
	{
		if (_vTools.size() > 8)
		{
			_viTools = _vTools.begin() + 8;
			Ekey_itemInfo = (*_viTools);
		}
	}

}

void BossMap::initialization()
{
	m_index = 0;
	m_count = 0;
	//m_camera = 0;
	isLeft = false;
	inventory_active = false;

	Qkey_itemInfo = nullptr;
	Wkey_itemInfo = nullptr;
	Ekey_itemInfo = nullptr;

	SAFE_DELETE(_player);
	_player = new bossMap_player;
	_player->init();

	SAFE_DELETE(_monster);
	_monster = new bossMap_monster;
	_monster->init();
}


void BossMap::lightGrayDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(220, 220, 220));
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	FillRect(getMemDC(), &rc, brush);
	DeleteObject(brush);
}
void BossMap::shadowDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(051, 051, 051));
	RECT shadow = RectMake(rc.left + 3, rc.top + 3, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), shadow.left, shadow.top, shadow.right, shadow.bottom);
	FillRect(getMemDC(), &shadow, brush);
	DeleteObject(brush);
}
void BossMap::lightDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	RECT light = RectMake(rc.left - 1, rc.top - 1, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
	FillRect(getMemDC(), &light, brush);
	DeleteObject(brush);
}
