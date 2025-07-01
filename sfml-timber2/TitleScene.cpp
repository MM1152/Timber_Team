#include "stdafx.h"
#include "TitleScene.h"
#include "TextGo.h"
#include "SpriteGo.h"

TitleScene::TitleScene()
	:Scene(SceneIds::Dev1)
{
}

void TitleScene::Init()
{
	fontIds.push_back("fonts/KOMIKAP_.ttf");
	texIds.push_back("graphics/background.png");

	//배경이미지 띄우기
	SpriteGo* background = new SpriteGo("graphics/background.png");
	AddGameObject(background);

	//game start 텍스트 띄우기
	TextGo* GameStart = new TextGo("fonts/KOMIKAP_.ttf");
	GameStart->SetString("GAME START");
	GameStart->SetCharacterSize(150);
	GameStart->SetFillColor(sf::Color::White);

	sf::FloatRect windowBounds = FRAMEWORK.GetWindowBounds();
	GameStart->SetPosition({ windowBounds.width * 0.5f-400, windowBounds.height * 0.5f-220 });////////////

	AddGameObject(GameStart);
	



	//Scene::Init();
}
