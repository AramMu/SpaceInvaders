#include "config.h"

std::string Config::basePath = "files/";
sf::Font Config::font;

const int Config::window_width = 800;
const int Config::window_height = 600;

sf::Texture Config::backgroundTexture;
sf::Texture Config::targetTexture, Config::standTexture, Config::cannonTexture, Config::aimTexture, Config::bulletTexture, Config::bombTexture, Config::clockTexture;
sf::Texture Config::target3HPTexture;
sf::Texture Config::target2HPTexture;
sf::Texture Config::target4HPTexture;

Config::GraphicsMode Config::graphicsMode = Config::GraphicsMode::NEW;

void Config::init() {
    font.loadFromFile(Config::basePath + "/fonts/arial.ttf");

    std::string base;
    if (Config::graphicsMode == Config::GraphicsMode::NEW) {
        base = Config::basePath +  + "/sprites-new/";
    } else {
        base =  Config::basePath +  + "/sprites/";
    }
    // Load textures
    backgroundTexture.loadFromFile(base + "Background.png");
    targetTexture.loadFromFile(base + "Target.png");
    standTexture.loadFromFile(base + "Stand.png");
    cannonTexture.loadFromFile(base + "Cannon.png");
    aimTexture.loadFromFile(base + "Aim.png");
    bulletTexture.loadFromFile(base + "Cannonball.png");
    bombTexture.loadFromFile(base + "Bomb.png");
    clockTexture.loadFromFile(base + "Clock.png");
    target3HPTexture.loadFromFile(base + "Target3HP.png");
    target2HPTexture.loadFromFile(base + "Target2HP.png");
    target4HPTexture.loadFromFile(base + "Target4HP.png");
//    backgroundTexture.loadFromFile(Config::basePath +  + "/sprites/Background.png");
//    targetTexture.loadFromFile(Config::basePath +  + "/sprites/Target.png");
//    standTexture.loadFromFile(Config::basePath +  + "/sprites/Stand.png");
//    cannonTexture.loadFromFile(Config::basePath +  "/sprites/Cannon.png");
//    aimTexture.loadFromFile(Config::basePath +  "/sprites/Aim.png");
//    bulletTexture.loadFromFile(Config::basePath +  "/sprites/Cannonball.png");
//    bombTexture.loadFromFile(Config::basePath + "/sprites/Bomb.png");
//    clockTexture.loadFromFile(Config::basePath + "/sprites/Clock.png");
//    target3HPTexture.loadFromFile(Config::basePath + "/sprites/Target3HP.png");
//    target2HPTexture.loadFromFile(Config::basePath + "/sprites/Target2HP.png");
//    target4HPTexture.loadFromFile(Config::basePath + "/sprites/Target4HP.png");
}


