#pragma once
#include <string>

class Character {
private:
    int hp;
    int strength;

public:
    Character(int hp, int strength);
    virtual ~Character() {}

    int getHp()       const;
    int getStrength() const;

    virtual void showInfo() const = 0;
};
