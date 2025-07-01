#include "stdafx.h"
#include "TitleScene.h"
#include "TextGo.h"

TitleScene::TitleScene()
	:Scene(SceneIds::Dev1)
{
}

void TitleScene::Init()
{
	fontIds.push_back("fonts/KOMIKAP_.ttf");

	TextGo* go = new TextGo("fonts/KOMIKAP_.ttf");
	go->SetString("GAME START");
	go->SetCharacterSize(30);
	go->SetFillColor(sf::Color::White);
	AddGameObject(go);

	//Scene::Init();
}
