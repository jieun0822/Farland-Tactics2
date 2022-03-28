#include "framework.h"
#include "bossMap_player.h"
#define barFront 152
#define barBack 17

bossMap_player::bossMap_player()
{
}

bossMap_player::~bossMap_player()
{
}

HRESULT bossMap_player::init()
{
	IMAGE->addImage("ī�޶�", "images/ī�޶�.bmp", WINSIZEX / 10, WINSIZEY / 10, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("��_���", "images/��_���.bmp", 174, 270, 3, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("��_�̵�", "images/al_move.bmp", 292, 236, 4, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("��_����", "images/al_attack.bmp", 752, 284, 8, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("��_��ų", "images/al_skill.bmp", 220, 384, 4, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("��_����2_����", "images/al_attack2_01.bmp", 1278, 808, 12, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("��_����2_������", "images/al_attack2_02.bmp", 1278, 808, 12, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("��_������", "images/al_hit.bmp", 79, 256, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("��_����", "images/al_die.bmp", 60, 208, 1, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("��_������", "images/al_levelUp.bmp", 130, 84, 2, 1, true, RGB(255, 0, 255));

	//IMAGE->addImage("�÷��̾�_ü�¹�_��", "images/HP_you.bmp", 200, 30, true, RGB(255, 0, 255));
	//IMAGE->addImage("�÷��̾�_ü�¹�_��", "images/emptyHP_you.bmp", 200, 30, true, RGB(255, 0, 255));
	//IMAGE->addImage("�÷��̾�_���¹�_��", "images/MP_me.bmp", 200, 30, true, RGB(255, 0, 255));
	//IMAGE->addImage("�÷��̾�_���¹�_��", "images/emptyMP_me.bmp", 200, 30, true, RGB(255, 0, 255));
	//IMAGE->addImage("�÷��̾�_����ġ_��", "images/EXP.bmp", 220, 15, true, RGB(255, 0, 255));
	//IMAGE->addImage("�÷��̾�_����ġ_��", "images/emptyEXP_1.bmp", 220, 15, true, RGB(255, 0, 255));
	IMAGE->addImage("�÷��̾�_ü�¹�_��", "images/HP_new.bmp", barFront, barBack, true, RGB(255, 0, 255));
	IMAGE->addImage("�÷��̾�_ü�¹�_��", "images/emptyBar.bmp", barFront, barBack, true, RGB(255, 0, 255));
	IMAGE->addImage("�÷��̾�_���¹�_��", "images/MP_new.bmp", barFront, barBack, true, RGB(255, 0, 255));
	IMAGE->addImage("�÷��̾�_���¹�_��", "images/emptyBar.bmp", barFront, barBack, true, RGB(255, 0, 255));
	IMAGE->addImage("�÷��̾�_����ġ_��", "images/EXP_new.bmp", barFront, barBack, true, RGB(255, 0, 255));
	IMAGE->addImage("�÷��̾�_����ġ_��", "images/emptyBar.bmp", barFront, barBack, true, RGB(255, 0, 255));

	IMAGE->addImage("��ų��", "images/skill.bmp", 190, 65, true, RGB(255, 0, 255));
	IMAGE->addImage("�κ��丮", "images/inventory.bmp", 190, 65, true, RGB(255, 0, 255));
	IMAGE->addImage("����", "images/level.bmp", 278, 35, true, RGB(255, 0, 255));

	//playerHP_Front = RectMakeCenter(280, 77, 200, 30);
	//playerHP_Back = RectMakeCenter(280, 77, 200, 30);

	//playerMP_Front = RectMakeCenter(280, 120, 200, 30);
	//playerMP_Back = RectMakeCenter(280, 120, 200, 30);

	_img = IMAGE->findImage("��_���");
	_skill = IMAGE->addFrameImage("��_��ų����Ʈ", "images/R_skill1.bmp", 640, 96, 10, 1, true, RGB(0, 255, 0));
	skillRC = RectMake(skillX, skillY, _skill->getFrameWidth() / 10, _skill->getFrameHeight());
	skillX = -100;
	skillY = -100;

	//_img->setX(WINSIZEX / 2);
	//_img->setY(600);

	x = WINSIZEX / 2;
	y = 510;
	level = 0;

	_img->setFrameX(0);
	_img->setFrameY(0);
	_currentState = PLAYER_STATE::IDLE;
	_prevState = PLAYER_STATE::IDLE;

	rc = RectMake(x, y, _img->getFrameWidth(), _img->getFrameHeight());
	//�ڡڡڡڡڡڡڽ�ų��Ʈ
	//if (isActive)
	//{
	skillRC = RectMake(skillX, skillY, _skill->getFrameWidth(), _skill->getFrameHeight());
	//}


	isPlayerDie = false;
	isLeft = true;
	isCollide = false;
	isDebug = false;

	m_count = 0;
	m_index = 0;

	attack2_left = 0;
	attack2_right = 0;
	cycle = 0;

	//ü�¹�.
	hp = 100;
	_hpBar = new progressBar;
	_hpBar->init(IMAGE->findImage("�÷��̾�_ü�¹�_��"), IMAGE->findImage("�÷��̾�_ü�¹�_��"), 10, 10, 200, 700);
	_hpBar->setGauge(hp, 100);

	mp = 100;
	_mpBar = new progressBar;
	_mpBar->init(IMAGE->findImage("�÷��̾�_���¹�_��"), IMAGE->findImage("�÷��̾�_���¹�_��"), 10, 10, 200, 700);
	_mpBar->setGauge(mp, 100);

	exp = 0;
	_expBar = new progressBar;
	_expBar->init(IMAGE->findImage("�÷��̾�_����ġ_��"), IMAGE->findImage("�÷��̾�_����ġ_��"), 10, 10, 400, 200);
	_expBar->setGauge(exp, 100);

	//����Ű display.
	key_attack1 = RectMake(800, 580, 50, 50);
	key_attack2 = RectMake(870, 580, 50, 50);
	key_skill = RectMake(940, 580, 50, 50);

	return S_OK;
}

void bossMap_player::release()
{
}

void bossMap_player::update()
{
	if (InputManager->isOnceKeyDown('1')) isDebug = !isDebug;
	//rc = RectMake(_img->getX(), _img->getY(), _img->getFrameWidth(), _img->getFrameHeight());

	//RECT.
	rc = RectMake(x, y, _img->getFrameWidth(), _img->getFrameHeight());
	skillRC = RectMake(skillX, skillY, _skill->getFrameWidth(), _skill->getFrameHeight());

	//�� ������Ʈ.
	_hpBar->setGauge(hp, 100);
	_hpBar->update();
	_mpBar->setGauge(mp, 100);
	_mpBar->update();

	if (exp >= 100)
	{
		level += 1;
		exp = 0;
	}

	_expBar->setGauge(exp, 100);
	_expBar->update();

	//�̵�.
	if (InputManager->isStayKeyDown(VK_LEFT) && x > 0)
	{
		_prevState = _currentState;
		_currentState = PLAYER_STATE::MOVE;
		_img = IMAGE->findImage("��_�̵�");
		isLeft = true;

		x -= PLAYERSPEED;

		/*
		if (x >= WINSIZEX / 2)
		{
			x -= PLAYERSPEED;
			//_img->setX(_img->getX() - PLAYERSPEED);
		}
		else if (_camera < 0)
		{
			_camera += CAMERASPEED;
		}
		else
		{
			x -= PLAYERSPEED;
			//->setX(_img->getX() - PLAYERSPEED);
		}
		*/
	}
	else if (InputManager->isStayKeyDown(VK_RIGHT) && x + 100 < WINSIZEX)
	{
		_prevState = _currentState;
		_currentState = PLAYER_STATE::MOVE;
		_img = IMAGE->findImage("��_�̵�");
		isLeft = false;

		x += PLAYERSPEED;
		/*
		if (x <= WINSIZEX / 2)
		{
			x += PLAYERSPEED;
			//_img->setX(_img->getX() + PLAYERSPEED);
		}
		else if (_camera > -WINSIZEX)
		{
			_camera -= CAMERASPEED;
		}
		else
		{
			x += PLAYERSPEED;
			//_img->setX(_img->getX() + PLAYERSPEED);
		}
		*/
	}


	if (InputManager->isOnceKeyUp(VK_RIGHT))
	{
		_img = IMAGE->findImage("��_���");
		_prevState = _currentState;
		_currentState = PLAYER_STATE::IDLE;
	}
	if (InputManager->isOnceKeyUp(VK_LEFT))
	{
		_img = IMAGE->findImage("��_���");
		_prevState = _currentState;
		_currentState = PLAYER_STATE::IDLE;
	}
	//����1.
	if (InputManager->isOnceKeyUp('Z'))
	{
		_prevState = _currentState;
		_currentState = PLAYER_STATE::ATTACK1;
		_img = IMAGE->findImage("��_����");
	}
	//����2.
	else if (InputManager->isOnceKeyUp('X'))
	{
		_prevState = _currentState;
		_currentState = PLAYER_STATE::ATTACK2;
		if (isLeft)
		{
			_img = IMAGE->findImage("��_����2_����");
			attack2_left++;
			if (attack2_left >= 5)attack2_left = 1;
		}
		else
		{
			_img = IMAGE->findImage("��_����2_������");
			attack2_right++;
			if (attack2_right >= 5)attack2_right = 1;
		}
	}
	//��ų.
	else if (InputManager->isOnceKeyUp('C'))
	{
		if (mp >= 30)
		{
			_prevState = _currentState;
			_currentState = PLAYER_STATE::SKILL;
			_img = IMAGE->findImage("��_��ų");
			//mp -= 30;

			isActive = true;
		}

		//if (isActive)
		//{
		//	//300fps������ ��ų �������..�ϰ���� 
		//	if (activeTime > 300)
		//	{
		//		isActive = false;
		//		activeTime = 0;
		//	}
		//	//skillAni = ANIMATION->findAnimation("��_��ų_�ִϸ��̼�");
		//	//ANIMATION->start("��_��ų_�ִϸ��̼�");
		//}
	}

	//������.
	if (_currentState == PLAYER_STATE::DAMAGE)
	{
		_prevState = _currentState;
		_currentState = PLAYER_STATE::DAMAGE;
		_img = IMAGE->findImage("��_������");
		hp -= 0.1;
	}

	//����.
	if (_currentState == PLAYER_STATE::DIE)
	{
		_prevState = _currentState;
		_currentState = PLAYER_STATE::DIE;
		_img = IMAGE->findImage("��_����");
	}

	//������.
	if (_currentState == PLAYER_STATE::IDLE)
	{
		if (isLeft)
		{
			m_count++;
			_img->setFrameY(0);

			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;
				if (m_index >= 3)
				{
					m_index = 0;
				}
				_img->setFrameX(m_index);
			}
		}
		else
		{
			m_count++;
			_img->setFrameY(1);

			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;
				if (m_index >= 3)
				{
					m_index = 0;
				}
				_img->setFrameX(m_index);
			}
		}
	}
	else if (_currentState == PLAYER_STATE::MOVE)
	{
		if (isLeft)
		{
			m_count++;
			_img->setFrameY(0);

			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;
				if (m_index >= 4)
				{
					m_index = 0;
				}
				_img->setFrameX(m_index);
			}
		}
		else
		{
			m_count++;
			_img->setFrameY(1);

			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;
				if (m_index >= 4)
				{
					m_index = 0;
				}
				_img->setFrameX(m_index);
			}
		}
	}
	else if (_currentState == PLAYER_STATE::ATTACK1)
	{
		if (isLeft)
		{
			m_count++;
			_img->setFrameY(0);

			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;
				if (m_index >= 8)
				{
					m_index = 0;
					_img = IMAGE->findImage("��_���");
					_currentState = PLAYER_STATE::IDLE;
				}
				_img->setFrameX(m_index);
			}
		}
		else
		{
			m_count++;
			_img->setFrameY(1);

			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;
				if (m_index >= 8)
				{
					m_index = 0;
					_img = IMAGE->findImage("��_���");
					_currentState = PLAYER_STATE::IDLE;
				}
				_img->setFrameX(m_index);
			}
		}
	}
	else if (_currentState == PLAYER_STATE::ATTACK2)
	{
		if (isLeft)
		{
			m_count++;
			if (attack2_left == 1) _img->setFrameY(0);
			else if (attack2_left == 2) _img->setFrameY(1);
			else if (attack2_left == 3) _img->setFrameY(2);
			else if (attack2_left == 4) _img->setFrameY(3);

			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;
				if (m_index >= 12)
				{
					m_index = 0;
					_img = IMAGE->findImage("��_���");
					_currentState = PLAYER_STATE::IDLE;
				}
				_img->setFrameX(m_index);
			}
		}
		else
		{
			m_count++;
			if (attack2_right == 1) _img->setFrameY(0);
			else if (attack2_right == 2) _img->setFrameY(1);
			else if (attack2_right == 3) _img->setFrameY(2);
			else if (attack2_right == 4) _img->setFrameY(3);

			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;
				if (m_index >= 12)
				{
					m_index = 0;
					_img = IMAGE->findImage("��_���");
					_currentState = PLAYER_STATE::IDLE;
				}
				_img->setFrameX(m_index);
			}
		}
	}
	/*
	else if (_currentState == PLAYER_STATE::SKILL)
	{
		if (isLeft)
		{
			m_count++;
			_img->setFrameY(0);

			if (m_count % 10 == 0)
			{
				m_count = 0;
				m_index++;
				if (m_index >= 4)
				{
					m_index = 0;
					cycle++;
					if (cycle > 2)
					{
						cycle = 0;
						_img = IMAGE->findImage("��_���");
						_currentState = PLAYER_STATE::IDLE;
					}
				}
				_img->setFrameX(m_index);
			}
		}
		else
		{
			m_count++;
			_img->setFrameY(2);

			if (m_count % 10 == 0)
			{
				m_count = 0;
				m_index++;
				if (m_index >= 4)
				{
					m_index = 0;
					cycle++;
					if (cycle > 2)
					{
						cycle = 0;
						_img = IMAGE->findImage("��_���");
						_currentState = PLAYER_STATE::IDLE;
					}
				}
				_img->setFrameX(m_index);
			}
		}
	}
	*/
	else if (_currentState == PLAYER_STATE::DAMAGE)
	{
		if (isLeft)
		{
			m_count++;
			_img->setFrameY(0);

			if (m_count % 10 == 0)
			{
				m_count = 0;
				m_index = 0;
				cycle++;
				if (cycle > 2)
				{
					cycle = 0;
					_img = IMAGE->findImage("��_���");
					_currentState = PLAYER_STATE::IDLE;
				}

				_img->setFrameX(m_index);
			}
		}
		else
		{
			m_count++;
			_img->setFrameY(2);

			if (m_count % 10 == 0)
			{
				m_count = 0;
				m_index = 0;
				cycle++;
				if (cycle > 2)
				{
					cycle = 0;
					_img = IMAGE->findImage("��_���");
					_currentState = PLAYER_STATE::IDLE;
				}

				_img->setFrameX(m_index);
			}
		}
	}
	else if (_currentState == PLAYER_STATE::DIE)
	{
		if (isLeft)
		{
			m_count++;
			_img->setFrameY(0);

			if (m_count % 10 == 0)
			{
				m_count = 0;
				m_index = 0;
				cycle++;
				if (cycle > 1)
				{
					cycle = 0;
					_img = IMAGE->findImage("��_���");
					_currentState = PLAYER_STATE::IDLE;
				}

				_img->setFrameX(m_index);
			}
		}
		else
		{
			m_count++;
			_img->setFrameY(2);

			if (m_count % 10 == 0)
			{
				m_count = 0;
				m_index = 0;
				cycle++;
				if (cycle > 1)
				{
					cycle = 0;
					_img = IMAGE->findImage("��_���");
					_currentState = PLAYER_STATE::IDLE;
				}

				_img->setFrameX(m_index);
			}
		}
	}
	//�ڡڡڡڡڡڡڡڡڽ�ų����!!!!!!!!!!!!�ڡڡڡڡڡڡڡڡ�
	else if (_currentState == PLAYER_STATE::SKILL) // && isActive) ////isActive �����߰�
	{
		if (isLeft)
		{
			m_count++;
			_img->setFrameY(0);
			if (m_count % 8 == 0)
			{
				m_count = 0;
				m_index++;
				if (m_index >= 4)
				{
					m_index = 0;
					cycle++;
					if (cycle > 2)
					{
						cycle = 0;
						_img = IMAGE->findImage("��_���");
						_currentState = PLAYER_STATE::IDLE;
					}
				}
				_img->setFrameX(m_index);
			}

			//��ų �ִϸ��̼�(����)
			s_count++;
			_skill->setFrameY(0);
			if (s_count % 10 == 0)
			{
				s_count = 0;
				s_index--;

				if (s_index < _skill->getMaxFrameY())
				{
					s_index = 9;
				}
				_skill->setFrameX(s_index);
			}

			////��ų��Ʈ ��ġ ����(����)
			//skillRC.left = rc.left - 10;
			//skillRC.top = rc.top - 10;
			skillX = rc.left - 40;
			skillY = rc.top - 30;
		}

		else
		{
			m_count++;
			_img->setFrameY(2);

			if (m_count % 10 == 0)
			{
				m_count = 0;
				m_index++;
				if (m_index >= 4)
				{
					m_index = 0;
					cycle++;
					if (cycle > 2)
					{
						cycle = 0;
						_img = IMAGE->findImage("��_���");
						_currentState = PLAYER_STATE::IDLE;
					}
				}
				_img->setFrameX(m_index);
			}

			//��ų �ִϸ��̼�(������)
			s_count++;
			_skill->setFrameY(0);

			if (s_count % 8 == 0)
			{
				s_count = 0;
				s_index++;

				if (s_index >= _skill->getMaxFrameX())
				{
					s_index = 0;
				}
				_skill->setFrameX(s_index);
			}

			//��ų��Ʈ ��ġ ����(������)
			skillX = rc.left + 35;
			skillY = rc.top - 30;
		}
	}
}

void bossMap_player::render()
{
	HFONT font, oldfont;

	TCHAR str[30];
	//wsprintf(str, "Collide : %d", isCollide);
	//TextOut(getMemDC(), x, y, str, lstrlen(str));

	//wsprintf(str, "Camera : %d", _camera);
	//TextOut(getMemDC(), 100, 100, str, lstrlen(str));

	//_stprintf(str, "HP : %f", hp);
	//TextOut(getMemDC(), 100, 170, str, lstrlen(str));



	//wsprintf(str, "mouse : %d, %d", m_ptMouse.x, m_ptMouse.y);
	//TextOut(getMemDC(), 100, 210, str, lstrlen(str));

	//wsprintf(str, "skillX : %d, skillY : %d", static_cast<int>(skillX), static_cast<int>(skillY));
	//TextOut(getMemDC(), 100, 230, str, lstrlen(str));


	switch (_currentState)
	{
	case PLAYER_STATE::IDLE:
		_img->frameRender(getMemDC(), x, y, _img->getFrameX(), _img->getFrameY());
		break;
	case PLAYER_STATE::MOVE:
		_img->frameRender(getMemDC(), x, y + 3, _img->getFrameX(), _img->getFrameY());
		break;
	case PLAYER_STATE::ATTACK1:
		_img->frameRender(getMemDC(), x - 18, y - 5, _img->getFrameX(), _img->getFrameY());
		break;
	case PLAYER_STATE::ATTACK2:
		if (isLeft) _img->frameRender(getMemDC(), x - 27, y - 130, _img->getFrameX(), _img->getFrameY());
		else _img->frameRender(getMemDC(), x - 22, y - 130, _img->getFrameX(), _img->getFrameY());
		break;
	case PLAYER_STATE::SKILL:
		_img->frameRender(getMemDC(), x - 1, y - 30, _img->getFrameX(), _img->getFrameY());
		_skill->frameRender(getMemDC(), skillX, skillY);											////��ų����
		//_skill->aniRender(getMemDC(), skillX, skillY, skillAni);									////��ų����
		break;
	case PLAYER_STATE::DAMAGE:
		_img->frameRender(getMemDC(), x - 18, y + 8, _img->getFrameX(), _img->getFrameY());
		break;
	case PLAYER_STATE::DIE:
		_img->frameRender(getMemDC(), x - 5, y + 22, _img->getFrameX(), _img->getFrameY());
		break;
	default:
		break;
	}

	//_hpBar->render(10, 10);
	//_mpBar->render(10, 30);
	//_expBar->render(300, 650);

	//��ǥ
	_hpBar->render(116, 32);
	_mpBar->render(116, 61);
	_expBar->render(116, 91);


	//����Ű display.
	//Rectangle(getMemDC(), key_attack1.left, key_attack1.top, key_attack1.right, key_attack1.bottom);
	//wsprintf(str, "Z");
	//TextOut(getMemDC(), key_attack1.left + 2, key_attack1.top + 2, str, lstrlen(str));
	//wsprintf(str, "����1");
	//TextOut(getMemDC(), key_attack1.left + 5, key_attack1.top + 20, str, lstrlen(str));
	//
	//Rectangle(getMemDC(), key_attack2.left, key_attack2.top, key_attack2.right, key_attack2.bottom);
	//wsprintf(str, "X");
	//TextOut(getMemDC(), key_attack2.left + 2, key_attack2.top + 2, str, lstrlen(str));
	//wsprintf(str, "����2");
	//TextOut(getMemDC(), key_attack2.left + 5, key_attack2.top + 20, str, lstrlen(str));
	//
	//Rectangle(getMemDC(), key_skill.left, key_skill.top, key_skill.right, key_skill.bottom);
	//wsprintf(str, "C");
	//TextOut(getMemDC(), key_skill.left + 2, key_skill.top + 2, str, lstrlen(str));
	//wsprintf(str, "��ų");
	//TextOut(getMemDC(), key_skill.left + 8, key_skill.top + 20, str, lstrlen(str));
	//IMAGE->render("��ų��", getMemDC(), 785, 585);
	//IMAGE->render("�κ��丮", getMemDC(), 785, 660);
	IMAGE->render("��ų��", getMemDC(), 785, 35);
	IMAGE->render("�κ��丮", getMemDC(), 785, 110);
	IMAGE->render("����", getMemDC(), 28, 128);

	font = CreateFont(20, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "Typo_DecoSolidFill");
	oldfont = (HFONT)SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	wsprintf(str, "Level ��%d", level);
	TextOut(getMemDC(), 130, 135, str, lstrlen(str));
	SelectObject(getMemDC(), oldfont);
	DeleteObject(font);

	if (isDebug)
	{
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
		Rectangle(getMemDC(), skillRC.left, skillRC.top, skillRC.right, skillRC.bottom); //��ų
	}
}