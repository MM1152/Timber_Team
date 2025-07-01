#include "stdafx.h"
#include "SceneCharacterChoice.h"
#include "UiHud.h"
#include "SpriteGo.h"


SceneCharacterChoice::SceneCharacterChoice()
	: Scene(SceneIds::CharacterChoice)
{

}
SceneCharacterChoice::~SceneCharacterChoice()
{

}
void SceneCharacterChoice::Init()
{
	
	texIds.push_back("graphics/background.png");
	texIds.push_back("graphics/player.png");
	fontIds.push_back("fonts/KOMIKAP_.ttf");

	uiHud = (UiHud*)AddGameObject(new UiHud());
	AddGameObject(new SpriteGo("graphics/background.png"));
	AddGameObject(new SpriteGo("graphics/player.png"));
}
void SceneCharacterChoice::Enter()
{
	Scene::Enter();
}
void SceneCharacterChoice::Exit()
{
	Scene::Exit();
}
void SceneCharacterChoice::Update(float dt)
{



}



