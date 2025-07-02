#pragma once
#include "Scene.h"

class SpriteGo;
class TextGo;

class SceneCharacterChoice2p : public Scene
{
protected:
	std::vector<SpriteGo*> characters;
	std::vector<TextGo*> characterNames;
	std::vector<SpriteGo*> characters2p;
	std::vector<TextGo*> characterNames2p;
	TextGo* Ready;
	TextGo* Ready2p;

	int choiceCharacter = 0;
	int choiceCharacter2p = 0;

	bool isChoice = false;
	bool isChoice2p = false;

public:
	SceneCharacterChoice2p();
	~SceneCharacterChoice2p() override;

	void Init() override;

	void Enter() override;
	void Exit() override;
	void Update(float dt) override;





};

