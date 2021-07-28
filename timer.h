#pragma once
class timer
{
private:
	float _timeScale;				//�ð� �����
	float _timeElapsed;				//ƽ �ֱ�
	__int64 _curTime;				//���� �ð�
	__int64 _lastTime;				//������ �ð� (�ֱ� ���)
	__int64 _periodFrequency;		//�ֱ�

	unsigned long _frameRate;		//������ ��
	unsigned long _FPSframeCount;	//������ ī��Ʈ 
	float _FPSTimeElapsed;			//�� ������ �� �����
	float _worldTime;				//�� �۵� �ð�

public:
	timer();
	~timer();

	HRESULT init();
	void tick(float lockFPS = 0.0f);
	unsigned long getFrameRate(char* str = nullptr) const;
	inline float getElapsedTime() const { return _timeElapsed; }
	inline float getWorldTime() const { return _worldTime; }
};

