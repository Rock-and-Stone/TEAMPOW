#include "pch.h"
#include "restaurantScene.h"

restaurantScene::restaurantScene()
{
}

restaurantScene::~restaurantScene()
{
}

HRESULT restaurantScene::init()
{
	_background = IMAGEMANAGER->addImage("restaurantScene", "SHOP/SHOP_RESTAURANT.bmp", 1600, 900, true, RGB(255, 0, 255));

	SOUNDMANAGER->addSound("����", "����.mp3", true, true);

	SOUNDMANAGER->play("����", 0.5f);

	return S_OK;
}

void restaurantScene::release()
{
}

void restaurantScene::update()
{
}

void restaurantScene::render()
{
	_background->render(getMemDC(), 0, 0);
}
