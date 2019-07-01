#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "particlesystem.hpp"

void draw(sf::RenderWindow& window){

}

void update(){}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game!");

    // Character sprite sheet
    sf::Texture character_sprite_sheet;

    // Character sprite
    sf::Sprite character_sprite;

    if(!character_sprite_sheet.loadFromFile("_assets/_sprites/character_sprite_sheet.png")){
        // TODO : error for loading sprite

    }
    character_sprite.setTexture(character_sprite_sheet);
    int x_offset = 0;

    sf::Clock clock;

    // Particle test
    ParticleSystem particles(1000);
    sf::Clock clock_particle;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {


            // Keyboard events
            if(event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::Left:
                        character_sprite.move(sf::Vector2f(-2.f, 0));
                        break;
                    case sf::Keyboard::Right:
                        character_sprite.move(sf::Vector2f(2.f, 0));
                        break;

                }
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(clock.getElapsedTime().asSeconds() > 0.5f){
            x_offset = (++x_offset)%3;
            clock.restart();
        }
        character_sprite.setTextureRect(sf::IntRect(x_offset*50, 0, 50, 37));

        // Particles
        sf::Vector2i mouse = sf::Mouse::getPosition(window);
        particles.setEmitter(window.mapPixelToCoords(mouse));
        sf::Time elapsed = clock_particle.restart();
        particles.update(elapsed);

        window.clear();
        window.draw(character_sprite);
        window.draw(particles);
        window.display();
    }

    return 0;
}
