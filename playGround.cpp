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
	IMAGEMANAGER->addImage("���", "backdu bisch ein archground.bmp", WINSIZEX, WINSIZEY, true,
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

//�޸� ������ ����� �ض�!!!!
void playGround::release()
{
	gameNode::release();


}

//����ó���� ����ٰ�!
void playGround::update()
{
	gameNode::update();

	_player->update();
	_cm->update(_player->getPosX(), _player->getPosY());

	//RENDERMANAGER->update();
}

//����� �׷����!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==============������ ���� �ǵ帮�� ���� ============
	
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

	//=============== �ؿ��� �ǵ������� ================
	_backBuffer->render(getHDC(), 0, 0);

}



