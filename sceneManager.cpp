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
	//맵 이터레이터에 내가 찾고자 하는 씬의 이름을 넣는다
	mapSceneIter find = _mSceneList.find(sceneName);

	//이터레이터가 맵의 엔드에 도착했다는건 없단 얘기
	if (find == _mSceneList.end()) return E_FAIL;

	//만약 바꾸려는 씬이 현재씬이면 변화없음
	if (find->second == _currentScene) return S_OK;

	//씬의 init함수를 실행한다. 만약 성공하면
	if (SUCCEEDED(find->second->init()))
	{
		//현재 있던 씬의 릴리즈 함수를 실행해주고
		if (_currentScene) _currentScene->release();

		//바꾸려는 씬을 현재씬으로 체인지
		_currentScene = find->second;

		return S_OK;
	}

	return E_FAIL;
}
