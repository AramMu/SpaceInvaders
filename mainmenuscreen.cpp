#include "mainmenuscreen.h"
#include "gamescreen.h"
#include "config.h"
#include "helpers.h"
#include "guidescreen.h"

MainMenuScreen::MainMenuScreen() :
    window(sf::VideoMode(Config::window_width, Config::window_height), "Space Invaders", sf::Style::Titlebar | sf::Style::Close)
{
    //    window.setVerticalSyncEnabled(true);
        window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);
    window.setMouseCursorVisible(true);

    background = sf::Sprite(Config::backgroundTexture);

    // Menu buttons
    startButton.setFont(Config::font);
    startButton.setCharacterSize(120);
    startButton.setString("START");
    startButton.setFillColor(sf::Color::Green);
    setCentered(startButton);
    startButton.setPosition(Config::window_width/2, Config::window_height * 0.25);
    startButton.scale(0.4,0.4);

    quitButton.setFont(Config::font);
    quitButton.setCharacterSize(120);
    quitButton.setString("QUIT");
    quitButton.setFillColor(sf::Color::Red);
    setCentered(quitButton);
    quitButton.setPosition(Config::window_width/2, Config::window_height * 0.75);
    quitButton.scale(0.4,0.4);
}

void MainMenuScreen::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
            case sf::Event::Closed: {
                window.close();
                return;
            }
            case sf::Event::MouseButtonPressed: {
                if (containsMouse(window, startButton)) {
                    GuideScreen guide(window);
                    guide.run(window);
                    GameScreen game(window);
                    game.run(window);
                    window.setMouseCursorVisible(true);
                } else if (containsMouse(window, quitButton)) {
                    window.close();
                    return;
                }
            }
            }
        }
        window.clear();
        window.draw(background);
        window.draw(startButton);
        window.draw(quitButton);

        // Update the window
        window.display();
    }
}
