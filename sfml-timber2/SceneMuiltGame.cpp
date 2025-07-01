#include "stdafx.h"
#include "SceneMuiltGame.h"
#include "SpriteGo.h"
#include "PlayerMuliti.h"
#include "Branch.h"
#include "TextGo.h"
#include "TextScore.h"
SceneMuiltGame::SceneMuiltGame()
	:Scene(SceneIds::Dev1)
	,isPlaying(true)
{
}

void SceneMuiltGame::Init()
{
	texIds.push_back(IMG"background.png");
	texIds.push_back(IMG"tree.png");
	texIds.push_back(IMG"player.png");
	texIds.push_back(IMG"branch.png");
	texIds.push_back(IMG"rip.png");
	fontIds.push_back(FONT);
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
	player1 = new PlayerMuliti("Player1", sf::Keyboard::A, sf::Keyboard::D);
	player2 = new PlayerMuliti("Player2", sf::Keyboard::Left, sf::Keyboard::Right);
	branch1 = new Branch(IMG"branch.png" , sf::Keyboard::A, sf::Keyboard::D , "branch1");
	branch2 = new Branch(IMG"branch.png", sf::Keyboard::Left, sf::Keyboard::Right , "branch2");
	TextScore* score = new TextScore(sf::Keyboard::A, sf::Keyboard::D , FONT);

	sf::FloatRect windowSize = FRAMEWORK.GetWindowBounds();

	backGround1->SetScale({ 0.49f , 1.f });

	backGround2->SetScale({ 0.49f , 1.f });
	backGround2->SetPosition({ (windowSize.width /  2) + 20 , 0.f});
	
	score->SetCharacterSize(10);
	score->SetPosition({20, 20});

	AddGameObject(backGround1);
	AddGameObject(backGround2);
	AddGameObject(tree1);
	AddGameObject(tree2);
	AddGameObject(player1);
	AddGameObject(player2);
	AddGameObject(branch1);
	AddGameObject(branch2);
	AddGameObject(score);

	Scene::Enter();

	tree1->SetOrigin(Origins::TC);
	tree1->SetScale({ 0.5, 1.f });
	tree1->SetPosition({ (backGround1->GetSprite().getLocalBounds().width * backGround1->GetScale().x) / 2 , 0.f });

	tree2->SetOrigin(Origins::TC);
	tree2->SetScale({ 0.5, 1.f });
	tree2->SetPosition({ (backGround2->GetSprite().getLocalBounds().width * backGround2->GetScale().x + backGround2->GetPosition().x / 2), 0.f});
	
	player1->SetOrigin({ -(tree1->GetSprite().getLocalBounds().width * tree1->GetScale().x), 0.f});
	player1->SetPosition({tree1->GetPosition().x , 700.f});

	player2->SetOrigin({ -(tree2->GetSprite().getLocalBounds().width * tree2->GetScale().x), 0.f });
	player2->SetPosition({ tree2->GetPosition().x , 700.f });

	
	branch1->SetOrigin({-(tree1->GetSprite().getLocalBounds().width * tree1->GetScale().x)  , 0});
	branch1->SetPosition(tree1->GetPosition());
	branch1->SetScale({ 0.5f , 1.f });
	
	branch2->SetOrigin({ -(tree2->GetSprite().getLocalBounds().width * tree2->GetScale().x)  , 0 });
	branch2->SetPosition(tree2->GetPosition());
	branch2->SetScale({ 0.5f , 1.f });

}

void SceneMuiltGame::Exit()
{
	Scene::Exit();
}

void SceneMuiltGame::Update(float dt)
{
	if (isPlaying) {
		Scene::Update(dt);

		if (branch1->GetSide() == player1->GetSide()) {
			isPlaying = false;
			player1->Die();
		}
		if (branch2->GetSide() == player2->GetSide()) {
			isPlaying = false;
			player2->Die();
		}
	}
	else {
		if (InputMgr::GetKeyDown(sf::Keyboard::Enter)) {
			isPlaying = true;
			branch1->Reset();
			branch2->Reset();
			player1->Reset();
			player2->Reset();
		}
	}
}

void SceneMuiltGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
