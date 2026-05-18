#pragma once
#include "Character.h"

class Warrior : public Character {
public:
    Warrior();
    void showInfo() const override;
};

class Mage : public Character {
public:
    Mage();
    void showInfo() const override;
};

class Rogue : public Character {
public:
    Rogue();
    void showInfo() const override;
};

class Paladin : public Character {
public:
    Paladin();
    void showInfo() const override;
};
