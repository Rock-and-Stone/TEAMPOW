#include "pch.h"
#include "UserInterface.h"

HRESULT UserInterface::init()
{

	IMAGEMANAGER->addFrameImage("hpNum", "source/hp_number.bmp", 140, 15, 10, 1, true, MAGENTA);

	IMAGEMANAGER->addFrameImage("gpNum", "source/gp_number.bmp", 140, 15, 10, 1, true, MAGENTA);

	IMAGEMANAGER->addFrameImage("coinNum", "source/coin_number.bmp", 140, 15, 10, 1, true, MAGENTA);


	IMAGEMANAGER->addImage("player1UI", "source/player1.bmp", 150, 130, true, MAGENTA);
	IMAGEMANAGER->addImage("player2UI", "source/player2.bmp", 150, 130, true, MAGENTA);

	_hp100 = IMAGEMANAGER->findImage("hpNum");
	_hp10 = IMAGEMANAGER->findImage("hpNum");
	_hp1 = IMAGEMANAGER->findImage("hpNum");

	_gp100 = IMAGEMANAGER->findImage("gpNum");
	_gp10 = IMAGEMANAGER->findImage("gpNum");
	_gp1 = IMAGEMANAGER->findImage("gpNum");

	_coin100 = IMAGEMANAGER->findImage("coinNum");
	_coin10 = IMAGEMANAGER->findImage("coinNum");
	_coin1 = IMAGEMANAGER->findImage("coinNum");

	_option = IMAGEMANAGER->addImage("option", "source/pause.bmp", 236, 200, true, MAGENTA);


	return S_OK;
}

void UserInterface::release()
{
}

void UserInterface::update()
{
	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		if (!_isPause) _isPause = true;
		else  _isPause = false;
	}
}

void UserInterface::render()
{
	IMAGEMANAGER->findImage("player1UI")->render(getMemDC(), 20, 20);

	int playerHP = 581;
	int playerGP = 123;
	int coin = 851;

	_hp100->frameRender(getMemDC(), 95, 63, playerHP / 100 , 0);
	_hp10->frameRender(getMemDC(), 110, 63, playerHP % 100 /10,0);
	_hp1->frameRender(getMemDC(), 125, 63, playerHP % 10,0);

	_gp100->frameRender(getMemDC(), 95, 84, playerGP / 100, 0);
	_gp10->frameRender(getMemDC(), 110, 84, playerGP % 100 / 10, 0);
	_gp1->frameRender(getMemDC(), 125, 84, playerGP % 10, 0);

	_coin100->frameRender(getMemDC(), 95, 104, coin / 100, 0);
	_coin10->frameRender(getMemDC(), 110, 104, coin  % 100 / 10, 0);
	_coin1->frameRender(getMemDC(), 125, 104, coin % 10, 0);

	if (_isPause)
	{
		_option->render(getMemDC() , WINSIZEX /2 - _option->getWidth()/2 , WINSIZEY /2 - _option->getHeight()/2);
	}
}
