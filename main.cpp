#include <iostream>
#include "game.h"
#include "mainmenu.h"
#include "config.h"

int main()
{
    Config::init();
    MainMenu menu;
    menu.run();
//    Game game;
//    game.run();


    return EXIT_SUCCESS;
}
