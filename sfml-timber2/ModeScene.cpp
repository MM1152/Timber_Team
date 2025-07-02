#include "stdafx.h"
#include "ModeScene.h"

ModeScene::ModeScene()
	:Scene(SceneIds::Mode), playMode1pCheck(false), playMode2pCheck(false)
{
}

void ModeScene::Init()
{
	texIds.push_back("graphics/background.png");
	fontIds.push_back("fonts/KOMIKAP_.ttf");

	SpriteGo* background = new SpriteGo("graphics/background.png");
	AddGameObject(background);

	//Text1P
	Text1P = new TextGo("fonts/KOMIKAP_.ttf");
	Text1P->SetString("1P");
	Text1P->SetCharacterSize(360);
	Text1P->SetFillColor(sf::Color::White);

	sf::FloatRect windowBounds = FRAMEWORK.GetWindowBounds();

	Text1P->SetPosition({ windowBounds.width * 0.5f - 520, windowBounds.height * 0.5f - 230 });////////////������ �� ���� �߰�
	AddGameObject(Text1P);

	//Text2P
	Text2P = new TextGo("fonts/KOMIKAP_.ttf");
	Text2P->SetString("2P");
	Text2P->SetCharacterSize(360);
	Text2P->SetFillColor(sf::Color::White);

	Text2P->SetPosition({ windowBounds.width * 0.5f + 220, windowBounds.height * 0.5f - 230 });////////////������ �� ���� �߰�
	AddGameObject(Text2P);

	Text2P->SetPosition({ windowBounds.width * 0.5f + 220, windowBounds.height * 0.5f - 230 });////////////������ �� ���� �߰�
	AddGameObject(Text2P);


}

void ModeScene::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		Text1P->SetFillColor(sf::Color::Red);
		Text1P->SetCharacterSize(320);
		Text2P->SetFillColor(sf::Color::White);
		Text2P->SetCharacterSize(360);
		playMode1pCheck = true;
		playMode2pCheck = false;
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && playMode1pCheck)
	{
		SCENE_MGR.ChangeScene(SceneIds::CharacterChoice);
		playMode1pCheck = false;
	}


	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		Text1P->SetFillColor(sf::Color::White);
		Text1P->SetCharacterSize(360);
		Text2P->SetFillColor(sf::Color::Red);
		Text2P->SetCharacterSize(320);
		playMode2pCheck = true;
		playMode1pCheck = false;
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && playMode2pCheck)
	{
		SCENE_MGR.ChangeScene(SceneIds::CharacterChoice2p);
		playMode2pCheck = false;
	}
}

void ModeScene::Enter()
{
	Text1P->SetFillColor(sf::Color::White);
	Text2P->SetFillColor(sf::Color::White);
	Scene::Enter();
}
