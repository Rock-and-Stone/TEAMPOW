#include "pch.h"
#include "timer.h"
#include <mmsystem.h>

//TimeGetTime() �Լ��� ����ϱ� ���� ���̺귯��
#pragma comment (lib, "winmm.lib")


timer::timer()
{
}


timer::~timer()
{
}

HRESULT timer::init()
{
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency))
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

		_timeScale = 1.0f / _periodFrequency;
	}

	_frameRate = 0;
	_FPSframeCount = 0;
	_FPSTimeElapsed = 0;
	_worldTime = 0;

	return S_OK;
}

void timer::tick(float lockFPS)
{
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);

	_timeElapsed = (_curTime - _lastTime) * _timeScale;

	if (lockFPS > 0.0f)
	{
		//���� �̺κ��� ������ ��Ű���̶�� ��
		while (_timeElapsed < (1.0f / lockFPS))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);

			_timeElapsed = (_curTime - _lastTime) * _timeScale;
			
		}
	}

	_lastTime = _curTime;
	_FPSframeCount++;
	_FPSTimeElapsed += _timeElapsed;
	_worldTime += _timeElapsed;

	if (_FPSTimeElapsed > 1.0f)
	{
		_frameRate = _FPSframeCount;
		_FPSframeCount = 0;
		_FPSTimeElapsed = 0.0f;
	}

}

unsigned long timer::getFrameRate(char* str) const
{
	if (str != nullptr)
	{
		wsprintf(str, "FPS : %d", _frameRate);
	}


	return _frameRate;
}
