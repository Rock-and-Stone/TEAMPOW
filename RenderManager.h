#pragma once
#include "singletonBase.h"

#include <vector>


#define ARRSIZE 10


class gameNode;

class RenderManager :  public singletonBase<RenderManager>
{
private:

	typedef vector<gameNode*>				arrRender;
	typedef vector<gameNode*>::iterator		iterRender;

	int _arr[ARRSIZE] = { 2 , 5 ,1 , 4 , 7 , 8 , 9, 3, 11, 10 };

private:
	arrRender _vRender;
	iterRender _viRender;

public:
	RenderManager();
	~RenderManager();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void swap(int* a, int* b);
	void swap(gameNode** a, gameNode** b);
	void selectionSort();
	void bubbleSort();
	void addRender(gameNode * obj);

};

