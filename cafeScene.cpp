#include "pch.h"
#include "cafeScene.h"

cafeScene::cafeScene()
{
}

cafeScene::~cafeScene()
{
}

HRESULT cafeScene::init()
{
	_background = IMAGEMANAGER->addImage("cafeScene", "SHOP/SHOP_CAFE.bmp", 1600, 900, true, RGB(255, 0, 255));

	return S_OK;
}

void cafeScene::release()
{
}

void cafeScene::update()
{
}

void cafeScene::render()
{
}
