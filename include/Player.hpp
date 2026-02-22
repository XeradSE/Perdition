#pragma once

#include "Entity.hpp"
#include "Inventory.hpp"

class Player : public Entity {

    int level;
    double experience, experience_to_next_level = 100;
    Inventory inventory;

public:

    void gainExperience(int amount);

    void levelUp();

    void update(const Player& player);
};