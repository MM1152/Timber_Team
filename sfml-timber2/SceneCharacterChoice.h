#pragma once
#include "Scene.h"

class SpriteGo;
class TextGo;
class SoundGo;

class SceneCharacterChoice : public Scene
{
protected:
	std::vector<SpriteGo*> characters;
	std::vector<TextGo*> characterNames;
	int choiceCharacter = 0;
	bool isChoice = false;


public:
	SceneCharacterChoice();
	~SceneCharacterChoice() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;

	



};

