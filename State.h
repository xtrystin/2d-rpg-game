#pragma once

#include "Entity.h"

//abstract class
class State
{
private:

protected:
	std::stack<State*> * states;	// huge stack of states
	sf::RenderWindow * window;
	std::map<std::string, sf::Keyboard::Key> * supportedKeys;		//const
	std::map<std::string, sf::Keyboard::Key> keybinds;			//each state has own keybinds
	bool quit;

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//resources
	std::vector<sf::Texture> textures;

	//func
	virtual void initKeybinds() =0;

public:
	State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key> * supportedKeys, std::stack<State*> * states);
	virtual ~State();


	const bool& getQuit() const;
	
	virtual void checkForQuit();	//same for all States -> if escape is cklicked then quit that state

	virtual void endState() = 0;	//save some items/ do the quitting animation before quitting

	virtual void updateMousePositions();
	virtual void updateInput(const float& dt) =0;
	virtual void update(const float& dt) =0;
	virtual void render(sf::RenderTarget * target = nullptr) =0;
};

