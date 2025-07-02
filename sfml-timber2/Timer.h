#pragma once
#include "GameObject.h"
class Timer : public GameObject
{
protected:
	sf::RectangleShape timer;

	int score = 0;
	float time = 5.f;
	
public:
	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetOrigin(Origins preset) override;

	void SetValue(float value);
	float GetTime(float value);
};

