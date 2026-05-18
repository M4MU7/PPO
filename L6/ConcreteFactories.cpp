#include "ConcreteFactories.h"

Character* WarriorFactory::createCharacter() { return new Warrior(); }
Character* MageFactory::createCharacter()    { return new Mage();    }
Character* RogueFactory::createCharacter()   { return new Rogue();   }
Character* PaladinFactory::createCharacter() { return new Paladin(); }
