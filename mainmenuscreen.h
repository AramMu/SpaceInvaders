#ifndef MAINMENUSCREEN_H
#define MAINMENUSCREEN_H
#include <SFML/Graphics.hpp>

class MainMenuScreen
{
public:
    MainMenuScreen();
    void run();
private:
    sf::RenderWindow window;
    sf::Sprite background;

//    sf::Sprite startButton;
//    sf::Sprite quitButton;

    sf::Text startButton;
    sf::Text quitButton;

//    sf::Texture startTexture;
//    sf::Texture quitTexture;
};

#endif // MAINMENUSCREEN_H
