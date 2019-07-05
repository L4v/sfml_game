#include "mainmenustate.hpp"

void MainMenuState::initFonts(){
    if(!this->font.loadFromFile("_assets/_fonts/SHPinscher-Regular.otf"))
        std::cout << "Could not load font in main menu state" << std::endl;
}

void MainMenuState::initKeybinds(){
    // Fetches the adequate keybinds for the state
    std::ifstream ifs("_config/gamestate_keybinds.ini");

    if(ifs.is_open()){
        std::string key = "";
        std::string key2 = "";

        while(ifs >> key >> key2)
            this->keybinds[key] = this->supportedKeys->at(key2);
    }

    ifs.close();
}

void MainMenuState::initButtons(){

    this->buttons["GAME_STATE_BTN"] = new Button(100, 100, 150, 50,
        &this->font, "New Game",
        sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255),
        sf::Color(20, 20, 20, 255));
    this->buttons["EXIT"] = new Button(100, 200, 150, 50,
        &this->font, "Quit",
        sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255),
        sf::Color(20, 20, 20, 255));
}

MainMenuState::MainMenuState(sf::RenderWindow* window,
    std::map<std::string, int>* supportedKeys) : State(window, supportedKeys){
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}

MainMenuState::~MainMenuState(){
    for(auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
        delete it->second;

}

void MainMenuState::endState(){
    std::cout << "Ending main menu state" << std::endl;
}

void MainMenuState::updateButtons(){
    for(auto &it : this->buttons){
        it.second->update(this->mousePosView);
    }

    // New Game
    if(this->buttons["GAME_STATE_BTN"]->isPressed()){
        // TODO : MAKE IT CLEANER, STATE MANAGER/HANDLER CLASS ?
        //this->states.push(new GameState(this->window, this->supportedKeys));
    }

    // Quit
    if(this->buttons["EXIT"]->isPressed()){
        this->quit = true;
    }
}

void MainMenuState::updateInput(const float& dt){
    this->checkForQuit();
}

void MainMenuState::update(const float& dt){

    this->updateMousePositions();
    this->updateInput(dt);

    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget* target){
    for(auto &it : this->buttons){
        it.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget* target){
    if(!target)
        target = this->window;

    target->draw(this->background);

    this->renderButtons(target);
}
