#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{
}

GameState::~GameState()
{
}


void GameState::endState()
{
	std::cout << "ending GameState \n";
}

void GameState::updateKeybinds(const float& dt)
{
	this->checkForQuit();	//State func  if escape clicked -> leave

	//check for pressing keys
}

void GameState::update(const float& dt)
{
	this->updateKeybinds(dt);
	std::cout << "GameState \n";

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "A\n";
}

void GameState::render(sf::RenderTarget* target /* = nullptr*/)
{

}