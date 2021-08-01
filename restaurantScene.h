#pragma once
#include "gameNode.h"
class restaurantScene :
    public gameNode
{
private:
	image* _background;

	

public:
	restaurantScene();
	~restaurantScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

