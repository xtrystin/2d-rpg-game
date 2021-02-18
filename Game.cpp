#include "Game.h"

// static func

// initialize func
void Game::initWindow()
{
    //sfml window
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "2d RPG GAME");
}

//Comstructor
Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//func

void Game::updateDt()
{
    //render and update 1 frame time
    this->dt = this->dtClock.restart().asSeconds();
    system("cls");
    std::cout << dt << "\n";
}

void Game::updateSFMLEvents()
{
    //check sfml events
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }

}

void Game::update()
{
    this->updateSFMLEvents();

}

void Game::render()
{
    this->window->clear();
    
    //render items

    this->window->display();
}

void Game::run()
{
    //window is open
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update(); 
        this->render();
    }
}
