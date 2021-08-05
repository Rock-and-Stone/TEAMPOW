#include "pch.h"
#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

HRESULT Enemy::init()
{
    return S_OK;
}

HRESULT Enemy::init(const char* imageName, const char* animationName, POINT position)
{

#pragma region STATES
    _idle = new EnemyIdle;
    _walk = new EnemyWalk;
    _run = new EnemyRun;
    _jump = new EnemyJump;
    _attack1 = new EnemyAttack1;
    _attack3 = new EnemyAttack3;
    _damaged = new EnemyDamaged;
    _down = new EnemyDown;
    _up = new EnemyUp;
    _guard = new EnemyGuard;

    _idle->SetEnemy(this);
    _walk->SetEnemy(this);
    _run->SetEnemy(this);
    _jump->SetEnemy(this);
    _attack1->SetEnemy(this);
    _attack3->SetEnemy(this);
    _damaged->SetEnemy(this);
    _down->SetEnemy(this);
    _up->SetEnemy(this);
    _guard->SetEnemy(this);

    _state = _idle;
    _enemyStatement = ENEMYSTATEMENT::IDLE;

#pragma endregion
    _imageName = IMAGEMANAGER->findImage(imageName);

    _motionName = KEYANIMANAGER->findAnimation(animationName);

    _posX = position.x;
    _posY = position.y;

    _gravity = _jumpPower = 0;

    _rc = RectMakeCenter(_posX, _posY,
        _imageName->getFrameWidth(), _imageName->getFrameHeight());

    _motionName->start();

   
    

    return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{
   
    _rc = RectMakeCenter(_posX, _posY,
        _imageName->getFrameWidth(), _imageName->getFrameHeight());

   
}

void Enemy::render()
{
    Draw();
}

void Enemy::Move()
{

}

void Enemy::Draw()
{
    _imageName->aniRender(getMemDC(), _rc.left - _cm->getCamX() , _rc.top - _cm->getCamY(), _motionName);
}

void Enemy::Collision()
{
}

void Enemy::TracePlayer()
{
}

void Enemy::ChangeStatement()
{
}
