#include "guidescreen.h"
#include "config.h"
#include "helpers.h"
#include "target.h"


GuideScreen::GuideScreen(sf::RenderWindow &window) {
    window.setMouseCursorVisible(true);
    background = sf::Sprite(Config::backgroundTexture);
}


void GuideScreen::run(sf::RenderWindow& window) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch(event.type) {
            case sf::Event::Closed: {
                window.close();
                return;
            }
            case sf::Event::MouseButtonPressed: {
                return;
            }
            }
        }

        window.clear();
        window.draw(background);

        // Update the window
        window.display();
    }
}


