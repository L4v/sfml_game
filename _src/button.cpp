#include "button.hpp"

Button::Button(float x, float y, float width, float height,
    sf::Font* font, std::string text, unsigned characterSize,
    sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
    sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor){

    this->buttonState = BTN_IDLE;

    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setFillColor(idleColor);

    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(textIdleColor);
    this->text.setCharacterSize(characterSize);
    this->text.setPosition(
        this->shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f
         - this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f
         - this->text.getGlobalBounds().height * 3.f / 4.f
    );

    this->textIdleColor = textIdleColor;
    this->textHoverColor = textHoverColor;
    this->textActiveColor = textActiveColor;

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

}

Button::~Button(){}

sf::RectangleShape& Button::getShape(){
    return this->shape;
}

const bool Button::isPressed() const{
    if(this->buttonState == 2)
        return true;
    return false;
    //return this->buttonState == BTN_ACTIVE ? true : false;
}

void Button::update(const sf::Vector2f& mousePos){

    // Resets to idle
    this->buttonState = BTN_IDLE;

    // Hover
    if(this->shape.getGlobalBounds().contains(mousePos)){
        this->buttonState = BTN_HOVER;

        // Active
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->buttonState =BTN_ACTIVE;
        }
    }

    // TODO : OPTIMIZE?
    switch(this->buttonState){
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
            this->text.setFillColor(this->textIdleColor);
            break;
        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            this->text.setFillColor(this->textHoverColor);
            break;
        case BTN_ACTIVE:
            this->shape.setFillColor(this->activeColor);
            this->text.setFillColor(this->textActiveColor);
            break;
        default:
            this->shape.setFillColor(sf::Color::Red);
            this->text.setFillColor(sf::Color::Blue);
            break;
    }

}

void Button::render(sf::RenderTarget& target){
    target.draw(this->shape);
    target.draw(this->text);
}
