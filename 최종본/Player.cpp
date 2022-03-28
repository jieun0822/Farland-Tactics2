#include "framework.h"
#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

HRESULT Player::init()
{
	_player = IMAGE->addFrameImage("��_�̵�", "images/al_move.bmp", 292, 236, 4, 4, true, RGB(255, 0, 255));
	IMAGE->addFrameImage("��_idle", "images/al_idle.bmp", 150, 248, 3, 4, true, RGB(255, 0, 255));
	ANIMATION->addAnimation("R_moveLeft", "��_�̵�", 0, 3, 10, false, true);
	ANIMATION->addAnimation("R_moveRight", "��_�̵�", 12, 15, 10, false, true);
	ANIMATION->addAnimation("R_moveUp", "��_�̵�", 8, 11, 10, false, true);
	ANIMATION->addAnimation("R_moveDown", "��_�̵�", 4, 7, 10, false, true);
	//int arrLen[] = { 1,2,3,4 };
	//ANIMATION->addAnimation("R_moveLeft", "��_�̵�", arrLen, 4, 10, true);
	_ani = ANIMATION->findAnimation("R_moveLeft");

	_player->setX(WINSIZEX / 2);
	_player->setY(WINSIZEY / 2);

	index_x = 26;
	index_y = 22;

	return S_OK;
}

void Player::release()
{
}

void Player::update()
{
	/*
	if (InputManager->isStayKeyDown(VK_LEFT))
	{
		_ani = ANIMATION->findAnimation("R_moveLeft");
		ANIMATION->start("R_moveLeft");
		_player->setX(_player->getX() - 1);
		_player->setY(_player->getY() + 1);
	}
	if (InputManager->isStayKeyDown(VK_RIGHT))
	{
		_ani = ANIMATION->findAnimation("R_moveRight");
		ANIMATION->start("R_moveRight");
		_player->setX(_player->getX() + 1);
		_player->setY(_player->getY() - 1);
	}
	if (InputManager->isStayKeyDown(VK_UP))
	{
		_ani = ANIMATION->findAnimation("R_moveUp");
		ANIMATION->start("R_moveUp");
		_player->setX(_player->getX() - 1);
		_player->setY(_player->getY() - 1);
	}
	if (InputManager->isStayKeyDown(VK_DOWN))
	{
		_ani = ANIMATION->findAnimation("R_moveDown");
		ANIMATION->start("R_moveDown");
		_player->setX(_player->getX() + 1);
		_player->setY(_player->getY() + 1);
	}
	*/
}

void Player::render()
{
	//_player->aniRender(getMemDC(), _player->getX(), _player->getY(), _ani);
	_player->frameRender(getMemDC(), _player->getX(), _player->getY(), _player->getFrameX(), _player->getFrameY());
}

void Player::setAnimation(string str)
{
	_ani = ANIMATION->findAnimation(str);
	//ANIMATION->start(str);
	currentAni = str;
}
