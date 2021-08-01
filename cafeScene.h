#pragma once
#include "gameNode.h"
class cafeScene :
    public gameNode
{
private:
	image* _background;

public:
	cafeScene();
	~cafeScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

