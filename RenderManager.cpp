#include "pch.h"
#include "RenderManager.h"

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
	bubbleSort();
}

void RenderManager::render(HDC hdc)
{
	/*SetTextColor(hdc, RGB(255, 255, 255));
	char str[128];
	for (int i = 0; i < ARRSIZE; i++)
	{
		sprintf_s(str, "%d", _arr[i]);
		TextOut(hdc, 100 + 50 * i, 90, str, strlen(str));
	}*/
}


void RenderManager::selectionSort()
{
	int minIndex;
	int i, j;
	for (i = 0; i < ARRSIZE - 1; i++) {
		minIndex = i;
		for (j = i + 1; j < 10; j++)
			if (_arr[j] < _arr[minIndex])
				minIndex = j;

		swap(&_arr[i], &_arr[minIndex]);
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

void RenderManager::addImage(image* img, int posY)
{
	_zOrder.insert(pair<image*, int>(img, posY));
}

void RenderManager::swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
