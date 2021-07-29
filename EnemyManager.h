#pragma once
#include "gameNode.h"
#include <vector>
#include "Luke.h"

class EnemyManager : public gameNode
{
private:
	typedef vector<Enemy*>				 vEnemy;
	typedef vector<Enemy*>::iterator	 viEnemy;

private:
	vEnemy	_vLuke;
	viEnemy _viLuke;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void EnemyImageStorage();

	void SetLuke();
	
	vector<Enemy*> GetVLuke() { return _vLuke; }
	vector<Enemy*>::iterator GetVILuke() { return _viLuke; }

};

