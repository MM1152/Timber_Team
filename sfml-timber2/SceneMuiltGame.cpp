#include "stdafx.h"
#include "SceneMuiltGame.h"
#include "SpriteGo.h"
SceneMuiltGame::SceneMuiltGame()
	:Scene(SceneIds::Dev1)
{
}

void SceneMuiltGame::Init()
{
	texIds.push_back(IMG"background.png");
	texIds.push_back(IMG"tree.png");
	Scene::Init();
}

void SceneMuiltGame::Release()
{

	Scene::Release();
}

void SceneMuiltGame::Enter()
{
	SpriteGo* backGround1 = new SpriteGo(IMG"background.png");
	SpriteGo* backGround2 = new SpriteGo(IMG"background.png");
	SpriteGo* tree1 = new SpriteGo(IMG"tree.png");
	SpriteGo* tree2 = new SpriteGo(IMG"tree.png");

	sf::FloatRect windowSize = FRAMEWORK.GetWindowBounds();

	backGround1->SetScale({ 0.49f , 1.f });

	backGround2->SetScale({ 0.49f , 1.f });
	backGround2->SetPosition({ (windowSize.width /  2) + 20 , 0.f});
	
	AddGameObject(backGround1);
	AddGameObject(backGround2);
	AddGameObject(tree1);
	AddGameObject(tree2);
	Scene::Enter();

	tree1->SetOrigin(Origins::TC);
	tree1->SetScale({ 0.5, 1.f });
	tree1->SetPosition({ (backGround1->GetSprite().getLocalBounds().width * backGround1->GetScale().x) / 2 , 0.f });

	tree2->SetOrigin(Origins::TC);
	tree2->SetScale({ 0.5, 1.f });
	std::cout << backGround2->GetPosition().x << std::endl;	
	tree2->SetPosition({ (backGround2->GetSprite().getLocalBounds().width * backGround2->GetScale().x + backGround2->GetPosition().x / 2), 0.f});
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
