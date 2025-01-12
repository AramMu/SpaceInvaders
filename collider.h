#ifndef COLLIDER_H
#define COLLIDER_H
#include "target.h"

class Collider {
public:
    Collider();
//    static bool checkCollision(const Target& t, const Bullet& b);
    static bool checkCollision(const Target& t1, const Target& t2);
    static void wallCollision(Target& t);
};

#endif // COLLIDER_H
