//
// Created by orocheco on 15/03/2025.
//
#include <iostream>

#include "Engine.h"


Engine::Engine(const sf::Vector2f size) : _size(size), _world(size) {

    _window = sf::RenderWindow(sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}), "Space Shooter <3", sf::Style::Default);
    // fixed framerate
    _window.setFramerateLimit(FRAMERATE);

    initialize();
}

Engine::~Engine() {
    std::cout << std::endl << "Game destructor" << std::endl;
}

void Engine::initialize() {
    // perform initialization here
}

void Engine::run() {
    // elapsed time since last frame
    sf::Clock clock;

    while (_window.isOpen()) {
        sf::Time elapsed = clock.restart();

        while (const std::optional<sf::Event> event = _window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                _window.close();
            }

        }

        // Handle input
        processEvents();

        // update method
        update(elapsed);

        _window.clear();
        draw();
        _window.display();
    }
}

void Engine::update(const sf::Time &elapsed) {
    // update your world
}

void Engine::draw() {
    // draw your world
}

void Engine::processEvents() {
    // power up your world with events
}
