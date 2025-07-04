#include "stdafx.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "BackgroundElement.h"
#include "Tree.h"
#include "Player.h"
#include "UiHud.h"
#include "Log.h"
#include "DummyLog.h" //@

SceneGame::SceneGame()
    : Scene(SceneIds::Game1P)
{
}

SceneGame::~SceneGame()
{
}

void SceneGame::Init()
{
    texIds.push_back("graphics/background.png");
    texIds.push_back("graphics/cloud.png");
    texIds.push_back("graphics/bee.png");
    texIds.push_back("graphics/tree.png");
    texIds.push_back("graphics/branch.png");
    texIds.push_back("graphics/player.png");
    texIds.push_back("graphics/pikachu.png");
    texIds.push_back("graphics/turtle.png");
    texIds.push_back("graphics/axe.png");
    texIds.push_back("graphics/rip.png");
    texIds.push_back("graphics/log.png");
    texIds.push_back("graphics/electric.png");
    texIds.push_back("graphics/water.png");
    texIds.push_back("graphics/muteicon.png");
    texIds.push_back("graphics/soundicon.png");

    fontIds.push_back("fonts/KOMIKAP_.ttf");

    AddGameObject(new SpriteGo("graphics/background.png"));

    for (int i = 0; i < 3; ++i)
    {
        BackgroundElement* element = (BackgroundElement*)AddGameObject(
            new BackgroundElement("graphics/cloud.png"));
    }

    tree = (Tree*)AddGameObject(new Tree());

    BackgroundElement* element = (BackgroundElement*)AddGameObject(
        new BackgroundElement("graphics/bee.png"));
    element->minScale = 1.f;
    element->maxScale = 1.f;
    element->minY = 600;
    element->maxY = 800;
    element->minSpeed = 400;
    element->maxSpeed = 600;
    element->SetMoveType(BackgroundElement::MoveType::Wave);

    player = (Player*)AddGameObject(new Player());

    uiHud = (UiHud*)AddGameObject(new UiHud());

    Scene::Init();
}

void SceneGame::Enter()
{
    isPlaying = false;
    Log* log = new Log(sf::Keyboard::Left , sf::Keyboard::Right , "graphics/log.png");
    AddGameObject(log);

    //DummyLog* Dummylog = new DummyLog(sf::Keyboard::Left, sf::Keyboard::Right,"graphics/log.png",{0,0},"dummylog");//@
    //AddGameObject(Dummylog);

    Scene::Enter();

    sf::Vector2f pos = tree->GetPosition();
    pos.y = 950.f;
    player->SetPosition(pos);

    score = 0;
    uiHud->SetScore(score);

    timer = timerMax;
    uiHud->SetTimeBar(timer / timerMax);

    uiHud->SetShowMassage(true);
    uiHud->SetMessage("Enter to Start!");

    log->SetPosition({ tree->GetPosition().x , (float)TEXTURE_MGR.Get("graphics/tree.png").getSize().y });
    log->SetOrigin(Origins::BC);

    //Dummylog->SetPosition({ tree->GetPosition().x , (float)TEXTURE_MGR.Get("graphics/tree.png").getSize().y });
    //Dummylog->SetOrigin(Origins::BC);
    
}

void SceneGame::Exit()
{
    Scene::Exit();
}

void SceneGame::Update(float dt)
{
  

    if (isPlaying)
    {
        Scene::Update(dt);
        uiHud->SetSoundIcon(true);
        
        if (InputMgr::GetKeyDown(sf::Keyboard::Q))
        {
            if (SOUND_MGR.MuteGet())
            {
                uiHud->SetMuteIcon(true);
                uiHud->SetSoundIcon(false);
            }
            else
            {
                uiHud->SetMuteIcon(false);
                uiHud->SetSoundIcon(true);
            }
            SOUND_MGR.MuteSet(!SOUND_MGR.MuteGet());
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Left))
        {
            tree->UpdateBranches();
            player->SetSide(Sides::Left);
            if (tree->GetSide() == player->GetSide())
            {
                isPlaying = false;
                FRAMEWORK.SetTimeScale(0.f);
                player->SetAlive(false);

                uiHud->SetShowMassage(true);
                uiHud->SetMessage("Enter to Restart!");
            }
            else
            {
                if (SCENE_MGR.GetChoiceCharacter() == 0)
                {
                    SOUND_MGR.Play("Chop");
                }
                if (SCENE_MGR.GetChoiceCharacter() == 1)
                {
                    SOUND_MGR.Play("spark");
                }
                if (SCENE_MGR.GetChoiceCharacter() == 2)
                {
                    SOUND_MGR.Play("wave");
                }
                score += 10;
                uiHud->SetScore(score);
            }
        }

        if (InputMgr::GetKeyDown(sf::Keyboard::Right))
        {
            tree->UpdateBranches();
            player->SetSide(Sides::Right);
            if (tree->GetSide() == player->GetSide())
            {
                isPlaying = false;
                FRAMEWORK.SetTimeScale(0.f);
                SOUND_MGR.Play("Death");
                player->SetAlive(false);

                uiHud->SetShowMassage(true);
                uiHud->SetMessage("Enter to Restart!");
            }
            else
            {
                if (SCENE_MGR.GetChoiceCharacter() == 0)
                {
                    SOUND_MGR.Play("Chop");
                }
                if (SCENE_MGR.GetChoiceCharacter() == 1)
                {
                    SOUND_MGR.Play("spark");
                }
                if (SCENE_MGR.GetChoiceCharacter() == 2)
                {
                    SOUND_MGR.Play("wave");
                }
                score += 10;
                uiHud->SetScore(score);
            }
        }

        player->SetDrawAxe(
            InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right));
        player->SetDrawElec(
            InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right));
        player->SetDrawWater(
            InputMgr::GetKey(sf::Keyboard::Left) || InputMgr::GetKey(sf::Keyboard::Right));

        timer -= dt;
        if (timer <= 0.f)
        {
            timer = 0.f;
            SOUND_MGR.Play("OutOfTime");
            isPlaying = false;
            FRAMEWORK.SetTimeScale(0.f);
            player->SetAlive(false);

            uiHud->SetShowMassage(true);
            uiHud->SetMessage("Enter to Restart!");
        }
        uiHud->SetTimeBar(timer / timerMax);
    }
    else
    {
        if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
        {
            FRAMEWORK.SetTimeScale(1.f);
            player->Reset();
            tree->Reset();
            isPlaying = true;

            score = 0;
            uiHud->SetScore(score);

            timer = timerMax;
            uiHud->SetTimeBar(timer / timerMax);

            uiHud->SetShowMassage(false);
        }
    }
}