#pragma once

#include "Entity.hpp"

class Enemy : public Entity {

protected:

    double experience_drop;

    int detection_range, speed = 1;

public:

    virtual void update(const Player& player); // virtuel mais implémenté, les sous-classes pourront la surcharger

    double getExperienceDrop() const { return experience_drop; };

};