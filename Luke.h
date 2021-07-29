#pragma once
#include "Enemy.h"
class Luke : public Enemy
{
public:
	Luke();
	~Luke();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

