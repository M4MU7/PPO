#include <iostream>
#include <string>
#include "CharacterFactory.h"
#include "ConcreteFactories.h"
using namespace std;

int main() {
    cout << "Dostepne typy postaci: warrior, mage, rogue, paladin" << endl;
    cout << "Podaj typ postaci: ";

    string type;
    cin >> type;

    CharacterFactory* factory = nullptr;

    if      (type == "warrior") factory = new WarriorFactory();
    else if (type == "mage")    factory = new MageFactory();
    else if (type == "rogue")   factory = new RogueFactory();
    else if (type == "paladin") factory = new PaladinFactory();
    else {
        cout << "Nieznany typ postaci: " << type << endl;
        return 1;
    }

    Character* character = factory->createCharacter();
    character->showInfo();

    delete character;
    delete factory;

    return 0;
}
