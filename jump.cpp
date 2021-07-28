#include "pch.h"
#include "jump.h"


jump::jump()
{
}


jump::~jump()
{
}

HRESULT jump::init()
{
	_isJumping = _jumpPower = _gravity = 0;


	return S_OK;
}

void jump::release()
{
}

void jump::update()
{
	if (!_isJumping) return;

	*_y -= _jumpPower;
	_jumpPower -= _gravity;

	//맨 처음 뛴자리보다 밑으로 내려가면 멈춘다
	if (_startY < *_y)
	{
		_isJumping = false;
		*_y = _startY;
	}
	
}

void jump::render()
{
}

void jump::jumping(float * x, float * y, float power, float gravity)
{
	if (_isJumping) return;

	_isJumping = true;

	_x = x;
	_y = y;

	_startX = *x;
	_startY = *y;

	_gravity = gravity;
	_jumpPower = power;
}
