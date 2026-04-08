#include <iostream>
#include "Enemy.h"
#include "Harpy.h"
#include "Werewolf.h"



int main()
{
    
    // Dynamiczna tablica czterech wskaźników typu Enemy*
    Enemy** enemies = new Enemy * [4];

    // Dwa obiekty dynamiczne Harpy
    enemies[0] = new Harpy(1.0f, 2.0f, 100.0f, 5.0f);
    enemies[1] = new Harpy(3.0f, 4.0f, 80.0f, 3.5f);

    // Dwa obiekty dynamiczne Werewolf
    enemies[2] = new Werewolf(5.0f, 6.0f, 120.0f, 2.0f);
    enemies[3] = new Werewolf(7.0f, 8.0f, 90.0f, 1.5f);

    // Pętla – polimorficzne wywołania metod
    std::cout << "Stan poczatkowy = " << std::endl;
    for (int i = 0; i < 4; ++i)
        enemies[i]->show();

    std::cout << "\nAktualizacja pozycji (dx=1, dy=1)" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        enemies[i]->update_position(1.0f, 1.0f);
        enemies[i]->show();
    }

    std::cout << "\n Atak (factor=0.1)" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        enemies[i]->attack(0.1f);
        enemies[i]->show();
    }

    // Zwolnienie pamięci obiektów, a następnie tablicy
    std::cout << "\nZwalnianie pamieci" << std::endl;
    for (int i = 0; i < 4; ++i)
        delete enemies[i];

    delete[] enemies;

    return 0;
}


/*
1. Dlaczego pola klasy Enemy są protected, a nie private?
   Bo klasy pochodne jak Harpy czy Werewolf muszą mieć dostęp do tych pól. Gdyby były private to w ogóle byśmy nie mogli
   ich użyć w klasach dziedziczących, np. w metodzie show() nie moglibyśmy wypisać x_ ani y_. Protected daje dostęp klasom
   pochodnym, ale nadal ukrywa pola przed "światem zewnętrznym".

2. Czy można wskaźnikowi klasy pochodnej przypisać wskaźnikklasy bazowej?
   Nie można tak po prostu. Wskaźnik klasy bazowej (Enemy*) może wskazywać na Harpy albo Werewolfa i kompilator nie wie który,
   więc nie pozwoli przypisać go do np. Harpy* bez rzutowania.
   Działa to tylko w drugą stronę. Wskaźnik pochodnej można przypisać do wskaźnika bazowej.

3. Które ze stworzonych klas są klasami abstrakcyjnymi?
   Tylko Enemy jest abstrakcyjna, bo ma trzy metody czysto wirtualne oznaczone przez = 0. Nie można więc stworzyć obiektu Enemy bezpośrednio.
   Harpy i Werewolf już nie są abstrakcyjne, bo implementują wszystkie te metody - dlatego możemy tworzyć ich obiekty.
*/