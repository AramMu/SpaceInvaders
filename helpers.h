#ifndef HELPERS_H
#define HELPERS_H
#include <SFML/Graphics.hpp>
#include <cmath>

// Sets origin to center
void setCentered(sf::Sprite &obj);
void setCentered(sf::Text &obj);

template <typename T>
T sqr(T x) {
    return x*x;
}

template <typename Point>
double distance(Point p1, Point p2) {
    return std::sqrt(sqr(p1.x - p2.x) + sqr(p1.y - p2.y));
}

template <typename SceneObject>
bool containsMouse(sf::RenderWindow &window, SceneObject& obj) {
    return obj.getGlobalBounds().contains((sf::Vector2f) sf::Mouse::getPosition(window));
}


#endif // HELPERS_H
