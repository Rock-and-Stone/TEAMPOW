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
    _imageName = IMAGEMANAGER->findImage(imageName);

    _motionName = KEYANIMANAGER->findAnimation(animationName);

    _rc = RectMakeCenter(position.x, position.y,
        _imageName->getFrameWidth(), _imageName->getFrameHeight());

    return S_OK;
}

void Enemy::release()
{
}

void Enemy::update()
{
}

void Enemy::render()
{
    draw();
}

void Enemy::move()
{
}

void Enemy::draw()
{
    _imageName->aniRender(getMemDC(), _rc.left, _rc.top, _motionName);
}
