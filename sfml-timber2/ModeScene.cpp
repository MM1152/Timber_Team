#include "stdafx.h"
#include "ModeScene.h"

ModeScene::ModeScene()
	:Scene(SceneIds::Mode), playModeCheck(false)
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
	Text1P->SetCharacterSize(400);
	Text1P->SetFillColor(sf::Color::White);

	sf::FloatRect windowBounds = FRAMEWORK.GetWindowBounds();

	Text1P->SetPosition({ windowBounds.width * 0.5f - 520, windowBounds.height * 0.5f - 230 });////////////오리진 값 설정 추가
	AddGameObject(Text1P);

	//Text2P
	Text2P = new TextGo("fonts/KOMIKAP_.ttf");
	Text2P->SetString("2P");
	Text2P->SetCharacterSize(360);
	Text2P->SetFillColor(sf::Color::White);

	Text2P->SetPosition({ windowBounds.width * 0.5f + 220, windowBounds.height * 0.5f - 230 });////////////오리진 값 설정 추가
	AddGameObject(Text2P);

	Text2P->SetPosition({ windowBounds.width * 0.5f + 220, windowBounds.height * 0.5f - 230 });////////////오리진 값 설정 추가
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
		playModeCheck = true;
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Space) && playModeCheck)
	{
		SCENE_MGR.ChangeScene(SceneIds::Character);
		playModeCheck = false;
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		Text1P->SetFillColor(sf::Color::White);
		Text1P->SetCharacterSize(360);
		Text2P->SetFillColor(sf::Color::Red);
		Text2P->SetCharacterSize(320);
		playModeCheck = true;
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Space))
	{
		SCENE_MGR.ChangeScene(SceneIds::Character);
		playModeCheck = false;
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneIds::Title);
		playModeCheck = false;
	}
}
