#include "target.h"
#include "helpers.h"
#include "config.h"

Target::Target() :
    direction(0,0),
    healthPoints(1)
{}
Target::Target(const sf::Texture &texture) :
    sf::Sprite(texture),
    direction(0,0),
    healthPoints(1)
{
    setCentered(*this);
}
void Target::setTextureCentered(const sf::Texture& texture) {
    this->setTexture(texture);
    setCentered(*this);
}

Target Target::createObject(ObjectType type) {//}, const sf::Texture& texture) {
    Target target;// = Target(texture);
    target.setHP(1);
    if (Config::graphicsMode == Config::GraphicsMode::NEW) {
        switch(type) {
        case AIM:
            target.setTextureCentered(Config::aimTexture);
            target.setScale(0.075, 0.075);
            break;
        case TARGET:
            target.setTextureCentered(Config::targetTexture);
            target.setScale(0.075, 0.075);
            break;
        case TARGET2HP:
            target.setTextureCentered(Config::target2HPTexture);
            target.setScale(0.10, 0.10);
            target.setHP(2);
            break;
        case TARGET3HP:
            target.setTextureCentered(Config::target3HPTexture);
            target.setScale(0.125, 0.125);
            target.setHP(3);
            break;
        case TARGET4HP:
            target.setTextureCentered(Config::target4HPTexture);
            target.setScale(0.15, 0.15);
            target.setHP(4);
            break;
        case CLOCK:
            target.setTextureCentered(Config::clockTexture);
            target.setScale(0.1,0.1);
            break;
        case BOMB:
            target.setTextureCentered(Config::bombTexture);
            target.setScale(0.1,0.1);
            break;
        case CANNON:
            target.setTextureCentered(Config::cannonTexture);
            target.setScale(0.1,0.1);
            break;
        case STAND:
            target.setTextureCentered(Config::standTexture);
            target.setScale(0.1,0.1);
            break;
        case BULLET:
            target.setTextureCentered(Config::bulletTexture);
            target.setScale(0.08,0.08);
            break;
        }
    } else {
        switch(type) {
        case AIM:
            target.setTextureCentered(Config::aimTexture);
            target.setScale(0.5, 0.5);
            break;
        case TARGET:
            target.setTextureCentered(Config::targetTexture);
            target.setScale(0.2, 0.2);
            break;
        case TARGET2HP:
            target.setTextureCentered(Config::target2HPTexture);
            target.setScale(0.3, 0.3);
            target.setHP(2);
            break;
        case TARGET3HP:
            target.setTextureCentered(Config::target3HPTexture);
            target.setScale(0.4, 0.4);
            target.setHP(3);
            break;
        case TARGET4HP:
            target.setTextureCentered(Config::target4HPTexture);
            target.setScale(0.5, 0.5);
            target.setHP(4);
            break;
        case CLOCK:
            target.setTextureCentered(Config::clockTexture);
            target.setScale(0.5, 0.5);
            break;
        case BOMB:
            target.setTextureCentered(Config::bombTexture);
            target.setScale(0.3, 0.3);
            break;
        case CANNON:
            target.setTextureCentered(Config::cannonTexture);
            target.setScale(0.2, 0.2);
            break;
        case STAND:
            target.setTextureCentered(Config::standTexture);
            target.setScale(0.2, 0.2);
            break;
        case BULLET:
            target.setTextureCentered(Config::bulletTexture);
            target.setScale(0.2, 0.2);
            break;
        }
    }
    //    setCentered(target);
    return target;
}

void Target::setDirection(sf::Vector2f direction) {
    this->direction = direction;
}

void Target::setDirectionX(float x) {
    this->direction.x = x;
}
void Target::setDirectionY(float y) {
    this->direction.y = y;
}

sf::Vector2f Target::getDirection() {
    return this->direction;
}
float Target::getDirectionX() {
    return this->direction.x;
}
float Target::getDirectionY() {
    return this->direction.y;
}

void Target::moveStep() {
    move(direction);
}
void Target::moveStepReverse() {
    move(-direction);
}


void Target::setHP(int hp) {
    healthPoints = hp;
}
void Target::hit() {
    healthPoints--;
    if (Config::graphicsMode == Config::GraphicsMode::NEW) {
        if (healthPoints == 3) {
            this->setTexture(Config::target3HPTexture);
            this->setScale(0.125, 0.125);
        } else if (healthPoints == 2) {
            this->setTexture(Config::target2HPTexture);
            this->setScale(0.10, 0.10);
        } else if (healthPoints == 1) {
            this->setTexture(Config::targetTexture);
            this->setScale(0.075, 0.075);
        }
    } else {
        if (healthPoints == 3) {
            this->setTexture(Config::target3HPTexture);
            this->setScale(0.4, 0.4);
        } else if (healthPoints == 2) {
            this->setTexture(Config::target2HPTexture);
            this->setScale(0.3, 0.3);
        } else if (healthPoints == 1) {
            this->setTexture(Config::targetTexture);
            this->setScale(0.2, 0.2);
        }
    }
}
bool Target::isDead() {
    return healthPoints <= 0;
}
void Target::randomizeDirection() {
    float speed = sqrt(sqr(direction.x) + sqr(direction.y));
    float xDir = (rand() % 10000) / 10000.0;
    float yDir = sqrt(1-xDir*xDir);
    xDir = xDir * (rand()%2 ? 1 : -1);
    yDir = yDir * (rand()%2 ? 1 : -1);
    direction.x = xDir*speed;
    direction.y = yDir*speed;

}

void Target::reverseDirection() {
    direction = -direction;
}
