#pragma once
#include "gameNode.h"
#include "CameraManager.h"
#include "EnemyIdle.h"
#include "EnemyWalk.h"
#include "EnemyRun.h"
#include "EnemyJump.h"
#include "EnemyAttack1.h"
#include "EnemyAttack3.h"
#include "EnemyDamaged.h"
#include "EnemyGuard.h"
#include "EnemyDown.h"
#include "EnemyUp.h"

#define ENEMYSPEED 5.0f

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
	CameraManager* _cm;

	image* _imageName;
	animation* _motionName;
	RECT _rc;

	//��������
	EnemyState* _state;
	EnemyIdle* _idle;
	EnemyWalk* _walk;
	EnemyRun* _run;
	EnemyJump* _jump;
	EnemyAttack1* _attack1;
	EnemyAttack3* _attack3;
	EnemyDamaged* _damaged;
	EnemyDown* _down;
	EnemyGuard* _guard;
	EnemyUp* _up;
	


	float _posX, _posY;				//���ʹ� x, y ��ǥ
	float _probeX, _probeY;			//�ȼ� �浹 ��
	float _jumpPower, _gravity;		//����, �߷�
	float _distance; //�÷��̾���� �Ÿ� ���

	int _hp;	//�÷��̾� ü��
	

public:
	Enemy();
	~Enemy();

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, const char* animationName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void SwitchImage() = 0;

	void Move();
	void Draw();

	void Collision();

	void TracePlayer();
	void ChangeStatement();

	//���ʹ� ��Ʈ ������
	inline RECT GetRect() { return _rc; }

	//���ʹ� ���� ������, ������
	void SetEnemyStatement(ENEMYSTATEMENT enemyStatement) { _enemyStatement = enemyStatement; }
	ENEMYSTATEMENT GetEnemyStatement() { return _enemyStatement; }

	//���ʹ� ���� ������, ������
	void SetEnemyDirection(ENEMYDIRECTION enemyDirection) { _enemyDirection = enemyDirection; }
	ENEMYDIRECTION GetEnemyDirection() { return _enemyDirection; }

	//�̹��� ������
	image* GetImageName() { return _imageName; }
	

	//�ִϸ��̼� ������
	void SetMotionName(animation* motionName) { _motionName =  motionName; }
	animation* GetMotionName() { return _motionName; }

	//ī�޶� ����
	void SetCamera(CameraManager* cm) { _cm = cm; }
};

