#pragma once
#include "Scene.h"

class UiHud;

class SceneCharacterChoice : public Scene
{
protected:
	
	UiHud* uiHud;


public:
	SceneCharacterChoice();
	~SceneCharacterChoice() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;

	



};

