#pragma once
#include "Scene.h"
#include "TextGo.h"


class TitleScene :
    public Scene
{
protected:
    TextGo* SelectMode;
    TextGo* SelectCharacter;
public:
    TitleScene();
	void Init() override;
    void Update(float dt) override;

};

