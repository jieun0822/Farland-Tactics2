#pragma once
#include"gameNode.h"
#include"IsoTile.h"
#include"Player.h"
#define BIGNUM 5000 
//타일 속성
enum class TILE_TYPE
{
	TILE_TYPE_EMPTY,	//빈타일 (지나갈수 있는곳)
	TILE_TYPE_START,	//시작지점
	TILE_TYPE_END,		//끝지점
	TILE_TYPE_WALL		//벽
};
enum class ASTAR_STATE
{
	ASTAR_STATE_SEARCHING,//검색중
	ASTAR_STATE_FOUND,	//발견!
	ASTAR_STATE_NOWAY,	//길없음
	ASTAR_STATE_END

};

struct  Tile
{
	int x;
	int y;

	int index_x;
	int index_y;

	POINT pt[4];
	RECT rc;

	bool isClick;

	COLORREF color;
	bool walkable;		//지나갈수 있냐	
	bool listOn;		//openList에 추가되었는지 여부
	int i, j;
	int F, G, H;
	char str[128];
	Tile* parent;	//부모 타일 주소
	TILE_TYPE type;		//타일속성

	bool isRightClick;
	bool isLeftClick;

	bool isCoin_exist;
	bool isCoins_exist;
};

struct vertx
{
	int x[4];
};

struct verty
{
	int y[4];
};

class park : public gameNode
{
private:
	/////////////////////////타일 클릭 인식
	Tile** tile;
	vertx vertX[TILE_COUNT_X][TILE_COUNT_Y];
	verty vertY[TILE_COUNT_X][TILE_COUNT_Y];

	bool _isDebug;
	bool _isIndex;

	vector<Tile*> openList;
	vector<Tile*> closeList;
	vector<Tile*> trackReverse;
	vector<Tile*> track;

	ASTAR_STATE _astarState;
	TILE_TYPE _selectType;
	COLORREF _selectedTypeColor;

	int startX, startY;
	int endX, endY;
	int _lastIndex;	//나중에 추가된 클로즈 리스트의 인덱스

	bool _startPointSet;
	bool _endPointSet;

	int Ci;
	int Cj;
	int Cg;

	///////////////////////////////////////

	TagTile _tileMap[TILE_COUNT_X][TILE_COUNT_Y];
	TagTile TileMap[TILE_COUNT_X * TILE_COUNT_Y]; // 파일에서 저장하고 불러오기 위한 것.

	int _isoX, _isoY;
	int _center;
	char str[128];

	int _startX;
	int _startY;

	POINT imageFrame;

	bool firstFloor;
	bool secondFloor;
	bool thirdFloor;

	bool isFirst;//처음시작.

	//마을.
	RECT townButton;
	bool town_active;

	//플레이어
	Player* _player;
	bool _playerTurn;
	int player_x;
	int player_y;

	bool isRight;
	bool isLeft;
	bool isUp;
	bool isDown;

	int m_count;
	int m_index;

	int money;
	float startTime_coin;
	float startTime_coins;
	float endTime;
public:
	park();
	~park();

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

	void TlieInit();
	void Load();

	//타일 클릭 인식
	void pnpoly();

	void playerMemoryLink(Player* player) { _player = player; }

	void tileComposition();//배치
	void tileInitializing();//배치후 속성에 맞게 초기화
	void addOpenList();	//오픈리스트 추가
	void caculateH();		//오픈리스트내 타일 H값 계산
	void caculateF();		//오픈리스트내 타일 F값 계산
	void addCloseList();	//가장 작은 F선택후 클로즈 리스트에 추가
	void checkArrive();	//도착했는지 여부 체크
	void showWay(Tile* tile);//도착후 시작지점과 도착지점을 잇는 경로 보여주자
	void typeColor(TILE_TYPE type);

	//타일 클릭 인식
	void aStarInit();

	void pnpoly_leftClick();

	void getTrack();
	void move();

	//마을.
	bool getTown_active() const { return town_active; }
	void setTown_active(int active) { town_active = active; }

	void initialization();

	//그리기.
	//추가쓰
	void lightGrayDraw(RECT rc);
	void shadowDraw(RECT rc);
	void lightDraw(RECT rc);
};