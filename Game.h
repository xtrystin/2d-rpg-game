#pragma once

#include "State.h"


class Game
{
private:
	//variables
	sf::RenderWindow * window;	
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;


	//initialization
	void initWindow();

public:
	//constructor 
	Game();
	virtual ~Game();

	//func
	void updateDt();
	void updateSFMLEvents();
	void update();	//update items in a window
	void render();	//dislay a window
	void run();		//run a window
};

