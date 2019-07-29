#include "game.hpp"
#include "mainmenustate.hpp"

void Game::initVariables(){
    this->mData->window = NULL;
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
        this->mData->window = new sf::RenderWindow(window_bounds, title,
            sf::Style::Fullscreen, this->windowSettings);
    else{
        this->mData->window = new sf::RenderWindow(window_bounds, title,
            sf::Style::Titlebar | sf::Style::Close, this->windowSettings);
    }

    this->mData->window->setFramerateLimit(framerate_limit);
    this->mData->window->setVerticalSyncEnabled(vertical_sync_enabled);

    sf::View view(sf::FloatRect(0.f, 0.f, window_bounds.width, window_bounds.height));
    this->mData->window->setView(view);
}

void Game::initStates(){
    this->mData->states.push(new MainMenuState(this->mData));
}

void Game::initKeys(){
    // Fetches the supported keys
    std::ifstream ifs("_config/supported_keys.ini");

    if(ifs.is_open()){
        std::string key = "";
        unsigned int key_value = 0;

        while(ifs >> key >> key_value)
            this->mData->supportedKeys[key] = key_value;
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
    /*delete this->window;

    while(!this->states.empty()){
        delete this->states.top();
        this->states.pop();
    }*/
}

void Game::endApplication(){
    std::cout << "Ending application" << std::endl;
}

void Game::updateDt(){
    // Updates dt - time it took to update and render one frame
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents(){
    while(this->mData->window->pollEvent(this->sfEvent)){
        if(this->sfEvent.type == sf::Event::Closed)
            this->mData->window->close();
    }
}

void Game::update(){
    this->updateSFMLEvents();

    if(!this->mData->states.empty()){
        this->mData->states.top()->update(this->dt);

        // Check for quit and quitting the state
        if(this->mData->states.top()->getQuit()){
            this->mData->states.top()->endState();
            delete this->mData->states.top();
            this->mData->states.pop();
        }
    }else{
        // Else if there are no states, then the application ends
        this->endApplication();
        this->mData->window->close();
    }
}

void Game::render(){
    this->mData->window->clear();

    if(!this->mData->states.empty())
        this->mData->states.top()->render();

    this->mData->window->display();
}

void Game::run(){
    while(this->mData->window->isOpen()){
        this->updateDt();
        this->update();
        this->render();
    }
}
