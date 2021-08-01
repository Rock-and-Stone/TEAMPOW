#pragma once
#include "gameNode.h"
#include <vector>
#include "Luke.h"
#include "Mike.h"
#include "Malcolm.h"
#include "CameraManager.h"



class EnemyManager : public gameNode
{
private:
	typedef vector<Enemy*>				 vEnemy;
	typedef vector<Enemy*>::iterator	 viEnemy;

private:
	vEnemy	_vLuke;
	viEnemy _viLuke;

	vEnemy _vMike;
	viEnemy _viMike;

	vEnemy _vMalcolm;
	viEnemy _viMalcolm;

	CameraManager* _cm;
	
	

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void EnemyImageStorage();

	void SetLuke();
	void SetMike();
	void SetMalcolm();
	
	vector<Enemy*> GetVLuke() { return _vLuke; }
	vector<Enemy*>::iterator GetVILuke() { return _viLuke; }

	vector<Enemy*> GetVMike() { return _vMike; }
	vector<Enemy*>::iterator GetVIMike() { return _viMike; }

	vector<Enemy*> GetVMalcolm() { return _vMalcolm; }
	vector<Enemy*>::iterator GetVIMalcolm() { return _viMalcolm; }

	void SetCamera(CameraManager* cm) { _cm = cm; }
};

