#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

//abstract class
class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

public:
	State(sf::RenderWindow* window);
	virtual ~State();


	const bool& getQuit() const;
	virtual void checkForQuit();
	virtual void endState() =0;	//save some items/ do the quitting animation before quitting
	
	virtual void updateKeybinds(const float& dt) =0;
	virtual void update(const float& dt) =0;
	virtual void render(sf::RenderTarget * target = nullptr) =0;
};

