#pragma once
#include "Equipment.h"

class LegendaryEquipment : public Equipment {
private:
    double runicPower;

public:
    LegendaryEquipment(double defense, double damage, double critChance, double runicPower);

    double getRunicPower() const;

    friend std::ostream& operator<<(std::ostream& os, const LegendaryEquipment& obj);
};