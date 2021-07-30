#include "pch.h"
#include "player.h"

HRESULT player::init()
{
	_img = IMAGEMANAGER->addFrameImage("playerIdle", "img/Idle.bmp", 2070, 960, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerWalk", "img/walk.bmp", 2070, 960, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerRun", "img/Run.bmp", 2760, 960, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("playerJump", "img/jump.bmp", 3105, 960, 9, 2, true, RGB(255, 0, 255));

	_direction = PLAYERDIRECTION::RIGHT_IDLE;

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;
	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

	int rightIdle[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("RightIdle", "playerIdle", rightIdle, 6, 6, true);
	int leftIdle[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("LeftIdle", "playerIdle", leftIdle, 6, 6, true);

	int rightWalk[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("RightWalk", "playerWalk", rightWalk, 6, 9, true);
	int leftWalk[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("LeftWalk", "playerWalk", leftWalk, 6, 9, true);

	int rightJump[] = { 9,10,11,12,13,14,15,16,17 };
	KEYANIMANAGER->addArrayFrameAnimation("RightJump", "playerJump", rightJump, 9, 5, false);
	int leftJump[] = { 0,1,2,3,4,5,6,7,8 };
	KEYANIMANAGER->addArrayFrameAnimation("LeftJump", "playerJump", leftJump, 9, 5, false);

	_playerMotion = KEYANIMANAGER->findAnimation("RightIdle");

	_gravity = _jumpPower = _jumpCount = 0;

	_isGroundCheak = true;	//땅에 닿음 : true , 땅에 안닿음 : false

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	if (KEYMANAGER->isOnceKeyDown('D')) //플레이어 오른쪽 방향으로 걷기
	{
		_direction = PLAYERDIRECTION::RIGHT_WALK;
		_playerMotion = KEYANIMANAGER->findAnimation("RightWalk");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyUp('D')) //플레이어 오른쪽 방향으로 Idle
	{
		_direction = PLAYERDIRECTION::RIGHT_IDLE;
		_playerMotion = KEYANIMANAGER->findAnimation("RightIdle");
		_playerMotion->start();
	}

	if (KEYMANAGER->isOnceKeyDown('A')) //플레이어 왼쪽 방향으로 걷기
	{
		_direction = PLAYERDIRECTION::LEFT_WALK;
		_playerMotion = KEYANIMANAGER->findAnimation("LeftWalk");
		_playerMotion->start();
	}
	if (KEYMANAGER->isOnceKeyUp('A')) //플레이어 왼쪽 방향으로 Idle
	{
		_direction = PLAYERDIRECTION::LEFT_IDLE;
		_playerMotion = KEYANIMANAGER->findAnimation("LeftIdle");
		_playerMotion->start();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE)) //스페이스 누르면 점프
	{
		_jumpPower = 8.0f;

		//첫방법 : 오른쪽보고잇으면 오른쪽 점프 이미지 , 왼쪽 보고있으면 왼쪽으로 점프 이미지
		/*if (_direction == PLAYERDIRECTION::RIGHT_WALK || _direction == PLAYERDIRECTION::RIGHT_IDLE)
		{
			_direction = PLAYERDIRECTION::RIGHT_JUMP;
			_playerMotion = KEYANIMANAGER->findAnimation("RightJump");
			_playerMotion->start();
		}
		else if (_direction == PLAYERDIRECTION::RIGHT_WALK || _direction == PLAYERDIRECTION::RIGHT_IDLE)
		{
			_direction = PLAYERDIRECTION::LEFT_JUMP;
			_playerMotion = KEYANIMANAGER->findAnimation("LeftJump");
			_playerMotion->start();
		}*/

		switch (_direction) //2방법 : 오른쪽보고잇으면 오른쪽 점프 이미지 , 왼쪽 보고있으면 왼쪽으로 점프 이미지
		{
		case PLAYERDIRECTION::RIGHT_IDLE: case PLAYERDIRECTION::RIGHT_WALK: case PLAYERDIRECTION::RIGHT_RUN:
			_direction = PLAYERDIRECTION::RIGHT_JUMP;
			_playerMotion = KEYANIMANAGER->findAnimation("RightJump");
			_playerMotion->start();
			break;
		case PLAYERDIRECTION::LEFT_IDLE: case PLAYERDIRECTION::LEFT_WALK: case PLAYERDIRECTION::LEFT_RUN:
			_direction = PLAYERDIRECTION::LEFT_JUMP;
			_playerMotion = KEYANIMANAGER->findAnimation("LeftJump");
			_playerMotion->start();
			break;
		default:
			break;
		}
	}

	switch (_direction)
	{
	case PLAYERDIRECTION::RIGHT_IDLE:
		_img = IMAGEMANAGER->findImage("playerIdle");
		break;
	case PLAYERDIRECTION::RIGHT_WALK:
		_x += PLAYERWALKSPEED;
		_img = IMAGEMANAGER->findImage("playerWalk");
		break;
	case PLAYERDIRECTION::RIGHT_JUMP:
		_img = IMAGEMANAGER->findImage("playerJump");
		_gravity = 0.2f;
		_jumpPower -= _gravity;
		_y -= _jumpPower;

		//오른쪽 임시 땅 만들기
		if (_y > WINSIZEY / 2)
		{
			_direction = PLAYERDIRECTION::RIGHT_IDLE;
			_playerMotion = KEYANIMANAGER->findAnimation("RightIdle");
			_playerMotion->start();
		}
		break;

	case PLAYERDIRECTION::LEFT_IDLE:
		_img = IMAGEMANAGER->findImage("playerIdle");
		break;
	case PLAYERDIRECTION::LEFT_WALK:
		_x -= PLAYERWALKSPEED;
		_img = IMAGEMANAGER->findImage("playerWalk");
		break;
	case PLAYERDIRECTION::LEFT_JUMP:
		_img = IMAGEMANAGER->findImage("playerJump");
		_gravity = 0.2f;
		_jumpPower -= _gravity;
		_y -= _jumpPower;

		//혹시모르니 왼쪽도 임시 땅 만들기
		if (_y > WINSIZEY / 2)
		{
			_direction = PLAYERDIRECTION::LEFT_IDLE;
			_playerMotion = KEYANIMANAGER->findAnimation("LeftIdle");
			_playerMotion->start();
		}
		break;
	}

	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

	KEYANIMANAGER->update();

}

void player::render()
{
	_img->aniRender(getMemDC(), _rc.left - _cm->getCamX(), _rc.top - _cm->getCamY() , _playerMotion);

	

	char str[128];

	SetTextColor(getMemDC(), RGB(0, 0, 0));

	sprintf_s(str, "direction : %d", (int)_direction);
	TextOut(getMemDC(), 10, 10, str, strlen(str));

	sprintf_s(str, "direction : %d", _y);
	TextOut(getMemDC(), 10, 10, str, strlen(str));

}