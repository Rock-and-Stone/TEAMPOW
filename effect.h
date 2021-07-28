#pragma once
#include "gameNode.h"

class animation;

class effect : public gameNode
{
protected:
	int _x;
	int _y;

	image* _effectImage;
	animation* _effectAnimation;
	BOOL _isRunning;
	float _elapsedTime;

public:
	effect();
	virtual ~effect();

	HRESULT init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime);
	void release();
	void update();
	void render();

	void startEffect(int x, int y);

	void killEffect();

	BOOL getIsRunning() { return _isRunning; }

};

