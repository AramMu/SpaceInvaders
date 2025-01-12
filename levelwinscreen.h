#ifndef LEVELWINSCREEN_H
#define LEVELWINSCREEN_H
#include <SFML/Graphics.hpp>

class LevelWinScreen
{
public:
    enum ResponseType {
        NEXT, EXIT
    };
    LevelWinScreen(sf::RenderWindow &window);
    void run(sf::RenderWindow &window);
    ResponseType getResponse();
private:
    sf::Sprite background;
    sf::Text nextButton;
    sf::Text quitButton;
    ResponseType response;
};

#endif // LEVELWINSCREEN_H
