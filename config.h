#ifndef CONFIG_H
#define CONFIG_H
#include <string>
#include <SFML/Graphics.hpp>

class Config
{
public:
    static std::string basePath;
    static void init();
    static sf::Font font;
    static const int window_width;
    static const int window_height;

    static sf::Texture backgroundTexture;
    static sf::Texture targetTexture;
    static sf::Texture target2HPTexture;
    static sf::Texture target3HPTexture;
    static sf::Texture target4HPTexture;
    static sf::Texture standTexture;
    static sf::Texture cannonTexture;
    static sf::Texture aimTexture;
    static sf::Texture bulletTexture;
    static sf::Texture bombTexture;
    static sf::Texture clockTexture;

    enum GraphicsMode {
        OLD, NEW
    } static graphicsMode;
};

#endif // CONFIG_H
