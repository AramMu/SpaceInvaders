#ifndef GAME_H
#define GAME_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "target.h"

struct Parameters {
    int targets1hp;
    int targets2hp;
    int targets3hp;
    int targets4hp;
    int bombs;
    int clocks;
};

class Game
{
public:
    Game(sf::RenderWindow& window);
    void run(sf::RenderWindow& window);
    void reset();
private:
    void randomTargets(Parameters params);
    bool randomTargetsByLevel(int level);
    void randomTargetsLv1();
    void randomTargetsLv5();
//    sf::Texture backgroundTexture;

//    sf::Texture targetTexture, standTexture,cannonTexture, aimTexture, bulletTexture, bombTexture, clockTexture;
    sf::Sprite background;

    std::vector<Target> targets;
    std::vector<Target> bombs;
    std::vector<Target> clocks;

    Target stand;
    Target cannon;
    Target aim;

    std::vector<Target> bullets;

    sf::Music musicPlyer;

    sf::Text timer;
    int timeRemains;
    sf::SoundBuffer buffer;
    bool leftPressed;
    bool rightPressed;
    int currentLevel;
//    sf::RectangleShape bottomLine;
};

#endif // GAME_H
