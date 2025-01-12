#include "mainmenu.h"
#include "game.h"
#include "config.h"
#include "helpers.h"

MainMenu::MainMenu() :
    window(sf::VideoMode(Config::window_width, Config::window_height), "Spase Invaders", sf::Style::Close | sf::Style::Resize)
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

void MainMenu::run() {
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
                if (startButton.getGlobalBounds().contains((sf::Vector2f) sf::Mouse::getPosition(window))) {
                    Game game(window);
                    game.run(window);
                    window.setMouseCursorVisible(true);
                } else if (quitButton.getGlobalBounds().contains((sf::Vector2f) sf::Mouse::getPosition(window))) {
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
