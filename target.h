#ifndef TARGET_H
#define TARGET_H
//#include <SFML/Graphics.hpp>
#include "entity.h"

class Target : public sf::Sprite
{
public:
    enum ObjectType {
        AIM,
        TARGET, TARGET2HP, TARGET3HP, TARGET4HP,
        CLOCK, BOMB,
        CANNON, STAND, BULLET
    };
    static Target createObject(ObjectType type);
    Target();
    Target(const sf::Texture& texture);
    void setDirection(sf::Vector2f direction);
    void setDirectionX(float x);
    void setDirectionY(float y);

    sf::Vector2f getDirection();
    float getDirectionX();
    float getDirectionY();

    void moveStep();
    void moveStepReverse();
    void setHP(int hp);
    void hit();
    bool isDead();

    void reverseDirection();
    void randomizeDirection();
    void setTextureCentered(const sf::Texture& texture);
private:
    sf::Vector2f direction;
    int healthPoints;
};

#endif // TARGET_H
