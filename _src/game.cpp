#include "game.hpp"

void Game::initVariables(){
    this->window = NULL;
    this->fullscreen = false;
    this->dt = 0.f;

}

void Game::initWindow(){

    // TODO : USE STRUCT ?

    std::ifstream ifs("_config/window.ini");

    this->videoModes = sf::VideoMode::getFullscreenModes();

    // Default values
    std::string title = "none";
    sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
    bool fullscreen = false;
    unsigned int framerate_limit = 60;
    bool vertical_sync_enabled = false;
    unsigned antialiasing_level = 0;

    // Reading from windows.ini file
    if(ifs.is_open()){
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> fullscreen;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
        ifs >> antialiasing_level;
    }

    ifs.close();

    this->fullscreen = fullscreen; // fuj
    this->windowSettings.antialiasingLevel = antialiasing_level;
    if(this->fullscreen)
        this->window = new sf::RenderWindow(window_bounds, title,
            sf::Style::Fullscreen, this->windowSettings);
    else{
        this->window = new sf::RenderWindow(window_bounds, title,
            sf::Style::Titlebar | sf::Style::Close, this->windowSettings);
    }

    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates(){
    this->states.push(new MainMenuState(this->window, &this->supportedKeys,
        &this->states));
}

void Game::initKeys(){
    // Fetches the supported keys
    std::ifstream ifs("_config/supported_keys.ini");

    if(ifs.is_open()){
        std::string key = "";
        unsigned int key_value = 0;

        while(ifs >> key >> key_value)
            this->supportedKeys[key] = key_value;
    }

    ifs.close();
}

Game::Game(){
    this->initVariables();
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game(){
    delete this->window;

    while(!this->states.empty()){
        delete this->states.top();
        this->states.pop();
    }
}

void Game::endApplication(){
    std::cout << "Ending application" << std::endl;
}

void Game::updateDt(){
    // Updates dt - time it took to update and render one frame
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents(){
    while(this->window->pollEvent(this->sfEvent)){
        if(this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update(){
    this->updateSFMLEvents();

    if(!this->states.empty()){
        this->states.top()->update(this->dt);

        // Check for quit and quitting the state
        if(this->states.top()->getQuit()){
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }else{
        // Else if there are no states, then the application ends
        this->endApplication();
        this->window->close();
    }
}

void Game::render(){
    this->window->clear();

    if(!this->states.empty())
        this->states.top()->render();

    this->window->display();
}

void Game::run(){
    while(this->window->isOpen()){
        this->updateDt();
        this->update();
        this->render();
    }
}