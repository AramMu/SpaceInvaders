#include "collider.h"
#include <cmath>
#include <iostream>
#include "config.h"
#include "helpers.h"


bool Collider::checkCollision(const Target& t1, const Target& t2) {

    sf::FloatRect b1 = t1.getGlobalBounds();
    sf::FloatRect b2 = t2.getGlobalBounds();
    double r1 = std::min(b1.width, b1.height) / 2;
    double r2 = std::min(b2.width, b2.height) / 2;
//    std::cout << r1 << " " << r2 << std::endl;
//    std::cout << distance(t1.getPosition(), t2.getPosition()) << std::endl;
    return distance(t1.getPosition(), t2.getPosition()) < r1+r2;
//    return t1.getGlobalBounds().intersects(t2.getGlobalBounds());
}

void Collider::wallCollision(Target& t) {
    sf::FloatRect bounds = t.getGlobalBounds();
    if (bounds.left <= 0) {
        t.setDirectionX(-t.getDirectionX());
    }
    if (bounds.top <= 0) {
        t.setDirectionY(-t.getDirectionY());
    }
    if (bounds.left+bounds.width >= Config::window_width) {
        t.setDirectionX(-t.getDirectionX());
    }
    if (bounds.top+bounds.height >= Config::window_height) {
        t.setDirectionY(-t.getDirectionY());
    }
}



