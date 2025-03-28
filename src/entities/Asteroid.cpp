//
// Created by orocheco on 25/03/2025.
//

#include "Asteroid.h"
Asteroid::Asteroid(const sf::Texture *texture, World &world) : Entity(texture, world)
{}
Asteroid::~Asteroid() {}
void Asteroid::update(sf::Time deltaTime) {}
void Asteroid::processEvents() {}
bool Asteroid::isCollidingWith(const Entity &other) {}
void Asteroid::onColliding(const Entity &other) { Entity::onColliding(other); }
void Asteroid::destroy() {}
