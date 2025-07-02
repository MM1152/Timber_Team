#pragma once
#include "GameObject.h"

class Player : public GameObject
{
protected:
	sf::Sprite sprite;
	sf::Sprite axe;
	sf::Sprite elec;
	sf::Sprite water;

	Sides side = Sides::Right;

	std::vector<sf::Vector2f> positions;
	std::vector<sf::Vector2f> scales;
	std::vector<sf::Vector2f> axePositions;
	std::vector<sf::Vector2f> elecPositions;
	std::vector<sf::Vector2f> waterPositions;

	std::string texPlayerId;
	std::string ripTexId;
	std::string axeTexId;
	std::string elecTexId;
	std::string waterTexId;

	bool isAlive = true;
	bool drawAxe = false;
	bool drawElec = false;
	bool drawWater = false;

public:
	Player(const std::string& name = "");
	~Player() override = default;

	void SetAlive(bool alive);
	void SetDrawAxe(bool draw) { drawAxe = draw; }
	void SetDrawElec(bool draw) { drawElec = draw; }
	void SetDrawWater(bool draw) { drawWater = draw; }

	void SetSide(Sides s);
	Sides GetSide() const { return side; }

	void SetPosition(const sf::Vector2f& pos) override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};
