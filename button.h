#pragma once
#include "gameNode.h"

//함수포인터 형태를 가진 콜백함수
typedef void(*CALLBACK_FUNCTION)(void);

//공부꺼리~ 물론 안하셔도 됩니다 자유
//<Functional> 이런 라이브러리가 있는데
//std::Function, std::move, std::bind 등등의 함수가 존재함
//요걸 잘 섞어서 사용하게 되면 일반적인 매개변수를 넣은 콜백함수를 사용할 수 있음.

//함정1) 너무 의외로 쉬워서 진짜 이게 정답인가? 의문이 들수있다
//꿀팁) Lambda expression, 람다식이랑 섞어쓰면 너무 좋다
//      람다식 == 익명함수 <-- 조사해보면 죠오습니다
//함수<>{}


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

	//콜백함수 선언
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

