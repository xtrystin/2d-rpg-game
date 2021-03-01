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
	ifs.open("config/mainmenustate_keybinds.ini");
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

void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50, &this->font, "New Game",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(100, 300, 150, 50, &this->font, "Quit",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

}

//constructor
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initFonts();
	this->initKeybinds();
	this->initButtons();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Cyan);
}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it)
	{
		delete it->second;
	}
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

void MainMenuState::updateButtons()
{
	//updates all the buttons and handles functionality
	for (auto &it : this->buttons)
	{
		it.second->update(this->mousePosView);
	}

	//push GameState on the stack
	if (this->buttons["GAME_STATE"]->isPressed())
		this->states->push(new GameState(this->window, this->supportedKeys, this->states));


	//quit the MainMenuState
	if (this->buttons["EXIT_STATE"]->isPressed())
		this->quit = true;

}

void MainMenuState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);

	this->updateButtons();

	//std::cout << this->mousePosView.x << " " << this->mousePosView.y << std::endl;
	//std::cout << "MainMenuState \n";

}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto &it : this->buttons)
	{
		it.second->render(target);
	}

}

void MainMenuState::render(sf::RenderTarget* target /* = nullptr*/)
{
	if (!target)			//if target = 0 or render() without an argument
		target = this->window;

	target->draw(this->background);
	
	this->renderButtons(target);

	//target->draw(sf::Text("MENU", this->font));
}