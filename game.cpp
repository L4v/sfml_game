#include "game.hpp"

void Game::initWindow(){

    std::ifstream ifs("_config/window.ini");

    std::string title = "none";
    sf::VideoMode window_bounds(800, 600);
    unsigned int framerate_limit = 60;
    bool vertical_sync_enabled = false;
    if(ifs.is_open()){
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initStates(){
    this->states.push(new GameState(this->window, &this->supportedKeys));
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
