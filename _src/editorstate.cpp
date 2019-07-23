#include "editorstate.hpp"

// Inits

void EditorState::initVariables(){}

void EditorState::initBackground(){

}

void EditorState::initFonts(){
    if(!this->font.loadFromFile("_assets/_fonts/SHPinscher-Regular.otf"))
        throw "ERROR::EDITOR_STATE::COULD_NOT_LOAD_FONT";
}

void EditorState::initKeybinds(){
    // Fetches the adequate keybinds for the state
    std::ifstream ifs("_config/editorstate_keybinds.ini");

    if(ifs.is_open()){
        std::string key = "";
        std::string key2 = "";

        while(ifs >> key >> key2)
            this->keybinds[key] = this->mData->supportedKeys->at(key2);
    }

    ifs.close();
}

void EditorState::initButtons(){

    // TODO : MAKE BETTER "WRAPPER" FOR BUTTONS (OR A MANAGER)

    int margin = 20; // Temp margin for buttons

}

EditorState::EditorState(GameDataRef data) :
    State(data){

    this->initVariables();
    this->initFonts();
    this->initKeybinds();
    this->initBackground();
    this->initButtons();

}

EditorState::~EditorState(){
    for(auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
        delete it->second;

}

void EditorState::updateButtons(){

    // Update all the buttons
    for(auto &it : this->buttons){
        it.second->update(this->mousePosView);
    }

}

void EditorState::updateInput(const float& dt){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))))
        this->endState();
}

void EditorState::update(const float& dt){

    this->updateMousePositions();
    this->updateInput(dt);

    this->updateButtons();
}

void EditorState::renderButtons(sf::RenderTarget& target){
    for(auto &it : this->buttons){
        it.second->render(target);
    }
}

void EditorState::render(sf::RenderTarget* target){
    if(!target)
        target = this->mData->window;


    this->renderButtons(*target);

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
