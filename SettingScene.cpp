#include "pch.h"
#include "SettingScene.h"

HRESULT SettingScene::init()
{
	IMAGEMANAGER->addImage("settingBackGround", "source/settingScene.bmp", WINSIZEX, WINSIZEY, true, MAGENTA);

	return S_OK;
}

void SettingScene::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN)) SCENEMANAGER->changeScene("selectScene");

}

void SettingScene::release()
{
}

void SettingScene::render()
{
	IMAGEMANAGER->findImage("settingBackGround")->render(getMemDC());
}
