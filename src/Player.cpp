#include "./../include/Player.hpp"

void Player::gainExperience(int amount) {

    if (experience + amount < experience_to_next_level) {
        experience += amount;
    } else {
        experience += amount - experience_to_next_level;
        levelUp();
    }

}

void Player::levelUp() {
    hp *= 1.10;
    max_hp *= 1.10;
    attack *= 1.10;
    defense *= 1.10;
    experience_to_next_level *= 1.50;
}