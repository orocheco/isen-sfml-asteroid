//
// Created by orocheco on 15/03/2025.
//

#include "AssetsManager.h"

#include <iostream>

#include "SFML/Audio/SoundBuffer.hpp"

AssetsManager::~AssetsManager() {
    std::cout << "AssetsManager::~AssetsManager()" << std::endl;
}

std::shared_ptr<AssetsManager> AssetsManager::getInstance() {
    // static instance
    static std::shared_ptr<AssetsManager> instance(new AssetsManager());
    return instance;
}

void AssetsManager::addFont(const std::string &name, const std::string &path) {
    try {
        // contains: C++20 feature
        if (!_fonts.contains(name)) {
            _fonts[name] = std::make_shared<sf::Font>(path);
            std::cout << "Loaded font " << name << std::endl;
        }
        else {
            std::cout << "Font already loaded " << name << std::endl;
        }

    } catch (std::exception &e) {
        std::cout << "Could not load font: " << path << " >> " << e.what() << std::endl;
    }
}

void AssetsManager::addTexture(const std::string &name, const std::string &path, bool smooth) {
    try {
        if (!_textures.contains(name)) {
            _textures[name] = std::make_shared<sf::Texture>(path);
            _textures[name]->setSmooth(smooth);

            std::cout << "Loaded texture " << name << std::endl;
        }
        else {
            std::cout << "Texture already loaded " << name << std::endl;
        }

    } catch (std::exception &e) {
        std::cout << "Could not load texture: " << path << " >> " << e.what() << std::endl;
    }
}

std::shared_ptr<sf::Font> AssetsManager::getFont(const std::string &name) {
    if (_fonts.contains(name)) {
        return _fonts[name];
    }
    return nullptr;
}

std::shared_ptr<sf::Texture> AssetsManager::getTexture(const std::string &name) {
    if (_textures.contains(name)) {
        return _textures[name];
    }
    return nullptr;
}
void AssetsManager::addSound(const std::string &name, const std::string &path) {
    try {
        if (_sounds.find(name) == _sounds.end()) {
            // smart pointer will be released
            _soundBuffers[name] = std::make_shared<sf::SoundBuffer>();

            if (!_soundBuffers[name]->loadFromFile(path)) {
                throw std::runtime_error("Failed to load sound file: " + path);
            }

            _sounds[name] = std::make_shared<sf::Sound>(*_soundBuffers[name]);
            _sounds[name]->setVolume(100);
            // _sounds[name]->setLooping(true);

            std::cout << "Loaded sound " << name << std::endl;
        } else {
            std::cout << "Sound already loaded " << name << std::endl;
        }

    } catch (std::exception &e) {
        std::cout << "Could not load sound: " << path << " >> " << e.what() << std::endl;
    }
}

std::shared_ptr<sf::Sound> AssetsManager::getSound(const std::string &name) {
    if (_sounds.contains(name)) {
        return _sounds[name];
    }
    return nullptr;
}

void AssetsManager::addMusic(const std::string &name, const std::string &path) {
    try {
        if (_musics.find(name) == _musics.end()) {
            // smart pointer will be released
            _musics[name] = std::make_shared<sf::Music>();

            if (!_musics[name]->openFromFile(path)) {
                throw std::runtime_error("Failed to load music file: " + path);
            }

            _musics[name]->setVolume(100);

            std::cout << "Loaded music " << name << std::endl;
        }
        else {
            std::cout << "Music already loaded " << name << std::endl;
        }

    } catch (std::exception &e) {
        std::cout << "Could not load music: " << path << " >> " << e.what() << std::endl;
    }
}

std::shared_ptr<sf::Music> AssetsManager::getMusic(const std::string &name) {
    if (_musics.contains(name)) {
        return _musics[name];
    }
    return nullptr;
}


AssetsManager::AssetsManager() {
    std::cout << "AssetsManager::AssetsManager()" << std::endl;
}

