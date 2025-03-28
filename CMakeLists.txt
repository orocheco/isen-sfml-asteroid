cmake_minimum_required(VERSION 3.5...4.0)
project(IsenShooter)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

# Compilation des sources officielles SFML 3.0.0
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(IsenShooter
        src/main.cpp
        src/core/Engine.cpp
        src/core/World.cpp
        src/entities/Entity.cpp
        src/entities/SpaceShip.cpp
        src/entities/Asteroid.cpp
        src/ui/UiComponent.cpp
)

target_link_libraries(IsenShooter PRIVATE SFML::Graphics SFML::Network SFML::Audio)
target_include_directories(IsenShooter PRIVATE src)
