#pragma once
class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

protected:
	SceneMgr() = default;
	~SceneMgr() = default;

	std::vector<Scene*> scenes;


	SceneIds startScene = SceneIds::CharacterChoice;
	SceneIds currentScene = SceneIds::None;
	SceneIds nextScene = SceneIds::None;
	SceneIds beforeScene = SceneIds::None;

	std::string characterChoose;
	std::string characterChoose2p;

	int choiceCharacterIndex = 0;
	int choiceCharacterIndex2p = 0;

public:
	void Init();
	void Release();

	Scene* GetCurrentScene() { return scenes[(int)currentScene]; }
	SceneIds GetCurrentSceneId() const { return currentScene; }
	void SetChoiceCharacter(int index) { choiceCharacterIndex = index; }
	int GetChoiceCharacter() { return choiceCharacterIndex; }
	void SetChoiceCharacter2p(int index) { choiceCharacterIndex2p = index; }
	int GetChoiceCharacter2p() { return choiceCharacterIndex2p; }
	void ChangeScene(SceneIds id);

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

#define SCENE_MGR (SceneMgr::Instance())

