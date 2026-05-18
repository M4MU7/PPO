#pragma once
#include "CharacterFactory.h"
#include "ConcreteCharacters.h"

class WarriorFactory : public CharacterFactory {
public:
    Character* createCharacter() override;
};

class MageFactory : public CharacterFactory {
public:
    Character* createCharacter() override;
};

class RogueFactory : public CharacterFactory {
public:
    Character* createCharacter() override;
};

class PaladinFactory : public CharacterFactory {
public:
    Character* createCharacter() override;
};
