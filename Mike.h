#pragma once
#include "Enemy.h"
class Mike :
    public Enemy
{
private:

public:
	Mike();
	~Mike();

	virtual HRESULT init();
	virtual void release();
	virtual void update();


	virtual void SwitchImage() override;
};

