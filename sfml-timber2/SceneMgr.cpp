#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneGame.h"
#include "TitleScene.h"
#include "ModeScene.h"
#include "CharacterScene.h"
#include "SceneCharacterChoice.h"
#include "SceneCharacterChoice2p.h"

void SceneMgr::Init()
{
	scenes.push_back(new TitleScene());
	scenes.push_back(new ModeScene());
	scenes.push_back(new CharacterScene());
	scenes.push_back(new SceneGame());
	scenes.push_back(new SceneCharacterChoice());
	scenes.push_back(new SceneCharacterChoice2p());

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

	scenes[(int)currentScene]->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes[(int)currentScene]->Draw(window);
}
