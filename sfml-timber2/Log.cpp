#include "stdafx.h"
#include "Log.h"
#include "DummyLog.h"

Log::Log(sf::Keyboard::Key key1, sf::Keyboard::Key key2, const std::string& id, sf::Vector2f windowRange, const std::string& name) ///windowRange값 변경해서 땅에 닿으면, 이미지 쌓이게 
	:key1(key1)
	, key2(key2)
	, logIds(id)
	, backGroundSize(backGroundSize)
	, windowRange(windowRange)
	,GameObject(name)
{

}

void Log::Init()
{
}

void Log::Release()
{
}

void Log::Reset()
{
	for (int i = 0; i < 5; i++) {
		spriteLog[i].setTexture(TEXTURE_MGR.Get(logIds));
		velocity[i] = { speed , -speed };
		isActive[i] = false;
		spriteLog[i].setPosition(InitPos);
	}
}

void Log::Update(float dt)
{
	if (InputMgr::GetKeyDown(key1) || InputMgr::GetKeyDown(key2)) {
		for (int i = 0; i < 5; i++) {
			if (!isActive[i]) {
				if (InputMgr::GetKeyDown(key1)) {
					velocity[i] = {speed , -speed};
				}
				else {
					velocity[i] = { -speed , -speed };
				}
				isActive[i] = true;
				break;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		if (isActive[i]) {
			sf::Vector2f pos = spriteLog[i].getPosition();
			velocity[i] += gravity * dt;
			pos += velocity[i] * dt;
			spriteLog[i].setPosition(pos);
			CheckOutOfWindow(i);
		}
	}
}

void Log::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 5; i++) {
		if (isActive[i])
		{
			window.draw(spriteLog[i]);
		}
	}
}

void Log::SetPosition(const sf::Vector2f& pos)
{
	position = pos;

	if (InitPos.x == -100 && InitPos.y == -100) {
		InitPos = position;
	}

	for (int i = 0; i < 5; i++) {
		spriteLog[i].setPosition(position);
	}
}

void Log::SetOrigin(Origins preset)
{
	originPreset = preset;
	if (originPreset != Origins::Custom) {
		for (int i = 0; i < 5; i++) {
			Utils::SetOrigin(spriteLog[i], originPreset);
		}
	}
}

void Log::SetScale(const sf::Vector2f& s)
{
	scale = s;
	for (int i = 0; i < 5; i++) {
		spriteLog[i].setScale(scale);
	}
}

void Log::CheckOutOfWindow(int idx)
{
	if (spriteLog[idx].getPosition().x >= windowRange.y || spriteLog[idx].getPosition().x <= windowRange.x) {
		spriteLog[idx].setPosition(InitPos);
		isActive[idx] = false;
		velocity[idx] = {speed , -speed};
	}
}


void Log::SetWindowRange(sf::Vector2f windowRange)
{
	this->windowRange = windowRange;
}
