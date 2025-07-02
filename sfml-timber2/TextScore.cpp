#include "stdafx.h"
#include "TextScore.h"

TextScore::TextScore(sf::Keyboard::Key key1, sf::Keyboard::Key key2,const std::string& id, const std::string& name)
	:TextGo(id , name)
	,key1(key1)
	,key2(key2)
	,score(0)
{
}

TextScore::~TextScore()
{
}

void TextScore::Init()
{
}

void TextScore::Release()
{
}

void TextScore::Reset()
{
	TextGo::Reset();
	score = 0;
	text.setString("SCORE: 0");
}

void TextScore::Update(float dt)
{	
	if (InputMgr::GetKeyDown(key1) || InputMgr::GetKeyDown(key2)) {
		score += 10;
		SetString("SCORE: " + std::to_string(score));
	}
}

void TextScore::Draw(sf::RenderWindow& window)
{
	TextGo::Draw(window);
}

