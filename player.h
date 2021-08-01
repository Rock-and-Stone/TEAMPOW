#pragma once
#include "gameNode.h"
#include "CameraManager.h"


enum class Statement
{
	IDLE,
	RUN,
	WALK,
	JUMP,
	FALL,
	LAND
};

class player : public gameNode
{
protected:

	Statement		_statement;
	RECT			_renderRC;
	RECT			_hitRC;
	image*			_img;

	int				_dirX;
	int				_dirY;
	int				_indexX;
	int				_count;
	int				_jumpCount;

	bool			_animLoop;
	bool			_trigger;
	bool			_isAttack;
	bool			_isAir;

	int				_posX, _posY;
	int				_probeX, _probeY;
	int				_jumpPower, _gravity;
	int				_keyCount;


	int				_speedX;
	int				_speedY;

public:
	player();
	~player();

	virtual HRESULT InitVariables();
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(int posX, int posY);

	void Input();

	void Movement();

	void CountFrame();

	void Collision();

	void ChangeState(Statement statement);

	bool getTrigger() { return _trigger; }

	void KeyPress();

	Statement getStatement() { return _statement; }
	void SetStatement(Statement statement) { _statement = statement; }

	void setAnimLoop(bool loop) { _animLoop = loop; }

	int getPosX() { return _posX; }
	void setPosX(int posX) { _posX = posX; }

	int getPosY() { return _posY; }
	void setPosY(int posY) { _posY = posY; }

	bool getIsAir() { return _isAir; }
	void setIsAir(bool isAir) { _isAir = isAir; }
};

