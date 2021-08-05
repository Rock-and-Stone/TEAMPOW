#pragma once
#include "EnemyState.h"
class Enemy;
class EnemyRun :
    public EnemyState
{
private:
	Enemy* _enemy;

public:

	virtual HRESULT init() override;
	virtual void release() override;
	virtual void update() override;

	void SetEnemy(Enemy* enemy) { _enemy = enemy; }
};

