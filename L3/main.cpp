#include <iostream>
#include "Enemy.h"
#include "Harpy.h"
#include "Werewolf.h"

// ============================================================
// Odpowiedzi na pytania (ocena 5.0)
// ============================================================
//
// 1. Dlaczego pola klasy Enemy są protected, a nie private?
//    Pola są protected, ponieważ klasy pochodne (Harpy, Werewolf)
//    muszą mieć do nich bezpośredni dostęp – np. w metodach show()
//    czy attack() odwołujemy się do x_, y_, strength_ wprost.
//    Gdyby pola były private, klasy pochodne nie miałyby do nich
//    dostępu i musiałyby korzystać wyłącznie z getterów/setterów,
//    co byłoby mniej wygodne i mniej czytelne.
//
// 2. Czy można wskaźnikowi klasy pochodnej przypisać wskaźnik
//    klasy bazowej?
//    NIE – nie jest to bezpieczne ani dozwolone bez jawnego rzutowania.
//    Wskaźnik klasy bazowej (Enemy*) wskazuje na obiekt, który może
//    być dowolnym typem pochodnym (Harpy lub Werewolf). Kompilator
//    nie wie, do jakiego konkretnego podtypu naprawdę wskazuje, więc
//    przypisanie Enemy* → Harpy* bez rzutowania jest błędem kompilacji.
//    Można to zrobić przez dynamic_cast<Harpy*>(ptr), ale tylko jeśli
//    faktycznie wskazuje na obiekt Harpy – w przeciwnym razie zwraca
//    nullptr. Ogólna zasada: dziedziczenie pozwala przypisać wskaźnik
//    klasy POCHODNEJ do wskaźnika klasy BAZOWEJ (upcasting), nie
//    odwrotnie (downcasting wymaga jawnego rzutowania).
//
// 3. Które klasy są abstrakcyjne?
//    Abstrakcyjna jest TYLKO klasa Enemy – zawiera trzy czysto wirtualne
//    metody (show, attack, make_sound) oznaczone = 0, co uniemożliwia
//    tworzenie jej obiektów.
//    Klasy Harpy i Werewolf NIE są abstrakcyjne – przesłaniają wszystkie
//    trzy czysto wirtualne metody, więc można tworzyć ich obiekty.
// ============================================================

int main()
{
    // --- Ocena 4.0 / 5.0 ---
    // Dynamiczna tablica czterech wskaźników typu Enemy*
    Enemy** enemies = new Enemy*[4];

    // Dwa obiekty dynamiczne Harpy
    enemies[0] = new Harpy(1.0f, 2.0f, 100.0f, 5.0f);
    enemies[1] = new Harpy(3.0f, 4.0f,  80.0f, 3.5f);

    // Dwa obiekty dynamiczne Werewolf
    enemies[2] = new Werewolf(5.0f, 6.0f, 120.0f, 2.0f);
    enemies[3] = new Werewolf(7.0f, 8.0f,  90.0f, 1.5f);

    // Pętla – polimorficzne wywołania metod
    std::cout << "=== Stan poczatkowy ===" << std::endl;
    for (int i = 0; i < 4; ++i)
        enemies[i]->show();

    std::cout << "\n=== Aktualizacja pozycji (dx=1, dy=1) ===" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        enemies[i]->update_position(1.0f, 1.0f);
        enemies[i]->show();
    }

    std::cout << "\n=== Atak (factor=0.1) ===" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        enemies[i]->attack(0.1f);
        enemies[i]->show();
    }

    // Zwolnienie pamięci obiektów, a następnie tablicy
    std::cout << "\n=== Zwalnianie pamieci ===" << std::endl;
    for (int i = 0; i < 4; ++i)
        delete enemies[i];

    delete[] enemies;

    return 0;
}
