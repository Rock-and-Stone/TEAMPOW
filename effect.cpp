#include "pch.h"
#include "effect.h"
#include "animation.h"

effect::effect()
	: _effectImage(nullptr), _effectAnimation(nullptr),
	_isRunning(false), _x(0), _y(0)
{
}


effect::~effect()
{
}

HRESULT effect::init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime)
{
	//이펙트 이미지가 없으면 실패를 띄워라
	if (!effectImage) return E_FAIL;

	_isRunning = false;

	_effectImage = effectImage;
	_elapsedTime = elapsedTime;

	if (!_effectAnimation) _effectAnimation = new animation;

	_effectAnimation->init(_effectImage->getWidth(), _effectImage->getHeight(), frameW, frameH);
	_effectAnimation->setDefPlayFrame(false, false);
	_effectAnimation->setFPS(fps);
	_effectAnimation->stop();

	return S_OK;
}

void effect::release()
{
	_effectImage = nullptr;
	SAFE_DELETE(_effectAnimation);
}

void effect::update()
{
	//애니메이션이 재생중이 아니라면 실행하지 않는다
	if (!_isRunning) return;

	_effectAnimation->frameUpdate(_elapsedTime);

	//애니메이션이 재생중이지 않으면 애니메이션을 작동중지하자
	if (!_effectAnimation->isPlay()) killEffect();

}

void effect::render()
{
	if (!_isRunning) return;

	_effectImage->aniRender(getMemDC(), _x, _y, _effectAnimation);
}

void effect::startEffect(int x, int y)
{
	if (!_effectImage || !_effectAnimation) return;

	//이펙트 시작은 중점좌표로
	_x = x - (_effectAnimation->getFrameWidth() / 2);
	_y = y - (_effectAnimation->getFrameHeight() / 2);

	_isRunning = true;
	_effectAnimation->start();
}

void effect::killEffect()
{
	_isRunning = false;
}
