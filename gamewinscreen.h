#ifndef GAMEWINSCREEN_H
#define GAMEWINSCREEN_H
#include <SFML/Graphics.hpp>

class GameWinScreen
{
public:
    GameWinScreen(sf::RenderWindow &window);
    void run(sf::RenderWindow &window);
private:
    sf::Sprite background;
    sf::Text congrats;
    sf::Text quitButton;
};

#endif // GAMEWINSCREEN_H
