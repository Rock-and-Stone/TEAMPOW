#pragma once
#include "gameNode.h"
#include "CameraManager.h"

#define PLAYERWALKSPEED 3.0f

enum class PLAYERDIRECTION //�÷��̾� ���� ������ ���� ����
{
	RIGHT_IDLE,
	LEFT_IDLE,
	RIGHT_WALK,
	LEFT_WALK,
	RIGHT_RUN,
	LEFT_RUN,
	RIGHT_JUMP,
	LEFT_JUMP
};

class player : public gameNode
{
private:
	image* _img;					//�÷��̾� �̹���
	int _x, _y;						//�÷��̾� ������ǥ
	RECT _rc;						//�÷��̾� ��Ʈ

	CameraManager* _cm;				//ī�޶� ��ȣ����

	float _gravity, _jumpPower;	//���� �߷�, ���� ��
	int _jumpCount;					//���� Ƚ��

	PLAYERDIRECTION _direction;		//�÷��̾� ���ⱸ��

	animation* _playerMotion;		//�÷��̾� �ִϸ��̼�

	bool _isGroundCheak;			//�÷��̾ ���� ��Ҵ��� �ȴ�Ҵ���

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void SetCamera(CameraManager* cm) { _cm = cm; }

};
