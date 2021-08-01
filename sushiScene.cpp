#include "pch.h"
#include "sushiScene.h"

sushiScene::sushiScene()
{
}

sushiScene::~sushiScene()
{
}

HRESULT sushiScene::init()
{
	_background = IMAGEMANAGER->addImage("sushiScene", "SHOP/SHOP_SUSHI.bmp", 1600, 900, true, RGB(255, 0, 255));

	return S_OK;
}

void sushiScene::release()
{
}

void sushiScene::update()
{
}

void sushiScene::render()
{
}
