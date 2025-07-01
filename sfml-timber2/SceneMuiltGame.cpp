#include "stdafx.h"
#include "SceneMuiltGame.h"
#include "SpriteGo.h"
SceneMuiltGame::SceneMuiltGame()
	:Scene(SceneIds::Dev1)
{
}

void SceneMuiltGame::Init()
{

	Scene::Init();
}

void SceneMuiltGame::Release()
{

	Scene::Release();
}

void SceneMuiltGame::Enter()
{
	texIds.push_back(IMG"background.png");

	SpriteGo* backGround1 = new SpriteGo(IMG"background.png");
	SpriteGo* backGround2 = new SpriteGo(IMG"background.png");

	backGround1->SetScale({ 0.49f , 1.f });
	std::cout << backGround1->GetOrigin().x << std::endl;
	backGround2->SetScale({ 0.49f , 1.f });
	backGround2->SetOrigin({ -FRAMEWORK.GetWindowBounds().width - 60.f , 0.f });

	AddGameObject(backGround1);
	AddGameObject(backGround2);
	Scene::Enter();
}

void SceneMuiltGame::Exit()
{
	Scene::Exit();
}

void SceneMuiltGame::Update(float dt)
{
	Scene::Update(dt);
}

void SceneMuiltGame::Draw(sf::RenderWindow& window)
{

	Scene::Draw(window);
}
