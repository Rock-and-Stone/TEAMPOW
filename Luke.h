#pragma once
#include "Enemy.h"

class Luke : public Enemy
{
private:

public:
	Luke();
	~Luke();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	

	virtual void SwitchImage() override;
};

