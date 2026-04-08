#include <iostream>
#include "Werewolf.h"

void Werewolf::show()
{
    std::cout << "The Werewolf is at point ("
              << x_ << "," << y_
              << ") and its radius is " << radius_
              << std::endl;
}

void Werewolf::attack(float factor)
{
    strength_ -= factor * strength_;   // siła spada o factor * strength
    radius_   *= 1.5f;                 // zasięg ręki rośnie 1.5x
    make_sound();
}

void Werewolf::make_sound()
{
    std::cout << "Werewolf's growl!" << std::endl;
}
