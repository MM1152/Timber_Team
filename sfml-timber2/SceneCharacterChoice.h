#pragma once
#include "Scene.h"

class UiHud;
class SpriteGo;
class TextGo;

class SceneCharacterChoice : public Scene
{
protected:
	std::vector<SpriteGo*> characters;
	std::vector<TextGo*> characterNames;
	int choiceCharacter = 0;
	bool isChoice = false;
	UiHud* uiHud;



public:
	SceneCharacterChoice();
	~SceneCharacterChoice() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;

	



};

