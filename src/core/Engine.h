//
// Created by orocheco on 15/03/2025.
//

#ifndef ENGINE_H
#define ENGINE_H


#include "SFML/Graphics/RenderWindow.hpp"
#include "World.h"


constexpr int SCREEN_WIDTH = 800u;
constexpr int SCREEN_HEIGHT = 600u;
constexpr int FRAMERATE = 60;

class Engine {
private:
    /// window size
    sf::Vector2f _size;
    /// SFML window
    sf::RenderWindow _window;
    /// World
    World _world;

public:
    Engine(sf::Vector2f size);
    ~Engine();

    /// perform initialization
    void initialize();
    /// start the game
    void run();
    /// sets the size
    void setSize(sf::Vector2f size) { _size = size; }
    /// gets the size
    sf::Vector2f getSize() const { return _size; }


private:
    /// update method
    void update(const sf::Time& elapsed);
    /// draw method
    void draw();
    /// process real-time events
    void processEvents();
};


#endif //ENGINE_H
