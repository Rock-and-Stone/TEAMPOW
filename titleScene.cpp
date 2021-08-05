#include "pch.h"
#include "titleScene.h"

titleScene::titleScene()
{
}

titleScene::~titleScene()
{
}

HRESULT titleScene::init()
{
	_titleBG = IMAGEMANAGER->addImage("title", "source/titleImage.bmp", 1600, 900, false, RGB(255, 0, 255));

	_opening = MCIWndCreate(_hWnd, NULL, WS_CHILD | WS_VISIBLE | MCIWNDF_NOPLAYBAR, "source/opening.avi");
	MoveWindow(_opening, 0, 0, WINSIZEX, WINSIZEY, NULL);
	MCIWndPlay(_opening);

	SCENEMANAGER->SetVideoPlay(true);

	return S_OK;
}

void titleScene::release()
{
}

void titleScene::update()
{

	if (MCIWndGetLength(_opening) <= MCIWndGetPosition(_opening))
	{
		MCIWndDestroy(_opening);
		SCENEMANAGER->SetVideoPlay(false);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{

		if (SCENEMANAGER->GetVideoPlay())
		{
			MCIWndDestroy(_opening);
			SCENEMANAGER->SetVideoPlay(false);

		}

		else 
		{
			SCENEMANAGER->changeScene("selectScene");
		}
	}

}

void titleScene::render()
{
	_titleBG->render(getMemDC());
}
