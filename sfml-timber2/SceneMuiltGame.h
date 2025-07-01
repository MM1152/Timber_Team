#pragma once
#include "Scene.h"

#define IMG "graphics/"

class SceneMuiltGame : public Scene
{
protected:
	
public:
	SceneMuiltGame();
	~SceneMuiltGame() override = default;

	virtual void Init();
	virtual void Release();

	virtual void Enter();
	virtual void Exit();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);
};

