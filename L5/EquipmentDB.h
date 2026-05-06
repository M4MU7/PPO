#pragma once
#include <vector>
#include <iostream>
#include "Equipment.h"

class EquipmentDB {
private:
    std::vector<Equipment> items;

public:
    EquipmentDB& operator+=(const Equipment& item);

    friend std::ostream& operator<<(std::ostream& os, const EquipmentDB& db);
};