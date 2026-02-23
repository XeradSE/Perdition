#include "./../include/Map.hpp"
#include <experimental/random>

void Map::placeRooms(int max_rooms, int min_size, int max_size) {

    Room first_room(std::experimental::randint(min_size, max_size), std::experimental::randint(max_size, max_size));

    salles.push_back(first_room);

    for (int i = 1; i < max_rooms; i++) {
        

        
    }

}

void Map::createCorridor(Position a, Position b) {



}

void Map::placeStairs() {



}

void Map::generate() {



}

Tile* Map::getTile(int x, int y) {
    Tile* tile = &map[x][y];
    return tile;
}