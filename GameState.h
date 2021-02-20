#pragma once
#include "State.h"

class GameState : public State
{
private:


public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	//func
	void endState() override;

	void updateKeybinds(const float& dt) override;
	void update(const float& dt) override;
	void render(sf::RenderTarget* target = nullptr) override;
};

