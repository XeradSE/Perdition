#pragma once

enum class Case { WALL, FLOOR, STAIRS_DOWN, STAIRS_UP };

class Tile {

    Case type;
    bool visible;
    bool explored; //pour le "fog of war"

public:

    Case getType() const {return type;};
    void setType(Case type) {this->type = type;};

    bool isVisible() const {return visible;};
    void setVisible(bool status) {visible = status;};

    bool isExplored() const {return explored;};
    void setExplored(bool status) {explored = status;};

    bool isWalkable() const;

    char getSymbole() const;

};