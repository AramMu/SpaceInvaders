#include "helpers.h"
#include <SFML/Graphics.hpp>

void setCentered(sf::Sprite &obj) {
    sf::FloatRect bounds = obj.getGlobalBounds();
    obj.setOrigin(bounds.width/2, bounds.height/2);
}

void setCentered(sf::Text &obj) {
    sf::FloatRect bounds = obj.getGlobalBounds();
    obj.setOrigin(bounds.width/2, bounds.height/2);
}

