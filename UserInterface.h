#pragma once
#include "gameNode.h"

class UserInterface : public gameNode
{
private:

	image* _hp100;
	image* _hp10;
	image* _hp1;

	image* _gp100;
	image* _gp10;
	image* _gp1;

	image* _coin100;
	image* _coin10;
	image* _coin1;

	image* _option;

	bool _isPause;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	bool GetIsPause() { return _isPause; }

};

