#pragma once
#include"gameNode.h"
#include"IsoTile.h"
class IsoMap : public gameNode
{
private:

	TagTile _tileMap[TILE_COUNT_X][TILE_COUNT_Y];
	TagTile TileMap[TILE_COUNT_X * TILE_COUNT_Y]; // 파일에서 저장하고 불러오기 위한 것.

	int _isoX, _isoY;
	int _center;
	char str[128];


	int _startX;
	int _startY;

	POINT imageFrame;
	CTRL _currentCTRL;


	bool _isDebug;
public:
	IsoMap();
	~IsoMap();

	HRESULT init();
	void release();
	void update();
	void render();

	//타일맵 그리자.
	void DrawTileMap();

	//마름모를 그리자
	void DrawRhombus(int left, int top);
	//코너검출(1~4분면)
	int GetCornerIndex(int isoX, int isoY);

	//마름모 안에 있음?
	bool IsInRhombus(int corner, int isoX, int isoY);

	void MapToolSetup();
	void setMap(int isoX, int isoY, bool isAdd);
	TILEKIND kindSelect(int frameX, int frameY);


	void TlieInit();
	void Load();
	void Save();

};


