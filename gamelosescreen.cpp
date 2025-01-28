#include "gamelosescreen.h"
#include "config.h"
#include "helpers.h"

GameLoseScreen::GameLoseScreen(sf::RenderWindow &window) {
    window.setMouseCursorVisible(true);
    background = sf::Sprite(Config::backgroundTexture);

    // Menu buttons
    sorry.setFont(Config::font);
    sorry.setCharacterSize(120);
    sorry.setString("YOU SHOOT A BOMB!\nYOU LOSE THE GAME");
    sorry.setFillColor(sf::Color::Red);
    setCentered(sorry);
    sorry.setPosition(Config::window_width/2, Config::window_height * 0.25);
    sorry.scale(0.4,0.4);

    quitButton.setFont(Config::font);
    quitButton.setCharacterSize(120);
    quitButton.setString("RETURN TO MENU");
    quitButton.setFillColor(sf::Color::Green);
    setCentered(quitButton);
    quitButton.setPosition(Config::window_width/2, Config::window_height * 0.75);
    quitButton.scale(0.4,0.4);
}

void GameLoseScreen::run(sf::RenderWindow& window) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
            case sf::Event::Closed: {
                window.close();
                break;
            }
            case sf::Event::MouseButtonPressed: {
                if (containsMouse(window, quitButton)) {
                    return;
                }
            }
            }
        }

        window.clear();
        window.draw(background);

        window.draw(sorry);
        window.draw(quitButton);

        // Update the window
        window.display();
    }
}
