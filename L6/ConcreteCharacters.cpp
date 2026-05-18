#include "ConcreteCharacters.h"
#include <iostream>
using namespace std;

// --- Warrior ---
Warrior::Warrior() : Character(150, 90) {}

void Warrior::showInfo() const {
    cout << "=== WOJOWNIK ===" << endl;
    cout << "Zakuty w ciężką zbroję mistrz walki wręcz – nikt nie przetrwa"
            " jego uderzenia toporem." << endl;
    cout << "Punkty życia : " << getHp()      << endl;
    cout << "Sila         : " << getStrength() << endl;
}

// --- Mage ---
Mage::Mage() : Character(80, 120) {}

void Mage::showInfo() const {
    cout << "=== MAG ===" << endl;
    cout << "Władca żywiołów, który jednym zaklęciem potrafi obrócić"
            " w pył całe oddziały wrogów." << endl;
    cout << "Punkty życia : " << getHp()      << endl;
    cout << "Sila         : " << getStrength() << endl;
}

// --- Rogue ---
Rogue::Rogue() : Character(100, 75) {}

void Rogue::showInfo() const {
    cout << "=== ŁOTRZYK ===" << endl;
    cout << "Niewidzialny jak cień, śmiertelny jak trucizna – uderza,"
            " zanim przeciwnik zdąży mrugnąć." << endl;
    cout << "Punkty życia : " << getHp()      << endl;
    cout << "Sila         : " << getStrength() << endl;
}

// --- Paladin ---
Paladin::Paladin() : Character(130, 85) {}

void Paladin::showInfo() const {
    cout << "=== PALADYN ===" << endl;
    cout << "Obrońca słabych i miecz sprawiedliwości – łączy świętą moc"
            " uzdrawiania z potęgą boskiego gniewu." << endl;
    cout << "Punkty życia : " << getHp()      << endl;
    cout << "Sila         : " << getStrength() << endl;
}
