#include "LegendaryEquipment.h"

LegendaryEquipment::LegendaryEquipment(double defense, double damage, double critChance, double runicPower)
    : Equipment(defense, damage, critChance), runicPower(runicPower) {
}

double LegendaryEquipment::getRunicPower() const { return runicPower; }

std::ostream& operator<<(std::ostream& os, const LegendaryEquipment& obj) {
    os << static_cast<const Equipment&>(obj) << ", RunicPower: " << obj.runicPower;
    return os;
}