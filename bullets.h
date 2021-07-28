#pragma once
#include "gameNode.h"
#include <vector>

struct tagBullet
{
	image* bulletImage;		//총알의 이미지
	RECT rc;				//총알의 렉트
	float x, y;				//총알의 중점
	float angle;			//총알의 각도
	float radius;			//총알의 반지름
	float speed;			//총알의 스피드
	float fireX, fireY;		//총알의 발사위치
	bool isFire;			//총알의 발사유무
	int count;
};

//공용으로 사용할 총알 클라쓰
class bullet : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;
public:
	bullet() {};
	~bullet() {};

	HRESULT init(const char* imageName, int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed);

	void move();

	void removeBullet(int arrNum);

	vector<tagBullet> getVBullet()			 { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }

};


//기존의 방식 (만들어두고 발사하는 미쏼)
class missile : public gameNode
{
private:
	vector<tagBullet>			_vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;		//미사일 사거리(응?)

public:
	missile() {}
	~missile() {}

	virtual HRESULT init(int bulletMax, float range);
	virtual void release();
	virtual void update();
	virtual void render();

	//총알 발사 함수
	void fire(float x, float y);

	//총알 움직이는 함수
	void move();

};


//쏠때 생성하는 방식
class hellFire : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	float _range;
	int _bulletMax;

public:
	hellFire() {};
	~hellFire() {};


	virtual HRESULT init(int bulletMax, float range);
	virtual void release();
	virtual void update();
	virtual void render();

	void fire(float x, float y);
	void move();

	void removeMissile(int arrNum);

	vector<tagBullet> getVBullet() { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet() { return _viBullet; }

};