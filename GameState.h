#pragma once
#include "State.h"

class GameState : public State
{
private:
	Player * player;

	//func
	void initKeybinds() override;
	void initTextures();
	void initPlayers();

public:
	GameState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys, std::stack<State*>* states);
	virtual ~GameState();

	//func
	//void endState() override;

	void updateInput(const float& dt) override;
	void update(const float& dt) override;
	void render(sf::RenderTarget* target = nullptr) override;
};

