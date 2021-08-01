#pragma once
#include "gameNode.h"
class convenientScene :
    public gameNode
{
private:
	image* _background;

public:
	convenientScene();
	~convenientScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

