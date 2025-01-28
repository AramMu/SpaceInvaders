#include "levelwinscreen.h"
#include "config.h"
#include "helpers.h"

LevelWinScreen::LevelWinScreen(sf::RenderWindow &window) {
    window.setMouseCursorVisible(true);
    background = sf::Sprite(Config::backgroundTexture);

    // Menu buttons
    nextButton.setFont(Config::font);
    nextButton.setCharacterSize(120);
    nextButton.setString("NEXT LEVEL");
    nextButton.setFillColor(sf::Color::Green);
    setCentered(nextButton);
    nextButton.setPosition(Config::window_width/2, Config::window_height * 0.25);
    nextButton.scale(0.4,0.4);

    quitButton.setFont(Config::font);
    quitButton.setCharacterSize(120);
    quitButton.setString("RETURN TO MENU");
    quitButton.setFillColor(sf::Color::Red);
    setCentered(quitButton);
    quitButton.setPosition(Config::window_width/2, Config::window_height * 0.75);
    quitButton.scale(0.4,0.4);
}

void LevelWinScreen::run(sf::RenderWindow& window) {
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
                if (containsMouse(window, nextButton)) {
                    response = NEXT;
                    return;
                } else if (containsMouse(window, quitButton)) {
                    response = EXIT;
                    return;
                }
            }
            }
        }

        window.clear();
        window.draw(background);

        window.draw(nextButton);
        window.draw(quitButton);

        // Update the window
        window.display();
    }
}
LevelWinScreen::ResponseType LevelWinScreen::getResponse() {
    return response;
}


