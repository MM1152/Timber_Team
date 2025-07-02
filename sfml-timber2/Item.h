#pragma once
#include "stdafx.h"
#include "GameObject.h"
class Item : public GameObject
{
protected:
	sf::Sprite sp;
public:
	// GameObject��(��) ���� ��ӵ�
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

