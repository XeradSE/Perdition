#pragma once

#include <random>
#include <vector>
#include "Tile.hpp"
#include "Room.hpp"
#include "Position.hpp"

class Map {

    std::vector<std::vector<Tile>> map;

    int height, width;

    std::vector<Room> salles;

    std::mt19937 rng{std::random_device{}()}; // pour pouvoir l'utiliser partout dans la classe

    void placeRooms(int max_rooms, int min_size, int max_size);

    void createCorridor(Position a, Position b); // couloir en L

    void placeStairs(bool first_floor);

public:

    Map (int w, int h) { height = h; width = w; };

    void generate(int max_rooms, int min_size, int max_size); // toute la génération

    Tile* getTile(int x, int y); // retourne une référence vers une Tile

    bool isWalkable(int x, int y) { return getTile(x, y)->isWalkable(); };

    std::vector<Room> getRooms() const { return salles; };

};