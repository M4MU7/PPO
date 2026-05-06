#include <iostream>
#include "Equipment.h"
#include "EquipmentDB.h"
#include "LegendaryEquipment.h"

int main() {
    // === 3.0 ===
    Equipment e1(10.0, 5.0, 0.15);
    Equipment e2(8.0, 7.0, 0.20);

    std::cout << "e1: " << e1 << "\n";
    std::cout << "e2: " << e2 << "\n";

    Equipment e3 = e1 + e2;
    std::cout << "e1 + e2: " << e3 << "\n";

    Equipment e4;
    std::cout << "Podaj defense, damage, critChance: ";
    std::cin >> e4;
    std::cout << "Wczytano: " << e4 << "\n";

    // === 4.0 ===
    EquipmentDB db;
    db += e1;
    db += e2;
    std::cout << "\nZawartosc bazy:\n" << db;

    // === 5.0 ===
    LegendaryEquipment leg(20.0, 15.0, 0.35, 100.0);
    std::cout << "\nLegendary: " << leg << "\n";

    // upcasting do wskaznika klasy bazowej
    Equipment* basePtr = static_cast<Equipment*>(&leg);
    std::cout << "Po upcastingu (przez wskaznik): " << *basePtr << "\n";

    // konwersja do obiektu bazowego (slicing)
    Equipment sliced = static_cast<Equipment>(leg);
    std::cout << "\nOryginalny legendary: " << leg << "\n";
    std::cout << "Po slicingu (obiekt bazowy): " << sliced << "\n";

    return 0;
}