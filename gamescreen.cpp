#include "gamescreen.h"
#include <cmath>
#include "collider.h"
#include "config.h"
#include "helpers.h"
#include "levelwinscreen.h"
#include "gamewinscreen.h"
#include "gamelosescreen.h"

std::string timeString(int seconds) {
    char buf[10];
    sprintf(buf, "%1d:%02d", seconds/60, seconds%60);
    return std::string(buf);
}

void GameScreen::randomTargets(Parameters params) {
    std::vector<sf::Vector2f> pos;
    for (int x = 100; x <= Config::window_width-100; x+=100) {
        for (int y = 100; y <= Config::window_width-400; y+= 100) {
            pos.push_back({x*1.0f, y*1.0f});
        }
    }
    for (int i = 0; i < params.targets1hp; ++i) {
        float xDir = (rand() % 10000) / 10000.0;
        float yDir = sqrt(1-xDir*xDir);
        xDir = xDir * (rand()%2 ? 1 : -1) * 0.1 * 5;
        yDir = yDir * (rand()%2 ? 1 : -1) * 0.1 * 5;
        Target target = Target::createObject(Target::TARGET);//, Config::targetTexture);
        int p = rand() % pos.size();
        target.setPosition(pos[p]);
        pos[p] = pos.back();
        pos.pop_back();
        target.setDirection({xDir, yDir});
        targets.push_back(target);
    }
    for (int i = 0; i < params.targets2hp; ++i) {
        float xDir = (rand() % 10000) / 10000.0;
        float yDir = sqrt(1-xDir*xDir);
        xDir = xDir * (rand()%2 ? 1 : -1) * 0.2 * 5;
        yDir = yDir * (rand()%2 ? 1 : -1) * 0.2 * 5;
        Target target = Target::createObject(Target::TARGET2HP);//, Config::targetTexture);
        int p = rand() % pos.size();
        target.setPosition(pos[p]);
        pos[p] = pos.back();
        pos.pop_back();
        target.setDirection({xDir, yDir});
        targets.push_back(target);
    }
    for (int i = 0; i < params.targets3hp; ++i) {
        float xDir = (rand() % 10000) / 10000.0;
        float yDir = sqrt(1-xDir*xDir);
        xDir = xDir * (rand()%2 ? 1 : -1) * 0.3 * 5;
        yDir = yDir * (rand()%2 ? 1 : -1) * 0.3 * 5;
        Target target = Target::createObject(Target::TARGET3HP);//, Config::targetTexture);
        int p = rand() % pos.size();
        target.setPosition(pos[p]);
        pos[p] = pos.back();
        pos.pop_back();
        target.setDirection({xDir, yDir});
        targets.push_back(target);
    }
    for (int i = 0; i < params.targets4hp; ++i) {
        float xDir = (rand() % 10000) / 10000.0;
        float yDir = sqrt(1-xDir*xDir);
        xDir = xDir * (rand()%2 ? 1 : -1) * 0.4 * 5;
        yDir = yDir * (rand()%2 ? 1 : -1) * 0.4 * 5;
        Target target = Target::createObject(Target::TARGET4HP);//, Config::targetTexture);
        int p = rand() % pos.size();
        target.setPosition(pos[p]);
        pos[p] = pos.back();
        pos.pop_back();
        target.setDirection({xDir, yDir});
        targets.push_back(target);
    }
    for (int i = 0; i < params.bombs; ++i) {
        float xDir = (rand() % 10000) / 10000.0;
        float yDir = sqrt(1-xDir*xDir);
        xDir = xDir * (rand()%2 ? 1 : -1) * 0.2 * 5;
        yDir = yDir * (rand()%2 ? 1 : -1) * 0.2 * 5;
        Target bomb = Target::createObject(Target::BOMB);
        int p = rand() % pos.size();
        bomb.setPosition(pos[p]);
        pos[p] = pos.back();
        pos.pop_back();
        bomb.setDirection({xDir, yDir});
        bombs.push_back(bomb);
    }
    for (int i = 0; i < params.clocks; ++i) {
        float xDir = (rand() % 10000) / 10000.0;
        float yDir = sqrt(1-xDir*xDir);
        xDir = xDir * (rand()%2 ? 1 : -1) * 0.2 * 5;
        yDir = yDir * (rand()%2 ? 1 : -1) * 0.2 * 5;
        Target clock = Target::createObject(Target::CLOCK);
        int p = rand() % pos.size();
        clock.setPosition(pos[p]);
        pos[p] = pos.back();
        pos.pop_back();
        clock.setDirection({xDir, yDir});
        clocks.push_back(clock);
    }
}
bool GameScreen::randomTargetsByLevel(int level) {
    targets.clear();
    bombs.clear();
    clocks.clear();
    bullets.clear();
    Parameters p;
    switch(level) {
    case 1: {
        p.targets1hp = 1;
        p.targets2hp = 1;
        p.targets3hp = 0;
        p.targets4hp = 0;
        p.bombs = 1;
        p.clocks = 1;
        break;
    }
    case 2: {
        p.targets1hp = 2;
        p.targets2hp = 1;
        p.targets3hp = 1;
        p.targets4hp = 1;
        p.bombs = 1;
        p.clocks = 1;
        break;
    }
    case 3: {
        p.targets1hp = 10;
        p.targets2hp = 3;
        p.targets3hp = 1;
        p.targets4hp = 1;
        p.bombs = 2;
        p.clocks = 2;
        break;
    }
    case 4: {
        p.targets1hp = 10;
        p.targets2hp = 6;
        p.targets3hp = 3;
        p.targets4hp = 2;
        p.bombs = 3;
        p.clocks = 3;
        break;
    }
    default:
        return false;
    }
    randomTargets(p);
    return true;
}


GameScreen::GameScreen(sf::RenderWindow &window)
{
    background = sf::Sprite(Config::backgroundTexture);
    musicPlyer.openFromFile(Config::basePath +  + "/audio/ufo_highpitch.wav");

    // Set cursor invisible and instead display aim sprite when in game
    window.setMouseCursorVisible(false);

    sf::Vector2u size = Config::backgroundTexture.getSize();
    float xsize = (static_cast<float>(window.getSize().x) / size.x);
    float ysize = (static_cast<float>(window.getSize().y));

    float sScale;
    if (xsize > ysize)
    {
        sScale = ysize;
    }
    else
    {
        sScale = xsize;
    }
    background.setScale(sScale, sScale);

    sf::FloatRect fRect = background.getGlobalBounds();
    int px = (window.getSize().x - fRect.width);
    int py = (window.getSize().y - fRect.height);
    background.setPosition(px, py);

    stand = Target::createObject(Target::STAND);//, Config::standTexture);
    stand.setPosition(Config::window_width/2, Config::graphicsMode == Config::GraphicsMode::NEW ?
                          Config::window_height - 38 : Config::window_height - 48);
    stand.setDirection({5,0});

    cannon = Target::createObject(Target::CANNON);//, Config::cannonTexture);
    cannon.setPosition(Config::window_width/2, Config::window_height - 118);
    cannon.setDirection({5,0});


    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    aim = Target::createObject(Target::AIM);//, Config::aimTexture);
    aim.setPosition(mousePosition.x, mousePosition.y);

    currentLevel = 1;
    randomTargetsByLevel(currentLevel);
//    Parameters lv2;
//    lv2.targets1hp = 1;
//    lv2.targets2hp = 1;
//    lv2.targets3hp = 1;
//    lv2.targets4hp = 1;
//    lv2.bombs = 1;
//    lv2.clocks = 1;
//    randomTargets(lv2);


    timer.setFont(Config::font);

    timeRemains = 20;
    timer.setString(timeString(timeRemains));
    timer.setCharacterSize(40); // In pixels, not points
    timer.setFillColor(sf::Color::Magenta);
    timer.setPosition(Config::window_width-124, 60);

    leftPressed = false;
    rightPressed = false;
    timer.setStyle(sf::Text::Bold);
}

void GameScreen::run(sf::RenderWindow& window) {
    int tick = 0;

    while (window.isOpen())
    {
        // Change game state (for example doing animations and moving objects)
        tick++;
        if (tick == 60) {
            tick = 0;
            timeRemains--;
            timer.setString(timeString(timeRemains));
        }
        if (timeRemains <= 0) {
            return;
        }
//        sf::Vector2f cannonPos = cannon.getOrigin();
//        sf::Vector2i mousePosition = sf:: Mouse::getPosition(window);
//        float mouseAngle = -atan2(mousePosition.x - cannonPos.x , mousePosition.y - cannonPos.y) * 180 / 3.14159;
//        cannon.setRotation(mouseAngle + 180);

        for (int i = 0; i < targets.size(); ++i) {
            targets[i].moveStep();
            Collider::wallCollision(targets[i]);
        }
        for (int i = 0; i < bombs.size(); ++i) {
            bombs[i].moveStep();
            Collider::wallCollision(bombs[i]);
        }
        for (int i = 0; i < clocks.size(); ++i) {
            clocks[i].moveStep();
            Collider::wallCollision(clocks[i]);
        }

        for (int i = 0; i < bullets.size(); ++i) {
            bullets[i].moveStep();
            sf::Vector2u size = window.getSize();
            sf::FloatRect rect({0,0}, {float(size.x), float(size.y)});
            if (!rect.intersects(bullets[i].getGlobalBounds())) {
                bullets[i] = bullets.back();
                bullets.pop_back();
                i--;
            }
        }


        // Checking collisions
        for (int i = 0; i < bombs.size(); ++i) {
            for (int j = 0; j < bullets.size(); ++j) {
                if (Collider::checkCollision(bombs[i], bullets[j])) {
                    GameLoseScreen scr(window);
                    scr.run(window);
                    return;
                }
            }
        }
        for (int j = 0; j < bullets.size(); ++j) {
            for (int i = 0; i < targets.size(); ++i) {
                if (Collider::checkCollision(targets[i], bullets[j])) {
                    bullets[j] = bullets.back();
                    bullets.pop_back();
                    targets[i].hit();
                    if (targets[i].isDead()) {
                        targets[i] = targets.back();
                        targets.pop_back();
                    }
                    break;
                }
            }
        }
        for (int j = 0; j < bullets.size(); ++j) {
            for (int i = 0; i < clocks.size(); ++i) {
                if (Collider::checkCollision(clocks[i], bullets[j])) {
                    bullets[j] = bullets.back();
                    bullets.pop_back();

                    clocks[i] = clocks.back();
                    clocks.pop_back();
                    timeRemains += 3;
                    timer.setString(timeString(timeRemains));
                    break;
                }
            }
        }
        if (targets.empty()) {
            if (currentLevel >= totalLevels) {
                GameWinScreen scr(window);
                scr.run(window);
                return;
            }
            LevelWinScreen scr(window);
            scr.run(window);
            currentLevel++;
            if (scr.getResponse() == LevelWinScreen::EXIT) {
                return;
            } else {
                if (!randomTargetsByLevel(currentLevel)) {
                    return;
                }
                reset();
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                aim.setPosition(mousePosition.x, mousePosition.y);
                window.setMouseCursorVisible(false);
                timeRemains = 20;
                timer.setString(timeString(timeRemains));
            }
        }

        std::vector<Target*> allTargets;
        for (int i = 0; i < targets.size(); ++i) {
            allTargets.push_back(&targets[i]);
        }
        for (int i = 0; i < bombs.size(); ++i) {
            allTargets.push_back(&bombs[i]);
        }
        for (int i = 0; i < clocks.size(); ++i) {
            allTargets.push_back(&clocks[i]);
        }
        std::vector<bool> toReverse(allTargets.size(), false);
        for (int i = 0; i < allTargets.size(); ++i) {
            for (int j = i+1; j < allTargets.size(); ++j) {
                if (Collider::checkCollision(*allTargets[i], *allTargets[j])) {
                    toReverse[i] = true;
                    toReverse[j] = true;
                }
            }
        }
        for (int i = 0; i < toReverse.size(); ++i) {
            if (toReverse[i]) {
                allTargets[i]->reverseDirection();
            }
        }


        if (leftPressed) {
            if (cannon.getGlobalBounds().left > 0) {
                stand.moveStepReverse();
                cannon.moveStepReverse();
            }
        }
        if (rightPressed) {
            if (cannon.getGlobalBounds().left + cannon.getGlobalBounds().width < Config::window_width) {
                stand.moveStep();
                cannon.moveStep();
            }

        }

        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
            case sf::Event::Closed: {
                window.close();
                break;
            }
            case sf::Event::KeyReleased : {
                if(event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A){
                    leftPressed = false;
                } else if(event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D){
                    rightPressed = false;
                }
                break;
            }
            case sf::Event::KeyPressed :{
                if(event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A){
                    leftPressed = true;
                } else if(event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D){
                    rightPressed = true;
                }
                break;
            }

            case sf::Event::MouseMoved : {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                aim.setPosition(mousePosition.x, mousePosition.y);
                break;
            }
            case sf::Event::MouseButtonPressed :{
                musicPlyer.setLoop(false);
                musicPlyer.setPlayingOffset(sf::seconds(0));
                musicPlyer.setVolume(50);
                musicPlyer.play();

                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f cannonPos = cannon.getPosition();
                sf::Vector2f ballDirection = {mousePos.x - cannonPos.x, mousePos.y - (cannonPos.y - 70)};
                float len = sqrt(ballDirection.x * ballDirection.x + ballDirection.y * ballDirection.y);
                ballDirection = ballDirection / len * 10.0f;
                Target bullet = Target::createObject(Target::BULLET);//, Config::bulletTexture);
                bullet.setDirection(ballDirection);
                bullet.setPosition({cannonPos.x, cannonPos.y-70});
                bullets.push_back(bullet);
                break;
            }

            }
        }

        // Render screen

        // Clear screen
        window.clear();

        // Draw background
        window.draw(background);

        // Draw the sprites
        for (int i = 0; i < clocks.size(); ++i) {
            window.draw(clocks[i]);
        }
        for (int i = 0; i < targets.size(); ++i) {
            window.draw(targets[i]);
        }
        for (int i = 0; i < bombs.size(); ++i) {
            window.draw(bombs[i]);
        }

        window.draw(stand);
        window.draw(cannon);

        for (int i = 0; i < bullets.size(); ++i) {
            window.draw(bullets[i]);
        }

        window.draw(timer);
        window.draw(aim);

        // Update the window
        window.display();
    }
}
void GameScreen::reset() {
    leftPressed = false;
    rightPressed = false;
}
