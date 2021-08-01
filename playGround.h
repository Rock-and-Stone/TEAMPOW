#pragma once
#include "gameNode.h"
#include "string"
#include "CameraManager.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "restaurantScene.h"


class playGround : public gameNode
{
private:
	CameraManager* _cm;
	RECT _player;
	EnemyManager* _em;
	Enemy* _enemy;
	

	int _posX;
	int _posY;

	char* _str;

	int _power;

	int _arr[10] = { 2 , 5 ,1 , 4 , 7 , 8 , 9, 3, 11, 10 };

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();			//�׸��� �Լ�

	void selectionSort();
	void swap(int index, int minIndex);
};

