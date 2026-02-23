#pragma once

#include <vector>
#include "Tile.hpp"
#include "Room.hpp"
#include "Position.hpp"

class Map {

    std::vector<std::vector<Tile>> map;

    int height, width;

    std::vector<Room> salles;

    void placeRooms(int max_rooms, int min_size, int max_size);

    void createCorridor(Position a, Position b); // couloir en L

    void placeStairs();

public:

    void generate(); // toute la génération

    Tile* getTile(int x, int y); // retourne une référence vers une Tile

    bool isWalkable(int x, int y) { return getTile(x, y)->isWalkable(); };

    std::vector<Room> getRooms() const { return salles; };

};