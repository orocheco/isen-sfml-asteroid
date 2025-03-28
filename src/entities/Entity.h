//
// Created by orocheco on 15/03/2025.
//

#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/System/Time.hpp"

#include <string>

class World;

class Entity : public sf::Drawable {
protected:
    /// World reference (Singleton could be used instead)
    World& _world;
    /// Each entity owns a sprite
    sf::Sprite* _sprite = nullptr;
    /// mark entity as alive
    bool _alive { true };


public:

    Entity(const sf::Texture* texture, World& world);
    ~Entity() override = default;

    /// update over time
    virtual void update(sf::Time deltaTime) = 0;
    /// process real time events
    virtual void processEvents() = 0;
    /// tells whether this entity shall be destroyed or not
    [[nodiscard]] virtual bool isAlive() const { return _alive; }
    /// sets the position of this entity
    virtual void setPosition(const sf::Vector2f &pos);
    /// gets the position of this entity
    [[nodiscard]] virtual sf::Vector2f getPosition() const;
    /// sets the rotation of this entity
    virtual void setRotation (const sf::Angle &rot);
    /// gets the rotation of this entity
    [[nodiscard]] virtual sf::Angle getRotation() const;
    /// gets this entity global bounds (relative to the window)
    [[nodiscard]] virtual sf::FloatRect getGlobalBounds() const;
    /// check if this entity collides with other entity
    virtual bool isCollidingWith(const Entity &other) = 0;
    /// callback when collision with other entity is detected
    virtual void onColliding(const Entity &other);


private:
    /// inherited from sf::Drawable
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif //ENTITY_H
