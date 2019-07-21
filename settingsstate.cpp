#include "settingsstate.hpp"

// Init functions

void SettingsState::initVariables(){}

void SettingsState::initBackground(){
    this->mBackground.setSize(sf::Vector2f(
        static_cast<float>(this->window->getSize().x),
        static_cast<float>(this->window->getSize().y)));

    // TODO : USE BETTER FILE LOADING (VARIABLES)
    if(!this->mBackgroundTexture.loadFromFile(
            "_assets/_backgrounds/mainmenustate_bg.png"))
        throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BG_TEXTURE";

    this->mBackground.setTexture(&this->mBackgroundTexture);
}

void SettingsState::initFonts(){
    if(!this->mFont.loadFromFile("_assets/_fonts/SHPinscher-Regular.otf"))
        std::cout << "Could not load font in main menu state" << std::endl;
}

void SettingsState::initKeybinds(){
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

void SettingsState::initButtons(){

    // TODO : MAKE BETTER "WRAPPER" FOR BUTTONS (OR A MANAGER)

    int margin = 20; // Temp margin for buttons

    this->mButtons["EXIT"] = new Button(
        100, 100,// TODO : Fix!!!
        150, 50,
        &this->mFont, "Quit", 24,
        sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250),
        sf::Color(20, 20, 20, 50),
        sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0),
        sf::Color(20, 20, 20, 0));
}

SettingsState::SettingsState(sf::RenderWindow* window,
    std::map<std::string, int>* supportedKeys, std::stack<State*>* states)
    : State(window, supportedKeys, states)
{
    this->initVariables();
    this->initFonts();
    this->initKeybinds();
    this->initBackground();
    this->initButtons();
}

SettingsState::~SettingsState(){
    for(auto it = this->mButtons.begin(); it != this->mButtons.end(); ++it)
        delete it->second;
}

// Getters and setters

// Functions

void SettingsState::updateButtons(){
    for(auto &it : this->mButtons){
        it.second->update(this->mousePosView);
    }

    // Quit
    if(this->mButtons["EXIT"]->isPressed()){
        this->endState();
    }
}

void SettingsState::updateInput(const float& dt){
}

void SettingsState::update(const float& dt){

    this->updateMousePositions();
    this->updateInput(dt);

    this->updateButtons();
}

void SettingsState::renderButtons(sf::RenderTarget& target){
    for(auto &it : this->mButtons){
        it.second->render(target);
    }
}

void SettingsState::render(sf::RenderTarget* target){
    if(!target)
        target = this->window;

    target->draw(this->mBackground);

    this->renderButtons(*target);

    // TEMP
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 10);
    mouseText.setFont(this->mFont);
    mouseText.setCharacterSize(12);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());

    target->draw(mouseText);
}
