//
// Created by orocheco on 22/03/2025.
//

#include "SpaceShip.h"
SpaceShip::SpaceShip(const sf::Texture *texture, World &world) : Entity(texture, world){}
SpaceShip::~SpaceShip() {}
void SpaceShip::update(sf::Time dt) {}
void SpaceShip::processEvents() {}
void SpaceShip::move(sf::Vector2f offset) {}
void SpaceShip::rotate(float direction) {}
void SpaceShip::accelerate() {}
void SpaceShip::decelerate() {}
void SpaceShip::shoot(float speed) {}
sf::Vector2f SpaceShip::getDirection() const {}
bool SpaceShip::isCollidingWith(const Entity &other) {}
void SpaceShip::onColliding(const Entity &other) { Entity::onColliding(other); }
