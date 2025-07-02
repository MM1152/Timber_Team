#include "stdafx.h"
#include "TitleScene.h"
#include "TextGo.h"
#include "SpriteGo.h"

TitleScene::TitleScene()
	:Scene(SceneIds::Title), ExitCheck(false), PlayModeCheck(false)
{
}

void TitleScene::Init()
{
	fontIds.push_back("fonts/KOMIKAP_.ttf");
	texIds.push_back("graphics/title.png");

	//배경이미지 띄우기
	SpriteGo* background = new SpriteGo("graphics/title.png");
	AddGameObject(background);

	//game start 텍스트 띄우기
	TextGo* GameStart = new TextGo("fonts/KOMIKAP_.ttf");
	GameStart->SetString("GAME START");
	GameStart->SetCharacterSize(150);
	GameStart->SetFillColor(sf::Color::Black);

	sf::FloatRect windowBounds = FRAMEWORK.GetWindowBounds();
	GameStart->SetPosition({ windowBounds.width * 0.5f - 1%30, windowBounds.height - 850 });////////////
	AddGameObject(GameStart);

	//Exit
	Exit = new TextGo("fonts/KOMIKAP_.ttf");
	Exit->SetString("Exit");
	Exit->SetCharacterSize(100);
	Exit->SetFillColor(sf::Color::Black);

	Exit->SetPosition({ windowBounds.width * 0.5f - 130, windowBounds.height - 280 });////////////오리진 값 설정 추가
	AddGameObject(Exit);

	//select Mode
	SelectMode = new TextGo("fonts/KOMIKAP_.ttf");
	SelectMode->SetString("SELECT MODE");
	SelectMode->SetCharacterSize(100);
	SelectMode->SetFillColor(sf::Color::Black);

	SelectMode->SetPosition({ windowBounds.width * 0.5f - 130, windowBounds.height - 480 });////////////오리진 값 설정 추가
	AddGameObject(SelectMode);

	////select Character
	//SelectCharacter = new TextGo("fonts/KOMIKAP_.ttf");
	//SelectCharacter->SetString("  SELECT \nCHARACTER");
	//SelectCharacter->SetCharacterSize(100);
	//SelectCharacter->SetFillColor(sf::Color::White);

	//SelectCharacter->SetPosition({ windowBounds.width - 1560, windowBounds.height - 480 });////////////오리진 값 설정 추가
	//AddGameObject(SelectCharacter);

	//Scene::Init();
}

void TitleScene::Update(float dt)
{
	Scene::Update(dt);

	if (InputMgr::GetKeyDown(sf::Keyboard::Left))
	{
		SelectMode->SetFillColor(sf::Color::Red);
		SelectMode->SetCharacterSize(90);
		Exit->SetFillColor(sf::Color::Black);
		Exit->SetCharacterSize(100);
		PlayModeCheck=true;	
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Space) && PlayModeCheck)
	{
		SCENE_MGR.ChangeScene(SceneIds::Mode);
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Right))
	{
		SelectMode->SetFillColor(sf::Color::Black);
		SelectMode->SetCharacterSize(100);
		Exit->SetFillColor(sf::Color::Red);
		Exit->SetCharacterSize(90);
		ExitCheck = true;
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && PlayModeCheck)
	{
		SCENE_MGR.ChangeScene(SceneIds::Mode);
	}
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter) && ExitCheck)
	{
		//게임종료
	}
}
