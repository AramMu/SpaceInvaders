#ifndef GAMELOSESCREEN_H
#define GAMELOSESCREEN_H
#include <SFML/Graphics.hpp>

class GameLoseScreen
{
public:
    GameLoseScreen(sf::RenderWindow &window);
    void run(sf::RenderWindow &window);
private:
    sf::Sprite background;
    sf::Text sorry;
    sf::Text quitButton;
};

#endif // GAMELOSESCREEN_H
