#pragma once
class EnemyState
{
private:

public:
	EnemyState();
	~EnemyState();

	virtual HRESULT init() = 0;
	virtual void release() = 0;
	virtual void update() = 0;
};

