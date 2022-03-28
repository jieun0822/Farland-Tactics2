#include"framework.h"
#include "Window.h"
#include"gameNode.h"
#include"IsoMap.h"
POINT Window::ptMouse = POINT{ 0,0 };
CTRL Window::_currentCTRL = CTRL::CTRL_DRAW;
Window::Window()
{
	m_backBuffer = new image();
	m_backBuffer->init(SUBWINSIZEX, SUBWINSIZEY);
}

Window::~Window()
{
	SAFE_DELETE(m_backBuffer);
}

void Window::init()
{
	CreateSubWindow();

	isActive = false;

	int tempX = 10;

	_btnDraw = CreateWindow("button", "Tile",
		//자식으로 생성하면 안쪽에 만들어짐
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		tempX, 0, 100, 20, hWnd, HMENU(0), m_hInstance, NULL);
	_btnEraser = CreateWindow("button", "Eraser",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		tempX, 30, 100, 20, hWnd, HMENU(1), m_hInstance, NULL);
	_btnInit = CreateWindow("button", "Init",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		tempX, 60, 100, 20, hWnd, HMENU(2), m_hInstance, NULL);
	_btnSave = CreateWindow("button", "Save",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		tempX + 115, 0, 100, 20, hWnd, HMENU(3), m_hInstance, NULL);
	_btnLoad = CreateWindow("button", "Load",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		tempX + 115, 30, 100, 20, hWnd, HMENU(4), m_hInstance, NULL);
	_btnN1 = CreateWindow("button", "desert",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		tempX + 50, 135, 50, 25, hWnd, HMENU(5), m_hInstance, NULL);
	_btnN2 = CreateWindow("button", "grass",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		tempX + 50 + 60, 135, 50, 25, hWnd, HMENU(6), m_hInstance, NULL);
	_btnN3 = CreateWindow("button", "Sign",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		tempX + 50 + 120, 135, 50, 25, hWnd, HMENU(7), m_hInstance, NULL);
	_btnN4 = CreateWindow("button", "tree",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		tempX + 50 + 180, 135, 50, 25, hWnd, HMENU(8), m_hInstance, NULL);
	_btnN5 = CreateWindow("button", "grass1",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		tempX + 50 + 240, 135, 50, 25, hWnd, HMENU(9), m_hInstance, NULL);

	clickFrame = { 0,0 };
	clickIndex = 0;
}

void Window::release()
{
}

void Window::update()
{
	if (currentScene != NULL)
	{
		currentScene->update();
	}
}

void Window::render()
{
	HDC hdc = GetDC(hWnd);
	PatBlt(m_backBuffer->getMemDC(), 0, 0, SUBWINSIZEX, SUBWINSIZEY, WHITENESS);

	if (currentScene != NULL)
	{
		currentScene->render(m_backBuffer->getMemDC());
	}
	m_backBuffer->render(hdc);
	ReleaseDC(hWnd, hdc);
}

void Window::SetScene(gameNode* scene)
{
	currentScene = scene;
	currentScene->init();
}

LRESULT Window::WndLogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_MOUSEMOVE:

		SUBWIN->SetIsActive(true);
		ptMouse.x = LOWORD(lParam);
		ptMouse.y = HIWORD(lParam);
		break;
		/*case WM_PAINT:
		{


		}
		break;*/
	case  WM_COMMAND:

		switch (LOWORD(wParam))
		{
		default:
			switch ((CTRL)LOWORD(wParam))
			{
			case CTRL::CTRL_DRAW:
			case CTRL::CTRL_ERASER:
				_currentCTRL = (CTRL)(LOWORD(wParam));
				break;

			case CTRL::CTRL_INIT:
				SUBWIN->GetIsoMap()->init();
				break;
			case CTRL::CTRL_SAVE:
				//_currentCTRL = (CTRL)(LOWORD(wParam));
				SUBWIN->SetFrameIndex(9);
				break;
			case CTRL::CTRL_LOAD:
				//_currentCTRL = (CTRL)(LOWORD(wParam));
				SUBWIN->SetFrameIndex(10);
				break;
			case CTRL::CTRL_NUM1:
				_currentCTRL = CTRL::CTRL_DRAW;
				SUBWIN->SetFrameIndex(0);
				break;
			case CTRL::CTRL_NUM2:
				_currentCTRL = CTRL::CTRL_DRAW;
				SUBWIN->SetFrameIndex(1);
				break;
			case CTRL::CTRL_NUM3:
				_currentCTRL = CTRL::CTRL_DRAW;
				SUBWIN->SetFrameIndex(2);
				break;
				//SUBWIN->SetFrameIndex(LOWORD(wParam) - 5);
			case CTRL::CTRL_NUM4:
				_currentCTRL = CTRL::CTRL_DRAW;
				SUBWIN->SetFrameIndex(3);
				break;
			case CTRL::CTRL_NUM5:
				_currentCTRL = CTRL::CTRL_DRAW;
				SUBWIN->SetFrameIndex(4);
				break;
			}
			break;
		}
		break;

	case WM_KEYDOWN:

		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void Window::CreateSubWindow()
{
	//로그 윈도우 생성
	int x, y, cx, cy;
	WNDCLASS wc;
	RECT rc;

	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = (WNDPROC)Window::WndLogProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetModuleHandle(NULL);
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "sub";
	RegisterClass(&wc);
	//부모 윈도우 오른쪽에 위치 하자.
	RECT rcWin;
	GetWindowRect(m_hWnd, &rcWin);

	cx = SUBWINSIZEX;
	cy = SUBWINSIZEY;
	x = rcWin.right;
	y = rcWin.top;

	rc.left = 0;
	rc.top = 0;
	rc.right = cx;
	rc.bottom = cy;

	HWND hParenthWnd = NULL;
	HINSTANCE hInst = NULL;

	hParenthWnd = m_hWnd;
	hInst = GetModuleHandle(NULL);

	hWnd = CreateWindow("sub", "sub",
		WS_POPUP | WS_CAPTION | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,
		x, y, cx, cy, hParenthWnd, NULL, hInst, NULL);

	AdjustWindowRect(&rc, WINSTYLE, FALSE);

	SetWindowPos(hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER);

	ShowWindow(hWnd, SW_SHOW);
}
