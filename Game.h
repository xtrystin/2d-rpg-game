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


	// initialization
	void initWindow();
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

