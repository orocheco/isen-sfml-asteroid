//
// Created by orocheco on 23/03/2025.
//

#ifndef WORLD_H
#define WORLD_H


#include <vector>

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/System/Vector2.hpp"

#include "entities/Entity.h"

class World final : public sf::Drawable {
private:
    /// vecteur temporaire utilisé pour ajouter les nouvelles entités
    std::vector<Entity*> _entities_queue;
    /// notre vecteur d'entités
    std::vector<Entity*> _entities;


public:
    /// Our world
    explicit World(sf::Vector2f size);
    /// Destructor
    ~World() override;

    /// Update
    void update(sf::Time dt);
    /// process events
    void processEvents();
    void initialize();

    /// Manage our world
    void add(Entity* entity);
    /// remove entity
    void remove(const Entity * entity);

private:
    /// Render on screen
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    /// check for collision amongst entities
    void checkCollisions();
    /// add entities from our queue to our map
    void mergeEntities();

};


#endif //WORLD_H
