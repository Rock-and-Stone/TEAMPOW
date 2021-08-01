#pragma once
#include "gameNode.h"
class sushiScene : public gameNode
{
private:
	image* _background;

public:
	sushiScene();
	~sushiScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

