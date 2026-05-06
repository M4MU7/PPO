#include "EquipmentDB.h"

EquipmentDB& EquipmentDB::operator+=(const Equipment& item) {
    items.push_back(item);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const EquipmentDB& db) {
    for (auto it = db.items.begin(); it != db.items.end(); ++it) {
        os << *it << "\n";
    }
    return os;
}