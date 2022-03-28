#include "framework.h"
#include "battleMap_monster.h"

battleMap_monster::battleMap_monster()
{
}

battleMap_monster::~battleMap_monster()
{
}

HRESULT battleMap_monster::init()
{	//1.
	IMAGE->addFrameImage("hunter_idle_1", "images/monster/hunter_idle.bmp", 141, 248, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_move_1", "images/monster/hunter_move.bmp", 216, 256, 4, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_attack_1", "images/monster/hunter_attack.bmp", 828, 264, 12, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_hit_1", "images/monster/hunter_hit.bmp", 44, 244, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_die_1", "images/monster/hunter_die.bmp", 37, 272, 1, 4, true, RGB(255, 0, 255));

	IMAGE->addFrameImage("son_idle_1", "images/monster/son_idle.bmp", 186, 318, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_move_1", "images/monster/son_move.bmp", 684, 408, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_attack_1", "images/monster/son_magic.bmp", 504, 320, 7, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_hit_1", "images/monster/son_hit.bmp", 74, 280, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_die_1", "images/monster/son_die.bmp", 457, 130, 5, 2, true, RGB(255, 0, 255));

	//IMAGE->addImage("hunter_emptyHP_1", "images/monster/emptyHP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("hunter_HP_1", "images/monster/HP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("son_emptyHP_1", "images/monster/emptyHP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("son_HP_1", "images/monster/HP.bmp", 150, 12, true, RGB(255, 0, 255));
	//2.
	IMAGE->addFrameImage("hunter_idle_2", "images/monster/hunter_idle.bmp", 141, 248, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_move_2", "images/monster/hunter_move.bmp", 216, 256, 4, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_attack_2", "images/monster/hunter_attack.bmp", 828, 264, 12, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_hit_2", "images/monster/hunter_hit.bmp", 44, 244, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_die_2", "images/monster/hunter_die.bmp", 37, 272, 1, 4, true, RGB(255, 0, 255));

	IMAGE->addFrameImage("son_idle_2", "images/monster/son_idle.bmp", 186, 318, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_move_2", "images/monster/son_move.bmp", 684, 408, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_attack_2", "images/monster/son_magic.bmp", 504, 320, 7, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_hit_2", "images/monster/son_hit.bmp", 74, 280, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_die_2", "images/monster/son_die.bmp", 457, 130, 5, 2, true, RGB(255, 0, 255));

	//IMAGE->addImage("hunter_emptyHP_2", "images/monster/emptyHP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("hunter_HP_2", "images/monster/HP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("son_emptyHP_2", "images/monster/emptyHP.bmp", 150, 12, true, RGB(255, 0, 255));
	//->addImage("son_HP_2", "images/monster/HP.bmp", 150, 12, true, RGB(255, 0, 255));
	//3.
	IMAGE->addFrameImage("hunter_idle_3", "images/monster/hunter_idle.bmp", 141, 248, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_move_3", "images/monster/hunter_move.bmp", 216, 256, 4, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_attack_3", "images/monster/hunter_attack.bmp", 828, 264, 12, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_hit_3", "images/monster/hunter_hit.bmp", 44, 244, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_die_3", "images/monster/hunter_die.bmp", 37, 272, 1, 4, true, RGB(255, 0, 255));

	IMAGE->addFrameImage("son_idle_3", "images/monster/son_idle.bmp", 186, 318, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_move_3", "images/monster/son_move.bmp", 684, 408, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_attack_3", "images/monster/son_magic.bmp", 504, 320, 7, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_hit_3", "images/monster/son_hit.bmp", 74, 280, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_die_3", "images/monster/son_die.bmp", 457, 130, 5, 2, true, RGB(255, 0, 255));

	//IMAGE->addImage("hunter_emptyHP_3", "images/monster/emptyHP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("hunter_HP_3", "images/monster/HP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("son_emptyHP_3", "images/monster/emptyHP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("son_HP_3", "images/monster/HP.bmp", 150, 12, true, RGB(255, 0, 255));
	//4.
	IMAGE->addFrameImage("hunter_idle_4", "images/monster/hunter_idle.bmp", 141, 248, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_move_4", "images/monster/hunter_move.bmp", 216, 256, 4, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_attack_4", "images/monster/hunter_attack.bmp", 828, 264, 12, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_hit_4", "images/monster/hunter_hit.bmp", 44, 244, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_die_4", "images/monster/hunter_die.bmp", 37, 272, 1, 4, true, RGB(255, 0, 255));

	IMAGE->addFrameImage("son_idle_4", "images/monster/son_idle.bmp", 186, 318, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_move_4", "images/monster/son_move.bmp", 684, 408, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_attack_4", "images/monster/son_magic.bmp", 504, 320, 7, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_hit_4", "images/monster/son_hit.bmp", 74, 280, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_die_4", "images/monster/son_die.bmp", 457, 130, 5, 2, true, RGB(255, 0, 255));

	//IMAGE->addImage("hunter_emptyHP_4", "images/monster/emptyHP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("hunter_HP_4", "images/monster/HP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("son_emptyHP_4", "images/monster/emptyHP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("son_HP_4", "images/monster/HP.bmp", 150, 12, true, RGB(255, 0, 255));
	//5.
	IMAGE->addFrameImage("hunter_idle_5", "images/monster/hunter_idle.bmp", 141, 248, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_move_5", "images/monster/hunter_move.bmp", 216, 256, 4, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_attack_5", "images/monster/hunter_attack.bmp", 828, 264, 12, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_hit_5", "images/monster/hunter_hit.bmp", 44, 244, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("hunter_die_5", "images/monster/hunter_die.bmp", 37, 272, 1, 4, true, RGB(255, 0, 255));

	IMAGE->addFrameImage("son_idle_5", "images/monster/son_idle.bmp", 186, 318, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_move_5", "images/monster/son_move.bmp", 684, 408, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_attack_5", "images/monster/son_magic.bmp", 504, 320, 7, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_hit_5", "images/monster/son_hit.bmp", 74, 280, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_die_5", "images/monster/son_die.bmp", 457, 130, 5, 2, true, RGB(255, 0, 255));

	//IMAGE->addImage("hunter_emptyHP_5", "images/monster/emptyHP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("hunter_HP_5", "images/monster/HP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("son_emptyHP_5", "images/monster/emptyHP.bmp", 150, 12, true, RGB(255, 0, 255));
	//IMAGE->addImage("son_HP_5", "images/monster/HP.bmp", 150, 12, true, RGB(255, 0, 255));
	// 
	//=======================
	// 	   애기추가쓰
	isKid = false;
	_kid = IMAGE->addFrameImage("kid", "images/kid.bmp", 210, 60, 3, 1, true, RGB(255, 0, 255));
	IMAGE->addImage("bubble", "images/bubble.bmp", 100, 50, true, RGB(255, 0, 255));
	_click = IMAGE->addFrameImage("click", "images/click.bmp", 171, 42, 2, 1, true, RGB(255, 0, 255));
	//kidRC = RectMake(_kid->getFrameX(), _kid->getFrameY(), _kid->getFrameWidth(), _kid->getFrameHeight());
	kidRC = RectMake(kidX, kidY, _kid->getFrameWidth(), _kid->getFrameHeight());
	kidX = WINSIZEX / 2;
	kidY = WINSIZEY / 2;
	//=======================

	monsterInfo* _hunter;
	_hunter = new monsterInfo[MAX_MONSTER];

	monsterInfo* _son;
	_son = new monsterInfo[MAX_MONSTER];

	for (size_t i = 0; i < MAX_MONSTER; i++)
	{
		//헌터.
		_hunter[i].name = "hunter";
		_hunter[i].x = RND->getFromIntTo(WINSIZEX, WINSIZEX * 2);
		_hunter[i].y = 510;
		_hunter[i].arrIndex = i;

		_hunter[i].isLeft = true;
		_hunter[i].isExist = false;
		_hunter[i].isCollide = false;
		if (i == 0) _hunter[i].img = IMAGE->findImage("hunter_idle_1");
		else if (i == 1) _hunter[i].img = IMAGE->findImage("hunter_idle_2");
		else if (i == 2) _hunter[i].img = IMAGE->findImage("hunter_idle_3");
		else if (i == 3) _hunter[i].img = IMAGE->findImage("hunter_idle_4");
		else if (i == 4) _hunter[i].img = IMAGE->findImage("hunter_idle_5");

		_hunter[i].rc = RectMake(_hunter[i].x, _hunter[i].y, _hunter[i].img->getFrameWidth(), _hunter[i].img->getFrameHeight());

		_hunter[i].currentState = MONSTER_STATE::IDLE;

		_hunter[i].hp = 100;
		_hunter[i].bar = new progressBar;
		_hunter[i].bar->init("images/monster/HP.bmp", "images/monster/emptyHP.bmp", _hunter->x, _hunter->y, 50, 12);
		_hunter[i].bar->setGauge(_hunter->hp, 100);

		_hunter[i].count = 0;
		_hunter[i].index = 0;
		_hunter[i].stateCount = 0;

		_vMonster.push_back(&_hunter[i]);

		//손.
		_son[i].name = "son";
		//_son[i].x = RND->getFromIntTo(0, 400);
		_son[i].x = RND->getFromIntTo(WINSIZEX, WINSIZEX * 2);
		_son[i].y = 510;
		_son[i].arrIndex = i;

		_son[i].isLeft = true;
		_son[i].isExist = false;
		_son[i].isCollide = false;
		if (i == 0) _son[i].img = IMAGE->findImage("son_idle_1");
		else if (i == 1) _son[i].img = IMAGE->findImage("son_idle_2");
		else if (i == 2) _son[i].img = IMAGE->findImage("son_idle_3");
		else if (i == 3) _son[i].img = IMAGE->findImage("son_idle_4");
		else if (i == 4) _son[i].img = IMAGE->findImage("son_idle_5");

		_son[i].rc = RectMake(_son[i].x, _son[i].y, _son[i].img->getFrameWidth(), _son[i].img->getFrameHeight());

		_son[i].currentState = MONSTER_STATE::IDLE;

		_son[i].hp = 100;
		_son[i].bar = new progressBar;
		_son[i].bar->init("images/monster/HP.bmp", "images/monster/emptyHP.bmp", _son->x, _son->y, 50, 10);
		_son[i].bar->setGauge(_son->hp, 100);

		_son[i].count = 0;
		_son[i].index = 0;
		_son[i].stateCount = 0;

		_vMonster.push_back(&_son[i]);
	}

	playerX = 0;
	playerY = 0;
	isDebug = false;

	return S_OK;
}

void battleMap_monster::release()
{

}

void battleMap_monster::update()
{
	if (InputManager->isOnceKeyDown('0'))isDebug = !isDebug;

	//_viMonster = _vMonster.begin();
	//for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
	//{
	//	//hp 닳으면 벡터에서 제거.
	//	if ((*_viMonster)->hp <= 0)
	//	{
	//		_vMonster.erase(_viMonster);
	//		SAFE_DELETE(*_viMonster);
	//	}
	//}



	//=======================
	// 	   애기추가쓰
	//kidRC = RectMake(_kid->getX(), _kid->getY(), _kid->getFrameWidth(), _kid->getFrameHeight());
	if (isKid) { kidRC = RectMake(kidX, kidY, _kid->getFrameWidth(), _kid->getFrameHeight()); }

	//애기 애니메이션
	m_count++;
	_kid->setFrameY(1);
	_click->setFrameY(1);

	if (m_count % 8 == 0)
	{
		m_count = 0;
		m_index--;
		if (m_index < _kid->getMaxFrameY())
		{
			m_index = 5;
		}
		_kid->setFrameX(m_index);

	}
	if (m_count % 5 == 0)
	{
		if (m_index < _click->getMaxFrameY())
		{
			m_index = 5;
		}
		_click->setFrameX(m_index);
	}
	//=======================



	_viMonster = _vMonster.begin();
	for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
	{
		//랜덤으로 존재.
		if (!(*_viMonster)->isExist)
		{
			(*_viMonster)->hp = 100;
			(*_viMonster)->x = RND->getFromIntTo(WINSIZEX, WINSIZEX * 2);;
			if (RND->getFromIntTo(0, 20) == 0)(*_viMonster)->isExist = true;
		}

		//이동.
		if ((*_viMonster)->isLeft && (*_viMonster)->currentState == MONSTER_STATE::MOVE)
		{
			(*_viMonster)->x -= 1;
		}
		else if (!((*_viMonster)->isLeft) && (*_viMonster)->currentState == MONSTER_STATE::MOVE)
		{
			(*_viMonster)->x += 1;
		}




		if (!(*_viMonster)->isCollide)(*_viMonster)->startTime = TIME->getWorldTime();
		else (*_viMonster)->endTime = TIME->getWorldTime();

		if ((*_viMonster)->endTime - (*_viMonster)->startTime > 3)
		{
			(*_viMonster)->isCollide = false;
			(*_viMonster)->currentState = MONSTER_STATE::MOVE;
		}

		//왼쪽 오른쪽 변경.
		if ((*_viMonster)->x < 0) (*_viMonster)->isLeft = false;
		if ((*_viMonster)->x /* + (*_viMonster)->img->getWidth()*/ > WINSIZEX) (*_viMonster)->isLeft = true;



		//바 업데이트.
		(*_viMonster)->bar->setX((*_viMonster)->x);
		(*_viMonster)->bar->setY((*_viMonster)->y);
		(*_viMonster)->bar->setGauge((*_viMonster)->hp, 100);
		(*_viMonster)->bar->update();

		//상태 변경.
		(*_viMonster)->stateCount++;
		if ((*_viMonster)->stateCount % 100 == 0)
		{
			(*_viMonster)->stateCount = 0;
			if ((*_viMonster)->isCollide)(*_viMonster)->currentState = MONSTER_STATE::ATTACK;
			else
			{
				(*_viMonster)->currentState = MONSTER_STATE::MOVE;
				//if (RND->getFromIntTo(0, 1) == 0) (*_viMonster)->currentState = MONSTER_STATE::IDLE;
				//else (*_viMonster)->currentState = MONSTER_STATE::MOVE;
			}
		}
		//if ((*_viMonster)->stateCount % 10 == 0)
		//{
		//	//hp 관리.
		//	if ((*_viMonster)->currentState == MONSTER_STATE::DAMAGE) (*_viMonster)->hp -= 30;
		//
		//}
	}

	//프레임.
	_viMonster = _vMonster.begin();
	for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
	{
		//헌터.
		if ((*_viMonster)->name == "hunter")
		{
			if ((*_viMonster)->currentState == MONSTER_STATE::IDLE)
			{
				if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_idle_1");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_idle_2");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_idle_3");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_idle_4");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_idle_5");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 3)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 3)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
			}
			else if ((*_viMonster)->currentState == MONSTER_STATE::MOVE)
			{
				if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_move_1");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_move_2");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_move_3");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_move_4");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_move_5");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 4)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 4)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
			}
			else if ((*_viMonster)->currentState == MONSTER_STATE::ATTACK)
			{
				if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_attack_1");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_attack_2");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_attack_3");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_attack_4");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_attack_5");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 12)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 12)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
			}
			else if ((*_viMonster)->currentState == MONSTER_STATE::DAMAGE)
			{
				if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_hit_1");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_hit_2");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_hit_3");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_hit_4");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_hit_5");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->img->setFrameX(0);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->img->setFrameX(0);
					}
				}
			}
			else if ((*_viMonster)->currentState == MONSTER_STATE::DIE)
			{
				if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_die_1");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_die_2");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_die_3");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_die_4");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("hunter_die_5");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->img->setFrameX(0);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->img->setFrameX(0);
					}
				}
			}
		}
		//손.
		else if ((*_viMonster)->name == "son")
		{
			if ((*_viMonster)->currentState == MONSTER_STATE::IDLE)
			{
				if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_idle_1");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_idle_2");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_idle_3");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_idle_4");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_idle_5");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 3)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 3)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
			}
			else if ((*_viMonster)->currentState == MONSTER_STATE::MOVE)
			{
				if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_move_1");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_move_2");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_move_3");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_move_4");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_move_5");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 6)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 6)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
			}
			else if ((*_viMonster)->currentState == MONSTER_STATE::ATTACK)
			{
				if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_attack_1");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_attack_2");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_attack_3");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_attack_4");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_attack_5");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 7)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 7)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
			}
			else if ((*_viMonster)->currentState == MONSTER_STATE::DAMAGE)
			{
				if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_hit_1");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_hit_2");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_hit_3");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_hit_4");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_hit_5");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->img->setFrameX(0);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->img->setFrameX(0);
					}
				}
			}
			else if ((*_viMonster)->currentState == MONSTER_STATE::DIE)
			{
				if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_die_1");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_die_2");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_die_3");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_die_4");
				else if ((*_viMonster)->arrIndex == 0)(*_viMonster)->img = IMAGE->findImage("son_die_5");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 5)
						{
							(*_viMonster)->index = 4;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index--;
						if ((*_viMonster)->index < 0)
						{
							(*_viMonster)->index = 0;
							//지우기
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
			}
		}//son일때 프레임.
	}//프레임.


	//RECT 조정.
	_viMonster = _vMonster.begin();
	for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
	{
		switch ((*_viMonster)->currentState)
		{
		case MONSTER_STATE::IDLE:
			if ((*_viMonster)->name == "hunter") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y + 7, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			else if ((*_viMonster)->name == "son") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y - 12, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			break;
		case MONSTER_STATE::MOVE:
			if ((*_viMonster)->name == "hunter") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			else if ((*_viMonster)->name == "son") (*_viMonster)->rc = RectMake((*_viMonster)->x + 30, (*_viMonster)->y - 40, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			break;
		case MONSTER_STATE::ATTACK:
			if ((*_viMonster)->name == "hunter") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y - 3, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			else if ((*_viMonster)->name == "son") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y - 13, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			break;
		case MONSTER_STATE::DAMAGE:
			if ((*_viMonster)->name == "hunter") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			else if ((*_viMonster)->name == "son") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			break;
		case MONSTER_STATE::DIE:
			if ((*_viMonster)->name == "hunter") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y + 11, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			else if ((*_viMonster)->name == "son") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y + 26, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			break;
		}
	}
}

void battleMap_monster::render()
{
	//=======================
	//   애기추가쓰
	if (isKid)
	{
		_kid->frameRender(getMemDC(), kidX, kidY);				//나중에 좌표수정
		IMAGE->findImage("bubble")->render(getMemDC(), kidX + 5, kidY - 60);
		IMAGE->findImage("click")->frameRender(getMemDC(), kidX + 10, kidY + 48);
	}
	if (isDebug) { Rectangle(getMemDC(), kidRC.left, kidRC.top, kidRC.right, kidRC.bottom); }
	//=======================

	if (isDebug)
	{
		_viMonster = _vMonster.begin();
		for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
		{
			Rectangle(getMemDC(), (*_viMonster)->rc.left, (*_viMonster)->rc.top, (*_viMonster)->rc.right, (*_viMonster)->rc.bottom);
		}


	}

	_viMonster = _vMonster.begin();
	for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
	{
		TCHAR str[20];
		//wsprintf(str, "Collide : %d", (*_viMonster)->isCollide);
		//TextOut(getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 30, str, lstrlen(str));

		if ((*_viMonster)->isExist)
		{
			switch ((*_viMonster)->currentState)
			{
			case MONSTER_STATE::IDLE:
				if ((*_viMonster)->name == "hunter")
				{
					if ((*_viMonster)->arrIndex == 0) IMAGE->frameRender("hunter_idle_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 7, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 1) IMAGE->frameRender("hunter_idle_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 7, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 2) IMAGE->frameRender("hunter_idle_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 7, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 3) IMAGE->frameRender("hunter_idle_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 7, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 4) IMAGE->frameRender("hunter_idle_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 7, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());

					//바 렌더.
					(*_viMonster)->bar->render((*_viMonster)->x, (*_viMonster)->y - 8);
				}
				else if ((*_viMonster)->name == "son")
				{
					if ((*_viMonster)->arrIndex == 0) IMAGE->frameRender("son_idle_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 12, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 1) IMAGE->frameRender("son_idle_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 12, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 2) IMAGE->frameRender("son_idle_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 12, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 3) IMAGE->frameRender("son_idle_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 12, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 4) IMAGE->frameRender("son_idle_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 12, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());

					//바 렌더.
					(*_viMonster)->bar->render((*_viMonster)->x + 5, (*_viMonster)->y - 8);
				}
				break;
			case MONSTER_STATE::MOVE:
				if ((*_viMonster)->name == "hunter")
				{
					if ((*_viMonster)->arrIndex == 0) IMAGE->frameRender("hunter_move_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 1) IMAGE->frameRender("hunter_move_2", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 2) IMAGE->frameRender("hunter_move_3", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 3) IMAGE->frameRender("hunter_move_4", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 4) IMAGE->frameRender("hunter_move_5", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());

					//바 렌더.
					(*_viMonster)->bar->render((*_viMonster)->x + 7, (*_viMonster)->y - 15);
				}
				else if ((*_viMonster)->name == "son")
				{
					if ((*_viMonster)->arrIndex == 0) IMAGE->frameRender("son_move_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 40, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 1) IMAGE->frameRender("son_move_2", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 40, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 2) IMAGE->frameRender("son_move_3", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 40, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 3) IMAGE->frameRender("son_move_4", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 40, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 4) IMAGE->frameRender("son_move_5", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 40, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());

					//바 렌더.
					(*_viMonster)->bar->render((*_viMonster)->x + 20, (*_viMonster)->y - 15);
				}
				break;
			case MONSTER_STATE::ATTACK:
				if ((*_viMonster)->name == "hunter")
				{
					if ((*_viMonster)->arrIndex == 0) IMAGE->frameRender("hunter_attack_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 3, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 1) IMAGE->frameRender("hunter_attack_2", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 3, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 2) IMAGE->frameRender("hunter_attack_3", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 3, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 3) IMAGE->frameRender("hunter_attack_4", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 3, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 4) IMAGE->frameRender("hunter_attack_5", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 3, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());

					//바 렌더.
					(*_viMonster)->bar->render((*_viMonster)->x + 17, (*_viMonster)->y - 15);
				}
				else if ((*_viMonster)->name == "son")
				{
					if ((*_viMonster)->arrIndex == 0) IMAGE->frameRender("son_attack_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 13, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 1) IMAGE->frameRender("son_attack_2", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 13, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 2) IMAGE->frameRender("son_attack_3", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 13, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 3) IMAGE->frameRender("son_attack_4", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 13, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 4) IMAGE->frameRender("son_attack_5", getMemDC(), (*_viMonster)->x, (*_viMonster)->y - 13, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());

					//바 렌더.
					(*_viMonster)->bar->render((*_viMonster)->x + 10, (*_viMonster)->y - 10);
				}
				break;
			case MONSTER_STATE::DAMAGE:
				if ((*_viMonster)->name == "hunter")
				{
					if ((*_viMonster)->arrIndex == 0) IMAGE->frameRender("hunter_hit_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 1) IMAGE->frameRender("hunter_hit_2", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 2) IMAGE->frameRender("hunter_hit_3", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 3) IMAGE->frameRender("hunter_hit_4", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 4) IMAGE->frameRender("hunter_hit_5", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());

					//바 렌더.
					(*_viMonster)->bar->render((*_viMonster)->x + 2, (*_viMonster)->y - 13);
				}
				else if ((*_viMonster)->name == "son")
				{
					if ((*_viMonster)->arrIndex == 0) IMAGE->frameRender("son_hit_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 1) IMAGE->frameRender("son_hit_2", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 2) IMAGE->frameRender("son_hit_3", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 3) IMAGE->frameRender("son_hit_4", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 4) IMAGE->frameRender("son_hit_5", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());

					//바 렌더.
					(*_viMonster)->bar->render((*_viMonster)->x + 18, (*_viMonster)->y - 13);
				}
				break;
			case MONSTER_STATE::DIE:
				if ((*_viMonster)->name == "hunter")
				{
					if ((*_viMonster)->arrIndex == 0) IMAGE->frameRender("hunter_die_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 11, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 1) IMAGE->frameRender("hunter_die_2", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 11, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 2) IMAGE->frameRender("hunter_die_3", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 11, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 3) IMAGE->frameRender("hunter_die_4", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 11, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 4) IMAGE->frameRender("hunter_die_5", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 11, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());

					//바 렌더.
					(*_viMonster)->bar->render((*_viMonster)->x - 8, (*_viMonster)->y - 5);
				}
				else if ((*_viMonster)->name == "son")
				{
					if ((*_viMonster)->arrIndex == 0) IMAGE->frameRender("son_die_1", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 26, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 1) IMAGE->frameRender("son_die_2", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 26, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 2) IMAGE->frameRender("son_die_3", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 26, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 3) IMAGE->frameRender("son_die_4", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 26, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					else if ((*_viMonster)->arrIndex == 4) IMAGE->frameRender("son_die_5", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 26, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());

					//바 렌더.
					(*_viMonster)->bar->render((*_viMonster)->x + 18, (*_viMonster)->y - 5);
				}
				break;
			}
			//if (isDebug)
			//{
			//	Rectangle(getMemDC(), (*_viMonster)->rc.left, (*_viMonster)->rc.top, (*_viMonster)->rc.right, (*_viMonster)->rc.bottom);
			//}
		}//if(isExist = true) end.
	}//for end.
	//Rectangle(getMemDC(), 0, 0, 100, 100);
}
