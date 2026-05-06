#include "Equipment.h"

Equipment::Equipment(double defense, double damage, double critChance)
    : defense(defense), damage(damage), critChance(critChance) {
}

double Equipment::getDefense() const { return defense; }
double Equipment::getDamage() const { return damage; }
double Equipment::getCritChance() const { return critChance; }

Equipment Equipment::operator+(const Equipment& other) const {
    return Equipment(defense + other.defense, damage + other.damage, critChance + other.critChance);
}

std::ostream& operator<<(std::ostream& os, const Equipment& obj) {
    os << "Defense: " << obj.defense << ", Damage: " << obj.damage << ", CritChance: " << obj.critChance;
    return os;
}

std::istream& operator>>(std::istream& is, Equipment& obj) {
    is >> obj.defense >> obj.damage >> obj.critChance;
    return is;
}