#pragma once

#include "GameState.h"


class Game
{
private:
	//variables
	sf::RenderWindow * window;	
	sf::Event sfEvent;

	//game clock
	sf::Clock dtClock;
	float dt;


	std::stack<State*> states;	//state is a abstract class

	std::map<const char*, sf::Keyboard::Key> supportedKeys;	//std::string - const char* ; sf::Keyboard::Key is int 

	// initialization
	void initWindow();
	void initKeys();
	void initStates();

public:
	//constructor 
	Game();
	virtual ~Game();

	//func

	//regular func
	void endApplication();

	//update
	void updateDt();
	void updateSFMLEvents();
	void update();	//update items in a window

	//render
	void render();	//dislay a window

	//core
	void run();		//run a window
};

