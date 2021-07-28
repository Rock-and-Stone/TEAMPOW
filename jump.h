#pragma once
#include "gameNode.h"

class jump : public gameNode
{
private:
	float _jumpPower;
	float _gravity;

	float* _x;
	float* _y;

	float _startX;	//¿¹Á¦¿ë
	float _startY;

	bool _isJumping;
public:
	jump();
	~jump();

	HRESULT init();
	void release();
	void update();
	void render();

	//½ÇÁ¦·Î Â«»Ñ¶Ù¾îÁÙ ÇÔ¼ö
	void jumping(float* x, float* y, float power, float gravity);

	bool getIsJumping() { return _isJumping; }
};

