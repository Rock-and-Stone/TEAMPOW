#include "pch.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ���⿡�� �ض�!!!
HRESULT playGround::init()
{
	gameNode::init(true);

	SCENEMANAGER->addScene("stage1", new stage1);
	SCENEMANAGER->addScene("settingScene", new SettingScene);
	SCENEMANAGER->addScene("titleScene", new titleScene);
	SCENEMANAGER->addScene("selectScene", new SelectScene);

	SCENEMANAGER->changeScene("titleScene");


	return S_OK;
}

//�޸� ������ ����� �ض�!!!!
void playGround::release()
{
	gameNode::release();
}

//����ó���� ����ٰ�!
void playGround::update()
{
	gameNode::update();
	SCENEMANAGER->update();
}

//����� �׷����!!!
void playGround::render()
{
	if (!SCENEMANAGER->GetVideoPlay())
	{
		PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
		//==============������ ���� �ǵ帮�� ���� ============

		SCENEMANAGER->render();

		//=============== �ؿ��� �ǵ������� ================
		_backBuffer->render(getHDC(), 0, 0);
	}

}



