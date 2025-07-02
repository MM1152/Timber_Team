#include "stdafx.h"
#include "SceneMuiltGame.h"
#include "SpriteGo.h"
#include "PlayerMuliti.h"
#include "Branch.h"
#include "TextGo.h"
#include "TextScore.h"
#include "Log.h"
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
	texIds.push_back(IMG"axe.png");
	texIds.push_back(IMG"log.png");
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
	textScore1 = new TextScore(sf::Keyboard::A, sf::Keyboard::D , FONT);
	textScore2 = new TextScore(sf::Keyboard::Left, sf::Keyboard::Right, FONT);
	textCenter = new TextGo(FONT);
	Log* log = new Log(sf::Keyboard::A, sf::Keyboard::D, IMG"log.png");
	Log* log1 = new Log(sf::Keyboard::Left, sf::Keyboard::Right, IMG"log.png");
	sf::FloatRect windowSize = FRAMEWORK.GetWindowBounds();

	backGround1->SetScale({ 0.49f , 1.f });

	backGround2->SetScale({ 0.49f , 1.f });
	backGround2->SetPosition({ (windowSize.width /  2) + 20 , 0.f});
	
	AddGameObject(backGround1);
	AddGameObject(backGround2);
	AddGameObject(tree1);
	AddGameObject(tree2);
	AddGameObject(log);
	AddGameObject(log1);
	AddGameObject(player1);
	AddGameObject(player2);
	AddGameObject(branch1);
	AddGameObject(branch2);
	AddGameObject(textScore1);
	AddGameObject(textScore2);
	AddGameObject(textCenter);
	

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

	log->SetOrigin(Origins::BC);
	log->SetPosition({ tree1->GetPosition().x , tree1->GetSprite().getLocalBounds().height});
	log->SetScale({ 0.5f , 0.5f });
	log->SetWindowRange({0 , backGround1->GetSprite().getLocalBounds().width * backGround1->GetScale().x + backGround1->GetPosition().x});

	log1->SetOrigin(Origins::BC);
	log1->SetPosition({ tree2->GetPosition().x , tree2->GetSprite().getLocalBounds().height });
	log1->SetScale({ 0.5f , 0.5f });
	log1->SetWindowRange({ backGround2->GetPosition().x , backGround2->GetSprite().getLocalBounds().width * backGround2->GetScale().x + backGround2->GetPosition().x });

	branch1->SetOrigin({-(tree1->GetSprite().getLocalBounds().width * tree1->GetScale().x)  , 0});
	branch1->SetPosition(tree1->GetPosition());
	branch1->SetScale({ 0.5f , 1.f });
	
	branch2->SetOrigin({ -(tree2->GetSprite().getLocalBounds().width * tree2->GetScale().x)  , 0 });
	branch2->SetPosition(tree2->GetPosition());
	branch2->SetScale({ 0.5f , 1.f });

	textScore1->SetCharacterSize(30);
	textScore1->SetPosition({ 20, 20 });

	textScore2->SetCharacterSize(30);
	textScore2->SetPosition({backGround2->GetPosition().x + 20 , backGround2->GetPosition().y + 20});

	textCenter->SetPosition({ windowSize.width / 2 , windowSize.height / 2 });
	textCenter->SetOrigin(Origins::MC);
	textCenter->SetCharacterSize(100);
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
			textCenter->SetString("Player 2 Win");
		}
		if (branch2->GetSide() == player2->GetSide()) {
			isPlaying = false;
			player2->Die();
			textCenter->SetString("Player 1 Win");
		}
	}
	else {
		if (InputMgr::GetKeyDown(sf::Keyboard::Enter)) {
			isPlaying = true;
			branch1->Reset();
			branch2->Reset();
			player1->Reset();
			player2->Reset();
			textScore1->Reset();
			textScore2->Reset();
			textCenter->Reset();
		}
	}
}

void SceneMuiltGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
}
