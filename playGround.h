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

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�
};

