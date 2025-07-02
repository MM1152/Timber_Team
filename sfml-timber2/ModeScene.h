#pragma once
#include "Scene.h"
#include "TextGo.h"
class ModeScene :
    public Scene
{
protected:
    TextGo* Text1P;
    TextGo* Text2P;
    bool playMode1pCheck;
    bool playMode2pCheck;
    int choicePoint = 0;


public:
    ModeScene();
    void Init() override;
    void Update(float dt) override;
    void Enter() override;
    //void Update() override;

};

