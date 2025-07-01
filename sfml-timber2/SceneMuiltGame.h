#pragma once
#include "Scene.h"

#define IMG "graphics/"
#define FONT "fonts/KOMIKAP_.ttf"
class PlayerMuliti;
class Branch;

class SceneMuiltGame : public Scene
{
protected:
	PlayerMuliti* player1;
	PlayerMuliti* player2;

	Branch* branch1;
	Branch* branch2;

	bool isPlaying;
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

