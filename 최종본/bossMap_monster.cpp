#include "framework.h"
#include "bossMap_monster.h"

bossMap_monster::bossMap_monster()
{
}

bossMap_monster::~bossMap_monster()
{
}

HRESULT bossMap_monster::init()
{
	IMAGE->addFrameImage("boss_idle", "images/boss/boss_idle0.bmp", 1134, 572, 4, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("boss_move", "images/boss/boss_move0.bmp", 690, 800, 2, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("boss_attack", "images/boss/boss_attack0.bmp", 1531, 696, 6, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("boss_hit", "images/boss/boss_hit0.bmp", 433, 610, 2, 2, true, RGB(255, 0, 255));
	//1.
	IMAGE->addFrameImage("son_idle_1", "images/monster/son_idle.bmp", 186, 318, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_move_1", "images/monster/son_move.bmp", 684, 408, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_attack_1", "images/monster/son_magic.bmp", 504, 320, 7, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_hit_1", "images/monster/son_hit.bmp", 74, 280, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_die_1", "images/monster/son_die.bmp", 457, 130, 5, 2, true, RGB(255, 0, 255));
	//2.
	IMAGE->addFrameImage("son_idle_2", "images/monster/son_idle.bmp", 186, 318, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_move_2", "images/monster/son_move.bmp", 684, 408, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_attack_2", "images/monster/son_magic.bmp", 504, 320, 7, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_hit_2", "images/monster/son_hit.bmp", 74, 280, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_die_2", "images/monster/son_die.bmp", 457, 130, 5, 2, true, RGB(255, 0, 255));
	//3.
	IMAGE->addFrameImage("son_idle_3", "images/monster/son_idle.bmp", 186, 318, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_move_3", "images/monster/son_move.bmp", 684, 408, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_attack_3", "images/monster/son_magic.bmp", 504, 320, 7, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_hit_3", "images/monster/son_hit.bmp", 74, 280, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_die_3", "images/monster/son_die.bmp", 457, 130, 5, 2, true, RGB(255, 0, 255));
	//4.
	IMAGE->addFrameImage("son_idle_4", "images/monster/son_idle.bmp", 186, 318, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_move_4", "images/monster/son_move.bmp", 684, 408, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_attack_4", "images/monster/son_magic.bmp", 504, 320, 7, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_hit_4", "images/monster/son_hit.bmp", 74, 280, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_die_4", "images/monster/son_die.bmp", 457, 130, 5, 2, true, RGB(255, 0, 255));
	//5.
	IMAGE->addFrameImage("son_idle_5", "images/monster/son_idle.bmp", 186, 318, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_move_5", "images/monster/son_move.bmp", 684, 408, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_attack_5", "images/monster/son_magic.bmp", 504, 320, 7, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_hit_5", "images/monster/son_hit.bmp", 74, 280, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("son_die_5", "images/monster/son_die.bmp", 457, 130, 5, 2, true, RGB(255, 0, 255));

	IMAGE->addFrameImage("boss_skill3_1_1", "images/boss/boss_skill3_1_1.bmp", 1142, 200, 6, 1, true, RGB(0, 0, 255));
	IMAGE->addFrameImage("boss_skill3_1_2", "images/boss/boss_skill3_1_1.bmp", 1142, 200, 6, 1, true, RGB(0, 0, 255));
	IMAGE->addFrameImage("boss_skill3_1_3", "images/boss/boss_skill3_1_1.bmp", 1142, 200, 6, 1, true, RGB(0, 0, 255));
	IMAGE->addFrameImage("boss_skill3_1_4", "images/boss/boss_skill3_1_1.bmp", 1142, 200, 6, 1, true, RGB(0, 0, 255));
	IMAGE->addFrameImage("boss_skill3_1_5", "images/boss/boss_skill3_1_1.bmp", 1142, 200, 6, 1, true, RGB(0, 0, 255));

	IMAGE->addFrameImage("boss_skill1_2", "images/boss/boss_skill1_2.bmp", 286, 400, 4, 1, true, RGB(255, 0, 0));

	IMAGE->addFrameImage("boss_skill2_1", "images/boss/boss_skill2.bmp", 640, 236, 10, 1, true, RGB(255, 255, 255));
	IMAGE->addFrameImage("boss_skill2_2", "images/boss/boss_skill2.bmp", 640, 236, 10, 1, true, RGB(255, 255, 255));
	IMAGE->addFrameImage("boss_skill2_3", "images/boss/boss_skill2.bmp", 640, 236, 10, 1, true, RGB(255, 255, 255));
	IMAGE->addFrameImage("boss_skill2_4", "images/boss/boss_skill2.bmp", 640, 236, 10, 1, true, RGB(255, 255, 255));
	IMAGE->addFrameImage("boss_skill2_5", "images/boss/boss_skill2.bmp", 640, 236, 10, 1, true, RGB(255, 255, 255));

	IMAGE->addFrameImage("devil_idle_1", "images/boss/devil1_idle0.bmp", 243, 196, 3, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_move_1", "images/boss/devil1_move.bmp", 500, 208, 6, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_attack_1", "images/boss/devil1_attack0.bmp", 639, 272, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_hit_1", "images/boss/devil1_hit0.bmp", 362, 192, 4, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_die_1", "images/boss/devil1_die0.bmp", 404, 196, 5, 2, true, RGB(255, 0, 255));

	IMAGE->addFrameImage("devil_idle_2", "images/boss/devil1_idle0.bmp", 243, 196, 3, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_move_2", "images/boss/devil1_move.bmp", 500, 208, 6, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_attack_2", "images/boss/devil1_attack0.bmp", 639, 272, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_hit_2", "images/boss/devil1_hit0.bmp", 362, 192, 4, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_die_2", "images/boss/devil1_die0.bmp", 404, 196, 5, 2, true, RGB(255, 0, 255));

	IMAGE->addFrameImage("devil_idle_3", "images/boss/devil1_idle0.bmp", 243, 196, 3, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_move_3", "images/boss/devil1_move.bmp", 500, 208, 6, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_attack_3", "images/boss/devil1_attack0.bmp", 639, 272, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_hit_3", "images/boss/devil1_hit0.bmp", 362, 192, 4, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_die_3", "images/boss/devil1_die0.bmp", 404, 196, 5, 2, true, RGB(255, 0, 255));

	IMAGE->addFrameImage("devil_idle_4", "images/boss/devil1_idle0.bmp", 243, 196, 3, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_move_4", "images/boss/devil1_move.bmp", 500, 208, 6, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_attack_4", "images/boss/devil1_attack0.bmp", 639, 272, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_hit_4", "images/boss/devil1_hit0.bmp", 362, 192, 4, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_die_4", "images/boss/devil1_die0.bmp", 404, 196, 5, 2, true, RGB(255, 0, 255));

	IMAGE->addFrameImage("devil_idle_5", "images/boss/devil1_idle0.bmp", 243, 196, 3, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_move_5", "images/boss/devil1_move.bmp", 500, 208, 6, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_attack_5", "images/boss/devil1_attack0.bmp", 639, 272, 6, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_hit_5", "images/boss/devil1_hit0.bmp", 362, 192, 4, 2, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("devil_die_5", "images/boss/devil1_die0.bmp", 404, 196, 5, 2, true, RGB(255, 0, 255));


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

	monsterInfo* _boss;
	_boss = new monsterInfo;

	monsterInfo* _son;
	_son = new monsterInfo[MAX_MONSTER];

	//보스.
	_boss->name = "boss";
	_boss->x = RND->getFromIntTo(WINSIZEX, WINSIZEX * 2);
	_boss->y = 223;
	//_boss->arrIndex = i;

	_boss->isLeft = true;
	_boss->isExist = true;
	_boss->isCollide = false;
	_boss->img = IMAGE->findImage("boss_idle");

	_boss->rc = RectMake(_boss->x, _boss->y, _boss->img->getFrameWidth(), _boss->img->getFrameHeight());

	_boss->currentState = MONSTER_STATE::IDLE;

	_boss->hp = 1000;
	_boss->bar = new progressBar;
	_boss->bar->init("images/monster/HP.bmp", "images/monster/emptyHP.bmp", _boss->x, _boss->y, 400, 30);
	_boss->bar->setGauge(_boss->hp, 1000);

	_boss->count = 0;
	_boss->index = 0;
	_boss->stateCount = 0;

	_vMonster.push_back(_boss);

	for (size_t i = 0; i < MAX_MONSTER; i++)
	{
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

	//데빌.
	monsterInfo* _devil;
	_devil = new monsterInfo[MAX_MONSTER];
	for (size_t i = 0; i < MAX_MONSTER; i++)
	{
		_devil[i].name = "devil";
		_devil[i].x = RND->getFromIntTo(WINSIZEX, WINSIZEX * 2);
		_devil[i].y = 485;
		_devil[i].arrIndex = i;

		_devil[i].isLeft = true;
		_devil[i].isExist = false;
		_devil[i].isCollide = false;
		if (i == 0) _devil[i].img = IMAGE->findImage("devil_move_1");
		else if (i == 1) _devil[i].img = IMAGE->findImage("devil_move_2");
		else if (i == 2) _devil[i].img = IMAGE->findImage("devil_move_3");
		else if (i == 3) _devil[i].img = IMAGE->findImage("devil_move_4");
		else if (i == 4) _devil[i].img = IMAGE->findImage("devil_move_5");

		//_devil[i].rc = RectMake(_devil[i].x, _devil[i].y, _devil[i].img->getFrameWidth(), _devil[i].img->getFrameHeight());

		_devil[i].currentState = MONSTER_STATE::MOVE;

		_devil[i].hp = 100;
		_devil[i].bar = new progressBar;
		_devil[i].bar->init("images/monster/HP.bmp", "images/monster/emptyHP.bmp", _devil->x, _devil->y, 50, 10);
		_devil[i].bar->setGauge(_devil->hp, 100);

		_devil[i].count = 0;
		_devil[i].index = 0;
		_devil[i].stateCount = 0;

		_vDevil.push_back(&_devil[i]);
	}

	//보스 스킬.
	bossSkill* _meteor;
	_meteor = new bossSkill[5];

	for (size_t i = 0; i < 5; i++)
	{
		_meteor[i].x = static_cast<int>(RND->getFromIntTo(0, WINSIZEX * 2));
		_meteor[i].y = static_cast<int>(RND->getFromIntTo(-300, -100));

		if (i == 0) _meteor[i].img = IMAGE->findImage("boss_skill3_1_1");
		else if (i == 1) _meteor[i].img = IMAGE->findImage("boss_skill3_1_2");
		else if (i == 2) _meteor[i].img = IMAGE->findImage("boss_skill3_1_3");
		else if (i == 3) _meteor[i].img = IMAGE->findImage("boss_skill3_1_4");
		else if (i == 4) _meteor[i].img = IMAGE->findImage("boss_skill3_1_5");
		_meteor[i].rc = RectMake(_meteor[i].x, _meteor[i].y, _meteor[i].img->getFrameWidth(), _meteor[i].img->getFrameHeight());
		_meteor[i].isExist = false;

		//_meteor[i].img->setFrameX(0);
		//_meteor[i].img->setFrameY(0);

		_meteor[i].count = 0;
		_meteor[i].index = 0;

		_vMeteor.push_back(&_meteor[i]);
	}
	//번개.
	lightning = new bossSkill;
	lightning->x = -100;
	lightning->y = -100;
	lightning->img = IMAGE->findImage("boss_skill1_2");

	lightning->rc = RectMake(lightning->x, lightning->y, lightning->img->getFrameWidth(), lightning->img->getFrameHeight());
	lightning->isExist = false;

	lightning->count = 0;
	lightning->index = 0;
	//불꽃 기둥.
	bossSkill* _flame;
	_flame = new bossSkill[5];

	for (size_t i = 0; i < 5; i++)
	{
		_flame[i].x = static_cast<int>(RND->getFromIntTo(0, WINSIZEX * 2));
		_flame[i].y = static_cast<int>(RND->getFromIntTo(-300, -100));

		if (i == 0) _flame[i].img = IMAGE->findImage("boss_skill2_1");
		else if (i == 1) _flame[i].img = IMAGE->findImage("boss_skill2_2");
		else if (i == 2) _flame[i].img = IMAGE->findImage("boss_skill2_3");
		else if (i == 3) _flame[i].img = IMAGE->findImage("boss_skill2_4");
		else if (i == 4) _flame[i].img = IMAGE->findImage("boss_skill2_5");
		_flame[i].rc = RectMake(_flame[i].x, _flame[i].y, _flame[i].img->getFrameWidth(), _flame[i].img->getFrameHeight());
		_flame[i].isExist = false;

		//_meteor[i].img->setFrameX(0);
		//_meteor[i].img->setFrameY(0);

		_flame[i].count = 0;
		_flame[i].index = 0;

		_vFlame.push_back(&_flame[i]);
	}

	playerX = 0;
	playerY = 0;
	isDebug = false;

	startTime = 0;
	endTime = 0;

	startTime_devil = 0;
	endTime_devil = 0;

	stayDamaged = 0;
	return S_OK;
}

void bossMap_monster::release()
{

}

void bossMap_monster::update()
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

	//운석.
	_viMeteor = _vMeteor.begin();
	for (_viMeteor; _viMeteor != _vMeteor.end(); ++_viMeteor)
	{
		if ((*_viMeteor)->isExist)
		{
			(*_viMeteor)->x -= 5;
			(*_viMeteor)->y += 5;
			(*_viMeteor)->rc = RectMake((*_viMeteor)->x, (*_viMeteor)->y, (*_viMeteor)->img->getFrameWidth(), (*_viMeteor)->img->getFrameHeight());

			if ((*_viMeteor)->x <-50 || (*_viMeteor)->y>WINSIZEY)(*_viMeteor)->isExist = false;
		}
		else
		{
			(*_viMeteor)->x = static_cast<int>(RND->getFromIntTo(0, 1020));
			(*_viMeteor)->y = static_cast<int>(RND->getFromIntTo(-300, -100));
			(*_viMeteor)->rc = RectMake((*_viMeteor)->x, (*_viMeteor)->y, (*_viMeteor)->img->getFrameWidth(), (*_viMeteor)->img->getFrameHeight());
		}
	}
	//번개.
	if (lightning->isExist)
	{
		lightning->rc = RectMake(lightning->x, lightning->y, lightning->img->getFrameWidth(), lightning->img->getHeight());
	}
	else
	{
		lightning->x = playerX;
		lightning->y = playerY - 315;
	}
	_viFlame = _vFlame.begin();
	for (_viFlame; _viFlame != _vFlame.end(); ++_viFlame)
	{
		if ((*_viFlame)->isExist)
		{
			(*_viFlame)->rc = RectMake((*_viFlame)->x, (*_viFlame)->y, (*_viFlame)->img->getFrameWidth(), (*_viFlame)->img->getFrameHeight());
		}
		else
		{
			(*_viFlame)->x = static_cast<int>(RND->getFromIntTo(0, 1020));
			(*_viFlame)->y = 350;
		}
	}


	_viMonster = _vMonster.begin();
	for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
	{
		//랜덤으로 존재.
		if (!(*_viMonster)->isExist && (*_viMonster)->name != "boss")
		{
			//if((*_viMonster)->name == "boss")(*_viMonster)->hp = 1000;
			//else 
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
		//바 업데이트.
		(*_viMonster)->bar->setX((*_viMonster)->x);
		(*_viMonster)->bar->setY((*_viMonster)->y);


		if ((*_viMonster)->name == "boss") (*_viMonster)->bar->setGauge((*_viMonster)->hp, 1000);
		else (*_viMonster)->bar->setGauge((*_viMonster)->hp, 100);
		(*_viMonster)->bar->update();

		//상태 변경.
		(*_viMonster)->stateCount++;
		endTime = TIME->getWorldTime();
		if ((*_viMonster)->stateCount % 100 == 0)
		{
			(*_viMonster)->stateCount = 0;

			//데미지 상태 유지.
			if ((*_viMonster)->name == "boss" && (*_viMonster)->currentState == MONSTER_STATE::DAMAGE && startTime == 0)
			{
				startTime = TIME->getWorldTime();
			}
			else if (endTime - startTime < 0.7 && startTime != 0 && (*_viMonster)->name == "boss")
			{
				(*_viMonster)->currentState == MONSTER_STATE::DAMAGE;
			}
			else
			{
				if ((*_viMonster)->isCollide)
				{
					(*_viMonster)->currentState = MONSTER_STATE::ATTACK;
				}
				else
				{
					if (RND->getInt(2) == 0 && (*_viMonster)->x < WINSIZEX && (*_viMonster)->name == "boss")
						(*_viMonster)->currentState = MONSTER_STATE::ATTACK;
					else (*_viMonster)->currentState = MONSTER_STATE::MOVE;
					//if (RND->getFromIntTo(0, 1) == 0) (*_viMonster)->currentState = MONSTER_STATE::IDLE;
					//else (*_viMonster)->currentState = MONSTER_STATE::MOVE;
				}
			}

		}//상태변경.



		if ((*_viMonster)->name == "boss" && (*_viMonster)->currentState == MONSTER_STATE::ATTACK)
		{
			_viMeteor = _vMeteor.begin();
			for (_viMeteor; _viMeteor != _vMeteor.end(); ++_viMeteor)
			{
				if (!((*_viMeteor)->isExist)) (*_viMeteor)->isExist = true;
			}

			lightning->isExist = true;
		}
		else if ((*_viMonster)->name == "boss" && (*_viMonster)->currentState != MONSTER_STATE::ATTACK)
		{
			lightning->isExist = false;
		}
		//if ((*_viMonster)->stateCount % 10 == 0)
		//{
		//	//hp 관리.
		//	if ((*_viMonster)->currentState == MONSTER_STATE::DAMAGE) (*_viMonster)->hp -= 30;
		//
		//}
		//불꽃 기둥.
		if ((*_viMonster)->name == "boss" && (*_viMonster)->hp < 500)
		{
			_viFlame = _vFlame.begin();
			for (_viFlame; _viFlame != _vFlame.end(); ++_viFlame)
			{
				if (!((*_viFlame)->isExist))
				{
					int random = RND->getFromIntTo(0, 600);
					if (random == 50) (*_viFlame)->isExist = true;
				}
			}
		}
	}//Monster for문.

	_viDevil = _vDevil.begin();
	for (_viDevil; _viDevil != _vDevil.end(); ++_viDevil)
	{
		//랜덤으로 존재.
		if (!(*_viDevil)->isExist)
		{
			(*_viDevil)->hp = 100;
			(*_viDevil)->x = RND->getFromIntTo(WINSIZEX, WINSIZEX * 2);;
			if (RND->getFromIntTo(0, 20) == 0)(*_viDevil)->isExist = true;
		}

		if ((*_viDevil)->isExist)
		{
			(*_viDevil)->currentState == MONSTER_STATE::MOVE;
			//이동.
			if ((*_viDevil)->isLeft && (*_viDevil)->currentState == MONSTER_STATE::MOVE)
			{
				(*_viDevil)->x -= 1;
			}
			else if (!((*_viDevil)->isLeft) && (*_viDevil)->currentState == MONSTER_STATE::MOVE)
			{
				(*_viDevil)->x += 1;
			}

			(*_viDevil)->rc = RectMake((*_viDevil)->x, (*_viDevil)->y, (*_viDevil)->img->getFrameWidth(), (*_viDevil)->img->getFrameHeight());

			//왼쪽 오른쪽 변경.
			if ((*_viDevil)->x < 0) (*_viDevil)->isLeft = false;
			if ((*_viDevil)->x /* + (*_viMonster)->img->getWidth()*/ > WINSIZEX) (*_viDevil)->isLeft = true;

			//바 업데이트.
			(*_viDevil)->bar->setGauge((*_viDevil)->hp, 100);
			(*_viDevil)->bar->setX((*_viDevil)->x);
			(*_viDevil)->bar->setY((*_viDevil)->y);

			//endTime_devil = TIME->getWorldTime();

			//if (endTime_devil - startTime_devil < 4 && startTime_devil != 0)
			//{
			//	(*_viDevil)->currentState = MONSTER_STATE::MOVE;
			//	startTime_devil = 0;
			//}

			//상태변경.
			(*_viDevil)->stateCount++;
			if ((*_viDevil)->stateCount % 100 == 0)
			{
				(*_viDevil)->stateCount = 0;

				//if ((*_viDevil)->isCollide && startTime_devil ==0)
				//{
				//	(*_viDevil)->currentState = MONSTER_STATE::ATTACK;
				//	startTime_devil = TIME->getWorldTime();
				//}
				//else
				//{
				(*_viDevil)->currentState = MONSTER_STATE::MOVE;
				//if (RND->getFromIntTo(0, 1) == 0) (*_viMonster)->currentState = MONSTER_STATE::IDLE;
				//else (*_viMonster)->currentState = MONSTER_STATE::MOVE;
			//}
			}
		}
	}


	//프레임.
	//운석.
	_viMeteor = _vMeteor.begin();
	for (_viMeteor; _viMeteor != _vMeteor.end(); ++_viMeteor)
	{
		(*_viMeteor)->count++;
		(*_viMeteor)->img->setFrameY(0);

		if ((*_viMeteor)->count % 5 == 0)
		{
			(*_viMeteor)->count = 0;
			(*_viMeteor)->index++;
			if ((*_viMeteor)->index >= 6)
			{
				(*_viMeteor)->index = 0;
			}
			(*_viMeteor)->img->setFrameX((*_viMeteor)->index);
		}
	}

	//번개.
	lightning->count++;
	lightning->img->setFrameY(0);

	if (lightning->count % 5 == 0)
	{
		lightning->count = 0;
		lightning->index++;
		if (lightning->index >= 4)
		{
			lightning->index = 0;
		}
		lightning->img->setFrameX(lightning->index);
	}
	//불꽃기둥.
	_viFlame = _vFlame.begin();
	for (_viFlame; _viFlame != _vFlame.end(); ++_viFlame)
	{
		(*_viFlame)->count++;
		(*_viFlame)->img->setFrameY(0);

		if ((*_viFlame)->count % 5 == 0)
		{
			(*_viFlame)->count = 0;
			(*_viFlame)->index++;
			if ((*_viFlame)->index >= 10)
			{
				(*_viFlame)->index = 0;
				(*_viFlame)->isExist = false;
			}
			(*_viFlame)->img->setFrameX((*_viFlame)->index);
		}
	}


	_viMonster = _vMonster.begin();
	for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
	{
		//보스.
		if ((*_viMonster)->name == "boss")
		{
			if ((*_viMonster)->currentState == MONSTER_STATE::IDLE)
			{
				(*_viMonster)->img = IMAGE->findImage("boss_idle");

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
			else if ((*_viMonster)->currentState == MONSTER_STATE::MOVE)
			{
				(*_viMonster)->img = IMAGE->findImage("boss_move");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 80 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 2)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX(1);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 80 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 2)
						{
							(*_viMonster)->index = 0;
						}
						(*_viMonster)->img->setFrameX(0);
					}
				}
			}
			else if ((*_viMonster)->currentState == MONSTER_STATE::ATTACK)
			{
				(*_viMonster)->img = IMAGE->findImage("boss_attack");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 10 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 6)
						{
							(*_viMonster)->index = 0;
							(*_viMonster)->currentState == MONSTER_STATE::MOVE;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 10 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->index++;
						if ((*_viMonster)->index >= 6)
						{
							(*_viMonster)->index = 0;
							(*_viMonster)->currentState == MONSTER_STATE::MOVE;
						}
						(*_viMonster)->img->setFrameX((*_viMonster)->index);
					}
				}
			}
			else if ((*_viMonster)->currentState == MONSTER_STATE::DAMAGE)
			{
				(*_viMonster)->img = IMAGE->findImage("boss_hit");

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
				(*_viMonster)->img = IMAGE->findImage("boss_hit");

				if ((*_viMonster)->isLeft)
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(0);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->img->setFrameX(1);
					}
				}
				else
				{
					(*_viMonster)->count++;
					(*_viMonster)->img->setFrameY(1);

					if ((*_viMonster)->count % 5 == 0)
					{
						(*_viMonster)->count = 0;
						(*_viMonster)->img->setFrameX(1);
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
				else if ((*_viMonster)->arrIndex == 1)(*_viMonster)->img = IMAGE->findImage("son_idle_2");
				else if ((*_viMonster)->arrIndex == 2)(*_viMonster)->img = IMAGE->findImage("son_idle_3");
				else if ((*_viMonster)->arrIndex == 3)(*_viMonster)->img = IMAGE->findImage("son_idle_4");
				else if ((*_viMonster)->arrIndex == 4)(*_viMonster)->img = IMAGE->findImage("son_idle_5");

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
				else if ((*_viMonster)->arrIndex == 1)(*_viMonster)->img = IMAGE->findImage("son_move_2");
				else if ((*_viMonster)->arrIndex == 2)(*_viMonster)->img = IMAGE->findImage("son_move_3");
				else if ((*_viMonster)->arrIndex == 3)(*_viMonster)->img = IMAGE->findImage("son_move_4");
				else if ((*_viMonster)->arrIndex == 4)(*_viMonster)->img = IMAGE->findImage("son_move_5");

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
				else if ((*_viMonster)->arrIndex == 1)(*_viMonster)->img = IMAGE->findImage("son_attack_2");
				else if ((*_viMonster)->arrIndex == 2)(*_viMonster)->img = IMAGE->findImage("son_attack_3");
				else if ((*_viMonster)->arrIndex == 3)(*_viMonster)->img = IMAGE->findImage("son_attack_4");
				else if ((*_viMonster)->arrIndex == 4)(*_viMonster)->img = IMAGE->findImage("son_attack_5");

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
				else if ((*_viMonster)->arrIndex == 1)(*_viMonster)->img = IMAGE->findImage("son_hit_2");
				else if ((*_viMonster)->arrIndex == 2)(*_viMonster)->img = IMAGE->findImage("son_hit_3");
				else if ((*_viMonster)->arrIndex == 3)(*_viMonster)->img = IMAGE->findImage("son_hit_4");
				else if ((*_viMonster)->arrIndex == 4)(*_viMonster)->img = IMAGE->findImage("son_hit_5");

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
				else if ((*_viMonster)->arrIndex == 1)(*_viMonster)->img = IMAGE->findImage("son_die_2");
				else if ((*_viMonster)->arrIndex == 2)(*_viMonster)->img = IMAGE->findImage("son_die_3");
				else if ((*_viMonster)->arrIndex == 3)(*_viMonster)->img = IMAGE->findImage("son_die_4");
				else if ((*_viMonster)->arrIndex == 4)(*_viMonster)->img = IMAGE->findImage("son_die_5");

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


	//데빌.
	for (_viDevil = _vDevil.begin(); _viDevil != _vDevil.end(); ++_viDevil)
	{

		if ((*_viDevil)->currentState == MONSTER_STATE::IDLE)
		{
			if ((*_viDevil)->arrIndex == 0)(*_viDevil)->img = IMAGE->findImage("devil_idle_1");
			else if ((*_viDevil)->arrIndex == 1)(*_viDevil)->img = IMAGE->findImage("devil_idle_2");
			else if ((*_viDevil)->arrIndex == 2)(*_viDevil)->img = IMAGE->findImage("devil_idle_3");
			else if ((*_viDevil)->arrIndex == 3)(*_viDevil)->img = IMAGE->findImage("devil_idle_4");
			else if ((*_viDevil)->arrIndex == 4)(*_viDevil)->img = IMAGE->findImage("devil_idle_5");

			if ((*_viDevil)->isLeft)
			{
				(*_viDevil)->count++;
				(*_viDevil)->img->setFrameY(0);

				if ((*_viDevil)->count % 5 == 0)
				{
					(*_viDevil)->count = 0;
					(*_viDevil)->index++;
					if ((*_viDevil)->index >= 3)
					{
						(*_viDevil)->index = 0;
					}
					(*_viDevil)->img->setFrameX((*_viDevil)->index);
				}
			}
			else
			{
				(*_viDevil)->count++;
				(*_viDevil)->img->setFrameY(1);

				if ((*_viDevil)->count % 5 == 0)
				{
					(*_viDevil)->count = 0;
					(*_viDevil)->index--;
					if ((*_viDevil)->index < 0)
					{
						(*_viDevil)->index = 2;
					}
					(*_viDevil)->img->setFrameX((*_viDevil)->index);
				}
			}
		}
		else if ((*_viDevil)->currentState == MONSTER_STATE::MOVE)
		{
			if ((*_viDevil)->arrIndex == 0)(*_viDevil)->img = IMAGE->findImage("devil_move_1");
			else if ((*_viDevil)->arrIndex == 1)(*_viDevil)->img = IMAGE->findImage("devil_move_2");
			else if ((*_viDevil)->arrIndex == 2)(*_viDevil)->img = IMAGE->findImage("devil_move_3");
			else if ((*_viDevil)->arrIndex == 3)(*_viDevil)->img = IMAGE->findImage("devil_move_4");
			else if ((*_viDevil)->arrIndex == 4)(*_viDevil)->img = IMAGE->findImage("devil_move_5");

			if ((*_viDevil)->isLeft)
			{
				(*_viDevil)->count++;
				(*_viDevil)->img->setFrameY(0);

				if ((*_viDevil)->count % 20 == 0)
				{
					(*_viDevil)->count = 0;
					(*_viDevil)->index++;
					if ((*_viDevil)->index >= 6)
					{
						(*_viDevil)->index = 0;
					}
					(*_viDevil)->img->setFrameX((*_viDevil)->index);
				}
			}
			else
			{
				(*_viDevil)->count++;
				(*_viDevil)->img->setFrameY(1);

				if ((*_viDevil)->count % 20 == 0)
				{
					(*_viDevil)->count = 0;
					(*_viDevil)->index--;
					if ((*_viDevil)->index < 0)
					{
						(*_viDevil)->index = 5;
					}
					(*_viDevil)->img->setFrameX((*_viDevil)->index);
				}
			}
		}
		else if ((*_viDevil)->currentState == MONSTER_STATE::ATTACK)
		{
			if ((*_viDevil)->arrIndex == 0)(*_viDevil)->img = IMAGE->findImage("devil_attack_1");
			else if ((*_viDevil)->arrIndex == 1)(*_viDevil)->img = IMAGE->findImage("devil_attack_2");
			else if ((*_viDevil)->arrIndex == 2)(*_viDevil)->img = IMAGE->findImage("devil_attack_3");
			else if ((*_viDevil)->arrIndex == 3)(*_viDevil)->img = IMAGE->findImage("devil_attack_4");
			else if ((*_viDevil)->arrIndex == 4)(*_viDevil)->img = IMAGE->findImage("devil_attack_5");

			if ((*_viDevil)->isLeft)
			{
				(*_viDevil)->count++;
				(*_viDevil)->img->setFrameY(0);

				if ((*_viDevil)->count % 5 == 0)
				{
					(*_viDevil)->count = 0;
					(*_viDevil)->index++;
					if ((*_viDevil)->index >= 6)
					{
						(*_viDevil)->index = 0;
					}
					(*_viDevil)->img->setFrameX((*_viDevil)->index);
				}
			}
			else
			{
				(*_viDevil)->count++;
				(*_viDevil)->img->setFrameY(1);

				if ((*_viDevil)->count % 5 == 0)
				{
					(*_viDevil)->count = 0;
					(*_viDevil)->index++;
					if ((*_viDevil)->index < 0)
					{
						(*_viDevil)->index = 5;
					}
					(*_viDevil)->img->setFrameX((*_viDevil)->index);
				}
			}
		}
		else if ((*_viDevil)->currentState == MONSTER_STATE::DAMAGE)
		{
			if ((*_viDevil)->arrIndex == 0)(*_viDevil)->img = IMAGE->findImage("devil_hit_1");
			else if ((*_viDevil)->arrIndex == 1)(*_viDevil)->img = IMAGE->findImage("devil_hit_2");
			else if ((*_viDevil)->arrIndex == 2)(*_viDevil)->img = IMAGE->findImage("devil_hit_3");
			else if ((*_viDevil)->arrIndex == 3)(*_viDevil)->img = IMAGE->findImage("devil_hit_4");
			else if ((*_viDevil)->arrIndex == 4)(*_viDevil)->img = IMAGE->findImage("devil_hit_5");

			if ((*_viDevil)->isLeft)
			{
				(*_viDevil)->count++;
				(*_viDevil)->img->setFrameY(0);

				if ((*_viDevil)->count % 5 == 0)
				{
					(*_viDevil)->count = 0;
					(*_viDevil)->img->setFrameX(0);
				}
			}
			else
			{
				(*_viDevil)->count++;
				(*_viDevil)->img->setFrameY(1);

				if ((*_viDevil)->count % 5 == 0)
				{
					(*_viDevil)->count = 0;
					(*_viDevil)->img->setFrameX(3);
				}
			}
		}
		else if ((*_viDevil)->currentState == MONSTER_STATE::DIE)
		{
			if ((*_viDevil)->arrIndex == 0)(*_viDevil)->img = IMAGE->findImage("devil_die_1");
			else if ((*_viDevil)->arrIndex == 1)(*_viDevil)->img = IMAGE->findImage("devil_die_2");
			else if ((*_viDevil)->arrIndex == 2)(*_viDevil)->img = IMAGE->findImage("devil_die_3");
			else if ((*_viDevil)->arrIndex == 3)(*_viDevil)->img = IMAGE->findImage("devil_die_4");
			else if ((*_viDevil)->arrIndex == 4)(*_viDevil)->img = IMAGE->findImage("devil_die_5");

			if ((*_viDevil)->isLeft)
			{
				(*_viDevil)->count++;
				(*_viDevil)->img->setFrameY(0);

				if ((*_viMonster)->count % 5 == 0)
				{
					(*_viDevil)->count = 0;
					(*_viDevil)->index++;
					if ((*_viDevil)->index >= 5)
					{
						(*_viDevil)->index = 4;
					}
					(*_viDevil)->img->setFrameX(4);
				}
			}
			else
			{
				(*_viDevil)->count++;
				(*_viDevil)->img->setFrameY(1);

				if ((*_viDevil)->count % 5 == 0)
				{
					(*_viDevil)->count = 0;
					(*_viDevil)->index--;
					if ((*_viDevil)->index < 0)
					{
						(*_viDevil)->index = 0;
						//지우기
					}
					(*_viDevil)->img->setFrameX(0);
				}
			}
		}
	}//devil일때 프레임.

	//RECT 조정.
	_viMonster = _vMonster.begin();
	for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
	{
		switch ((*_viMonster)->currentState)
		{
		case MONSTER_STATE::IDLE:
			if ((*_viMonster)->name == "boss") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			else if ((*_viMonster)->name == "son") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y - 12, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			break;
		case MONSTER_STATE::MOVE:
			if ((*_viMonster)->name == "boss") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			else if ((*_viMonster)->name == "son") (*_viMonster)->rc = RectMake((*_viMonster)->x + 30, (*_viMonster)->y - 40, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			break;
		case MONSTER_STATE::ATTACK:
			if ((*_viMonster)->name == "boss") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			else if ((*_viMonster)->name == "son") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y - 13, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			break;
		case MONSTER_STATE::DAMAGE:
			if ((*_viMonster)->name == "boss") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			else if ((*_viMonster)->name == "son") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			break;
		case MONSTER_STATE::DIE:
			if ((*_viMonster)->name == "boss") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			else if ((*_viMonster)->name == "son") (*_viMonster)->rc = RectMake((*_viMonster)->x, (*_viMonster)->y + 26, (*_viMonster)->img->getFrameWidth(), (*_viMonster)->img->getFrameHeight());
			break;
		}
	}
}

void bossMap_monster::render()
{
	//=======================
	//   애기추가쓰
	//if (isKid)
	//{
	//	_kid->frameRender(getMemDC(), kidX, kidY);				//나중에 좌표수정
	//	IMAGE->findImage("bubble")->render(getMemDC(), kidX + 5, kidY - 60);
	//	IMAGE->findImage("click")->frameRender(getMemDC(), kidX + 10, kidY + 48);
	//}
	//if (isDebug) { Rectangle(getMemDC(), kidRC.left, kidRC.top, kidRC.right, kidRC.bottom); }
	//=======================

	if (isDebug)
	{
		_viMonster = _vMonster.begin();
		for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
		{
			Rectangle(getMemDC(), (*_viMonster)->rc.left, (*_viMonster)->rc.top, (*_viMonster)->rc.right, (*_viMonster)->rc.bottom);
		}


		_viMeteor = _vMeteor.begin();
		for (_viMeteor; _viMeteor != _vMeteor.end(); ++_viMeteor)
		{
			if ((*_viMeteor)->isExist) Rectangle(getMemDC(), (*_viMeteor)->rc.left, (*_viMeteor)->rc.top, (*_viMeteor)->rc.right, (*_viMeteor)->rc.bottom);
		}

		Rectangle(getMemDC(), lightning->rc.left, lightning->rc.top, lightning->rc.right, lightning->rc.bottom);

		_viFlame = _vFlame.begin();
		for (_viFlame; _viFlame != _vFlame.end(); ++_viFlame)
		{
			if ((*_viFlame)->isExist) Rectangle(getMemDC(), (*_viFlame)->rc.left, (*_viFlame)->rc.top, (*_viFlame)->rc.right, (*_viFlame)->rc.bottom);
		}

		_viDevil = _vDevil.begin();
		for (_viDevil; _viDevil != _vDevil.end(); ++_viDevil)
		{
			if ((*_viDevil)->isExist) Rectangle(getMemDC(), (*_viDevil)->rc.left, (*_viDevil)->rc.top, (*_viDevil)->rc.right, (*_viDevil)->rc.bottom);
		}

	}
	//운석.
	_viMeteor = _vMeteor.begin();
	for (_viMeteor; _viMeteor != _vMeteor.end(); ++_viMeteor)
	{
		if ((*_viMeteor)->isExist) (*_viMeteor)->img->frameRender(getMemDC(), (*_viMeteor)->x, (*_viMeteor)->y);
	}

	//번개.
	if (lightning->isExist) lightning->img->frameRender(getMemDC(), lightning->x, lightning->y);

	//불꽃 기둥.
	_viFlame = _vFlame.begin();
	for (_viFlame; _viFlame != _vFlame.end(); ++_viFlame)
	{
		if ((*_viFlame)->isExist) (*_viFlame)->img->frameRender(getMemDC(), (*_viFlame)->x, (*_viFlame)->y);
	}

	//보스 바.
	_viMonster = _vMonster.begin();
	for (_viMonster; _viMonster != _vMonster.end(); ++_viMonster)
	{
		if ((*_viMonster)->name == "boss")
		{
			(*_viMonster)->bar->render(350, 100);
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
				if ((*_viMonster)->name == "boss")
				{
					IMAGE->frameRender("boss_idle", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 7, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					//바 렌더.
					//(*_viMonster)->bar->render((*_viMonster)->x, (*_viMonster)->y - 8);
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
				if ((*_viMonster)->name == "boss")
				{
					IMAGE->frameRender("boss_move", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					//바 렌더.
					//(*_viMonster)->bar->render((*_viMonster)->x + 7, (*_viMonster)->y - 15);
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
				if ((*_viMonster)->name == "boss")
				{
					IMAGE->frameRender("boss_attack", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 46, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					//바 렌더.
					//(*_viMonster)->bar->render((*_viMonster)->x + 17, (*_viMonster)->y - 15);
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
				if ((*_viMonster)->name == "boss")
				{
					IMAGE->frameRender("boss_hit", getMemDC(), (*_viMonster)->x, (*_viMonster)->y, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					//바 렌더.
					//(*_viMonster)->bar->render((*_viMonster)->x + 2, (*_viMonster)->y - 13);
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
				if ((*_viMonster)->name == "boss")
				{
					IMAGE->frameRender("boss_hit", getMemDC(), (*_viMonster)->x, (*_viMonster)->y + 11, (*_viMonster)->img->getFrameX(), (*_viMonster)->img->getFrameY());
					//바 렌더.
					//(*_viMonster)->bar->render((*_viMonster)->x - 8, (*_viMonster)->y - 5);
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

	_viDevil = _vDevil.begin();
	for (_viDevil; _viDevil != _vDevil.end(); ++_viDevil)
	{
		//if ((*_viDevil)->arrIndex == 0) IMAGE->frameRender("devil_move_1", getMemDC(), (*_viDevil)->x, (*_viDevil)->y - 40, (*_viDevil)->img->getFrameX(), (*_viDevil)->img->getFrameY());
		//else if ((*_viDevil)->arrIndex == 1) IMAGE->frameRender("devil_move_2", getMemDC(), (*_viDevil)->x, (*_viDevil)->y - 40, (*_viDevil)->img->getFrameX(), (*_viDevil)->img->getFrameY());
		//else if ((*_viDevil)->arrIndex == 2) IMAGE->frameRender("devil_move_3", getMemDC(), (*_viDevil)->x, (*_viDevil)->y - 40, (*_viDevil)->img->getFrameX(), (*_viDevil)->img->getFrameY());
		//else if ((*_viDevil)->arrIndex == 3) IMAGE->frameRender("devil_move_4", getMemDC(), (*_viDevil)->x, (*_viDevil)->y - 40, (*_viDevil)->img->getFrameX(), (*_viDevil)->img->getFrameY());
		//else if ((*_viDevil)->arrIndex == 4) IMAGE->frameRender("devil_move_5", getMemDC(), (*_viDevil)->x, (*_viDevil)->y - 40, (*_viDevil)->img->getFrameX(), (*_viDevil)->img->getFrameY());

		(*_viDevil)->img->frameRender(getMemDC(), (*_viDevil)->x, (*_viDevil)->y, (*_viDevil)->img->getFrameX(), (*_viDevil)->img->getFrameY());
		(*_viDevil)->bar->render((*_viDevil)->x + 20, (*_viDevil)->y - 15);
	}
	//IMAGE->findImage("devil_idle_1")->render(getMemDC(),0,0);
}
