#include "pch.h"
#include "CameraManager.h"

CameraManager::CameraManager()
{
}

CameraManager::~CameraManager()
{
}

HRESULT CameraManager::init(int mapSizeX, float mapSizeY)
{
    _posX = WINSIZEX / 2;
    _posY = WINSIZEY / 2;

    _mapSizeX = mapSizeX;
    _mapSizeY = mapSizeY;

    return S_OK;
}

void CameraManager::release()
{
}

void CameraManager::update(int playerX, int playerY)
{
    CameraWork(playerX, playerY);
}

void CameraManager::CameraWork(int playerX, int playerY)
{
    _rc = RectMake(playerX - _posX, + playerY - _posY, WINSIZEX, WINSIZEY);

    CameraClamp();

    _renderPosX = playerX - _rc.left;
    _renderPosY = playerY - _rc.top;
}

void CameraManager::CameraClamp()
{
    if (_rc.left <= 0) _rc.left = 0;
    if (_rc.top <= 0) _rc.top = 0;
    if (_rc.left + WINSIZEX >= _mapSizeX) _rc.left = _mapSizeX - WINSIZEX;
    if (_rc.top + WINSIZEY >= _mapSizeY) _rc.top = _mapSizeY - WINSIZEY;
}
