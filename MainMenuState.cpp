#include "MainMenuState.h"

//initializer func
void MainMenuState::initVariables()
{
}

void MainMenuState::initBackground()
{
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);
	//loading background picture
	if (!this->backgroundTexture.loadFromFile("resources/images/backgrounds/bg2.jpg"))
	{
		throw("ERROR: MainMenuState::initBackground (could not load picture)");
		std::cerr << "ERROR: MainMenuState::initBackground (could not load picture) \n";
		this->background.setFillColor(sf::Color::Cyan);			//default background color
	}
	else
		this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("fonts/Macondo-Regular.ttf"))
	{
		throw("ERROR: MainMenuState::initFonts  (could not load font)");
		std::cerr << "ERROR: MainMenuState::initFonts  (could not load font) \n";
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
	this->buttons["GAME_STATE"] = new Button(260, 230, 250, 50, &this->font, "New Game",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["SETTINGS"] = new Button(260, 330, 250, 50, &this->font, "Settings",
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(260, 430, 250, 50, &this->font, "Quit",
		sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));

}

//constructor
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initKeybinds();
	this->initButtons();


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
/*void MainMenuState::endState()
{
	std::cout << "ending MainMenuState \n";
}
*/
void MainMenuState::updateInput(const float& dt)
{
	//this->checkForQuit();	//State func  if escape clicked -> leave

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
		this->endState();

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

	//DEBUG --- show mouse position ---
	sf::Text mouseText;
	mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
	mouseText.setFont(this->font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << this->mousePosView.x << " " << this->mousePosView.y;
	mouseText.setString(ss.str());

	target->draw(mouseText);

	//target->draw(sf::Text("MENU", this->font));
}