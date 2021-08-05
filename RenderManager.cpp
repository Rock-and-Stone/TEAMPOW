#include "pch.h"
#include "RenderManager.h"
#include "gameNode.h"

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
}

HRESULT RenderManager::init()
{

	return S_OK;
}

void RenderManager::release()
{

}

void RenderManager::update()
{
	selectionSort();
	//bubbleSort();
}

void RenderManager::render(HDC hdc)
{
	char str[128];
	int i = 0;
	/*SetTextColor(hdc, RGB(255, 255, 255));
	char str[128];
	for (int i = 0; i < ARRSIZE; i++)
	{
		sprintf_s(str, "%d", _arr[i]);
		TextOut(hdc, 100 + 50 * i, 90, str, strlen(str));
	}*/

	for (_viRender = _vRender.begin(); _viRender != _vRender.end(); _viRender++)
	{
		(*_viRender)->render();

		sprintf_s(str, "%d", (*_viRender)->getRenderPosY());
		TextOut(hdc, 300, 90 + i* 30, str, strlen(str));

		i++;
	}
}


void RenderManager::selectionSort()
{
	int minIndex;
	int i, j;
	for (i = 0; i < ARRSIZE - 1; i++) 
	{
		minIndex = i;
		for (j = i + 1; j < 10; j++)
			if (_arr[j] < _arr[minIndex])
				minIndex = j;

		swap(&_arr[i], &_arr[minIndex]);
	}

	for (i = 0; i < _vRender.size() - 1; i++)
	{
		minIndex = i;
		for (j = i+1; j < _vRender.size(); j++)
			if (_vRender[j]->getRenderPosY() < _vRender[minIndex]->getRenderPosY())
				minIndex = j;
		

		swap(&_vRender[i], &_vRender[minIndex]);
	}
}

void RenderManager::bubbleSort()
{
	int i, j;
	for (i = ARRSIZE - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (_arr[j] > _arr[j + 1])
				swap(&_arr[j], &_arr[j + 1]);
		}
	}
}

void RenderManager::addRender(gameNode* obj)
{

	_vRender.push_back(obj);

}

void RenderManager::swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void RenderManager::swap(gameNode** a, gameNode** b)
{
	gameNode* temp = *a;
	*a = *b;
	*b = temp;
}
