#pragma once
#include "GameObject.h"
#define BRANCH_SIZE 6
class Branch : public GameObject
{
protected:
	sf::Sprite branchs[BRANCH_SIZE];
	std::string texId;

	sf::Keyboard::Key key1;
	sf::Keyboard::Key key2;

	float scaleX;
	bool scaleSetting;
	Sides sides[BRANCH_SIZE];

public:
	Branch(const std::string& id, sf::Keyboard::Key key1, sf::Keyboard::Key key2, const std::string& name ="");
	~Branch() override = default;

	void SetOrigin(const sf::Vector2f& o) override;
	void SetPosition(const sf::Vector2f& pos) override;
	void SetScale(const sf::Vector2f& s) override;
	// GameObject을(를) 통해 상속됨
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetSide();
	void UpdateBranch();
	Sides GetSide();
};

