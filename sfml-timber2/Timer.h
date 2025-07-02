#pragma once
#include "GameObject.h"
class Timer : public GameObject
{
protected:
	sf::RectangleShape timer;

	int score = 0;
	float time = 5.f;
	
	sf::Vector2f timerSize = { 400, 80 };
public:
	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetOrigin(Origins preset) override;
	void SetPosition(const sf::Vector2f& pos);

	sf::Vector2f GetSize() const { return timerSize; };

	void SetValue(float value);
	float GetTime();
};

