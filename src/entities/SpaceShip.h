//
// Created by orocheco on 22/03/2025.
//

#ifndef SPACESHIP_H
#define SPACESHIP_H


#include "Entity.h"
#include "SFML/Graphics/Texture.hpp"


class SpaceShip : public Entity {
private:
    /// spaceship speed
    float _velocity;
    /// spaceship acceleration
    float _acceleration;

public:
    SpaceShip(const sf::Texture* texture, World& world);
    ~SpaceShip() override;

    /// update method
    void update(sf::Time dt) override;
    void processEvents() override;

    bool isCollidingWith(const Entity &other) override;
    void onColliding(const Entity &other) override;

    /// ---------------------------------------------------------------
    /// You can create helper methods to move your sprite:
    ///  - It's important to keep track of the ship's direction.
    ///  - Velocity and acceleration add physics to your game.
    /// For example, acceleration can accumulate over time and be used
    /// to calculate the spaceship's velocity.
    /// ---------------------------------------------------------------

    /// move towards a direction
    void move(sf::Vector2f offset);
    /// rotate this spaceship
    void rotate(float angle);
    /// shoot some lasers at enemies
    void shoot(float speed);
    /// get the direction the spaceship is moving towards
    [[nodiscard]] sf::Vector2f getDirection() const;
    /// accelerate
    void accelerate();
    /// decelerate
    void decelerate();
    /// returns the current velocity
    float getVelocity() const { return _velocity; };
    /// returns the current acceleration
    float getAcceleration() const { return _acceleration; };



private:

};



#endif //SPACESHIP_H
