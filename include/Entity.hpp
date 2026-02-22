#pragma once

#include "Position.hpp"
#include <string>

class Player; //forward declaration -> dit au compilateur "cette classe existe" sans avoir besoin de connaître sa définition complète (sinon dépendance circulaire)

class Entity {

protected: //les classes qui hérite d'Entity auront besoin des attributs

    Position pos;
    double hp, max_hp, attack, defense;
    char skin; //le ASCII qui représente l'entité
    std::string name;

public:

    /*
    CONSTRUCTEURS / DESTRUCTEURS
    */

    virtual ~Entity(); // destructeur virtuel pour l'héritage

    /*
    MÉTHODES
    */

    bool isAlive() const {return hp > 0;};

    void takeDamage(int amount);

    void move(int pos_x, int pos_y);

    virtual void update(const Player& player) = 0; // méthode virtuel pure (= 0 remplace l'implémentation par défaut) -> Entity est une classe abstraite.

    /*
    ACCESSEURS
    */

    int getX() const { return pos.x; }
    int getY() const { return pos.y; }

    double getHp() const { return hp; }
    void setHp(double val) { hp = val; }

    double getMaxHp() const { return max_hp; }
    
    double getAttack() const { return attack; }
    double getDefense() const { return defense; }

    char getSkin() const { return skin; }
    std::string getName() const { return name; }

};