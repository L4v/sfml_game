#pragma once

#include <SFML/Graphics.hpp>

// Button states
enum ButtonStates{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE};

class Button{
private:
    short unsigned buttonState;

    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    // TODO : MAKE STRUCT
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:

    /*
    * Constructor and destructor
    */
    Button(float x, float y, float width, float height,
        sf::Font* font, std::string text,
        sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

    virtual ~Button();

    /*
    * Check if button is pressed
    */
    const bool isPressed() const;

    /*
    * Update hovered/pressed buttons
    */
    void update(sf::Vector2f mousePos);

    /*
    * Render buttons
    */
    void render(sf::RenderTarget* target);
};
