#include "stdafx.h"
#include "SceneCharacterChoice2p.h"
#include "SpriteGo.h"
#include "TextGo.h"

SceneCharacterChoice2p::SceneCharacterChoice2p()
    : Scene(SceneIds::CharacterChoice2p)
{

}
SceneCharacterChoice2p::~SceneCharacterChoice2p()
{

}
void SceneCharacterChoice2p::Init()
{
    texIds.push_back("graphics/background.png");
    texIds.push_back("graphics/player.png");
    texIds.push_back("graphics/pikachu.png");
    texIds.push_back("graphics/turtle.png");

    fontIds.push_back("fonts/KOMIKAP_.ttf");

    SpriteGo* back1 = (SpriteGo*)AddGameObject(new SpriteGo("graphics/background.png"));
    back1->SetScale({ 0.49f , 1.f });

    SpriteGo* back2 = (SpriteGo*)AddGameObject(new SpriteGo("graphics/background.png"));
    back2->SetScale({ 0.49f , 1.f });
    back2->SetPosition({ 980 , 0.f });

    SpriteGo* char1BeardMan = (SpriteGo*)AddGameObject(new SpriteGo("graphics/player.png"));
    char1BeardMan->SetOrigin(Origins::MC);
    char1BeardMan->SetPosition({ 140.f, 600.f });

    SpriteGo* char2BeardMan = (SpriteGo*)AddGameObject(new SpriteGo("graphics/player.png"));
    char2BeardMan->SetOrigin(Origins::MC);
    char2BeardMan->SetPosition({ 1120.f, 600.f });

    SpriteGo* char1Pikachu = (SpriteGo*)AddGameObject(new SpriteGo("graphics/pikachu.png"));
    char1Pikachu->SetOrigin(Origins::MC);
    char1Pikachu->SetScale({ 0.5f , 0.5f });
    char1Pikachu->SetPosition({ 470.f, 600.f });

    SpriteGo* char2Pikachu = (SpriteGo*)AddGameObject(new SpriteGo("graphics/pikachu.png"));
    char2Pikachu->SetOrigin(Origins::MC);
    char2Pikachu->SetScale({ 0.5f , 0.5f });
    char2Pikachu->SetPosition({ 1430.f, 600.f });

    SpriteGo* char1Squirtle = (SpriteGo*)AddGameObject(new SpriteGo("graphics/turtle.png"));
    char1Squirtle->SetOrigin(Origins::MC);
    char1Squirtle->SetScale({ 0.25f , 0.25f });
    char1Squirtle->SetPosition({ 800.f, 600.f });

    SpriteGo* char2Squirtle = (SpriteGo*)AddGameObject(new SpriteGo("graphics/turtle.png"));
    char2Squirtle->SetOrigin(Origins::MC);
    char2Squirtle->SetScale({ 0.25f , 0.25f });
    char2Squirtle->SetPosition({ 1760.f, 600.f });

    TextGo* Ready = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    TextGo* Ready2p = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));

    characters.push_back(char1BeardMan);
    characters.push_back(char1Pikachu);
    characters.push_back(char1Squirtle);

    characters2p.push_back(char2BeardMan);
    characters2p.push_back(char2Pikachu);
    characters2p.push_back(char2Squirtle);

    TextGo* title = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    title->SetString("Choose Character\n     1 Player");
    title->SetCharacterSize(50);
    title->SetFillColor(sf::Color::White);
    title->SetPosition({ 470.f, 100.f });
    title->SetOrigin(Origins::MC);

    TextGo* title2 = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    title2->SetString("Choose Character\n     2 Player");
    title2->SetCharacterSize(50);
    title2->SetFillColor(sf::Color::White);
    title2->SetPosition({ 1430.f, 100.f });
    title2->SetOrigin(Origins::MC);

    TextGo* name1Beardman = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    name1Beardman->SetString("beard man");
    name1Beardman->SetCharacterSize(50);
    name1Beardman->SetFillColor(sf::Color::White);
    name1Beardman->SetPosition({ 140.f, 750.f });
    name1Beardman->SetOrigin(Origins::MC);

    TextGo* name2Beardman = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    name2Beardman->SetString("beard man");
    name2Beardman->SetCharacterSize(50);
    name2Beardman->SetFillColor(sf::Color::White);
    name2Beardman->SetPosition({ 1120.f, 750.f });
    name2Beardman->SetOrigin(Origins::MC);


    TextGo* name1Pikachu = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    name1Pikachu->SetString("pikachu");
    name1Pikachu->SetCharacterSize(50);
    name1Pikachu->SetFillColor(sf::Color::White);
    name1Pikachu->SetPosition({ 470.f, 750.f });
    name1Pikachu->SetOrigin(Origins::MC);

    TextGo* name2Pikachu = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    name2Pikachu->SetString("pikachu");
    name2Pikachu->SetCharacterSize(50);
    name2Pikachu->SetFillColor(sf::Color::White);
    name2Pikachu->SetPosition({ 1430.f, 750.f });
    name2Pikachu->SetOrigin(Origins::MC);

    TextGo* name1Sqirtle = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    name1Sqirtle->SetString("Squirtle");
    name1Sqirtle->SetCharacterSize(50);
    name1Sqirtle->SetFillColor(sf::Color::White);
    name1Sqirtle->SetPosition({ 800.f, 750.f });
    name1Sqirtle->SetOrigin(Origins::MC);

    TextGo* name2Sqirtle = (TextGo*)AddGameObject(new TextGo("fonts/KOMIKAP_.ttf"));
    name2Sqirtle->SetString("Squirtle");
    name2Sqirtle->SetCharacterSize(50);
    name2Sqirtle->SetFillColor(sf::Color::White);
    name2Sqirtle->SetPosition({ 1760.f, 750.f });
    name2Sqirtle->SetOrigin(Origins::MC);

    characterNames.push_back(name1Beardman);
    characterNames.push_back(name1Pikachu);
    characterNames.push_back(name1Sqirtle);

    characterNames2p.push_back(name2Beardman);
    characterNames2p.push_back(name2Pikachu);
    characterNames2p.push_back(name2Sqirtle);

    choiceCharacter = 0;
    choiceCharacter2p = 0;
    isChoice = false;
    isChoice2p = false;

    Scene::Init();

}
void SceneCharacterChoice2p::Enter()
{
    Scene::Enter();
}
void SceneCharacterChoice2p::Exit()
{
    Scene::Exit();
}
void SceneCharacterChoice2p::Update(float dt)
{
    if (isChoice)
    {
        Ready->SetString("Ready");
        Ready->SetCharacterSize(50);
        Ready->SetFillColor(sf::Color::Yellow);
        Ready->SetPosition({ 470.f, 200.f });
        Ready->SetOrigin(Origins::MC);
    }


    if (isChoice2p)
    {
        Ready2p->SetString("Ready");
        Ready2p->SetCharacterSize(50);
        Ready2p->SetFillColor(sf::Color::Yellow);
        Ready2p->SetPosition({ 470.f, 200.f });
        Ready2p->SetOrigin(Origins::MC);
    }

    if (isChoice2p && isChoice)
    {
        SCENE_MGR.Instance().ChangeScene(SceneIds::SceneMuiltGame);
        return;
    }

    if (InputMgr::GetKeyDown(sf::Keyboard::Left))
    {
        choiceCharacter2p--;
        if (choiceCharacter2p < 0)
        {
            choiceCharacter2p = (int)characters.size() - 1;
        }
    }
    if (InputMgr::GetKeyDown(sf::Keyboard::A))
    {
        choiceCharacter--;
        if (choiceCharacter < 0)
        {
            choiceCharacter = (int)characters.size() - 1;
        }
    }
    if (InputMgr::GetKeyDown(sf::Keyboard::Right))
    {
        choiceCharacter2p++;
        if (choiceCharacter2p >= (int)characters2p.size())
        {
            choiceCharacter2p = 0;
        }

    }
    if (InputMgr::GetKeyDown(sf::Keyboard::D))
    {
        choiceCharacter++;
        if (choiceCharacter >= (int)characters.size())
        {
            choiceCharacter = 0;
        }

    }
    if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
    {
        SCENE_MGR.SetChoiceCharacter2p(choiceCharacter2p);
        isChoice2p = true;
    }
    if (InputMgr::GetKeyDown(sf::Keyboard::Space))
    {
        SCENE_MGR.SetChoiceCharacter(choiceCharacter);
        isChoice = true;
    }

    for (int i = 0; i < characterNames2p.size(); ++i)
    {
        if (i == choiceCharacter2p)
        {
            characterNames2p[i]->SetFillColor(sf::Color::Yellow);
        }
        else
        {
            characterNames2p[i]->SetFillColor(sf::Color::Black);
        }
    }
    for (int i = 0; i < characterNames.size(); ++i)
    {
        if (i == choiceCharacter)
        {
            characterNames[i]->SetFillColor(sf::Color::Red);
        }
        else
        {
            characterNames[i]->SetFillColor(sf::Color::Black);
        }
    }
}
