#include <iostream>
#include "gamescreen.h"
#include "mainmenuscreen.h"
#include "config.h"

int main()
{
    Config::init();
    MainMenuScreen menu;
    menu.run();
//    Game game;
//    game.run();


    return EXIT_SUCCESS;
}
