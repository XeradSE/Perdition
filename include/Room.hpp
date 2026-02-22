#pragma once

#include "Position.hpp"

class Room {

    Position gauche_sup; //position du coin supérieur gauche

    int width, height;

public:

    Position getCenter();

    bool intersects(const Room& other) const; // retourne vrai si deux salles se chevauchent, utile pour la génération

    int getWidth() const { return width; };

    int getHeight() const { return height; };
};