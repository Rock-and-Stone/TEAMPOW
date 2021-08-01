#pragma once
#include "player.h"

class Ramona :public player
{
private:

public:
	Ramona();
	~Ramona();

	virtual HRESULT InitVariables();

	virtual void update();

	virtual void SwitchImage();

};

