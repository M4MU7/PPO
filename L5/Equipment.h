#pragma once
#include <iostream>

class Equipment {
private:
    double defense;
    double damage;
    double critChance;

public:
    Equipment(double defense = 0, double damage = 0, double critChance = 0);

    double getDefense() const;
    double getDamage() const;
    double getCritChance() const;

    Equipment operator+(const Equipment& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Equipment& obj);
    friend std::istream& operator>>(std::istream& is, Equipment& obj);
};
