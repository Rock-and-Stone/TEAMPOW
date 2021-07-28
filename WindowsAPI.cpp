#include "pch.h"
#include "playGround.h"

//인스턴스(메모리 상에 할당되어 실행중인 프로그램)
HINSTANCE _hInstance;

//윈도우 핸들
HWND _hWnd;

//마우스 포인트
POINT _ptMouse;

playGround _pg;

//함수의 프로토 타입 선언
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void setWindowsSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int cmdShow)
{
	_hInstance = hInstance;

	//윈도우 메세지 구조체
	MSG message;

	//윈도우 클래스 구조체
	WNDCLASS wndClass;

	wndClass.cbClsExtra = 0;		//클래스 여분 메모리
	wndClass.cbWndExtra = 0;		//윈도우 여분 메모리
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//윈도우 바탕색
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//윈도우 커서모양
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//아이콘 모양
	wndClass.hInstance = hInstance;									//인스턴스 부여
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//프로시저 설정
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	//윈도우를 위에 설정한 정보를 토대로 등록해준다
	RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		WINNAME,				//클래스 이름
		WINNAME,				//윈도우 이름
		WS_OVERLAPPEDWINDOW,	//윈도우 창 모양
		WINSTARTX,				//시작좌표 X (left)
		WINSTARTY,				//시작좌표 Y (top)
		WINSIZEX,				//윈도우 창 가로크기
		WINSIZEY,				//윈도우 창 세로크기
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	//클라이언트 영역 재조정 
	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	//실제로 윈도우 창을 우리 눈에 보이게 해주는 함수
	ShowWindow(_hWnd, cmdShow);

	if (FAILED(_pg.init()))
	{
		return NULL;
	}

	//GetMessage vs PeekMessage
	//겟메세지는 윈도우에서 처리해달라는 메세지가 넘어올때 동작하고
	//픽메세지는 메세지가 있든 없든 계속해서 동작하고 있다.

	while (true)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT) break;
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			TIMEMANAGER->update(60.0f);
			_pg.update();
			_pg.render();
		}
	}


	/* 잠시봉인
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);	//키 입력 등의 메시지 처리를 담당
		DispatchMessage(&message);	//실제 윈도우에 메시지를 전달해주는 역할 담당
	}
	*/
	_pg.release();

	UnregisterClass(WINNAME, _hInstance);

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return _pg.MainProc(hWnd, iMessage, wParam, lParam);
}

//클라이언트 영역 재조정 함수
void setWindowsSize(int x, int y, int width, int height)
{
	RECT winRect;

	winRect.left = 0;
	winRect.top = 0;
	winRect.right = width;
	winRect.bottom = height;

	//윈도우 사이즈 재조정을 해주는 함수
	AdjustWindowRect(&winRect, WINSTYLE, false);

	SetWindowPos(_hWnd, NULL, x, y, (winRect.right - winRect.left),
		(winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);

}