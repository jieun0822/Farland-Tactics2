#pragma once
#include"framework.h"
//크기
#define CELL_WIDTH 62
#define CELL_HEIGHT 30

#define RADIUS_WIDTH (CELL_WIDTH / 2)
#define RADIUS_HEIGHT (CELL_HEIGHT / 2)
//초기좌표
#define INIT_X 400
#define INIT_Y -290
//타일 갯수
#define TILE_COUNT_X 50
#define TILE_COUNT_Y 50

//타일 이미지
#define TILE_SIZE_X 1
#define TILE_SIZE_Y 1


#define TILE_MAX 10
enum class TILEKIND
{
	TILEKIND_OBJECT,
	TILEKIND_TERRAIN,
	TILEKIND_NONE
};

struct TagTile
{
	int left, top;

	int index;

	int tileNum[TILE_MAX];
	TILEKIND tileKind[TILE_MAX];
	POINT tilePos[TILE_MAX];


	int height;
};