#include "framework.h"
#include "loadiingTest.h"

loadiingTest::loadiingTest()
{
}

loadiingTest::~loadiingTest()
{
}

HRESULT loadiingTest::init()
{

	_loading = new loading;
	_loading->init();
	this->totalLoading();

	isDone=false;

	return S_OK;
}

void loadiingTest::release()
{
	SAFE_DELETE(_loading);
}

void loadiingTest::update()
{
	_loading->update();

	if (_loading->loadingDone())
	{
		isDone = true;
	}
}

void loadiingTest::render()
{
	_loading->render();
}

void loadiingTest::totalLoading()
{
	for (size_t i = 0; i < 500; i++)
	{
		_loading->loadImage("1", WINSIZEX, WINSIZEY);
	}
}

void loadiingTest::initialization()
{
	SAFE_DELETE(_loading);
	_loading = new loading;
	_loading->init();
	_loading->setActiveTime(0);
}
