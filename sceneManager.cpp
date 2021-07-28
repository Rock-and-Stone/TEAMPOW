#include "pch.h"
#include "sceneManager.h"
#include "gameNode.h"

gameNode* sceneManager::_currentScene = nullptr;


sceneManager::sceneManager()
{
}


sceneManager::~sceneManager()
{
}

HRESULT sceneManager::init()
{
	_currentScene = nullptr;

	return S_OK;
}

void sceneManager::release()
{
	mapSceneIter miSceneList = _mSceneList.begin();

	for (; miSceneList != _mSceneList.end();)
	{
		if (miSceneList->second != nullptr)
		{
			if (miSceneList->second == _currentScene) miSceneList->second->release();
			SAFE_DELETE(miSceneList->second);
			miSceneList = _mSceneList.erase(miSceneList);
		}
		else ++miSceneList;
	}

	_mSceneList.clear();

}

void sceneManager::update()
{
	if (_currentScene) _currentScene->update();
}

void sceneManager::render()
{
	if (_currentScene) _currentScene->render();
}

gameNode* sceneManager::addScene(string sceneName, gameNode * scene)
{
	if (!scene) return nullptr;

	_mSceneList.insert(make_pair(sceneName, scene));


	return scene;
}

HRESULT sceneManager::changeScene(string sceneName)
{
	//�� ���ͷ����Ϳ� ���� ã���� �ϴ� ���� �̸��� �ִ´�
	mapSceneIter find = _mSceneList.find(sceneName);

	//���ͷ����Ͱ� ���� ���忡 �����ߴٴ°� ���� ���
	if (find == _mSceneList.end()) return E_FAIL;

	//���� �ٲٷ��� ���� ������̸� ��ȭ����
	if (find->second == _currentScene) return S_OK;

	//���� init�Լ��� �����Ѵ�. ���� �����ϸ�
	if (SUCCEEDED(find->second->init()))
	{
		//���� �ִ� ���� ������ �Լ��� �������ְ�
		if (_currentScene) _currentScene->release();

		//�ٲٷ��� ���� ��������� ü����
		_currentScene = find->second;

		return S_OK;
	}

	return E_FAIL;
}
