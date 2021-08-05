#pragma once
#include "gameNode.h"

class CameraManager : public gameNode
{
private:
	int _posX;
	int _posY;

	int _renderPosX;
	int _renderPosY;

	int _mapSizeX;
	int _mapSizeY;

	RECT _rc;

public:
	CameraManager();
	~CameraManager();

	HRESULT init(int mapSizeX, float mapSizeY);
	virtual void release();
	virtual void update(int playerX, int playerY);

	void CameraWork(int playerX, int playerY);
	void CameraClamp();

	int getRenderPosX() { return _renderPosX; }
	int getRenderPosY() { return _renderPosY; }

	int getCamX() { return _rc.left; }
	int getCamY() { return _rc.top; }
};

