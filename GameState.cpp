#include "GameState.h"

//init func
void GameState::initKeybinds()
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

void GameState::initTextures()
{
	//load texture from file to new std::map element
	if (!this->textures["PLAYER_IDLE"].loadFromFile("resources/images/sprites/player/test1.png"))
	{
		throw("ERROR::GameState::Could not load PLAYER_IDLE texture");
		std::cerr << "ERROR::GameState::Could not load PLAYER_IDLE texture \n";
	}
}

void GameState::initPlayers()
{
	this->player = new Player(0, 0, &this->textures["PLAYER_IDLE"]);
}

//constructor
GameState::GameState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys, std::stack<State*>* states)
	: State(window, supportedKeys, states)
{
	this->initKeybinds();
	this->initTextures();
	this->initPlayers();
}

GameState::~GameState()
{
	delete this->player;
}

//func
/*void GameState::endState()
{
	std::cout << "ending GameState \n";
}
*/
void GameState::updateInput(const float& dt)
{
	//this->checkForQuit();	//State func  if escape clicked -> leave

	//check for pressing keys
	if (sf::Keyboard::isKeyPressed(this->keybinds.at("MOVE_LEFT")))
		this->player->move(dt, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(this->keybinds.at("MOVE_RIGHT")))
		this->player->move(dt, 1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(this->keybinds.at("MOVE_UP")))
		this->player->move(dt, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(this->keybinds.at("MOVE_DOWN")))
		this->player->move(dt, 0.f, 1.f);

	if (sf::Keyboard::isKeyPressed(this->keybinds.at("CLOSE")))
		this->endState();
}

void GameState::update(const float& dt)
{
	this->updateMousePositions();
	this->updateInput(dt);
	
	//std::cout << "GameState \n";
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//	std::cout << "A\n";

	this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target /* = nullptr*/)
{
	if (!target)			//if target = 0 or render() without an argument
		target = this->window;
	
	this->player->render(target);	//render specific target
}