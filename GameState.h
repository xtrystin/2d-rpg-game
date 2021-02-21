#pragma once
#include "State.h"

class GameState : public State
{
private:
	Entity player;

	//func
	void initKeybinds() override;

public:
	GameState(sf::RenderWindow* window, std::map<const char*, sf::Keyboard::Key>* supportedKeys);
	virtual ~GameState();

	//func
	void endState() override;

	void updateInput(const float& dt) override;
	void update(const float& dt) override;
	void render(sf::RenderTarget* target = nullptr) override;
};

