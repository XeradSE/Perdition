#include "./../include/Entity.hpp"

void Entity::takeDamage(int amount) {   
    if (hp - amount > 0) { hp -= amount; }
    else { hp = 0; }
}

void Entity::move(int pos_x, int pos_y) {
    pos.x = pos_x;
    pos.y = pos_y;
}