#pragma once
#include "image.h"

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);

class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;
	
public:
	gameNode();
	virtual ~gameNode();	//���� �Ҹ��� �����ϸ� ���ܴ� ��ζ�

	virtual HRESULT init();			//�ʱ�ȭ �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release();			//�޸� ���� �Խ�
	virtual void update();			//�����ϴ� �Լ�
	virtual void render();	//�׸��� �Լ�

	//������� DC������ ���� ������
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }


	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);

};

