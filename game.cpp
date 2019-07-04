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

Game::Game(){
    this->initWindow();
}

Game::~Game(){
    delete this->window;
}

void Game::updateDt(){
    // Updates dt - time it took to update and render one frame
    this->dt = this->dtClock.restart().asSeconds();

    system("clear");
    std::cout << this->dt << "\n";
}

void Game::updateSFMLEvents(){
    while(this->window->pollEvent(this->sfEvent)){
        if(this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update(){
    this->updateSFMLEvents();
}

void Game::render(){
    this->window->clear();

    this->window->display();
}

void Game::run(){
    while(this->window->isOpen()){
        this->updateDt();
        this->update();
        this->render();
    }
}
