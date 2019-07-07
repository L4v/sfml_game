#include "mainmenustate.hpp"

// Inits

void MainMenuState::initVariables(){}

void MainMenuState::initBackground(){
    this->background.setSize(sf::Vector2f(
        static_cast<float>(this->window->getSize().x),
        static_cast<float>(this->window->getSize().y)));

    // TODO : USE BETTER FILE LOADING (VARIABLES)
    if(!this->backgroundTexture.loadFromFile(
            "_assets/_backgrounds/mainmenustate_bg.png"))
        throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BG_TEXTURE";

    this->background.setTexture(&this->backgroundTexture);
}

void MainMenuState::initFonts(){
    if(!this->font.loadFromFile("_assets/_fonts/SHPinscher-Regular.otf"))
        std::cout << "Could not load font in main menu state" << std::endl;
}

void MainMenuState::initKeybinds(){
    // Fetches the adequate keybinds for the state
    std::ifstream ifs("_config/mainmenustate_keybinds.ini");

    if(ifs.is_open()){
        std::string key = "";
        std::string key2 = "";

        while(ifs >> key >> key2)
            this->keybinds[key] = this->supportedKeys->at(key2);
    }

    ifs.close();
}

void MainMenuState::initButtons(){

    // TODO : MAKE BETTER "WRAPPER" FOR BUTTONS (OR A MANAGER)

    int margin = 20; // Temp margin for buttons

    this->buttons["GAME_STATE_BTN"] = new Button(
        this->background.getSize().x / 10, this->background.getSize().y * 5 / 8,
        150, 50,
        &this->font, "New Game",
        sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255),
        sf::Color(20, 20, 20, 255));

    this->buttons["SETTINGS"] = new Button(
        this->background.getSize().x / 10,
        this->buttons["GAME_STATE_BTN"]->getShape().getPosition().y
            + this->buttons["GAME_STATE_BTN"]->getShape().getSize().y + margin,//this->background.getSize().y * 5 / 8,
        150, 50,
        &this->font, "Settings",
        sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255),
        sf::Color(20, 20, 20, 255));

    this->buttons["EXIT"] = new Button(
        this->background.getSize().x / 10,
        this->buttons["SETTINGS"]->getShape().getPosition().y
            + this->buttons["SETTINGS"]->getShape().getSize().y + margin,//this->background.getSize().y / 2,
        150, 50,
        &this->font, "Quit",
        sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255),
        sf::Color(20, 20, 20, 255));
}

MainMenuState::MainMenuState(sf::RenderWindow* window,
    std::map<std::string, int>* supportedKeys, std::stack<State*>* states) :
    State(window, supportedKeys, states){

    this->initVariables();
    this->initFonts();
    this->initKeybinds();
    this->initBackground();
    this->initButtons();

}

MainMenuState::~MainMenuState(){
    for(auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
        delete it->second;

}

void MainMenuState::updateButtons(){
    for(auto &it : this->buttons){
        it.second->update(this->mousePosView);
    }

    // New Game
    if(this->buttons["GAME_STATE_BTN"]->isPressed()){
        // TODO : MAKE IT CLEANER, STATE MANAGER/HANDLER CLASS ?
        this->states->push(new GameState(this->window, this->supportedKeys,
            this->states));

    }

    // Quit
    if(this->buttons["EXIT"]->isPressed()){
        this->endState();
    }
}

void MainMenuState::updateInput(const float& dt){
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

    // TEMP
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 10);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(12);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());

    target->draw(mouseText);
}
