#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics.hpp>

class MainMenu
{
public:
    MainMenu();
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

#endif // MAINMENU_H
