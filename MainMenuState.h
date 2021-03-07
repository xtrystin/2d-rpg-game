#pragma once

#include "GameState.h"
#include "Button.h"

class MainMenuState : public State
{
private:
	//variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, Button*>  buttons;

	//func
	void initVariables();
	void initBackground();
	void initFonts();
	void initKeybinds() override;
	void initButtons();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys, std::stack<State*>* states);
	virtual ~MainMenuState();

	//func
	//void endState() override;

	void updateInput(const float& dt) override;
	void updateButtons();
	void update(const float& dt) override;
	void renderButtons(sf::RenderTarget* target = nullptr);
	void render(sf::RenderTarget* target = nullptr) override;
};

