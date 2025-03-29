//
// Created by orocheco on 29/03/2025.
//

#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Entity.h"


class Projectile : public Entity {

public:
    void update(sf::Time deltaTime) override;
    void processEvents() override;
    bool isCollidingWith(const Entity &other) override;
};



#endif //PROJECTILE_H
