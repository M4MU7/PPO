#include <iostream>
#include <string>
using namespace std;

class Character {
private:
    int hp;
    int strength;
public:
    Character(int hp, int strength) : hp(hp), strength(strength) {}
    virtual ~Character() {}
    int getHp() const { return hp; }
    int getStrength() const { return strength; }
    virtual void showInfo() const = 0;
};

class Warrior : public Character {
public:
    Warrior() : Character(150, 90) {}
    void showInfo() const override {
        cout << "Wojownik - zakuty w zbroje mistrz walki wrec." << endl;
        cout << "HP: " << getHp() << ", Sila: " << getStrength() << endl;
    }
};

class Mage : public Character {
public:
    Mage() : Character(80, 120) {}
    void showInfo() const override {
        cout << "Mag - wladca zywiolow niszczacy wrogow zaklęciami." << endl;
        cout << "HP: " << getHp() << ", Sila: " << getStrength() << endl;
    }
};

class Rogue : public Character {
public:
    Rogue() : Character(100, 75) {}
    void showInfo() const override {
        cout << "Lotrzyk - uderza z cienia zanim wrog zdazy zareagowac." << endl;
        cout << "HP: " << getHp() << ", Sila: " << getStrength() << endl;
    }
};

class Paladin : public Character {
public:
    Paladin() : Character(130, 85) {}
    void showInfo() const override {
        cout << "Paladyn - lacze swiety zbroje z moca uzdrawiania." << endl;
        cout << "HP: " << getHp() << ", Sila: " << getStrength() << endl;
    }
};

class CharacterFactory {
public:
    virtual Character* createCharacter() = 0;
    virtual ~CharacterFactory() {}
};

class WarriorFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Warrior(); }
};

class MageFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Mage(); }
};

class RogueFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Rogue(); }
};

class PaladinFactory : public CharacterFactory {
public:
    Character* createCharacter() override { return new Paladin(); }
};

int main() {
    cout << "Podaj typ postaci (warrior, mage, rogue, paladin): ";
    string type;
    cin >> type;

    CharacterFactory* factory = nullptr;

    if      (type == "warrior") factory = new WarriorFactory();
    else if (type == "mage")    factory = new MageFactory();
    else if (type == "rogue")   factory = new RogueFactory();
    else if (type == "paladin") factory = new PaladinFactory();
    else {
        cout << "Nieznany typ postaci." << endl;
        return 1;
    }

    Character* character = factory->createCharacter();
    character->showInfo();

    delete character;
    delete factory;
    return 0;
}