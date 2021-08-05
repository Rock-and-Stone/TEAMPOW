#include "pch.h"
#include "stage1.h"

HRESULT stage1::init()
{
	IMAGEMANAGER->addImage("background", "Level 1 - Frozen Suburbs.bmp", 31812, 1400, true, MAGENTA);
	IMAGEMANAGER->addImage("배경", "backdu bisch ein archground.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_player = new Ramona;
	_player->init();
	_player->InitVariables();

	_maxY = 1225;

	_cm = new CameraManager;
	_cm->init(31812, _maxY);

	_ui = new UserInterface;
	_ui->init();


	return S_OK;
}

void stage1::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) SCENEMANAGER->changeScene("settingScene");

	if (!_ui->GetIsPause())
	{
		_player->update();

		_cm->update(_player->getPosX(), _player->getPosY());

#pragma region 언덕카메라무브

		if (_player->getPosX() >= 24765)
		{
			if (_maxY <= 1400) _maxY = 1225 + 0.6 * (_player->getPosX() - 24765);
		}

		if (_maxY >= 1400)
		{
			_maxY = 1400;
		}

		_cm->init(31812, _maxY);

#pragma endregion

	}

	_ui->update();

}

void stage1::release()
{
}

void stage1::render()
{
	IMAGEMANAGER->findImage("background")->render(getMemDC(), 0, 0, _cm->getCamX(), _cm->getCamY(), WINSIZEX, WINSIZEY);
	_player->render(_cm->getRenderPosX(), _cm->getRenderPosY());
	_ui->render();

#pragma region 디버깅

	char str[256];
	HFONT oldFont, font1;

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

#pragma endregion

}
