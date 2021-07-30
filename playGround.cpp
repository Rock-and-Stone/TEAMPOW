#include "pch.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기에다 해라!!!
HRESULT playGround::init()
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("background", "Level 1 - Frozen Suburbs.bmp", 31812, 1400, true, MAGENTA);
	IMAGEMANAGER->addImage("배경", "background.bmp", WINSIZEX, WINSIZEY, true,
		RGB(255, 0, 255));
	
	_posX = 100;
	_posY = WINSIZEY / 2;

	_cm = new CameraManager;
	_cm->init(31812, 1400);

	_player = new player;
	_player->init();

	return S_OK;
}

//메모리 해제는 여기다 해라!!!!
void playGround::release()
{
	gameNode::release();


}

//연산처리는 여기다가!
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

//여기다 그려줘라!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============
	
	char str[256];
	HFONT oldFont, font1;
	/*
	CreateFont(
		40,			//문자폭
		0,			//문자 넓이
		40,			//문자 기울기(진짜 기울어짐)
		0,			//문자 방향
		600,		//문자 굵기
		0,			//bool 문자 기울기 이탤릭체 사용유무
		0,			//bool 문자 밑줄 
		0,			//bool 문자 취소선 (나무위키에 많은 그것)
		HANGUL_CHARSET,	//문자 셋팅
		0,				//출력 정확도
		0,				//클리핑 정확도
		0,				//출력의 퀄리티
		0,				//자간
		TEXT("궁서체"));	//폰트 
	*/
	/*
	

	font1 = CreateFont(50, 0, 0, 0, 100, true, true, true, HANGUL_CHARSET, 0, 0, 0, 50, TEXT("휴먼굴림"));
	oldFont = (HFONT)SelectObject(getMemDC(), font1);
	sprintf_s(str, "울트라 캡숑 나이쓰");
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

	//=============== 밑에도 건들지마라 ================
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


