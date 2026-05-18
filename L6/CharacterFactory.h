#pragma once
#include "Character.h"

class CharacterFactory {
public:
    virtual Character* createCharacter() = 0;
    virtual ~CharacterFactory() {}
};
