#pragma once

#include "GameState.h"
#include "Button.h"

class MainMenuState : public State
{
private:
	//variables
	sf::RectangleShape background;
	sf::Font font;

	//func
	void initFonts();
	void initKeybinds() override;

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys);
	virtual ~MainMenuState();

	//func
	void endState() override;

	void updateInput(const float& dt) override;
	void update(const float& dt) override;
	void render(sf::RenderTarget* target = nullptr) override;
};

