#include "pch.h"
#include "Luke.h"

Luke::Luke()
{
}

Luke::~Luke()
{
}

HRESULT Luke::init()
{
	

	return S_OK;
}

void Luke::release()
{
}

void Luke::update()
{

	SwitchImage();
	
}

void Luke::SwitchImage()
{
	//어떤 상황의 패턴
	//_imageName = IMAGEMANAGER->findImage("LUKE_IDLE");
	//_motionName = KEYANIMANAGER->findAnimation("LUKEleftIdle");

	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		_imageName = IMAGEMANAGER->findImage("LUKE_JUMP");
		_motionName = KEYANIMANAGER->findAnimation("LUKEleftJump");
		_motionName->start();
	}
	
}



