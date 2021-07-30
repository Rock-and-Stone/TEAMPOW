#pragma once
#include "gameNode.h"
#include "CameraManager.h"

#define PLAYERWALKSPEED 3.0f

enum class PLAYERDIRECTION //플레이어 왼쪽 오른쪽 방향 구분
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
	image* _img;					//플레이어 이미지
	int _x, _y;						//플레이어 중점좌표
	RECT _rc;						//플레이어 렉트

	CameraManager* _cm;				//카메라 상호참조

	float _gravity, _jumpPower;	//점프 중력, 점프 힘
	int _jumpCount;					//점프 횟수

	PLAYERDIRECTION _direction;		//플레이어 방향구분

	animation* _playerMotion;		//플레이어 애니메이션

	bool _isGroundCheak;			//플레이어가 땅에 닿았는지 안닿았는지

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void SetCamera(CameraManager* cm) { _cm = cm; }

};
