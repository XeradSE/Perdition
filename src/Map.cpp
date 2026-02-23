#include "./../include/Map.hpp"
#include <experimental/random>
#include <vector>
#include <iostream>

void Map::placeRooms(int max_rooms, int min_size, int max_size) {

    std::uniform_int_distribution<int> pos_room_x(0, width - max_rooms); // - max_size pour ne pas dépasser les limites de la map.
    std::uniform_int_distribution<int> pos_room_y(0, height - max_rooms); // - max_size pour ne pas dépasser les limites de la map.

    Position pos_room;
    pos_room.x = pos_room_x(rng);
    pos_room.y = pos_room_y(rng);

    std::uniform_int_distribution<int> dist(min_size, max_size);
    Room first_room(pos_room, dist(rng), dist(rng));

    salles.push_back(first_room);

    bool intersect_pas;

    while (salles.size() < max_rooms) {

        intersect_pas = true;
        
        pos_room.x = pos_room_x(rng);
        pos_room.y = pos_room_y(rng);

        Room current_room(pos_room, dist(rng), dist(rng));
        
        for (int i = 0; i < salles.size(); i++) {
            if (current_room.intersects(salles[i])) {
                intersect_pas = false;
            }
        }

        if (intersect_pas) {
            createCorridor(salles.back().getCenter(), current_room.getCenter());
            salles.push_back(current_room);
        }
        
    }

}

void Map::createCorridor(Position a, Position b) {

    std::uniform_int_distribution<int> dist(0, 1);

    if (dist(rng)) { // 0 ou 1 -> True ou False
        for (int x = std::min(a.x, b.x); x <= std::max(a.x, b.x); x++) {
            map[a.y][x].setType(Case::FLOOR);
        }

        for (int y = std::min(a.y, b.y); y <= std::max(a.y, b.y); y++) {
            map[y][a.x].setType(Case::FLOOR);
        }
    } else {
        for (int x = std::min(a.x, b.x); x <= std::max(a.x, b.x); x++) {
            map[b.y][x].setType(Case::FLOOR);
        }

        for (int y = std::min(a.y, b.y); y <= std::max(a.y, b.y); y++) {
            map[y][b.x].setType(Case::FLOOR);
        }
    }

}

void Map::placeStairs(bool first_floor) {

    if (!first_floor) {
        Position center = salles[0].getCenter();
        map[center.x][center.y].setType(Case::STAIRS_UP);
    }
    
    Position center = salles.back().getCenter();
    map[center.x][center.y].setType(Case::STAIRS_DOWN);

}

void Map::generate(int max_rooms, int min_size, int max_size) {

    map.resize(height, std::vector<Tile>(width)); // initialisation du vecteur

    for (std::vector<Tile> v : map) {
        for (Tile t : v) {
            t.setType(Case::WALL);
        }
    }

    placeRooms(max_rooms, min_size, max_size);

    placeStairs(false);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << map[y][x].getSymbole();
        }
        std::cout << "\n";
    }

}

Tile* Map::getTile(int x, int y) {
    Tile* tile = &map[x][y];
    return tile;
}