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

    _posX = position.x;
    _posY = position.y;

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
    draw();
}

void Enemy::move()
{

}

void Enemy::draw()
{
    _imageName->aniRender(getMemDC(), _rc.left - _cm->getCamX() , _rc.top - _cm->getCamY(), _motionName);
}
