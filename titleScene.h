#pragma once
#pragma comment (lib, "Vfw32.lib")

#include "gameNode.h"
#include <Vfw.h>

class titleScene :public gameNode
{
private:
	image* _titleBG;
	HWND _opening;
	bool _isSelect;

public:
	titleScene();
	~titleScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
};

