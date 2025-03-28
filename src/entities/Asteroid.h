//
// Created by orocheco on 25/03/2025.
//

#ifndef ASTEROID_H
#define ASTEROID_H
#include "Entity.h"


class Asteroid : public Entity {
private:

public:
    Asteroid(const sf::Texture* texture, World& world);
    ~Asteroid() override;

    void update(sf::Time deltaTime) override;
    void processEvents() override;
    bool isCollidingWith(const Entity &other) override;
    void onColliding(const Entity &other) override;

private:
    // destroy this asteroid
    void destroy();
};



#endif //ASTEROID_H
