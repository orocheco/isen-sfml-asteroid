//
// Created by orocheco on 23/03/2025.
//

#include "World.h"

#include <iostream>
#include <ostream>

#include "SFML/Graphics/RenderStates.hpp"
#include "SFML/Graphics/RenderTarget.hpp"


World::World(const sf::Vector2f size) {

}

World::~World() {
    std::cout << "World::~World()" << std::endl;
}

void World::initialize() {

}

void World::update(const sf::Time dt) {

    // update alive entities
    for (const auto entity: _entities) {

        if (entity->isAlive()) {
            entity->processEvents();
            entity->update(dt);
        }
    }

    // detect collisions
    checkCollisions();

    // merge new entities > entities
    mergeEntities();

    // remove dead entities from vector
    // removeDeadEntities()
}

void World::processEvents() {
    // forward events to entities
    for (const auto entity: _entities) {
        if (entity->isAlive()) {
            entity->processEvents();
        }
    }
}

void World::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // draw entities
    for (const auto entity: _entities) {
        if (entity->isAlive()) {
            target.draw(*entity, states);
        }
    }
}

// add entity to this world
void World::add(Entity *entity) {
    _entities_queue.push_back(entity);
}

// remove entity from this world
void World::remove(const Entity *entity) {
    // C++20
    std::erase(_entities, entity);
    delete entity;
}


void World::checkCollisions() {
    // detect collisions between entitites
}

void World::mergeEntities() {
    // merge _entities_queue into _entities
}