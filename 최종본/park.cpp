#include "framework.h"
#include "park.h"

park::park()
{
}

park::~park()
{
}

HRESULT park::init()
{
	SOUND->addSound("����", "sound/bgm10_�뷡����.mp3", true, false);

	IMAGE->addImage("����", "images/����.bmp", 19, 14, true, RGB(255, 0, 255));
	IMAGE->addImage("���ٹ�", "images/���ٹ�.bmp", 38, 30, true, RGB(255, 0, 255));

	_isoX = 0;
	_isoY = 0;
	_center = 0;
	memset(_tileMap, 0, sizeof(_tileMap));

	_startX = INIT_X;
	_startY = INIT_Y;

	_isDebug = false;
	_isIndex = false;

	MapToolSetup();
	Load();

	//Ÿ�� Ŭ�� �ν�.
	startX = INIT_X;
	startY = INIT_Y;

	tile = new Tile * [TILE_COUNT_X];
	for (size_t i = 0; i < TILE_COUNT_X; i++)
	{
		tile[i] = new Tile[TILE_COUNT_Y];
		memset(tile[i], 0, sizeof(Tile) * TILE_COUNT_Y);
	}

	for (size_t i = 0; i < TILE_COUNT_X; i++)
	{
		for (size_t j = 0; j < TILE_COUNT_Y; j++)
		{
			int left = _startX + (i * RADIUS_WIDTH) - (j * RADIUS_WIDTH);
			int top = _startY + (i * RADIUS_HEIGHT) + (j * RADIUS_HEIGHT);

			_tileMap[i][j].left = left;
			_tileMap[i][j].top = top;

			int centerX = left + RADIUS_WIDTH;
			int centerY = top + RADIUS_HEIGHT;

			tile[i][j].pt[0].x = centerX;
			tile[i][j].pt[0].y = centerY - RADIUS_HEIGHT;

			tile[i][j].pt[1].x = centerX + RADIUS_WIDTH;
			tile[i][j].pt[1].y = centerY;

			tile[i][j].pt[2].x = centerX;
			tile[i][j].pt[2].y = centerY + RADIUS_HEIGHT;

			tile[i][j].pt[3].x = centerX - RADIUS_WIDTH;
			tile[i][j].pt[3].y = centerY;

			tile[i][j].isClick = false;

			tile[i][j].index_x = i;
			tile[i][j].index_y = j;

			tile[i][j].type = TILE_TYPE::TILE_TYPE_EMPTY;
			tile[i][j].color = RGB(255, 255, 255);
			tile[i][j].parent = NULL;
			tile[i][j].F = BIGNUM;
			tile[i][j].H = 0;
			tile[i][j].i = i;
			tile[i][j].j = j;
			tile[i][j].isLeftClick = false;

			if (i >= 3 && i <= 42)
			{
				int random = RND->getFromIntTo(0, 40);
				if (random == 0) tile[i][j].isCoin_exist = true;
				else if (random == 1) tile[i][j].isCoins_exist = true;
				else
				{
					tile[i][j].isCoin_exist = false;
					tile[i][j].isCoins_exist = false;
				}
			}
			else tile[i][j].isCoin_exist = false;
		}
	}


	firstFloor = false;
	secondFloor = false;
	thirdFloor = false;

	_playerTurn = true;

	_astarState = ASTAR_STATE::ASTAR_STATE_END;//�ʱ���� = Ÿ�Ϲ�ġ �Ϸ���
	_selectType = TILE_TYPE::TILE_TYPE_EMPTY;//��ġ�� Ÿ�� �Ӽ� = ��Ÿ��
	_selectedTypeColor = RGB(255, 255, 255);//��ġ�� Ÿ�� ���� = �Ͼ�

	_startPointSet = false;
	_endPointSet = false;

	isFirst = true;

	//����.
	//�߰���
	townButton = RectMake(WINSIZEX - 180, WINSIZEY - 80, 150, 30);
	town_active = false;

	//�÷��̾�.
	_player = new Player;
	_player->init();

	player_x = WINSIZEX / 2;
	player_y = WINSIZEY / 2;

	m_count = 0;
	m_index = 0;

	_player->getImg()->setFrameY(0);
	_player->getImg()->setFrameX(0);

	isRight = false;
	isLeft = true;
	isUp = false;
	isDown = false;

	money = 0;
	startTime_coin = 0;
	startTime_coins = 0;
	endTime = 0;

	return S_OK;
}

void park::release()
{
	for (size_t i = 0; i < TILE_COUNT_X; ++i)
		delete[] tile[i];
	delete[] tile;

	SAFE_DELETE(_player);
}

void park::update()
{
	if (isFirst)
	{
		aStarInit();
		isFirst = false;
	}

	move();
	//if (InputManager->isStayKeyDown('W')) { _startY += 5; }
	//if (InputManager->isStayKeyDown('S')) { _startY -= 5; }
	//if (InputManager->isStayKeyDown('A')) { _startX += 5; }
	//if (InputManager->isStayKeyDown('D')) { _startX -= 5; }

	if (InputManager->isOnceKeyDown(VK_TAB)) _isDebug = !_isDebug;
	if (InputManager->isOnceKeyDown(VK_SHIFT)) _isIndex = !_isIndex;

	//�������� display.
	if (InputManager->isOnceKeyDown('1')) firstFloor = !firstFloor;
	if (InputManager->isOnceKeyDown('2')) secondFloor = !secondFloor;
	if (InputManager->isOnceKeyDown('3')) thirdFloor = !thirdFloor;

	if (_astarState == ASTAR_STATE::ASTAR_STATE_END)
	{
		if (InputManager->isOnceKeyUp(VK_LBUTTON))
		{
			if (PtInRect(&townButton, m_ptMouse))
			{
				town_active = true;

				SOUND->stop("����");
				SOUND->play("����");
			}
			else pnpoly_leftClick();
		}
		tileComposition();
	}
	if (_startPointSet && _endPointSet && _astarState == ASTAR_STATE::ASTAR_STATE_END)
	{
		tileInitializing();
	}
	if (_astarState == ASTAR_STATE::ASTAR_STATE_END || _astarState == ASTAR_STATE::ASTAR_STATE_FOUND || _astarState == ASTAR_STATE::ASTAR_STATE_NOWAY)return;

	addOpenList();
	caculateH();
	caculateF();
	addCloseList();
	checkArrive();
	getTrack();
	_playerTurn = true;

	_player->update();
}

void park::render()
{
	if (!SOUND->isPlaySound("����"))
	{
		SOUND->play("����");
	}

	DrawTileMap();

	//if (_playerTurn) showArea();
	//Rectangle(getMemDC(), townButton.left, townButton.top, townButton.right, townButton.bottom);
	
	//���ƿ��� ��ư
	//�߰���
	shadowDraw(townButton);
	lightGrayDraw(townButton);
	SetTextColor(getMemDC(), RGB(0, 0, 0));
	SetBkMode(getMemDC(), TRANSPARENT);
	TextOut(getMemDC(), townButton.left + 17, townButton.top + 8, "������ ���ư���", lstrlen("������ ���ư���"));

	//��� display.
	if (_isDebug)
	{
		int height = 1;

		RECT rc = RectMake(200, 20, 50, 400);
		Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
		vector<Tile*>::iterator iter;

		iter = track.begin();
		for (iter; iter != track.end(); ++iter)
		{
			wsprintf(str, "%d , %d", (*iter)->i, (*iter)->j);
			TextOut(getMemDC(), 200, 20 * height, str, lstrlen(str));
			height++;
		}
	}
	_player->render();

	HFONT font, oldfont;
	font = CreateFont(25, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, "OdBestFreind");
	oldfont = (HFONT)SelectObject(getMemDC(), font);


	if (endTime - startTime_coin < 1 && startTime_coin != 0)
	{
		SetBkMode(getMemDC(), TRANSPARENT);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 750, 600, "+20 ��带 ȹ���߽��ϴ�.", lstrlen("+20 ��带 ȹ���߽��ϴ�."));
	}
	else if (endTime - startTime_coins < 1 && startTime_coins != 0)
	{
		SetBkMode(getMemDC(), TRANSPARENT);
		SetTextColor(getMemDC(), RGB(0, 0, 0));
		TextOut(getMemDC(), 750, 650, "+100 ��带 ȹ���߽��ϴ�.", lstrlen("+100 ��带 ȹ���߽��ϴ�."));
	}

	SelectObject(getMemDC(), oldfont);
	DeleteObject(font);
}

void park::DrawTileMap()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			int left = _startX + (i * RADIUS_WIDTH) - (j * RADIUS_WIDTH);
			int top = _startY + (i * RADIUS_HEIGHT) + (j * RADIUS_HEIGHT);

			_tileMap[i][j].left = left;
			_tileMap[i][j].top = top;

			int centerX = left + RADIUS_WIDTH;
			int centerY = top + RADIUS_HEIGHT;

			tile[i][j].x = centerX;
			tile[i][j].y = centerY;

			tile[i][j].pt[0].x = centerX;
			tile[i][j].pt[0].y = centerY - RADIUS_HEIGHT;

			tile[i][j].pt[1].x = centerX + RADIUS_WIDTH;
			tile[i][j].pt[1].y = centerY;

			tile[i][j].pt[2].x = centerX;
			tile[i][j].pt[2].y = centerY + RADIUS_HEIGHT;

			tile[i][j].pt[3].x = centerX - RADIUS_WIDTH;
			tile[i][j].pt[3].y = centerY;

			for (int z = 0; z <= _tileMap[i][j].index; z++)
			{
				if (_tileMap[i][j].tileKind[z] != TILEKIND::TILEKIND_NONE)
				{
					//ȭ��� ���������� ����.
					if (_tileMap[i][j].left >= -CELL_WIDTH && _tileMap[i][j].left + CELL_WIDTH <= WINSIZEX + CELL_WIDTH
						&& _tileMap[i][j].top >= -CELL_HEIGHT && _tileMap[i][j].top + CELL_HEIGHT <= WINSIZEY + CELL_HEIGHT)
					{

						switch (_tileMap[i][j].tileNum[z])
						{
						case 0:
							IMAGE->render("_1", getMemDC(),
								_tileMap[i][j].left,
								_tileMap[i][j].top - _tileMap[i][j].height * z);
							break;
						case 1:
							IMAGE->render("_2", getMemDC(),
								_tileMap[i][j].left,
								_tileMap[i][j].top - _tileMap[i][j].height * z);
							break;
						case 2:
							IMAGE->render("_3", getMemDC(),
								_tileMap[i][j].left + 10,
								_tileMap[i][j].top - _tileMap[i][j].height * z - 33);
							break;
						case 3:
							IMAGE->render("_2", getMemDC(),
								_tileMap[i][j].left,
								_tileMap[i][j].top - _tileMap[i][j].height * z+30);
							//IMAGE->render("tree", getMemDC(),
							//	_tileMap[i][j].left,
							//	_tileMap[i][j].top - _tileMap[i][j].height * z - 90);
							break;
						case 4:
							IMAGE->render("grass1", getMemDC(),
								_tileMap[i][j].left,
								_tileMap[i][j].top - _tileMap[i][j].height * z - 8);
							break;
						}
					}
				}

				if (_tileMap[i][j].tileNum[z] == 3)
				{
					//���߿� ������ ��ġ�� alpharender�� �ٲ��.
					// �浹ó���� ���� rect.
					//RECT rc = RectMake(_tileMap[i][j].left, _tileMap[i][j].top - _tileMap[i][j].height * z - 90, 64, 131);
					//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
				}
			}

			if (firstFloor && _tileMap[i][j].index == 0)
			{
				DrawRhombus(left, top);
				SetTextColor(getMemDC(), RGB(0, 0, 0));
				sprintf_s(str, "(%d,%d)", i, j);
				TextOut(getMemDC(),
					left + RADIUS_WIDTH / 2 + 8,
					top + RADIUS_HEIGHT / 2 + 5, str, strlen(str));
			}

			if (secondFloor && _tileMap[i][j].index == 1)
			{
				DrawRhombus(left, top - 13);
				SetTextColor(getMemDC(), RGB(0, 0, 0));
				sprintf_s(str, "(%d,%d)", i, j);
				TextOut(getMemDC(),
					left + RADIUS_WIDTH / 2 + 8,
					top + RADIUS_HEIGHT / 2 + 5 - 13, str, strlen(str));
			}

			if (thirdFloor && _tileMap[i][j].index == 2)
			{
				DrawRhombus(left, top - 13 * 2);
				SetTextColor(getMemDC(), RGB(0, 0, 0));
				sprintf_s(str, "(%d,%d)", i, j);
				TextOut(getMemDC(),
					left + RADIUS_WIDTH / 2 + 8,
					top + RADIUS_HEIGHT / 2 + 5 - 13 * 2, str, strlen(str));
			}//if end
		}//for end
	}//for end

	for (size_t i = 0; i < TILE_COUNT_X; i++)
	{
		for (size_t j = 0; j < TILE_COUNT_Y; j++)
		{
			if (_isDebug) Polygon(getMemDC(), tile[i][j].pt, 4);

			if (_isIndex)
			{
				TCHAR str[10];
				wsprintf(str, "%d,%d", tile[i][j].index_x, tile[i][j].index_y);
				TextOut(getMemDC(), tile[i][j].pt[3].x + 10, tile[i][j].pt[3].y - 10, str, lstrlen(str));
			}

			if (tile[i][j].isCoin_exist) IMAGE->render("����", getMemDC(), tile[i][j].pt[3].x + 10, tile[i][j].pt[3].y - 10);
			else if (tile[i][j].isCoins_exist) IMAGE->render("���ٹ�", getMemDC(), tile[i][j].pt[3].x + 10, tile[i][j].pt[3].y - 10);
		}
	}
}

void park::DrawRhombus(int left, int top)
{
	int centerX = left + RADIUS_WIDTH;
	int centerY = top + RADIUS_HEIGHT;

	POINT p[5];
	p[0].x = centerX;
	p[0].y = centerY - RADIUS_HEIGHT;

	p[1].x = centerX + RADIUS_WIDTH;
	p[1].y = centerY;

	p[2].x = centerX;
	p[2].y = centerY + RADIUS_HEIGHT;

	p[3].x = centerX - RADIUS_WIDTH;
	p[3].y = centerY;

	p[4].x = centerX;
	p[4].y = centerY - RADIUS_HEIGHT;

	for (int i = 1; i < 5; i++)
	{
		LineMake(getMemDC(), p[i - 1], p[i]);
	}
}

int park::GetCornerIndex(int isoX, int isoY)
{
	//Ŭ���� ��ǥ���� ���ؼ� ������ ���� ��Ʈ�� left,top�� ���Ѵ�.
	int left = _startX + (isoX * RADIUS_WIDTH) - (isoY * RADIUS_WIDTH);
	int top = _startY + (isoX * RADIUS_HEIGHT) + (isoY * RADIUS_HEIGHT);

	//left���� ���콺���� ���� ����Ʈ���� �̵��� ���� ���µ�,
	//�̰� ��ü���̷� ������ 0.0~ 1.0 (float���� ������ , ������ float�̴ϱ�)�� ���� ���´�
	//���������� ������ ������ ��Ʈ�� 1~4������ ��������
	//���� ��ġ�� �� �� �ִ�.
	float dx = (m_ptMouse.x - left) / static_cast<float>(CELL_WIDTH);
	float dy = (m_ptMouse.y - top) / static_cast<float>(CELL_HEIGHT);

	//���� �Ѵ� ���� ���� ������ 1/4�и�
	if (dx < 0.5f && dy < 0.5f) return 1;
	//���� dx ����(0.5)���� ũ�� 2/4�и�
	if (dx >= 0.5f && dy < 0.5f) return 2;
	//���� dx ����(0.5)���� �۰� dy �������� ũ�� 3/4�и�
	if (dx < 0.5f && dy >= 0.5f) return 3;
	//���� �Ѵ� ����(0.5)���� ũ�� 4/4
	if (dx >= 0.5f && dy >= 0.5f) return 4;

	return 0;
}

bool park::IsInRhombus(int corner, int isoX, int isoY)
{
	// lefttop
	if (corner == 1) {
		int left = _startX + (isoX * RADIUS_WIDTH) - (isoY * RADIUS_WIDTH);
		int top = _startY + (isoX * RADIUS_HEIGHT) + (isoY * RADIUS_HEIGHT);

		//left ���� ���콺���� ����(left���� �̵��Ÿ�)��
		//left�� ���������� top�� ������ ���̷� �ϴ� ���� �簢������ 
		//����ϱ� ���� dx�� dy�� ���Ѵ�.
		float dx = static_cast<float>(m_ptMouse.x - left) / RADIUS_WIDTH;
		float dy = static_cast<float>(m_ptMouse.y - top) / RADIUS_HEIGHT;

		//���� ��ü ��ʣO���� ���ﰢ�� �ȿ� ���� �ϱ� ������
		//������ dy�� dx���� ���ų� ���� �� �ۿ� ����.
		//���ﰢ�� �ȿ� �� �մ� ���� ������ y�� x���� �۰ų� 
		//���� �� �ۿ� ����.

		//1���ִ� ������ top�������� ���̸� ��� �߱� ������
		//���ҿ��������� ���� ���ϱ� ����
		if ((1.0f - dy) <= dx) return true;
		//���ﰢ�� �ۿ� �ִٸ� 
		else return false;
	}
	// righttop
	else if (corner == 2)
	{
		int left = _startX + (isoX * RADIUS_WIDTH) - (isoY * RADIUS_WIDTH);
		//����Ʈ�� ������ ������ ���ϴ� ������
		//�˻��ϴ� ��Ʈ�� ���������� �������� �������� left��
		//�ƴ� ���������� ���� ��Ʈ(�簢��)�̱� ������
		//���� �������� ���Ѵ�
		left += RADIUS_WIDTH;
		int top = _startY + (isoX * RADIUS_HEIGHT) + (isoY * RADIUS_HEIGHT);

		float dx = static_cast<float>(m_ptMouse.x - left) / RADIUS_WIDTH;
		float dy = static_cast<float>(m_ptMouse.y - top) / RADIUS_HEIGHT;

		if (dy >= dx) return true;
		else return false;
	}
	// leftdown
	else if (corner == 3) {
		int left = _startX + (isoX * RADIUS_WIDTH) - (isoY * RADIUS_WIDTH);
		int top = _startY + (isoX * RADIUS_HEIGHT) + (isoY * RADIUS_HEIGHT);
		top += RADIUS_HEIGHT;

		float dx = static_cast<float>(m_ptMouse.x - left) / RADIUS_WIDTH;
		float dy = static_cast<float>(m_ptMouse.y - top) / RADIUS_HEIGHT;

		if (dy < dx) return true;
		else return false;
	}
	// rightdown
	else if (corner == 4)
	{
		int left = _startX + (isoX * RADIUS_WIDTH) - (isoY * RADIUS_WIDTH);
		left += RADIUS_WIDTH;
		int top = _startY + (isoX * RADIUS_HEIGHT) + (isoY * RADIUS_HEIGHT);
		top += RADIUS_HEIGHT;

		float dx = static_cast<float>(m_ptMouse.x - left) / RADIUS_WIDTH;
		float dy = static_cast<float>(m_ptMouse.y - top) / RADIUS_HEIGHT;

		if ((1.0f - dy) > dx) return true;
		else return false;
	}

	return false;
}

void park::MapToolSetup()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			_tileMap[i][j].index = -1;
			_tileMap[i][j].height = 13;
		}
	}
}



void park::TlieInit()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			_tileMap[i][j].index = -1;
		}
	}
}

void park::Load()
{
	HANDLE file;
	DWORD read;
	file = CreateFile("save/tileMap.map",
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	ReadFile(file, TileMap, sizeof(TagTile) * TILE_COUNT_X * TILE_COUNT_Y, &read, NULL);
	//	ReadFile(file, _pos, sizeof(int) * 2, &read, NULL);
	for (size_t i = 0; i < TILE_COUNT_X; i++)
	{
		for (size_t j = 0; j < TILE_COUNT_Y; j++)
		{
			_tileMap[i][j] = TileMap[i * TILE_COUNT_Y + j];
		}
	}
	CloseHandle(file);
}

void park::pnpoly()
{
	int nvert = 4;

	for (size_t i = 0; i < TILE_COUNT_X; i++)
	{
		for (size_t j = 0; j < TILE_COUNT_Y; j++)
		{
			//polygon x��
			vertX[i][j].x[0] = tile[i][j].pt[0].x;
			vertX[i][j].x[1] = tile[i][j].pt[1].x;
			vertX[i][j].x[2] = tile[i][j].pt[2].x;
			vertX[i][j].x[3] = tile[i][j].pt[3].x;

			//polygon y��
			vertY[i][j].y[0] = tile[i][j].pt[0].y;
			vertY[i][j].y[1] = tile[i][j].pt[1].y;
			vertY[i][j].y[2] = tile[i][j].pt[2].y;
			vertY[i][j].y[3] = tile[i][j].pt[3].y;
		}
	}

	int testx = m_ptMouse.x;
	int testy = m_ptMouse.y;

	for (size_t k = 0; k < TILE_COUNT_X; k++)
	{
		for (size_t r = 0; r < TILE_COUNT_Y; r++)
		{
			int i, j, c = 0;
			for (i = 0, j = nvert - 1; i < nvert; j = i++) {
				if (((vertY[k][r].y[i] > testy) != (vertY[k][r].y[j] > testy)) &&
					(testx < (vertX[k][r].x[j] - vertX[k][r].x[i]) * (testy - vertY[k][r].y[i]) / (vertY[k][r].y[j] - vertY[k][r].y[i]) + vertX[k][r].x[i]))
					c = !c;
			}

			tile[k][r].isClick = c;
		}
	}
}

void park::tileComposition()
{
	//static int order = 0;


	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			if (tile[i][j].isLeftClick)
			{
				if (tile[i][j].type != TILE_TYPE::TILE_TYPE_EMPTY)return;
			}
		}
	}


	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			if (i == _player->getIndexX() && j == _player->getIndexY())
			{
				_selectType = TILE_TYPE::TILE_TYPE_START;

				typeColor(_selectType);
				tile[i][j].type = TILE_TYPE::TILE_TYPE_START;
				if (tile[i][j].type == TILE_TYPE::TILE_TYPE_START)_startPointSet = false;

				tile[i][j].color = _selectedTypeColor;

				if (_selectType == TILE_TYPE::TILE_TYPE_START)
				{
					if (_startPointSet)
					{
						tile[startX][startY].color = RGB(255, 255, 255);
						tile[startX][startY].type = TILE_TYPE::TILE_TYPE_EMPTY;
					}
					_startPointSet = true;
					startX = i;
					startY = j;
				}
			}
		}
	}

	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			if (tile[i][j].isLeftClick)
			{
				_selectType = TILE_TYPE::TILE_TYPE_END;

				typeColor(_selectType);
				tile[i][j].type = TILE_TYPE::TILE_TYPE_END;

				if (tile[i][j].type == TILE_TYPE::TILE_TYPE_END)_endPointSet = false;

				tile[i][j].color = _selectedTypeColor;

				if (_selectType == TILE_TYPE::TILE_TYPE_END)
				{
					if (_endPointSet)
					{
						tile[endX][endY].color = RGB(255, 255, 255);
						tile[endX][endY].type = TILE_TYPE::TILE_TYPE_EMPTY;
					}
					_endPointSet = true;
					endX = i;
					endY = j;
				}
			}
		}
	}
}

void park::tileInitializing()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			switch (tile[i][j].type)
			{
			case TILE_TYPE::TILE_TYPE_EMPTY:
			{
				tile[i][j].walkable = true;
				tile[i][j].listOn = false;
			}
			break;
			case TILE_TYPE::TILE_TYPE_WALL:
			{
				tile[i][j].walkable = false;
				tile[i][j].listOn = false;
			}
			break;
			case TILE_TYPE::TILE_TYPE_START:
			{
				tile[i][j].walkable = false;
				tile[i][j].listOn = false;
				closeList.push_back(&tile[i][j]);
			}
			break;
			case TILE_TYPE::TILE_TYPE_END:
			{
				endX = i;
				endY = j;
				tile[i][j].walkable = true;
				tile[i][j].listOn = false;
			}
			break;
			}
		}
	}
	_astarState = ASTAR_STATE::ASTAR_STATE_SEARCHING;
	_lastIndex = 0;
}

void park::addOpenList()
{
	Ci = closeList[_lastIndex]->i;
	Cj = closeList[_lastIndex]->j;
	Cg = closeList[_lastIndex]->G;

	//�밢�� ���԰�.
	int diagonalWeight = 25;

	if (Cj != 0)//0��° ���̾ƴϸ� ��ܶ��� ���
	{
		if (tile[Ci][Cj - 1].walkable)//��� ��� Ÿ���� �������� �ִٸ�
		{
			if (!tile[Ci][Cj - 1].listOn)//���¸���Ʈ�� ������ �ȵǾ� �ִ� Ÿ���̶��
			{
				tile[Ci][Cj - 1].listOn = true;//���¸���Ʈ�� ���ԵǾ���.
				tile[Ci][Cj - 1].color = RGB(220, 255, 220);
				tile[Ci][Cj - 1].G = Cg + 10;//Ÿ����G���� Ŭ���� ����Ʈ�� ���� G+10
				tile[Ci][Cj - 1].parent = closeList[_lastIndex];//Ÿ���� �θ� Ŭ���� ����Ʈ�� ���������� �߰�
				openList.push_back(&tile[Ci][Cj - 1]);//���� ����Ʈ�� �߰�
			}
			else//���¸���Ʈ�� ������ �Ǿ� �ִ� Ÿ���̶��
			{
				if (Cg + 10 < tile[Ci - 1][Cj].G)//����G������ ���� ����� G���� �۴ٸ�
				{
					tile[Ci][Cj - 1].G = Cg + 10;//G�� ���Ӱ� ���
					tile[Ci][Cj - 1].parent = closeList[_lastIndex];
				}
			}
			if (Cj != 0)//�»�� : 0��° ���� �ƴ϶��
			{
				//�»�� Ÿ���� �����̳� �Ʒ��� ���� ���ٸ�
				if (tile[Ci - 1][Cj + 1].walkable && tile[Ci][Cj].walkable && tile[Ci + 1][Cj].walkable)
				{
					if (!tile[Ci - 1][Cj + 1].listOn)
					{
						tile[Ci - 1][Cj + 1].listOn = true;
						tile[Ci - 1][Cj + 1].color = RGB(220, 255, 220);
						tile[Ci - 1][Cj + 1].G = Cg + diagonalWeight;//�밢�� �̹Ƿ�
						tile[Ci - 1][Cj + 1].parent = closeList[_lastIndex];
						openList.push_back(&tile[Ci - 1][Cj + 1]);
					}
					else
					{
						if (Cg + 14 < tile[Ci - 1][Cj + 1].G)
						{
							tile[Ci - 1][Cj + 1].G = Cg + diagonalWeight;
							tile[Ci - 1][Cj + 1].parent = closeList[_lastIndex];
						}
					}
				}
			}
			if (Ci != TILE_COUNT_X - 1)//���� :  ���������� �ƴ϶��
			{
				//���� Ÿ���� �����̳� �Ʒ��� ���� ���ٸ�
				if (tile[Ci - 1][Cj - 1].walkable && tile[Ci - 1][Cj].walkable && tile[Ci + 1][Cj].walkable)
				{
					if (!tile[Ci - 1][Cj - 1].listOn)
					{
						tile[Ci - 1][Cj - 1].listOn = true;
						tile[Ci - 1][Cj - 1].color = RGB(220, 255, 220);
						tile[Ci - 1][Cj - 1].G = Cg + diagonalWeight;
						tile[Ci - 1][Cj - 1].parent = closeList[_lastIndex];
						openList.push_back(&tile[Ci - 1][Cj - 1]);
					}
					else
					{
						if (Cg + 14 < tile[Ci - 1][Cj - 1].G)
						{
							tile[Ci - 1][Cj - 1].G = Cg + diagonalWeight;
							tile[Ci - 1][Cj - 1].parent = closeList[_lastIndex];
						}
					}
				}
			}
		}

		if (Ci != 0)//���� : 0��° ���� �ƴ϶��
		{
			//����Ÿ���� �̵������ϴٸ�
			if (tile[Ci][Cj + 1].walkable)
			{
				if (!tile[Ci][Cj + 1].listOn)
				{
					tile[Ci][Cj + 1].listOn = true;
					tile[Ci][Cj + 1].color = RGB(220, 255, 220);
					tile[Ci][Cj + 1].G = Cg + 10;
					tile[Ci][Cj + 1].parent = closeList[_lastIndex];
					openList.push_back(&tile[Ci][Cj + 1]);
				}
				else
				{
					if (Cg + 10 < tile[Ci][Cj + 1].G)
					{
						tile[Ci][Cj + 1].G = Cg + 10;
						tile[Ci][Cj + 1].parent = closeList[_lastIndex];
					}
				}
			}
		}
		if (Ci != TILE_COUNT_X - 1)//���� :���������� �ƴ϶��
		{
			if (tile[Ci - 1][Cj].walkable)//����Ÿ���� �̵������ϴٸ�
			{
				if (!tile[Ci - 1][Cj].listOn)
				{
					tile[Ci - 1][Cj].listOn = true;
					tile[Ci - 1][Cj].color = RGB(220, 255, 220);
					tile[Ci - 1][Cj].G = Cg + 10;
					tile[Ci - 1][Cj].parent = closeList[_lastIndex];
					openList.push_back(&tile[Ci - 1][Cj]);
				}
				else
				{
					if (Cg + 10 < tile[Ci - 1][Cj].G)
					{
						tile[Ci - 1][Cj].G = Cg + 10;
						tile[Ci - 1][Cj].parent = closeList[_lastIndex];
					}
				}
			}
		}
		if (Cj != TILE_COUNT_Y - 1)//������ ���� �ƴ϶�� �ϴ� ���� ���
		{
			if (tile[Ci + 1][Cj].walkable)//�ϴ� ��� Ÿ���� �̵������ϴٸ�
			{
				if (!tile[Ci + 1][Cj].listOn)
				{
					tile[Ci + 1][Cj].listOn = true;
					tile[Ci + 1][Cj].color = RGB(220, 255, 220);
					tile[Ci + 1][Cj].G = Cg + 10;
					tile[Ci + 1][Cj].parent = closeList[_lastIndex];
					openList.push_back(&tile[Ci + 1][Cj]);
				}
				else
				{
					if (Cg + 10 < tile[Ci + 1][Cj].G)
					{
						tile[Ci + 1][Cj].G = Cg + 10;
						tile[Ci + 1][Cj].parent = closeList[_lastIndex];
					}
				}
			}
			if (Ci != 0)//���ϴ� : 0��° ���� �ƴ϶��
			{
				//���ϴ� Ÿ���� �������̳� ���� ���� ���ٸ�
				if (tile[Ci + 1][Cj + 1].walkable && tile[Ci + 1][Cj].walkable && tile[Ci][Cj + 1].walkable)
				{
					if (!tile[Ci + 1][Cj + 1].listOn)
					{
						tile[Ci + 1][Cj + 1].listOn = true;
						tile[Ci + 1][Cj + 1].color = RGB(220, 255, 220);
						tile[Ci + 1][Cj + 1].G = Cg + diagonalWeight;
						tile[Ci + 1][Cj + 1].parent = closeList[_lastIndex];
						openList.push_back(&tile[Ci + 1][Cj + 1]);
					}
					else
					{
						if (Cg + 14 < tile[Ci + 1][Cj + 1].G)
						{
							tile[Ci + 1][Cj + 1].G = Cg + diagonalWeight;
							tile[Ci + 1][Cj + 1].parent = closeList[_lastIndex];
						}
					}
				}
			}
			if (Ci != TILE_COUNT_X - 1)//���ϴ� :������ ���� �ƴ϶��
			{
				//���ϴ� Ÿ���� �������̳� ���� �̵������ϴٸ�
				if (tile[Ci + 1][Cj - 1].walkable && tile[Ci][Cj - 1].walkable && tile[Ci + 1][Cj].walkable)
				{
					if (!tile[Ci + 1][Cj - 1].listOn)
					{
						tile[Ci + 1][Cj - 1].listOn = true;
						tile[Ci + 1][Cj - 1].color = RGB(220, 255, 220);
						tile[Ci + 1][Cj - 1].G = Cg + diagonalWeight;
						tile[Ci + 1][Cj - 1].parent = closeList[_lastIndex];
						openList.push_back(&tile[Ci + 1][Cj - 1]);
					}
					else
					{
						if (Cg + 14 < tile[Ci + 1][Cj - 1].G)
						{
							tile[Ci + 1][Cj - 1].G = Cg + diagonalWeight;
							tile[Ci + 1][Cj - 1].parent = closeList[_lastIndex];
						}
					}
				}
			}
		}
	}
}

void park::caculateH()
{
	for (size_t i = 0; i < openList.size(); i++)
	{
		int vertical = (endX - openList[i]->i) * 10;//����H
		int horizontal = (endY - openList[i]->j) * 10;//����H

		if (vertical < 0)vertical *= -1;
		if (horizontal < 0)horizontal *= -1;

		openList[i]->H = vertical + horizontal;
	}
}

void park::caculateF()
{
	for (size_t i = 0; i < openList.size(); i++)
	{
		openList[i]->F = openList[i]->G + openList[i]->H;
	}
}

void park::addCloseList()
{
	if (openList.size() == 0)
	{
		_astarState = ASTAR_STATE::ASTAR_STATE_NOWAY;
		return;
	}
	int index = 0;
	int lowest = BIGNUM;

	for (size_t i = 0; i < openList.size(); i++)
	{
		if (openList[i]->F < lowest)
		{
			lowest = openList[i]->F;
			index = i;
		}
	}

	openList[index]->color = RGB(180, 180, 255);
	closeList.push_back(openList[index]);
	openList.erase(openList.begin() + index);//���� ����Ʈ�� �߰��� Ÿ���� ���¸���Ʈ���� ����
	_lastIndex++;//���� ���߿� �߰��� Ŭ������ �ε���
}

void park::checkArrive()
{
	//Ŭ���� ����Ʈ�� i,j�� ���������� ���ٸ�
	if (closeList[_lastIndex]->i == endX && closeList[_lastIndex]->j == endY)
	{
		_astarState = ASTAR_STATE::ASTAR_STATE_FOUND;
		closeList[_lastIndex]->color = RGB(255, 100, 100);
		showWay(closeList[_lastIndex]);
	}
}

void park::showWay(Tile* tile)
{
	if (!(tile->i == endX && tile->j == endY))//���������� �ƴ϶��
	{
		tile->color = RGB(255, 180, 180);
	}

	trackReverse.push_back(tile);

	tile = tile->parent;	//Ÿ���� �θ� �����ؼ� showWay�Լ��� �ٽ� �ִ´�.

	if (tile->parent == NULL)
		return;
	else
		showWay(tile);
}

void park::typeColor(TILE_TYPE type)
{
	switch (type)
	{
	case TILE_TYPE::TILE_TYPE_EMPTY:_selectedTypeColor = RGB(255, 255, 255); break;
	case TILE_TYPE::TILE_TYPE_START:_selectedTypeColor = RGB(100, 255, 100); break;
	case TILE_TYPE::TILE_TYPE_END:_selectedTypeColor = RGB(255, 0, 0); break;
	case TILE_TYPE::TILE_TYPE_WALL:_selectedTypeColor = RGB(255, 255, 0); break;
	}
}

void park::aStarInit()
{
	startX = _player->getPlayerX();
	startY = _player->getPlayerY();

	for (size_t i = 0; i < TILE_COUNT_X; i++)
	{
		for (size_t j = 0; j < TILE_COUNT_Y; j++)
		{
			tile[i][j].isClick = false;

			tile[i][j].type = TILE_TYPE::TILE_TYPE_EMPTY;
			tile[i][j].color = RGB(255, 255, 255);
			tile[i][j].parent = NULL;
			tile[i][j].F = BIGNUM;
			tile[i][j].H = 0;
			tile[i][j].i = i;
			tile[i][j].j = j;
			tile[i][j].isLeftClick = false;
		}
	}

	for (size_t i = 0; i < TILE_COUNT_X; i++)
	{
		for (size_t j = 0; j < TILE_COUNT_Y; j++)
		{
			for (int z = 0; z <= _tileMap[i][j].index; z++)
			{
				if (_tileMap[i][j].tileKind[z] != TILEKIND::TILEKIND_NONE)
				{
					switch (_tileMap[i][j].tileNum[z])
					{
					case 0://desert.
					case 1://grass.
					case 4://�ܵ�.
						break;
					case 2://sign.
					case 3://tree.
						tile[i][j].type = TILE_TYPE::TILE_TYPE_WALL;
						break;
					}
				}
			}//z end.
		}//j end.
	}//i end.
	_playerTurn = true;

	_astarState = ASTAR_STATE::ASTAR_STATE_END;//�ʱ���� = Ÿ�Ϲ�ġ �Ϸ���
	_selectType = TILE_TYPE::TILE_TYPE_EMPTY;//��ġ�� Ÿ�� �Ӽ� = ��Ÿ��
	_selectedTypeColor = RGB(255, 255, 255);//��ġ�� Ÿ�� ���� = �Ͼ�

	_startPointSet = false;
	_endPointSet = false;

	openList.clear();
	closeList.clear();
	trackReverse.clear();
}

void park::pnpoly_leftClick()
{
	int nvert = 4;

	for (size_t i = 0; i < TILE_COUNT_X; i++)
	{
		for (size_t j = 0; j < TILE_COUNT_Y; j++)
		{
			//polygon x��
			vertX[i][j].x[0] = tile[i][j].pt[0].x;
			vertX[i][j].x[1] = tile[i][j].pt[1].x;
			vertX[i][j].x[2] = tile[i][j].pt[2].x;
			vertX[i][j].x[3] = tile[i][j].pt[3].x;

			//polygon y��
			vertY[i][j].y[0] = tile[i][j].pt[0].y;
			vertY[i][j].y[1] = tile[i][j].pt[1].y;
			vertY[i][j].y[2] = tile[i][j].pt[2].y;
			vertY[i][j].y[3] = tile[i][j].pt[3].y;
		}
	}

	int testx = m_ptMouse.x;
	int testy = m_ptMouse.y;

	for (size_t k = 0; k < TILE_COUNT_X; k++)
	{
		for (size_t r = 0; r < TILE_COUNT_Y; r++)
		{
			int i, j, c = 0;
			for (i = 0, j = nvert - 1; i < nvert; j = i++) {
				if (((vertY[k][r].y[i] > testy) != (vertY[k][r].y[j] > testy)) &&
					(testx < (vertX[k][r].x[j] - vertX[k][r].x[i]) * (testy - vertY[k][r].y[i]) / (vertY[k][r].y[j] - vertY[k][r].y[i]) + vertX[k][r].x[i]))
					c = !c;
			}

			tile[k][r].isLeftClick = c;
		}
	}
}

void park::getTrack()
{
	TCHAR str[20];
	int height = 1;

	RECT rc = RectMake(200, 20, 50, 300);
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	vector<Tile*>::iterator iter;

	iter = trackReverse.end();
	for (iter; iter != trackReverse.begin(); )
	{
		--iter;
		track.push_back((*iter));
		wsprintf(str, "%d , %d", (*iter)->i, (*iter)->j);
		TextOut(getMemDC(), 200, 20 * height, str, lstrlen(str));
		height++;
	}
}

void park::move()
{
	TCHAR str[20];
	int height = 1;

	//�ִϸ��̼� ���� �ѹ���.
	//static bool firstMove_up = 1;
	//static bool firstMove_down = 1;
	//static bool firstMove_left = 1;
	//static bool firstMove_right = 1;

	vector<Tile*>::iterator Iter;

	if (!(track.empty()))
	{
		Iter = track.begin();

		float num = 15; //�ε��� �þ������ movement ��. 
		int startX_num = 6;
		int startY_num = 3;
		int moveX = 6;
		int moveY = 3;

		//if (_player->getIndexX() != (*Iter)->i || _player->getIndexY() != (*Iter)->j)
		_player->setImg(IMAGE->findImage("��_�̵�"));

		/*
		else //���������� �������� ��.
		{
			_player->setImg(IMAGE->findImage("��_idle"));

			if (isLeft) { _player->getImg()->setFrameY(0); }
			else if (isRight) { _player->getImg()->setFrameY(3); }
			else if (isUp) { _player->getImg()->setFrameY(2); }
			else if (isDown) { _player->getImg()->setFrameY(1); }

			m_count++;

			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;

				if (m_index >= 3)
				{
					m_index = 0;
				}
				_player->getImg()->setFrameX(m_index);
			}
		}
		*/


		if (_player->getIndexX() < (*Iter)->i)
		{
			isLeft = false;
			isRight = false;
			isUp = false;
			isDown = true;

			static float movement = 0;

			m_count++;
			_player->getImg()->setFrameY(1);

			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;

				if (m_index >= 4)
				{
					m_index = 0;
				}
				_player->getImg()->setFrameX(m_index);
			}
			//if (firstMove_down)
			//{
			//	_player->setAnimation("R_moveDown");
			//	ANIMATION->start("R_moveDown");
			//	firstMove_down = 0;
			//}
			_player->setPlayerX(_player->getPlayerX() + moveX);
			_player->setPlayerY(_player->getPlayerY() + moveY);
			movement += 1.414 * moveY;

			if (movement > 15)
			{
				_player->setIndexX(_player->getIndexX() + 1);
				movement = 0;
				_startX -= startX_num;
				_startY -= startY_num;
				track.erase(track.begin());
			}
		}
		else if (_player->getIndexX() > (*Iter)->i)
		{
			isLeft = false;
			isRight = false;
			isUp = true;
			isDown = false;

			static int movement = 0;

			m_count++;
			_player->getImg()->setFrameY(2);


			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;

				if (m_index >= 4)
				{
					m_index = 0;
				}
				_player->getImg()->setFrameX(m_index);
			}

			//if (firstMove_up)
			//{
			//	_player->setAnimation("R_moveUp");
			//	ANIMATION->start("R_moveUp");
			//	firstMove_up = 0;
			//}
			_player->setPlayerX(_player->getPlayerX() - moveX);
			_player->setPlayerY(_player->getPlayerY() - moveY);
			movement += 1.414 * moveY;

			if (movement > 15)
			{
				_player->setIndexX(_player->getIndexX() - 1);
				movement = 0;
				_startX += startX_num;
				_startY += startY_num;
				track.erase(track.begin());
			}
		}
		else if (_player->getIndexY() < (*Iter)->j)
		{
			isLeft = true;
			isRight = false;
			isUp = false;
			isDown = false;

			static int movement = 0;

			m_count++;
			_player->getImg()->setFrameY(0);


			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;

				if (m_index >= 4)
				{
					m_index = 0;
				}
				_player->getImg()->setFrameX(m_index);
			}

			//if (firstMove_left)
			//{
			//	_player->setAnimation("R_moveLeft");
			//	ANIMATION->start("R_moveLeft");
			//	firstMove_left = 0;
			//}
			_player->setPlayerX(_player->getPlayerX() - moveX);
			_player->setPlayerY(_player->getPlayerY() + moveY);
			movement += 1.414 * moveY;

			if (movement > 15)
			{
				_player->setIndexY(_player->getIndexY() + 1);
				movement = 0;
				_startX += startX_num;
				_startY -= startY_num;
				track.erase(track.begin());
			}
		}
		else if (_player->getIndexY() > (*Iter)->j)
		{
			isLeft = false;
			isRight = true;
			isUp = false;
			isDown = false;

			static int movement = 0;

			m_count++;
			_player->getImg()->setFrameY(3);


			if (m_count % 5 == 0)
			{
				m_count = 0;
				m_index++;

				if (m_index >= 4)
				{
					m_index = 0;
				}
				_player->getImg()->setFrameX(m_index);
			}

			//if (firstMove_right)
			//{
			//	_player->setAnimation("R_moveRight");
			//	ANIMATION->start("R_moveRight");
			//	firstMove_right = 0;
			//}
			_player->setPlayerX(_player->getPlayerX() + moveX);
			_player->setPlayerY(_player->getPlayerY() - moveY);
			movement += 1.414 * moveY;

			if (movement > 15)
			{
				_player->setIndexY(_player->getIndexY() - 1);
				movement = 0;
				_startX -= startX_num;
				_startY += startY_num;
				track.erase(track.begin());
			}
		}
		player_x = _player->getPlayerX();
		player_y = _player->getPlayerY();

		//firstMove_up = 1;
		//firstMove_down = 1;
		//firstMove_left = 1;
		//firstMove_right = 1;

		aStarInit();
	}
	else
	{
		_player->setImg(IMAGE->findImage("��_idle"));

		if (isLeft) { _player->getImg()->setFrameY(0); }
		else if (isRight) { _player->getImg()->setFrameY(3); }
		else if (isUp) { _player->getImg()->setFrameY(1); }
		else if (isDown) { _player->getImg()->setFrameY(2); }

		m_count++;

		if (m_count % 5 == 0)
		{
			m_count = 0;
			m_index++;

			if (m_index >= 3)
			{
				m_index = 0;
			}
			_player->getImg()->setFrameX(m_index);
		}
		_player->setPlayerX(player_x);
		_player->setPlayerY(player_y);

		if (tile[_player->getIndexX()][_player->getIndexY()].isCoin_exist == true)
		{
			tile[_player->getIndexX()][_player->getIndexY()].isCoin_exist = false;

			money += 20;
			startTime_coin = TIME->getWorldTime();
		}//if end.
		else if (tile[_player->getIndexX()][_player->getIndexY()].isCoins_exist == true)
		{
			tile[_player->getIndexX()][_player->getIndexY()].isCoins_exist = false;

			money += 100;
			startTime_coins = TIME->getWorldTime();
		}
	}
	endTime = TIME->getWorldTime();
}

void park::initialization()
{
	_isoX = 0;
	_isoY = 0;
	_center = 0;

	_startX = INIT_X;
	_startY = INIT_Y;

	_isDebug = false;
	_isIndex = false;

	//Ÿ�� Ŭ�� �ν�.
	startX = INIT_X;
	startY = INIT_Y;

	firstFloor = false;
	secondFloor = false;
	thirdFloor = false;

	_playerTurn = true;

	isFirst = true;

	//����.
	town_active = false;

	//�÷��̾�.
	SAFE_DELETE(_player);
	_player = new Player;
	_player->init();

	player_x = WINSIZEX / 2;
	player_y = WINSIZEY / 2;

	m_count = 0;
	m_index = 0;

	_player->getImg()->setFrameY(0);
	_player->getImg()->setFrameX(0);

	isRight = false;
	isLeft = true;
	isUp = false;
	isDown = false;
}


//�߰���
void park::lightGrayDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(220, 220, 220));
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	FillRect(getMemDC(), &rc, brush);
	DeleteObject(brush);
}
void park::shadowDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(051, 051, 051));
	RECT shadow = RectMake(rc.left + 3, rc.top + 3, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), shadow.left, shadow.top, shadow.right, shadow.bottom);
	FillRect(getMemDC(), &shadow, brush);
	DeleteObject(brush);
}
void park::lightDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	RECT light = RectMake(rc.left - 1, rc.top - 1, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
	FillRect(getMemDC(), &light, brush);
	DeleteObject(brush);
}
