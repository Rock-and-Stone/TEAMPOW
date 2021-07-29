#pragma once
#include "gameNode.h"

//���ʹ� ���� enum Ŭ����
enum class ENEMYDIRECTION
{
	LEFT,
	RIGHT
};

//���ʹ� ���� enum Ŭ����
enum class ENEMYSTATEMENT
{
	INIT,						//����
	IDLE,						//�⺻
	WALK,						//�ȱ�
	RUN,						//�ٱ�
	JUMP,						//����
	ATTACK1,					//�����1
	ATTACK2,					//�����2(�޺�)
	ATTACK3,					//������1
	ATTACK4,					//������2(�޺�)
	DAMAGED,					//�ǰ�
	DOWN,						//�ǰݽ� �ٿ�(����)
	DOWN_DAMAGED,				//������¿����� �ǰ�
	DOWN_ATTACK,				//������¿��� ����
	UP,							//������¿��� �Ͼ��
	GUARD,						//����
	OBJECT_ATTACK,				//������Ʈ ��� ����
	OBJECT_THROW,				//������Ʈ ������
	OBJECT_GRAB					//������Ʈ ���
};

class Enemy : public gameNode
{
protected:
	ENEMYDIRECTION _enemyDirection;
	ENEMYSTATEMENT _enemyStatement;

	image* _imageName;
	animation* _motionName;
	RECT _rc;

	float _posX, _posY;
	

public:
	Enemy();
	~Enemy();

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, const char* animationName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	void draw();

	inline RECT GetRect() { return _rc; }

};

