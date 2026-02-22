#include "./../include/Room.hpp"

Position Room::getCenter() {
    Position centre;

    centre.x = (gauche_sup.x + width) / 2;
    centre.y = (gauche_sup.y + height) / 2;

    return centre;
}

bool Room::intersects(const Room& other) const {

    return (!(gauche_sup.x + width < other.gauche_sup.x || gauche_sup.x > other.gauche_sup.x + other.width || gauche_sup.y + height < other.gauche_sup.y || gauche_sup.y > other.gauche_sup.y + height));

    /*
    Deux salles ne se superposent pas si :

        La salle A est entièrement à gauche de B : a.x + a.width < b.x
        La salle A est entièrement à droite de B : a.x > b.x + b.width
        La salle A est entièrement au dessus de B : a.y + a.height < b.y
        La salle A est entièrement en dessous de B : a.y > b.y + b.height

    C'est plus simple que de vérifier l'intersection directement.
    */

}