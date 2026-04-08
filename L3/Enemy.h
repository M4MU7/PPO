#pragma once
#include <iostream>

class Enemy
{
protected:
    float x_;
    float y_;
    float strength_;

    Enemy() : x_(0.0f), y_(0.0f), strength_(0.0f) {}
    Enemy(float x, float y, float s) : x_(x), y_(y), strength_(s) {}

public:
    virtual ~Enemy() { std::cout << "Enemy destroyed!" << std::endl; }

    // Gettery
    float get_x()        const { return x_; }
    float get_y()        const { return y_; }
    float get_strength() const { return strength_; }

    // Settery
    void set_x(float x)        { x_ = x; }
    void set_y(float y)        { y_ = y; }
    void set_strength(float s) { strength_ = s; }

    // Aktualizacja pozycji
    void update_position(float x, float y) { x_ += x; y_ += y; }

    // Czysto wirtualne metody
    virtual void show()               = 0;
    virtual void attack(float factor) = 0;
    virtual void make_sound()         = 0;
};
