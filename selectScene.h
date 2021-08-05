#pragma once
#include "gameNode.h"

class SelectScene : public gameNode
{
private:
	RECT _selectRc;
	int _selectNum;
public:
	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
};
