#pragma once
#include "GameObject.h"
class UiHud : public GameObject
{
protected:
	sf::Text textScore;
	sf::Text textMessage;

	sf::RectangleShape timeBar;

	std::string fontId;
	std::string texSoundId;
	std::string texMuteId;
	bool isShowMessage;

	sf::Vector2f timeBarSize;

	//@
	sf::Sprite soundIcon;
	sf::Sprite muteIcon;
	bool isShowSoundIcon;
	bool isShowMuteIcon;

public:
	UiHud(const std::string& name = "");
	~UiHud() override = default;

	void SetScore(int score);
	void SetMessage(const std::string& msg);
	void SetShowMassage(bool show) { isShowMessage = show; }
	void SetTimeBar(float value); // 0.f ~ 1.f
	void SetSoundIcon(bool show) { isShowSoundIcon = show; } 
	void SetMuteIcon(bool show) { isShowMuteIcon = show; }	

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
};
