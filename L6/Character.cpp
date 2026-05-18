#include "Character.h"

Character::Character(int hp, int strength) : hp(hp), strength(strength) {}

int Character::getHp()       const { return hp; }
int Character::getStrength() const { return strength; }
