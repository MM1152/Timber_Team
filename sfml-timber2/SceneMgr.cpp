#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneGame.h"
#include "SceneMuiltGame.h"
#include "TitleScene.h"
#include "ModeScene.h"
#include "SceneCharacterChoice.h"
#include "SceneCharacterChoice2p.h"

void SceneMgr::Init()
{
	scenes.push_back(new TitleScene());
	scenes.push_back(new ModeScene());
	scenes.push_back(new SceneGame());
	scenes.push_back(new SceneCharacterChoice());
	scenes.push_back(new SceneCharacterChoice2p());
	scenes.push_back(new SceneMuiltGame());

	//startScene = SceneIds::Dev1;
	for (auto scene : scenes)
	{
		scene->Init();
	}
	currentScene = startScene;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto scene : scenes)
	{
		if (scene->Id == currentScene)
		{
			scene->Exit();
		}
		scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	beforeScenes.push(currentScene);
	nextScene = id;
}

void SceneMgr::Update(float dt)
{
	if (nextScene != SceneIds::None)
	{
		scenes[(int)currentScene]->Exit();
		currentScene = nextScene;
		nextScene = SceneIds::None;
		scenes[(int)currentScene]->Enter();
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Escape) && !beforeScenes.empty() ) {
		nextScene = beforeScenes.top();
		beforeScenes.pop();
	}

	scenes[(int)currentScene]->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes[(int)currentScene]->Draw(window);
}
