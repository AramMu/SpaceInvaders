#ifndef GUIDESCREEN_H
#define GUIDESCREEN_H
#include <SFML/Graphics.hpp>

class GuideScreen
{
public:
    GuideScreen(sf::RenderWindow &window);
    void run(sf::RenderWindow &window);
private:
    sf::Sprite background;
};

#endif // GUIDESCREEN_H
