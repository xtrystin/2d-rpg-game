#include "Game.h"

// static func


// initialize func
void Game::initVariables()
{
    this->window = nullptr;
    this->fullscreen = false;
    this->dt = 0.f;
}

void Game::initWindow()
{
    //default window values
    std::string title = "none";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    bool fullscreen = false;
    unsigned int framerate_limit = 120;
    bool vertical_sync_enabled = false;
    unsigned antialiasing_level = 0;

    this->videoModes = sf::VideoMode::getFullscreenModes();


    //read from config file
    std::ifstream ifs;
    ifs.open("config/windowConfig.ini");
    if (!ifs.fail())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> fullscreen;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
        ifs >> antialiasing_level;
    }
    ifs.close();

    this->fullscreen = fullscreen;
    //contex config
    this->windowSettings.antialiasingLevel = antialiasing_level;
    //sfml window initialize
    if(this->fullscreen)
        this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, this->windowSettings);
    else
        this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close, this->windowSettings);

    //window config
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);

}

void Game::initKeys()
{
    //read keybinds from file
    std::ifstream ifs;
    ifs.open("config/supported_keys.ini");
    if (!ifs.fail())
    {
        std::string key;
        int key_int_value;
        while (ifs >> key >> key_int_value)
        {
            this->supportedKeys.emplace(key, sf::Keyboard::Key(key_int_value));
        }


    }
    else        //defailt basic values
    {
        this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
        this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
        this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
        this->supportedKeys["W"] = sf::Keyboard::Key::W;
        this->supportedKeys["S"] = sf::Keyboard::Key::S;
    }
    ifs.close();

    

    //DEBUG
    //std::cout << this->supportedKeys.at("A") << std::endl;
    for (auto it : this->supportedKeys)     //std::map<const char*, sf::Keyboard::Key>::iterator it
        std::cout << it.first << " " << it.second << std::endl;
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &(this->supportedKeys), &this->states));
    //this->states.push(new GameState(this->window, &(this->supportedKeys)));

}

//Comstructor
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initKeys();
    this->initStates();

}

Game::~Game()
{
	delete this->window;

    while (!this->states.empty())   //remove all the states
    {
        delete this->states.top();
        this->states.pop();
    }
        
}

//func

void Game::endApplication()
{
    std::cout << "Ending the application \n";
}

void Game::updateDt()
{
    //render and update 1 frame time
    this->dt = this->dtClock.restart().asSeconds();
   // system("cls");
    //std::cout << dt << "\n";
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

    if (!this->states.empty())
    {
        this->states.top()->update(this->dt);   //update a state that is on top of stack

        if (this->states.top()->getQuit())  //if wants to quit -> delete that state from stack
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else                        //if 0 states -> close the program
    {
        this->endApplication();
        this->window->close();
    }


}

void Game::render()
{
    this->window->clear();
    
    //render items
    if (!this->states.empty())
        this->states.top()->render();//render this->window   //render a state that is on top of stack

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
