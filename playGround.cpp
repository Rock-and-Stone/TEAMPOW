#include "pch.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ���⿡�� �ض�!!!
HRESULT playGround::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("background", "Level 1 - Frozen Suburbs.bmp", 31812, 1400, true, MAGENTA);
	IMAGEMANAGER->addImage("���", "background.bmp", WINSIZEX, WINSIZEY, true,
		RGB(255, 0, 255));
	
	_posX = 100;
	_posY = WINSIZEY / 2;

	_cm = new CameraManager;
	_cm->init(31812, 1400);

	_player = new player;
	_player->init();

	return S_OK;
}

//�޸� ������ ����� �ض�!!!!
void playGround::release()
{
	gameNode::release();


}

//����ó���� ����ٰ�!
void playGround::update()
{
	gameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _posX -= 5;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _posX += 5;
	if (KEYMANAGER->isStayKeyDown(VK_UP)) _posY -= 5;
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) _posY += 5;

	_cm->update(_posX, _posY);
	selectionSort();

	_player->update();

}

//����� �׷����!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============
	
	char str[256];
	HFONT oldFont, font1;
	/*
	CreateFont(
		40,			//������
		0,			//���� ����
		40,			//���� ����(��¥ ������)
		0,			//���� ����
		600,		//���� ����
		0,			//bool ���� ���� ���Ÿ�ü �������
		0,			//bool ���� ���� 
		0,			//bool ���� ��Ҽ� (������Ű�� ���� �װ�)
		HANGUL_CHARSET,	//���� ����
		0,				//��� ��Ȯ��
		0,				//Ŭ���� ��Ȯ��
		0,				//����� ����Ƽ
		0,				//�ڰ�
		TEXT("�ü�ü"));	//��Ʈ 
	*/
	/*
	

	font1 = CreateFont(50, 0, 0, 0, 100, true, true, true, HANGUL_CHARSET, 0, 0, 0, 50, TEXT("�޸ձ���"));
	oldFont = (HFONT)SelectObject(getMemDC(), font1);
	sprintf_s(str, "��Ʈ�� ĸ�� ���̾�");
	TextOut(getMemDC(), 10, 100, str, strlen(str));
	DeleteObject(font1);
	*/

	SetTextColor(getMemDC(), RGB(0, 0, 0));

	IMAGEMANAGER->findImage("background")->render(getMemDC(), 0, 0, _cm->getCamX(), _cm->getCamY(), WINSIZEX, WINSIZEY);

	_player->render();

	RectangleMakeCenter(getMemDC(), _cm->getRenderPosX(), _cm->getRenderPosY(), 50, 81);

	sprintf_s(str, "char X : %d", _posX);
	TextOut(getMemDC(), 100, 90, str, strlen(str));
	
	sprintf_s(str, "render X : %d", _cm->getRenderPosX());
	TextOut(getMemDC(), 100, 110, str, strlen(str));


	sprintf_s(str, "char Y : %d", _posY);
	TextOut(getMemDC(), 100, 130, str, strlen(str));

	sprintf_s(str, "render Y : %d", _cm->getRenderPosY());
	TextOut(getMemDC(), 100, 150, str, strlen(str));


	RECT rcText = RectMake(10, 300, 400, 100);

	HFONT font2 = CreateFont(40, 0, 0, 0, 300, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("PokemonGSC"));

	HFONT oldFont2 = (HFONT)SelectObject(getMemDC(), font2);

	//DrawText(getMemDC(), TEXT("TEXT"), 7, &rcText, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	for (int i = 0; i < 10; i++)
	{
		//sprintf_s(str, "%d", _arr[i]);
		//TextOut(getMemDC(), 50 + 50 * i, 90, str, strlen(str));
	}

	//DrawText(getMemDC(), TEXT("Subway"), 7, &rcText, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	SelectObject(getMemDC(), oldFont2);
	DeleteObject(font2);



	TIMEMANAGER->render(getMemDC());

	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);

}

void playGround::selectionSort()
{
		int minIndex;
		int i, j;
		for (i = 0; i < 10 - 1; i++) {
			minIndex = i;
			for (j = i + 1; j < 10; j++)
				if (_arr[j] < _arr[minIndex])
					minIndex = j;

			swap(i, minIndex);
		}
}

void playGround::swap(int index, int minIndex)
{
	int temp;

	temp = _arr[index];
	_arr[index] = _arr[minIndex];
	_arr[minIndex] = temp;

}


