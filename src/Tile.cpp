#include "./../include/Tile.hpp"

bool Tile::isWalkable() const {
    switch (type) {
        case Case::WALL: return false; break;
        default: return true; break;
    }
}

char Tile::getSymbole() const {
    switch (type) {
        case Case::FLOOR: return '.'; break;
        case Case::WALL: return '#'; break;
        case Case::STAIRS_DOWN: return '>'; break;
        case Case::STAIRS_UP: return '<'; break;
    }
}