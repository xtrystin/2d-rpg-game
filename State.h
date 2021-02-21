#pragma once

#include "Entity.h"

//abstract class
class State
{
private:

protected:
	sf::RenderWindow * window;
	std::map<const char*, sf::Keyboard::Key> * supportedKeys;
	std::map<const char*, sf::Keyboard::Key> keybinds;			//each state has own keybinds
	bool quit;

	//resources
	std::vector<sf::Texture> textures;

	//func
	virtual void initKeybinds() =0;

public:
	State(sf::RenderWindow* window, std::map<const char*, sf::Keyboard::Key> * supportedKeys);
	virtual ~State();


	const bool& getQuit() const;
	virtual void checkForQuit();	//same for all States -> if escape is cklicked then quit that state
	virtual void endState() =0;	//save some items/ do the quitting animation before quitting
	
	virtual void updateInput(const float& dt) =0;
	virtual void update(const float& dt) =0;
	virtual void render(sf::RenderTarget * target = nullptr) =0;
};

