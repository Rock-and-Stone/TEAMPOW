#pragma once
#include "gameNode.h"
#include "jump.h"

#define KNIGHTSPEED 2.5f

enum KNIGHTDIRECTION
{
	KNIGHTDIRECTION_RIGHT_STOP,
	KNIGHTDIRECTION_LEFT_STOP,
	KNIGHTDIRECTION_RIGHT_MOVE,
	KNIGHTDIRECTION_LEFT_MOVE,
	KNIGHTDIRECTION_RIGHT_SIT,
	KNIGHTDIRECTION_LEFT_SIT,
	KNIGHTDIRECTION_RIGHT_ATTACK,
	KNIGHTDIRECTION_LEFT_ATTACK,
	KNIGHTDIRECTION_RIGHT_SIT_ATTACK,
	KNIGHTDIRECTION_LEFT_SIT_ATTACK,
	KNIGHTDIRECTION_RIGHT_JUMP,
	KNIGHTDIRECTION_LEFT_JUMP,
	KNIGHTDIRECTION_RIGHT_MOVE_JUMP,
	KNIGHTDIRECTION_LEFT_MOVE_JUMP
};

class knight : public gameNode
{
private:
	KNIGHTDIRECTION _knightDirection;

	image* _image;
	float _x, _y;
	RECT _rc;

	animation* _knightMotion;

	jump* _jump;

public:
	knight();
	~knight();

	HRESULT init();
	void release();
	void update();
	void render();

	static void rightFire(void* obj);
	static void leftFire(void* obj);

	static void rightJump(void* obj);
	static void leftJump(void* obj);
	static void rightMoveJump(void* obj);
	static void leftMoveJump(void* obj);

	//��翡 ���¿� ���� ������ ������
	KNIGHTDIRECTION getKnightDirection() { return _knightDirection; }
	void setKnightDirection(KNIGHTDIRECTION direction) { _knightDirection = direction; }

	//����� ��ǿ� ���� ������ ������
	animation* getKnightMotion() { return _knightMotion; }
	void setKnightMotion(animation* ani) { _knightMotion = ani; }
};

