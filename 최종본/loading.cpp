#include"framework.h"
#include "loading.h"
loadItem::loadItem()
{
}

loadItem::~loadItem()
{
}

HRESULT loadItem::initForImage(string keyName, int width, int height)
{
	_kind = LOAD_KIND::LOAD_KIND_IMAGE_0;


	memset(&_imageResource, 0, sizeof(tagImageResource));
	_imageResource.keyName = keyName;
	_imageResource.width = width;
	_imageResource.height = height;

	return S_OK;
}

HRESULT loadItem::initForImage(string keyName, const char* fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{


	_kind = LOAD_KIND::LOAD_KIND_IMAGE_1;


	memset(&_imageResource, 0, sizeof(tagImageResource));
	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;
	return S_OK;
}

HRESULT loadItem::initForImage(string keyName, const char* fileName, float x, float y, int width, int height, BOOL isTrans, COLORREF transColor)
{

	_kind = LOAD_KIND::LOAD_KIND_IMAGE_2;


	memset(&_imageResource, 0, sizeof(tagImageResource));
	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;
	return S_OK;
}

HRESULT loadItem::initForFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL isTrans, COLORREF transColor)
{



	_kind = LOAD_KIND::LOAD_KIND_FRAMEIMAGE_0;


	memset(&_imageResource, 0, sizeof(tagImageResource));
	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;


	return S_OK;
}

HRESULT loadItem::initForFrameImage(string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL isTrans, COLORREF transColor)
{

	_kind = LOAD_KIND::LOAD_KIND_FRAMEIMAGE_1;


	memset(&_imageResource, 0, sizeof(tagImageResource));
	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;
	_imageResource.trans = isTrans;
	_imageResource.transColor = transColor;

	return S_OK;
}

loading::loading()
{
}

loading::~loading()
{
}

HRESULT loading::init()
{
	//��Ʈ ���ҽ�.
	AddFontResource("font/THEHappyfruit.ttf");
	AddFontResource("font/OdBestFreind.ttf");

	_background = IMAGE->addImage("�ε�ȭ��", "images/�ε�ȭ��.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));


	_loadingBar = new progressBar;
	_loadingBar->init("images/bar.bmp", "images/bar.bmp", 180, WINSIZEY / 2 + 200, 600, 20);
	_loadingBar->setGauge(0, 0);
	_currentGauge = 0;

	activeTime = 0;
	barOutline = RectMake(165, WINSIZEY / 2 + 200 - 10, 630, 40);

	return S_OK;
}

void loading::release()
{
	SAFE_DELETE(_loadingBar);
}

void loading::update()
{
	activeTime++;
	_loadingBar->update();
}

void loading::render()
{
	HBRUSH brush;
	HBRUSH oldBrush;
	HPEN pen;
	HPEN oldPen;

	_background->render(getMemDC());

	HFONT font, oldfont;

	//font = CreateFont(40, 0, 0, 0, FW_LIGHT, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, "THEHappyfruit");
	font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
	oldfont = (HFONT)SelectObject(getMemDC(), font);
	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	TCHAR str[50];
	if (activeTime <= 170)
	{
		wsprintf(str, "���� �ſ� �������ϴ�.");
		TextOut(getMemDC(), 390, 535, str, lstrlen(str));
	}
	else if (activeTime > 170 && activeTime <= 380)
	{
		wsprintf(str, "��ī���̸� �湮�ϸ� ������ �ö󰩴ϴ�.");
		TextOut(getMemDC(), 270, 535, str, lstrlen(str));
	}
	else
	{
		wsprintf(str, "�������� ��å�� �� �� �ֽ��ϴ�.");
		TextOut(getMemDC(), 320, 535, str, lstrlen(str));
	}

	SetTextColor(getMemDC(), RGB(0, 0, 0));
	SelectObject(getMemDC(), oldfont);
	DeleteObject(font);

	brush = (HBRUSH)::GetStockObject(NULL_BRUSH); // ���� �귯��
	oldBrush = (HBRUSH)::SelectObject(getMemDC(), brush); // �귯�� ����
	pen = CreatePen(PS_DOT, 3, RGB(255, 255, 255)); // �� ��Ÿ��, ����, ����
	oldPen = (HPEN)::SelectObject(getMemDC(), (HGDIOBJ)pen); // �� ����

	Rectangle(getMemDC(), barOutline.left, barOutline.top, barOutline.right, barOutline.bottom);

	pen = (HPEN)::SelectObject(getMemDC(), oldPen); // ���� �� ����
	::DeleteObject(pen); // ������ �� ����
	brush = (HBRUSH)::SelectObject(getMemDC(), oldBrush); // ���� �귯�� ����
	::DeleteObject(brush); // ������ �귯�� ����

	_loadingBar->loadingRender();
}

void loading::loadImage(string keyName, int width, int height)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, width, height);
	_vLoadItem.push_back(item);
}

void loading::loadImage(string keyName, const char* fileName, int width, int height, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, fileName, width, height, isTrans, transColor);
	_vLoadItem.push_back(item);
}

void loading::loadImage(string keyName, const char* fileName, float x, float y, int width, int height, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, fileName, x, y, width, height, isTrans, transColor);
	_vLoadItem.push_back(item);
}

void loading::loadForFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForFrameImage(keyName, fileName, width, height, frameX, frameY, isTrans, transColor);
	_vLoadItem.push_back(item);
}

void loading::loadForFrameImage(string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL isTrans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForFrameImage(keyName, fileName, x, y, width, height, frameX, frameY, isTrans, transColor);
	_vLoadItem.push_back(item);
}

BOOL loading::loadingDone()
{

	if (_currentGauge >= _vLoadItem.size())
	{
		return TRUE;
	}
	loadItem* item = _vLoadItem[_currentGauge];
	tagImageResource img = item->getImageResource();



	switch (item->getLoadKind())
	{
	case LOAD_KIND::LOAD_KIND_IMAGE_0:
		IMAGE->addImage(img.keyName, img.width, img.height);
		break;
	case LOAD_KIND::LOAD_KIND_IMAGE_1:
		IMAGE->addImage(img.keyName, img.fileName, img.width, img.height, img.trans, img.transColor);
		break;
	case LOAD_KIND::LOAD_KIND_IMAGE_2:
		IMAGE->addImage(img.keyName, img.fileName, img.x, img.y, img.width, img.height, img.trans, img.transColor);
		break;
	case LOAD_KIND::LOAD_KIND_FRAMEIMAGE_0:
		IMAGE->addFrameImage(img.keyName, img.fileName, img.width, img.height, img.frameX, img.frameY, img.trans, img.transColor);
		break;
	case LOAD_KIND::LOAD_KIND_FRAMEIMAGE_1:
		IMAGE->addFrameImage(img.keyName, img.fileName, img.x, img.y, img.width, img.height, img.frameX, img.frameY, img.trans, img.transColor);
		break;
	case LOAD_KIND::LOAD_KIND_SOUND:
		break;
	}

	_loadingBar->setGauge(_currentGauge, _vLoadItem.size());
	_currentGauge++;
	return 0;
}
