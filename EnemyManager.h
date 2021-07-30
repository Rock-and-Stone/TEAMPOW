#pragma once
#include "gameNode.h"
#include <vector>
#include "Luke.h"
#include "CameraManager.h"



class EnemyManager : public gameNode
{
private:
	typedef vector<Enemy*>				 vEnemy;
	typedef vector<Enemy*>::iterator	 viEnemy;

private:
	vEnemy	_vLuke;
	viEnemy _viLuke;

	CameraManager* _cm;
	
	
	
	

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void EnemyImageStorage();

	void SetLuke();
	
	vector<Enemy*> GetVLuke() { return _vLuke; }
	vector<Enemy*>::iterator GetVILuke() { return _viLuke; }

	void SetCamera(CameraManager* cm) { _cm = cm; }
};

