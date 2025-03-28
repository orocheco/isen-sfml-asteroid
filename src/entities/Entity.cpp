//
// Created by orocheco on 15/03/2025.
//

#include "Entity.h"


#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"

Entity::Entity(const sf::Texture* texture, World &world) : _world(world) {
    // construire son sprite
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*_sprite, states);
}

void Entity::setPosition(const sf::Vector2f &pos) {
    _sprite->setPosition(pos);
}

sf::Vector2f Entity::getPosition() const {
    return _sprite->getPosition();
}


void Entity::setRotation(const sf::Angle &rot) {
    _sprite->setRotation(rot);
}

sf::Angle Entity::getRotation() const {
    return _sprite->getRotation();
}

sf::FloatRect Entity::getGlobalBounds() const {
    return _sprite->getGlobalBounds();
}

void Entity::onColliding(const Entity &other) {}

