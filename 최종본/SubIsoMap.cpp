#include "framework.h"
#include "SubIsoMap.h"

SubIsoMap::SubIsoMap()
{
}


SubIsoMap::~SubIsoMap()
{
}

HRESULT SubIsoMap::init()
{
	for (int i = 0; i < TILE_SIZE_X; i++)
	{
		for (int j = 0; j < TILE_SIZE_Y; j++)
		{
			rc[i][j] = RectMake(
				SUBWINSIZEX / TILE_SIZE_X * i,
				300 / TILE_SIZE_Y * j + 200,
				SUBWINSIZEX / TILE_SIZE_X, 300 / TILE_SIZE_Y);
		}
	}


	isDebug = false;

	return S_OK;
}

void SubIsoMap::release()
{
}

void SubIsoMap::update()
{
	if (SUBWIN->GetIsActive() && InputManager->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < TILE_SIZE_Y; i++)
		{
			for (int j = 0; j < TILE_SIZE_X; j++)
			{
				if (PtInRect(&rc[j][i], SUBWIN->GetMousePos()))
				{
					SUBWIN->SetFramePoint(PointMake(j, i));
				}
			}
		}
	}

	if (InputManager->isOnceKeyDown(VK_SHIFT))
		isDebug = !isDebug;
}

void SubIsoMap::render(HDC hdc)
{

	switch (SUBWIN->GetFrameIndex())
	{
	case 0:
		IMAGE->findImage("_1")->render(hdc, 0, 200, 64, 48);
		break;
	case 1:
		IMAGE->findImage("_2")->render(hdc, 0, 200, 64, 48);
		break;
	case 2:
		IMAGE->findImage("_3")->render(hdc, 0, 200, 48, 67);
		break;
	case 3:
		IMAGE->findImage("tree")->render(hdc, 0, 200, 64, 131);
		break;
	case 4:
		IMAGE->findImage("grass1")->render(hdc, 0, 200, 64, 56);
		break;
	}//end of switch

	if (isDebug)
	{
		for (int i = 0; i < TILE_SIZE_X; i++)
		{
			for (int j = 0; j < TILE_SIZE_Y; j++)
			{
				RectangleMake(hdc, rc[i][j]);
			}
		}
	}
}
