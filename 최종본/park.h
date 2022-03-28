#pragma once
#include"gameNode.h"
#include"IsoTile.h"
#include"Player.h"
#define BIGNUM 5000 
//Ÿ�� �Ӽ�
enum class TILE_TYPE
{
	TILE_TYPE_EMPTY,	//��Ÿ�� (�������� �ִ°�)
	TILE_TYPE_START,	//��������
	TILE_TYPE_END,		//������
	TILE_TYPE_WALL		//��
};
enum class ASTAR_STATE
{
	ASTAR_STATE_SEARCHING,//�˻���
	ASTAR_STATE_FOUND,	//�߰�!
	ASTAR_STATE_NOWAY,	//�����
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
	bool walkable;		//�������� �ֳ�	
	bool listOn;		//openList�� �߰��Ǿ����� ����
	int i, j;
	int F, G, H;
	char str[128];
	Tile* parent;	//�θ� Ÿ�� �ּ�
	TILE_TYPE type;		//Ÿ�ϼӼ�

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
	/////////////////////////Ÿ�� Ŭ�� �ν�
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
	int _lastIndex;	//���߿� �߰��� Ŭ���� ����Ʈ�� �ε���

	bool _startPointSet;
	bool _endPointSet;

	int Ci;
	int Cj;
	int Cg;

	///////////////////////////////////////

	TagTile _tileMap[TILE_COUNT_X][TILE_COUNT_Y];
	TagTile TileMap[TILE_COUNT_X * TILE_COUNT_Y]; // ���Ͽ��� �����ϰ� �ҷ����� ���� ��.

	int _isoX, _isoY;
	int _center;
	char str[128];

	int _startX;
	int _startY;

	POINT imageFrame;

	bool firstFloor;
	bool secondFloor;
	bool thirdFloor;

	bool isFirst;//ó������.

	//����.
	RECT townButton;
	bool town_active;

	//�÷��̾�
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

	//Ÿ�ϸ� �׸���.
	void DrawTileMap();

	//������ �׸���
	void DrawRhombus(int left, int top);
	//�ڳʰ���(1~4�и�)
	int GetCornerIndex(int isoX, int isoY);

	//������ �ȿ� ����?
	bool IsInRhombus(int corner, int isoX, int isoY);

	void MapToolSetup();

	void TlieInit();
	void Load();

	//Ÿ�� Ŭ�� �ν�
	void pnpoly();

	void playerMemoryLink(Player* player) { _player = player; }

	void tileComposition();//��ġ
	void tileInitializing();//��ġ�� �Ӽ��� �°� �ʱ�ȭ
	void addOpenList();	//���¸���Ʈ �߰�
	void caculateH();		//���¸���Ʈ�� Ÿ�� H�� ���
	void caculateF();		//���¸���Ʈ�� Ÿ�� F�� ���
	void addCloseList();	//���� ���� F������ Ŭ���� ����Ʈ�� �߰�
	void checkArrive();	//�����ߴ��� ���� üũ
	void showWay(Tile* tile);//������ ���������� ���������� �մ� ��� ��������
	void typeColor(TILE_TYPE type);

	//Ÿ�� Ŭ�� �ν�
	void aStarInit();

	void pnpoly_leftClick();

	void getTrack();
	void move();

	//����.
	bool getTown_active() const { return town_active; }
	void setTown_active(int active) { town_active = active; }

	void initialization();

	//�׸���.
	//�߰���
	void lightGrayDraw(RECT rc);
	void shadowDraw(RECT rc);
	void lightDraw(RECT rc);
};