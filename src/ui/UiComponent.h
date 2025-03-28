//
// Created by orocheco on 26/03/2025.
//

#ifndef UICOMPONENT_H
#define UICOMPONENT_H

#include <SFML/Graphics/Drawable.hpp>

#include "SFML/System/Time.hpp"

class UIComponent : public sf::Drawable {

public:
    UIComponent() = default;
    ~UIComponent() override = default;

    virtual void update(sf::Time dt) = 0;
    virtual void processEvents() = 0;

};



#endif //UICOMPONENT_H
