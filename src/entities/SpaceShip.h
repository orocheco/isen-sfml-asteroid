//
// Created by orocheco on 22/03/2025.
//

#ifndef SPACESHIP_H
#define SPACESHIP_H


#include "Entity.h"
#include "SFML/Graphics/Texture.hpp"


class SpaceShip : public Entity {
private:
    // spaceship speed
    float _velocity;
    // spaceship acceleration
    float _acceleration;

public:
    SpaceShip(const sf::Texture* texture, World& world);
    ~SpaceShip() override;

    /// update method
    void update(sf::Time dt) override;
    void processEvents() override;

    void move(sf::Vector2f offset);
    void rotate(float direction);
    void accelerate();
    void decelerate();

    /// shoot some lasers at enemies
    void shoot(float speed);

    float getVelocity() const { return _velocity; };
    float getAcceleration() const { return _acceleration; };

    sf::Vector2f getDirection() const;


    bool isCollidingWith(const Entity &other) override;
    void onColliding(const Entity &other) override;


private:

};



#endif //SPACESHIP_H
