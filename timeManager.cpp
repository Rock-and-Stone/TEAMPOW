#include "pch.h"
#include "timeManager.h"


timeManager::timeManager()
	: _timer(nullptr)
{
}


timeManager::~timeManager()
{
}

HRESULT timeManager::init()
{
	_timer = new timer;
	_timer->init();

	return S_OK;
}

void timeManager::release()
{
	if (_timer != nullptr)
	{
		SAFE_DELETE(_timer);
	}
}

void timeManager::update(float lock)
{
	if (_timer != nullptr) _timer->tick(lock);

}

void timeManager::render(HDC hdc)
{
	char str[256];
	string strFrame;

	//글자 배경모드
	SetBkMode(hdc, TRANSPARENT);

	SetTextColor(hdc, RGB(255, 255, 255));

#ifdef _DEBUG
	if (_timer != nullptr)
	{
		//프레임 출력
		wsprintf(str, "framePerSec : %d", _timer->getFrameRate());
		TextOut(hdc, 0, 0, str, strlen(str));

		//월드 타임 (경과시간)
		sprintf_s(str, "worldTime : %f", _timer->getWorldTime());
		TextOut(hdc, 0, 20, str, strlen(str));

		//갱신 tick Time.deltaTime
		sprintf_s(str, "elapsedTime : %f", _timer->getElapsedTime());
		TextOut(hdc, 0, 40, str, strlen(str));

	}
#else
	if (_timer != nullptr)
	{
		//프레임 출력
		wsprintf(str, "framePerSec : %d", _timer->getFrameRate());
		TextOut(hdc, 0, 0, str, strlen(str));
	}
#endif

}
