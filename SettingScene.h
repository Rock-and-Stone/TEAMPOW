#pragma once
#include "gameNode.h"

class SettingScene : public gameNode
{
private:
public:
	virtual HRESULT init();
	virtual void update();
	virtual void release();
	virtual void render();
};

