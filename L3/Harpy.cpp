#include <iostream>
#include "Harpy.h"

void Harpy::show()
{
    std::cout << "The Harpy is at point ("
              << x_ << "," << y_
              << ") and its height is " << height_
              << std::endl;
}

void Harpy::attack(float factor)
{
    strength_ -= factor * strength_;   // siła spada o factor * strength
    height_    = 1.85f;                // obniżenie lotu
    make_sound();
}

void Harpy::make_sound()
{
    std::cout << "Harpy's yell" << std::endl;
}
