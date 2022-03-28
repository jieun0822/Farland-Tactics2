#include "framework.h"
#include "Guild.h"

Guild::Guild()
{
}

Guild::~Guild()
{
}

HRESULT Guild::init()
{
	_townMap = new townMap;
	_townMap->init();

	IMAGE->addImage("����", "images/guildMap.bmp", WINSIZEX - 10, WINSIZEY - 30, false, RGB(0, 0, 0));
	IMAGE->addImage("����_NPC", "images/guildNpc.bmp", 36 + 20, 66 + 40, true, RGB(255, 0, 255));
	IMAGE->addImage("����_å��պκ�", "images/guildTable_front.bmp", 64 + 30, 53 + 28, true, RGB(255, 0, 0));
	IMAGE->addImage("����_�÷��̾�", "images/guild_player.bmp", 48 + 25, 75 + 48, true, RGB(255, 0, 255));

	////���NPC ��ȭâ
	IMAGE->addImage("��ȭ�׵θ�_���NPC", "images/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("��ȭâ_���NPC", "images/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("�̹���_���NPC", "images/face13a.bmp", 360, 250, true, RGB(255, 255, 255));

	//�÷��̾� ��ȭâ
	IMAGE->addImage("��ȭ�׵θ�_���Player", "images/conversation_wnd.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("��ȭâ_���Player", "images/conversation_con.bmp", WINSIZEX - 20, 250, true, RGB(0, 0, 0));
	IMAGE->addImage("�̹���_���Player", "images/face02a.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("�̹���_���Player_��Ȳ", "images/face02h.bmp", 360, 250, true, RGB(255, 255, 255));
	IMAGE->addImage("�̹���_���Player_���", "images/face02b.bmp", 360, 250, true, RGB(255, 255, 255));

	//ȭ���Ӱ�
	IMAGE->addImage("ȭ���Ӱ�", "images/darkenScreen.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));

	//Ȯ��â
	confirmWindow = RectMake(370, 280, 280, 120);
	confirmWin_name = RectMake(confirmWindow.left + 2, confirmWindow.top + 2, 276, 30);
	confirmWin_yesButton = RectMake(confirmWindow.left + 15, confirmWindow.bottom - 43, 110, 30);
	confirmWin_noButton = RectMake(confirmWindow.left + 155, confirmWindow.bottom - 43, 110, 30);

	isCheck = false;
	isCheck_yes = false;
	isCheck_no = false;

	activeTime = 0;
	_activeTime = 0;

	//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	isFirst = true;
	//Ȱ-�ι�° ����Ʈ ����
	isSecond = false;

	return S_OK;
}

void Guild::release()
{
}

void Guild::update()
{
	//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	if (isFirst && !isSecond)		//Ȱ-�ι�° ����Ʈ false�϶�
	{
		if (InputManager->isOnceKeyUp(VK_LBUTTON))
		{
			if (PtInRect(&confirmWin_yesButton, m_ptMouse) && activeTime > 260) { isCheck_yes = true; }
			//Ȱ-isCheckNo ����
			if (PtInRect(&confirmWin_noButton, m_ptMouse) && activeTime > 260) { isCheck_no = true; }//_activeTime++; }
		}

		if (isCheck_yes)
		{
			isFirst = false;
			town_active = true;
		}

		//Ȱ-_activeTime�߰�
		if (isCheck_no && _activeTime > 600)
		{
			isFirst = false;
			//town_active = true;
		}
	}
}

void Guild::render()
{
	//Ȱ-��� �̹��� �⺻���� �߰�
	IMAGE->findImage("����")->render(getMemDC(), 0, 0);
	IMAGE->findImage("����_NPC")->render(getMemDC(), 525, 225);
	IMAGE->findImage("����_å��պκ�")->render(getMemDC(), 535, 308);
	IMAGE->findImage("����_�÷��̾�")->render(getMemDC(), 605, 328);

	HFONT font, oldfont;


	//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	if (isFirst && !isSecond)		//Ȱ-�ι�° ����Ʈ false�϶�
	{
		//IMAGE->findImage("����")->render(getMemDC(), 0, 0);
		//IMAGE->findImage("����_NPC")->render(getMemDC(), 525, 225);
		//IMAGE->findImage("����_å��պκ�")->render(getMemDC(), 535, 308);
		//IMAGE->findImage("����_�÷��̾�")->render(getMemDC(), 605, 328);

		activeTime++;
		if (activeTime >= 30 && activeTime < 140)
		{
			IMAGE->render("��ȭ�׵θ�_���NPC", getMemDC(), 0, 10);
			IMAGE->alphaRender("��ȭâ_���NPC", getMemDC(), 0, 10, 170);
			IMAGE->render("�̹���_���NPC", getMemDC(), 10, 12);

			HFONT font, oldfont;
			SetBkMode(getMemDC(), TRANSPARENT);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 380, 55, "������", lstrlen("������"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TCHAR strrr[128];
			wsprintf(strrr, "�� ���� �ֱ� �־�. ��");
			TextOut(getMemDC(), 385, 90, strrr, lstrlen(strrr));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			if (activeTime >= 80 && !(isCheck_no))
			{
				IMAGE->render("��ȭ�׵θ�_���Player", getMemDC(), 0, WINSIZEY - 300);
				IMAGE->alphaRender("��ȭâ_���Player", getMemDC(), 0, WINSIZEY - 301, 170);
				IMAGE->render("�̹���_���Player", getMemDC(), 600, 470);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 102));
				TextOut(getMemDC(), 48, WINSIZEY - 260, "��", lstrlen("��"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				TextOut(getMemDC(), 50, WINSIZEY - 225, "�� ��� ���. ��", lstrlen("�� ��� ���. ��"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);
			}
		}


		if (activeTime >= 140 && !(isCheck_no))
		{


			IMAGE->render("��ȭ�׵θ�_���NPC", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("��ȭâ_���NPC", getMemDC(), 0, WINSIZEY - 301, 170);
			//IMAGE->render("�̹���_���NPC", getMemDC(), 600, 470);


			SetBkMode(getMemDC(), TRANSPARENT);
			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "������", lstrlen("������"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));

			TCHAR str[100];
			wsprintf(str, "������� �Ѹ���, ���⼭ ���� ������ ���� �ִ� ��ӿ��� �̾ư� �Ǿ���.");
			TextOut(getMemDC(), 50, WINSIZEY - 225, str, lstrlen(str));

			wsprintf(str, "����� ���Ͱ� �ִ� ���� �ƴ�����, ����̿��� �־��");
			TextOut(getMemDC(), 75, WINSIZEY - 195, str, lstrlen(str));

			wsprintf(str, "���� ����� ������. ���ѷ� �����ַ� ������. �, �ϰھ�? ��");
			TextOut(getMemDC(), 75, WINSIZEY - 165, str, lstrlen(str));

			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (/*isCheck &&*/ !(isCheck_no) && activeTime >= 300)
		{
			//Ȯ��â.
			HBRUSH brush;

			IMAGE->alphaRender("ȭ���Ӱ�", getMemDC(), 0, 0, 170);
			grayDraw(confirmWindow);

			brush = CreateSolidBrush(RGB(0, 0, 204));
			Rectangle(getMemDC(), confirmWin_name.left, confirmWin_name.top, confirmWin_name.right, confirmWin_name.bottom);
			FillRect(getMemDC(), &confirmWin_name, brush);
			DeleteObject(brush);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), confirmWin_name.left + 3, confirmWin_name.top + 6, "Ȯ��", lstrlen("Ȯ��"));
			SetTextColor(getMemDC(), RGB(0, 0, 0));

			TextOut(getMemDC(), confirmWin_name.left + 82, confirmWin_name.top + 45, "���� �ϰڽ��ϱ�?", lstrlen("���� �ϰڽ��ϱ�?"));

			lightDraw(confirmWin_yesButton);
			shadowDraw(confirmWin_yesButton);
			grayDraw(confirmWin_yesButton);
			TextOut(getMemDC(), confirmWin_yesButton.left + 45, confirmWin_yesButton.top + 7, "��", lstrlen("��"));

			lightDraw(confirmWin_noButton);
			shadowDraw(confirmWin_noButton);
			grayDraw(confirmWin_noButton);
			TextOut(getMemDC(), confirmWin_noButton.left + 30, confirmWin_noButton.top + 7, "�ƴϿ�", lstrlen("�ƴϿ�"));
		}


		//�������� ��.
		if (isCheck_no)
		{
			_activeTime++;

			if (_activeTime >= 30 && _activeTime < 200)
			{
				IMAGE->render("��ȭ�׵θ�_���Player", getMemDC(), 0, WINSIZEY - 300);
				IMAGE->alphaRender("��ȭâ_���Player", getMemDC(), 0, WINSIZEY - 301, 170);
				IMAGE->render("�̹���_���Player_��Ȳ", getMemDC(), 600, 470);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 102));
				TextOut(getMemDC(), 48, WINSIZEY - 260, "��", lstrlen("��"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				TextOut(getMemDC(), 50, WINSIZEY - 225, "�� �ð��� �ȵ� �� ���ƿ�. ��", lstrlen("�� �ð��� �ȵ� �� ���ƿ�. ��"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);
			}

			if (_activeTime >= 100 && _activeTime < 350)
			{
				IMAGE->render("��ȭ�׵θ�_���NPC", getMemDC(), 0, 10);
				IMAGE->alphaRender("��ȭâ_���NPC", getMemDC(), 0, 10, 170);
				IMAGE->render("�̹���_���NPC", getMemDC(), 10, 12);


				SetBkMode(getMemDC(), TRANSPARENT);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 102));
				TextOut(getMemDC(), 380, 55, "������", lstrlen("������"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);

				//Ȱ- "���̵�"������
				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				TCHAR strrr[128];
				wsprintf(strrr, "�� �츮���� �����ַ� ����, ���� �ʿ��� ");
				TextOut(getMemDC(), 385, 90, strrr, lstrlen(strrr));
				wsprintf(strrr, "   �������� ������ ����. �׷��� ��Ź��. ��");
				TextOut(getMemDC(), 395, 120, strrr, lstrlen(strrr));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);
			}

			if (_activeTime >= 200 && _activeTime < 350)
			{
				IMAGE->render("��ȭ�׵θ�_���Player", getMemDC(), 0, WINSIZEY - 300);
				IMAGE->alphaRender("��ȭâ_���Player", getMemDC(), 0, WINSIZEY - 301, 170);
				IMAGE->render("�̹���_���Player_���", getMemDC(), 600, 470);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 102));
				TextOut(getMemDC(), 48, WINSIZEY - 260, "��", lstrlen("��"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				TextOut(getMemDC(), 50, WINSIZEY - 225, "�� �˾Ҿ��. ��", lstrlen("�� �˾Ҿ��. ��"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);
			}

			if (_activeTime >= 350 && _activeTime < 700)
			{
				IMAGE->render("��ȭ�׵θ�_���NPC", getMemDC(), 0, 10);
				IMAGE->alphaRender("��ȭâ_���NPC", getMemDC(), 0, 10, 170);
				IMAGE->render("�̹���_���NPC", getMemDC(), 10, 12);


				SetBkMode(getMemDC(), TRANSPARENT);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 102));
				TextOut(getMemDC(), 380, 55, "������", lstrlen("������"));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);

				font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
				oldfont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				TCHAR strrr[128];
				wsprintf(strrr, "�� �ֱ�, �Ǹ��� ���� �ٴϴϱ� ������. ");
				TextOut(getMemDC(), 385, 90, strrr, lstrlen(strrr));
				wsprintf(strrr, "   �氡�� ����� �ҷ� ����, �ºθ� �ɾ�, ");
				TextOut(getMemDC(), 395, 120, strrr, lstrlen(strrr));
				wsprintf(strrr, "   �ִ� ���� ��� ���Ѿ� ���� �� ����. ��");
				TextOut(getMemDC(), 395, 150, strrr, lstrlen(strrr));
				SelectObject(getMemDC(), oldfont);
				DeleteObject(font);
			}

			if (_activeTime >= 650)
			{
				town_active = true;
				//SCENE->changeScene("townMap");
			}
		}
	}

	//quest1 �Ϸ���� �ʾ��� ��.
	//�����ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�
	else if (!isFirst && !quest1_complete)
	{
		IMAGE->findImage("����")->render(getMemDC(), 0, 0);
		IMAGE->findImage("����_NPC")->render(getMemDC(), 525, 225);
		IMAGE->findImage("����_å��պκ�")->render(getMemDC(), 535, 308);
		IMAGE->findImage("����_�÷��̾�")->render(getMemDC(), 605, 328);

		activeTime++;

		if (activeTime > 10 && activeTime < 450)
		{
			IMAGE->render("��ȭ�׵θ�_���NPC", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("��ȭâ_���NPC", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("�̹���_���NPC", getMemDC(), 600, 470);

			HFONT font, oldfont;
			SetBkMode(getMemDC(), TRANSPARENT);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "������", lstrlen("������"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TCHAR strrr[128];
			wsprintf(strrr, "�� �� ���� ������ ����, ���͸� óġ�� �Ŀ�,");
			TextOut(getMemDC(), 48, WINSIZEY - 225, strrr, lstrlen(strrr));
			wsprintf(strrr, "�����̵��� ã����. ������ ����ġ �ʰ� �ְھ�. ��");
			TextOut(getMemDC(), 48, WINSIZEY - 195, strrr, lstrlen(strrr));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (activeTime > 450)
		{
			town_active = true;
		}
	}//����Ʈ�� �Ϸ����� ��.
	
	
	//Ȱ
	//�����߰� & ��Ƽ��Ÿ�ӱ���
	//else if (!isFirst && quest1_complete)
	if (!isFirst && quest1_complete && !isSecond)		//Ȱ-�ι�° ����Ʈ false�϶�
	{
		activeTime++;

		IMAGE->findImage("����")->render(getMemDC(), 0, 0);
		IMAGE->findImage("����_NPC")->render(getMemDC(), 525, 225);
		IMAGE->findImage("����_å��պκ�")->render(getMemDC(), 535, 308);
		IMAGE->findImage("����_�÷��̾�")->render(getMemDC(), 605, 328);

		HFONT font, oldfont;
		SetBkMode(getMemDC(), TRANSPARENT);

		if (activeTime > 30 && activeTime < 240)
		{

			IMAGE->render("��ȭ_����", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("��ȭ_����2", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("�̹���_���NPC", getMemDC(), 630, 470);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			TextOut(getMemDC(), 50, WINSIZEY - 260, "������", lstrlen("������"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(250, 244, 192));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "������", lstrlen("������"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 225, "�� ù ��° �ӹ��� ���������� �����߱�.", lstrlen("�� ù ��° �ӹ��� ���������� �����߱�."));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(22, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 180, "����, ����, �Ϸ� ���� 1000G��. ��", lstrlen("����, ����, �Ϸ� ���� 1000G��. ��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (activeTime >= 240 && activeTime < 370)
		{
			IMAGE->render("��ȭ_����", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("��ȭ_����2", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("�̹���_���NPC", getMemDC(), 630, 470);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			TextOut(getMemDC(), 50, WINSIZEY - 260, "������", lstrlen("������"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(250, 244, 192));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "������", lstrlen("������"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(22, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 225, "�� ���� ������ �ٽ� ����. ���ο� ������ �ñ⵵�� ����. ��", lstrlen("�� ���� ������ �ٽ� ����. ���ο� ������ �ñ⵵�� ����. ��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

		}

		if (activeTime >= 370)
		{
			town_active = true;
			SOUND->stop("bgm02");
			
			//Ȱ - �ι�° ����Ʈ Ȱ��ȭ
			//if (activeTime >= 380) { isSecond = true; }		
			isSecond = true;
			//townNight_active = true;
		}
	}


	if (isSecond)
	{
		activeTime++;

		if (activeTime > 30 && activeTime <= 400)
		{

			IMAGE->render("��ȭ�׵θ�_���NPC", getMemDC(), 0, 10);
			IMAGE->alphaRender("��ȭâ_���NPC", getMemDC(), 0, 10, 170);
			IMAGE->render("�̹���_���NPC", getMemDC(), 10, 12);

			HFONT font, oldfont;
			SetBkMode(getMemDC(), TRANSPARENT);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 380, 55, "������", lstrlen("������"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(28, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TCHAR strrr[128];
			wsprintf(strrr, "�� ����, ��ٸ��� �־���.");
			TextOut(getMemDC(), 385, 90, strrr, lstrlen(strrr));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(20, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 385, 130, "�������ϴ� �̹� ������ ���̵��� �� �ִ���, �����ھ�? ��", lstrlen("�������ϴ� �̹� ������ ���̵��� �� �ִ���, �����ھ�? ��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (activeTime >= 250 && activeTime <= 790)
		{
			IMAGE->render("��ȭ�׵θ�_���Player", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("��ȭâ_���Player", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("�̹���_���Player_���", getMemDC(), 600, 470);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "��", lstrlen("��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 225, "�� ������? ��", lstrlen("�� ������? ��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (activeTime > 400)
		{
			IMAGE->render("��ȭ�׵θ�_���NPC", getMemDC(), 0, 10);
			IMAGE->alphaRender("��ȭâ_���NPC", getMemDC(), 0, 10, 170);
			IMAGE->render("�̹���_���NPC", getMemDC(), 10, 12);

			HFONT font, oldfont;
			SetBkMode(getMemDC(), TRANSPARENT);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 380, 55, "������", lstrlen("������"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(18, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TCHAR strrr[128];
			wsprintf(strrr, "�� �ֱ�, ���� ������ �޵��꿡, �Ǹ��� ���� '�˺��'�� ��Ÿ����. ");
			TextOut(getMemDC(), 385, 90, strrr, lstrlen(strrr));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(18, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 385, 120, "���� �༮�� ����ġ��, ������ ��ȭ�� ��ã�°� �̹� �ӹ���. ��", lstrlen("���� �༮�� ����ġ��, ������ ��ȭ�� ��ã�°� �̹� �ӹ���. ��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (activeTime >= 800)
		{
			IMAGE->render("��ȭ�׵θ�_���Player", getMemDC(), 0, WINSIZEY - 300);
			IMAGE->alphaRender("��ȭâ_���Player", getMemDC(), 0, WINSIZEY - 301, 170);
			IMAGE->render("�̹���_���Player_���", getMemDC(), 600, 470);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 102));
			TextOut(getMemDC(), 48, WINSIZEY - 260, "��", lstrlen("��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);

			font = CreateFont(24, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, "����");
			oldfont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), 50, WINSIZEY - 225, "�� �˾Ҿ��. ��", lstrlen("�� �˾Ҿ��. ��"));
			SelectObject(getMemDC(), oldfont);
			DeleteObject(font);
		}

		if (activeTime >= 900)
		{
			town_active = true;
		}
	}



	TCHAR str[100];
	wsprintf(str, "activeTime(no)_guild : %d", _activeTime);
	TextOut(getMemDC(), 0, 0, str, lstrlen(str));

}

void Guild::shadowDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(051, 051, 051));
	RECT shadow = RectMake(rc.left + 3, rc.top + 3, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), shadow.left, shadow.top, shadow.right, shadow.bottom);
	FillRect(getMemDC(), &shadow, brush);
	DeleteObject(brush);
}

void Guild::lightDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(255, 255, 255));
	RECT light = RectMake(rc.left - 1, rc.top - 1, rc.right - rc.left, rc.bottom - rc.top);
	Rectangle(getMemDC(), light.left, light.top, light.right, light.bottom);
	FillRect(getMemDC(), &light, brush);
	DeleteObject(brush);
}

void Guild::grayDraw(RECT rc)
{
	HBRUSH brush = CreateSolidBrush(RGB(204, 204, 204));
	Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	FillRect(getMemDC(), &rc, brush);
	DeleteObject(brush);
}
