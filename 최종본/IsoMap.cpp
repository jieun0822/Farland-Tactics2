#include"framework.h"
#include "IsoMap.h"

IsoMap::IsoMap()
{
}

IsoMap::~IsoMap()
{
}

HRESULT IsoMap::init()
{
	_isoX = 0;
	_isoY = 0;
	_center = 0;
	memset(_tileMap, 0, sizeof(_tileMap));

	_startX = INIT_X;
	_startY = INIT_Y;

	_isDebug = true;
	_currentCTRL = CTRL::CTRL_DRAW;

	MapToolSetup();

	return S_OK;
}

void IsoMap::release()
{
}

void IsoMap::update()
{

	if (InputManager->isStayKeyDown('W')) { _startY += 5; }
	if (InputManager->isStayKeyDown('S')) { _startY -= 5; }
	if (InputManager->isStayKeyDown('A')) { _startX += 5; }
	if (InputManager->isStayKeyDown('D')) { _startX -= 5; }

	if (InputManager->isOnceKeyDown(VK_TAB))
	{
		_isDebug = !_isDebug;
	}

	if (!SUBWIN->GetIsActive() && InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		float cellX = static_cast<float>(m_ptMouse.x - _startX);

		if (cellX < 0)
		{
			cellX = (cellX - CELL_WIDTH) / static_cast<float>(CELL_WIDTH);
		}
		else
		{
			//��ŭ �������� Ŭ���ߴ°��� ��ġȭ(�������� ����)
			cellX = cellX / static_cast<float>(CELL_WIDTH);
		}

		//cellY�� -������ ���� ������(�������� ���� ��)���밪���� ������
		int cellY = abs(m_ptMouse.y - _startY) / CELL_HEIGHT;
		//���� -������ �ڤ�ü�� -�̸� -1�� ��������
		cellY = (m_ptMouse.y < _startY) ? cellY * -1 : cellY;
		//x�� y�� �������� ����� ������ �۾����� �Ѵ�.
		//������ �̱� ������ x���� y�Ǳ��ذ����κ��� �ָ� ���������� x���� Ŀ����.
		int isoX = static_cast<int>(cellX) + static_cast<int>(cellY);
		//y���� x���ذ����� ���� �ָ� ���������� y�� �þ�� �ȴ�.
		int isoY = static_cast<int>(cellY) - static_cast<int>(cellX);
		/*
		//���� x��ǥ�� 0���� ũ�� �ִ�Ÿ�ϼ� ���� �۰�
		//Y��ǥ 0���� ũ��, �ִ�Ÿ�ϼ����� ������ ������ �������
		*/
		if (isoX >= 0 && isoX < TILE_COUNT_X && isoY >= 0 && isoY < TILE_COUNT_Y)
		{

			//1�и��̸�[x - 1][y]
			//2�и��̸�[x][y - 1]
			//3�и��̸�[x1][y + 1]
			//4�и��̸�[x + 1][y]

			//�ڳ� ����(��� �и鿡 ��������)
			int corner = GetCornerIndex(isoX, isoY);
			// ����Ǿ��µ�, �װ� ������ȿ� �ִ��� Ȯ��
			/*
			//���� �� �ִٸ� ������ isoX, isoY�� �ǵ� �ʿ� ����
			//������ �ȿ� �� �ֱ� ������ ����ó���� �� �ʿ䰡 ����
			//���� �� ���� false�� �Ǿ��ٸ� ���ҹǰ� �ƴ� �� �ۿ� �����ٴ� ���� �ǹǷ�
			//�ٸ� Ÿ���� �����ٴ� ���� �ǰ� �ű⿡ ���� ����ó���� �ؿ��� ���ָ� �ȴ�.

			*/
			if (IsInRhombus(corner, isoX, isoY))corner = 0;

			//���� 1/4�и鿡�� ������ �ȿ� ������ �ƴ϶�� �� ���� ������ ������ �ȴ�.
			switch (corner)
			{
			case 1:
				isoX = isoX - 1;//�������� 4���߿� ���� ������ �´�� �ִ� ������� x������ �Ѵܰ� �������� ��ǥ��.
				break;
			case 2:
				isoY = isoY - 1;
				break;
			case 3:
				isoY = isoY + 1;
				break;
			case 4:
				isoX = isoX + 1;
				break;
			}

			setMap(isoX, isoY, true);

			_center = corner;
			_isoX = isoX;
			_isoY = isoY;
		}
	}

	int index = SUBWIN->GetFrameIndex();

	switch (SUBWIN->GetFrameIndex())
	{
	case 9:
		Save();
		break;
	case 10:
		Load();
		break;
	}
}

void IsoMap::render()
{
	//sprintf_s(str, "isoX : %d, isoY : %d, corner : %d",
	//	_isoX, _isoY, _center);
	//TextOut(getMemDC(), 50, 300, str, strlen(str));

	DrawTileMap();
}

void IsoMap::DrawTileMap()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			int left = _startX + (i * RADIUS_WIDTH) - (j * RADIUS_WIDTH);
			int top = _startY + (i * RADIUS_HEIGHT) + (j * RADIUS_HEIGHT);

			_tileMap[i][j].left = left;
			_tileMap[i][j].top = top;

			for (int z = 0; z <= _tileMap[i][j].index; z++)
			{
				if (_tileMap[i][j].tileKind[z] != TILEKIND::TILEKIND_NONE)
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
						IMAGE->render("tree", getMemDC(),
							_tileMap[i][j].left,
							_tileMap[i][j].top - _tileMap[i][j].height * z - 90);
						break;
					case 4:
						IMAGE->render("grass1", getMemDC(),
							_tileMap[i][j].left,
							_tileMap[i][j].top - _tileMap[i][j].height * z - 8);
						break;
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

			if (_isDebug)
			{
				DrawRhombus(left, top);
				SetTextColor(getMemDC(), RGB(0, 0, 0));
				sprintf_s(str, "(%d,%d)", i, j);
				TextOut(getMemDC(),
					left + RADIUS_WIDTH / 2 + 8,
					top + RADIUS_HEIGHT / 2 + 5, str, strlen(str));
			}
		}
	}
}

void IsoMap::DrawRhombus(int left, int top)
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

int IsoMap::GetCornerIndex(int isoX, int isoY)
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

bool IsoMap::IsInRhombus(int corner, int isoX, int isoY)
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

void IsoMap::MapToolSetup()
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

void IsoMap::setMap(int isoX, int isoY, bool isAdd)
{
	int index = SUBWIN->GetFrameIndex();

	switch (SUBWIN->GetFrameIndex())
	{
	case 0:
		imageFrame = SUBWIN->GetFramePoint();
		break;
	case 1:
		imageFrame = SUBWIN->GetFramePoint();
		break;
	case 2:
		imageFrame = SUBWIN->GetFramePoint();
		break;
	case 3:
		imageFrame = SUBWIN->GetFramePoint();
		break;
	case 4:
		imageFrame = SUBWIN->GetFramePoint();
		break;

	}
	_currentCTRL = SUBWIN->GetCTRL();

	switch (_currentCTRL)
	{
	case CTRL::CTRL_DRAW:
		if (isAdd)
		{
			if (kindSelect(imageFrame.x, imageFrame.y) == TILEKIND::TILEKIND_OBJECT
				&& _tileMap[isoX][isoY].index == -1)
				break;

			_tileMap[isoX][isoY].index++;
			if (_tileMap[isoX][isoY].index >= TILE_MAX) _tileMap[isoX][isoY].index = TILE_MAX - 1;
			_tileMap[isoX][isoY].tileNum[_tileMap[isoX][isoY].index] = index;
			_tileMap[isoX][isoY].tileKind[_tileMap[isoX][isoY].index] = kindSelect(imageFrame.x, imageFrame.y);
			_tileMap[isoX][isoY].tilePos[_tileMap[isoX][isoY].index] = imageFrame;

		}
		else
		{
			if (kindSelect(imageFrame.x, imageFrame.y) == TILEKIND::TILEKIND_OBJECT)break;

			if (_tileMap[isoX][isoY].index == -1)
			{
				_tileMap[isoX][isoY].index++;

				if (_tileMap[isoX][isoY].index >= TILE_MAX)
				{
					_tileMap[isoX][isoY].index = TILE_MAX - 1;
				}
				_tileMap[isoX][isoY].tileNum[_tileMap[isoX][isoY].index] = index;
				_tileMap[isoX][isoY].tileKind[_tileMap[isoX][isoY].index] = kindSelect(imageFrame.x, imageFrame.y);
				_tileMap[isoX][isoY].tilePos[_tileMap[isoX][isoY].index] = imageFrame;
			}
		}
		break;
	case  CTRL::CTRL_ERASER:
		if (_tileMap[isoX][isoY].index > -1)
		{
			_tileMap[isoX][isoY].index--;
		}
		break;
	case CTRL::CTRL_SAVE:
		//Save();

		break;
	case CTRL::CTRL_LOAD:
		//Load();

		break;
	}
}

TILEKIND IsoMap::kindSelect(int frameX, int frameY)
{
	if (frameX == -1 && frameY == -1)return TILEKIND::TILEKIND_NONE;


	if (SUBWIN->GetFrameIndex() == 0 || SUBWIN->GetFrameIndex() == 1 || SUBWIN->GetFrameIndex() == 4)
	{
		return TILEKIND::TILEKIND_TERRAIN;
	}
	if (SUBWIN->GetFrameIndex() == 2 || SUBWIN->GetFrameIndex() == 3)
	{
		return TILEKIND::TILEKIND_OBJECT;
	}
	return TILEKIND::TILEKIND_TERRAIN;
}

void IsoMap::TlieInit()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			_tileMap[i][j].index = -1;
		}
	}
}

void IsoMap::Load()
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

void IsoMap::Save()
{
	HANDLE file;
	DWORD write;
	file = CreateFile("save/tileMap.map",
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	for (size_t i = 0; i < TILE_COUNT_X; i++)
	{
		for (size_t j = 0; j < TILE_COUNT_Y; j++)
		{
			TileMap[i * TILE_COUNT_Y + j] = _tileMap[i][j];
		}
	}

	WriteFile(file, TileMap, sizeof(TagTile) * TILE_COUNT_X * TILE_COUNT_Y, &write, NULL);
	//WriteFile(file, _pos, sizeof(int) * 2, &write, NULL);
	CloseHandle(file);
}

