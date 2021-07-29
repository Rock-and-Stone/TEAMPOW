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
}

void Luke::render()
{
	_imageName = IMAGEMANAGER->findImage("LUKE_IDLE");
}
