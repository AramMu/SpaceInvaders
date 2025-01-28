#include "gamewinscreen.h"
#include "config.h"
#include "helpers.h"

GameWinScreen::GameWinScreen(sf::RenderWindow &window) {
    window.setMouseCursorVisible(true);
    background = sf::Sprite(Config::backgroundTexture);

    // Menu buttons
    congrats.setFont(Config::font);
    congrats.setCharacterSize(120);
    congrats.setString("CONGRATULATIONS!\nYOU WIN THE GAME");
    congrats.setFillColor(sf::Color::Green);
    setCentered(congrats);
    congrats.setPosition(Config::window_width/2, Config::window_height * 0.25);
    congrats.scale(0.4,0.4);

    quitButton.setFont(Config::font);
    quitButton.setCharacterSize(120);
    quitButton.setString("RETURN TO MENU");
    quitButton.setFillColor(sf::Color::Red);
    setCentered(quitButton);
    quitButton.setPosition(Config::window_width/2, Config::window_height * 0.75);
    quitButton.scale(0.4,0.4);
}

void GameWinScreen::run(sf::RenderWindow& window) {
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

        window.draw(congrats);
        window.draw(quitButton);

        // Update the window
        window.display();
    }
}


