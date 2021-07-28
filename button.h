#pragma once
#include "gameNode.h"

//�Լ������� ���¸� ���� �ݹ��Լ�
typedef void(*CALLBACK_FUNCTION)(void);

//���β���~ ���� ���ϼŵ� �˴ϴ� ����
//<Functional> �̷� ���̺귯���� �ִµ�
//std::Function, std::move, std::bind ����� �Լ��� ������
//��� �� ��� ����ϰ� �Ǹ� �Ϲ����� �Ű������� ���� �ݹ��Լ��� ����� �� ����.

//����1) �ʹ� �ǿܷ� ������ ��¥ �̰� �����ΰ�? �ǹ��� ����ִ�
//����) Lambda expression, ���ٽ��̶� ����� �ʹ� ����
//      ���ٽ� == �͸��Լ� <-- �����غ��� �ҿ����ϴ�
//�Լ�<>{}


enum BUTTONDIRECTION
{
	BUTTONDIRECTION_NULL,
	BUTTONDIRECTION_UP,
	BUTTONDIRECTION_DOWN
};

class button : public gameNode
{
private:
	BUTTONDIRECTION _direction;

	const char* _imageName;
	image* _image;
	RECT _rc;
	float _x, _y;

	POINT _btnDownFramePoint;
	POINT _btnUpFramePoint;

	//�ݹ��Լ� ����
	CALLBACK_FUNCTION _callbackFunction;

public:
	button();
	~button();

	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTION cbFunction);

	void release();
	void update();
	void render();
};

