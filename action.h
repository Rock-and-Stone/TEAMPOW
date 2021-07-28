#pragma once
#include "gameNode.h"

//보간개념

class action : public gameNode
{
private:
	image* _image;
	float _startX, _startY;
	float _endX, _endY;
	float _angle;
	float _travelRange;
	float _time;
	float _worldTimeCount;

	bool _isMoving;

public:
	action();
	~action();

	HRESULT init();
	void release();
	void update();
	void render();

	//움직이게 할 것.
	void moveTo(image* image, float endX, float endY, float time);

	void moving();
	
	bool getIsMoving() { return _isMoving; }

};

