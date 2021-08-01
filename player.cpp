#include "pch.h"
#include "player.h"

player::player()
{
}

player::~player()
{
}

HRESULT player::InitVariables()
{
	return S_OK;
}

HRESULT player::init()
{
	IMAGEMANAGER->addFrameImage("Ramona_Idle", "Ramona/Idle.bmp", 2070, 960, 6, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("Ramona_Jump", "Ramona/Jump_Loop.bmp", 345, 960, 1, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("Ramona_Fall", "Ramona/Fall.bmp", 2070, 960, 6, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("Ramona_Walk", "Ramona/Walk.bmp", 2070, 960, 6, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("Ramona_Land", "Ramona/Walk.bmp", 345, 960, 1, 2, true, MAGENTA);
	IMAGEMANAGER->addFrameImage("Ramona_Run", "Ramona/Run.bmp", 2760, 960, 8, 2, true, MAGENTA);


#pragma region Variables
	_posX = 200;
	_posY = WINSIZEY / 2;

	_gravity = 0;
	_jumpPower = 0;

	_dirX = 0;
	_dirY = 0;
	_indexX = 0;
	_keyCount = 0;
	_animLoop = true;
	_trigger = false;
	_isAir = false;
	_isAttack = false;

	_statement = Statement::IDLE;
#pragma endregion

	return S_OK;
}

void player::release()
{

}

void player::update()
{

}

void player::render(int posX, int posY)
{
	int absolX, absolY;

	absolX = posX - (_renderRC.right - _renderRC.left) / 2;
	absolY = posY - (_renderRC.bottom - _renderRC.top) / 2;

	_img->frameRender(getMemDC(), absolX, absolY, _indexX, _dirX);
	_hitRC = RectMakeCenter(posX, posY, 70, 150);
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _hitRC);
	}

}

void player::KeyPress()
{
	if (_keyCount > 0) ChangeState(Statement::WALK);
	else ChangeState(Statement::IDLE);
}


void player::Input()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			_keyCount++;
			KeyPress();
			_speedX = 5;
			_dirX = 0;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			_keyCount++;
			KeyPress();
			_speedX = 5;
			_dirX = 1;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_keyCount++;
			KeyPress();

			_speedY = 2;
			_dirY = 0;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_keyCount++;
			KeyPress();
			KeyPress();
			_speedY = 2;
			_dirY = 1;
		}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
		_keyCount--;
		KeyPress();
			_speedX = 0;
			_dirX = 0;
		}

		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_keyCount--;
			KeyPress();
			_speedX = 0;
			_dirX = 1;
		}

		if (KEYMANAGER->isOnceKeyUp(VK_UP))
		{
			_keyCount--;
			KeyPress();
			_speedY = 0;
			_dirY = 1;
		}

		if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
		{
			_keyCount--;
			KeyPress();
			_speedY = 0;
			_dirY = 1;
		}

}

void player::Movement()
{

	if (_dirX == 0)_posX -= _speedX;
	else _posX += _speedX;

	if (_dirY == 0)_posY -= _speedY;
	else _posY += _speedY;

	if (_isAir)
	{
		_gravity = 0.52f;

		_posY -= _jumpPower;

		_jumpPower -= _gravity;
	}
	else
	{
		_gravity = 0;
		_jumpPower = 0;
	}

}

void player::CountFrame()
{
	_count++;

	_img->setFrameX(_indexX);
	_img->setFrameY(_dirX);

	if (_count % 7 == 0)
	{
		//맥스 프레임 조건 확인.
		_indexX++;

		if (_indexX > _img->getMaxFrameX())  // 최대 프레임 도달
		{
			if (_animLoop) _indexX = 0; // 루프일때 프레임 초기화

			else // 루프가 아닐때
			{
				_indexX = _img->getMaxFrameX(); // 프레임 고정
				_trigger = true;
			}
		}

		_count = 0;
	}
}

void player::Collision()
{

}

void player::ChangeState(Statement statement)
{
	_indexX = 0;
	_trigger = false;
	_isAttack = false;

	_statement = statement;
}

