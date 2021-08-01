#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

#define ARRSIZE 10

class RenderManager :  public singletonBase<RenderManager>
{
private:
	typedef map<image*, int>	arrOrder;
	typedef map<image*, int>::iterator	iterOrder;

	int _arr[ARRSIZE] = { 2 , 5 ,1 , 4 , 7 , 8 , 9, 3, 11, 10 };

private:
	arrOrder _zOrder;

public:
	RenderManager();
	~RenderManager();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void swap(int* a, int* b);
	void selectionSort();
	void bubbleSort();

	void addImage(image* img, int posY);
};

