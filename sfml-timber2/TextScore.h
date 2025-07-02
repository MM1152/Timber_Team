#pragma once
#include "stdafx.h"
#include "TextGo.h"
class TextScore : public TextGo
{
protected:
	int score;
	std::string textId;
	sf::Keyboard::Key key1;
	sf::Keyboard::Key key2;
public:
	TextScore(sf::Keyboard::Key key1, sf::Keyboard::Key key2 , const std::string& id = "", const std::string& name = "");
	~TextScore() override;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	int GetScore() const { return score; };
};

