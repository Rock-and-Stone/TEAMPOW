#pragma once
#include "gameNode.h"

//에너미 방향 enum 클래스
enum class ENEMYDIRECTION
{
	LEFT,
	RIGHT
};

//에너미 상태 enum 클래스
enum class ENEMYSTATEMENT
{
	INIT,						//등장
	IDLE,						//기본
	WALK,						//걷기
	RUN,						//뛰기
	JUMP,						//점프
	ATTACK1,					//약공격1
	ATTACK2,					//약공격2(콤보)
	ATTACK3,					//강공격1
	ATTACK4,					//강공격2(콤보)
	DAMAGED,					//피격
	DOWN,						//피격시 다운(죽음)
	DOWN_DAMAGED,				//누운상태에서의 피격
	DOWN_ATTACK,				//누운상태에서 공격
	UP,							//누운상태에서 일어나기
	GUARD,						//가드
	OBJECT_ATTACK,				//오브젝트 들고 공격
	OBJECT_THROW,				//오브젝트 던지기
	OBJECT_GRAB					//오브젝트 들기
};

class Enemy : public gameNode
{
protected:
	ENEMYDIRECTION _enemyDirection;
	ENEMYSTATEMENT _enemyStatement;

	image* _imageName;
	animation* _motionName;
	RECT _rc;

	float _posX, _posY;
	

public:
	Enemy();
	~Enemy();

	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, const char* animationName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();

	void move();
	void draw();

	inline RECT GetRect() { return _rc; }

};

