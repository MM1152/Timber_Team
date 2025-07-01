#pragma once
#include "Scene.h"
#include "TextGo.h"
class ModeScene :
    public Scene
{
protected:
    TextGo* Text1P;
    TextGo* Text2P;



public:
    ModeScene();
    void Init() override;
    void Update(float dt) override;
    //void Update() override;

};

