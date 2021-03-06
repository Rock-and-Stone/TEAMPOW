#pragma once
#include "gameNode.h"
#include "string"
#include "CameraManager.h"
#include "Ramona.h"
#define ARRSIZE 10

class playGround : public gameNode
{
private:
	CameraManager* _cm;
	player* _player;

	int _posX;
	int _posY;

	char* _str;

	int _power;

	int _arr[ARRSIZE] = { 2 , 5 ,1 , 4 , 7 , 8 , 9, 3, 11, 10 };

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 함수
	virtual void release();			//메모리 해제 함슈
	virtual void update();			//연산하는 함수
	virtual void render();			//그리기 함수
};

