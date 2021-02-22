#include "MainMenuState.h"

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("fonts/Macondo-Regular.ttf"))
	{
		throw("ERROR: MainMenuState::initFonts  (could not load font)");
	}

}

void MainMenuState::initKeybinds()
{
	
	std::ifstream ifs;
	ifs.open("config/gamestate_keybinds.ini");
	if (!ifs.fail())
	{
		std::string key;
		std::string supportedkey;
		while (ifs >> key >> supportedkey)
		{
			this->keybinds[key] = this->supportedKeys->at(supportedkey);
		}


	}
	else        //defailt basic values
	{
		this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
		this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
		this->keybinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
		this->keybinds["MOVE_UP"] = this->supportedKeys->at("W");
		this->keybinds["MOVE_DOWN"] = this->supportedKeys->at("S");
	}
	ifs.close();
	
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys) : State(window, supportedKeys)
{
	this->initFonts();
	this->initKeybinds();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Cyan);
}

MainMenuState::~MainMenuState()
{
}

//func
void MainMenuState::endState()
{
	std::cout << "ending MainMenuState \n";
}

void MainMenuState::updateInput(const float& dt)
{
	this->checkForQuit();	//State func  if escape clicked -> leave

	//check for pressing keys

}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << std::endl;
	//std::cout << "MainMenuState \n";

}

void MainMenuState::render(sf::RenderTarget* target /* = nullptr*/)
{
	if (!target)			//if target = 0 or render() without an argument
		target = this->window;

	target->draw(this->background);
	//target->draw(sf::Text("MENU", this->font));
}