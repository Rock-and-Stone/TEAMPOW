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
	IMAGEMANAGER->addImage("배경", "backdu bisch ein archground.bmp", WINSIZEX, WINSIZEY, true,
		RGB(255, 0, 255));


	_posX = 200;
	_posY = WINSIZEY / 2;

	_player = new Ramona;
	_player->init();
	_player->InitVariables();


	_cm = new CameraManager;
	_cm->init(31812, 1400);

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

	_player->update();
	_cm->update(_player->getPosX(), _player->getPosY());

	//RENDERMANAGER->update();
}

//여기다 그려줘라!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============위에는 제발 건드리지 마라 ============
	
	char str[256];
	HFONT oldFont, font1;

	IMAGEMANAGER->findImage("background")->render(getMemDC(), 0, 0, _cm->getCamX(), _cm->getCamY(), WINSIZEX, WINSIZEY);
	_player->render(_cm->getRenderPosX(), _cm->getRenderPosY());

	sprintf_s(str, "char X : %d", _player->getPosX());
	TextOut(getMemDC(), 100, 90, str, strlen(str));
	
	sprintf_s(str, "render X : %d", _cm->getRenderPosX());
	TextOut(getMemDC(), 100, 110, str, strlen(str));


	sprintf_s(str, "char Y : %d", _player->getPosY());
	TextOut(getMemDC(), 100, 130, str, strlen(str));

	sprintf_s(str, "render Y : %d", _cm->getRenderPosY());
	TextOut(getMemDC(), 100, 150, str, strlen(str));



	//RENDERMANAGER->render(getMemDC());
	TIMEMANAGER->render(getMemDC());

	//=============== 밑에도 건들지마라 ================
	_backBuffer->render(getHDC(), 0, 0);

}



