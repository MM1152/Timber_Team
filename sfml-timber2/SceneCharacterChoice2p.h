#pragma once
#include "Scene.h"

class SpriteGo;
class TextGo;

class SceneCharacterChoice2p : public Scene
{
protected:
	std::vector<SpriteGo*> characters;
	std::vector<TextGo*> characterNames;
	int choiceCharacter = 0;
	bool isChoice = false;


public:
	SceneCharacterChoice2p();
	~SceneCharacterChoice2p() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;





};

