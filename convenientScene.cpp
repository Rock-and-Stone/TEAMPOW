#include "pch.h"
#include "convenientScene.h"

convenientScene::convenientScene()
{
}

convenientScene::~convenientScene()
{
}

HRESULT convenientScene::init()
{
	_background = IMAGEMANAGER->addImage("convenientScene", "SHOP/SHOP_CONVENIENTSTORE.bmp", 1600, 900, true, RGB(255, 0, 255));

	return S_OK;
}

void convenientScene::release()
{
}

void convenientScene::update()
{
}

void convenientScene::render()
{
}
