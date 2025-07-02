#include "stdafx.h"

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
    texIds.push_back("graphics/pikachu.png");
    texIds.push_back("graphics/turtle.png");

    fontIds.push_back("fonts/KOMIKAP_.ttf");

    AddGameObject(new SpriteGo("graphics/background.png"));

    SpriteGo* char1 = (SpriteGo*)AddGameObject(new SpriteGo("graphics/player.png"));
    char1->SetOrigin(Origins::MC);
    char1->SetPosition({ 400.f, 500.f });

    SpriteGo* char2 = (SpriteGo*)AddGameObject(new SpriteGo("graphics/pikachu.png"));
    char2->SetOrigin(Origins::MC);
    char2->SetPosition({ 950.f, 500.f });

    SpriteGo*  char3 = (SpriteGo*)AddGameObject(new SpriteGo("graphics/turtle.png"));
    char3->SetOrigin(Origins::MC);
    char3->SetPosition({ 1550.f, 500.f });

    characters.push_back(char1);
    characters.push_back(char2);
    characters.push_back(char3);

    TextGo* title = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    title->SetString("Choose Character");
    title->SetCharacterSize(50);
    title->SetFillColor(sf::Color::White);
    title->SetPosition({ 950.f, 100.f });
    title->SetOrigin(Origins::MC);

    TextGo* name1 = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    name1->SetString("beard man");
    name1->SetCharacterSize(50);
    name1->SetFillColor(sf::Color::White);
    name1->SetPosition({ 400.f, 650.f });
    name1->SetOrigin(Origins::MC);

    TextGo* name2 = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    name2->SetString("pikachu");
    name2->SetCharacterSize(50);
    name2->SetFillColor(sf::Color::White);
    name2->SetPosition({ 950.f, 650.f });
    name2->SetOrigin(Origins::MC);

    TextGo* name3 = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    name3->SetString("Squirtle");
    name3->SetCharacterSize(50);
    name3->SetFillColor(sf::Color::White);
    name3->SetPosition({ 1550.f, 650.f });
    name3->SetOrigin(Origins::MC);

    characterNames.push_back(name1);
    characterNames.push_back(name2);
    characterNames.push_back(name3);

    choiceCharacter = 0;
    isChoice = false;

    Scene::Init();

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
    if (isChoice)
    {
        SCENE_MGR.Instance().ChangeScene(SceneIds::Game1P);    //���߿� 1P Scene �̸����� ��ü
        return;
    }

    if (InputMgr::GetKeyDown(sf::Keyboard::Left))
    {
        choiceCharacter--;
        if (choiceCharacter < 0)
        {
            choiceCharacter = (int)characters.size() - 1;
        }
    }
    if (InputMgr::GetKeyDown(sf::Keyboard::Right))
    {
        choiceCharacter++;
        if (choiceCharacter >= (int)characters.size())
        {
            choiceCharacter = 0;
        }
    }
    if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
    {
        SCENE_MGR.SetChoiceCharacter(choiceCharacter);
        isChoice = true;
    }
    for (int i = 0; i < characterNames.size(); ++i)
    {
        if (i == choiceCharacter)
        {
            characterNames[i]->SetFillColor(sf::Color::Red);
        }
        else
        {
            characterNames[i]->SetFillColor(sf::Color::White);
        }
    }
}



