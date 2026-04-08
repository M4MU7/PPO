#pragma once
#include "Enemy.h"

class Harpy : public Enemy
{
private:
    float height_;

public:
    Harpy() : Enemy(), height_(0.0f) {}
    Harpy(float x, float y, float s, float h) : Enemy(x, y, s), height_(h) {}
    ~Harpy() override { std::cout << "Harpy destroyed" << std::endl; }

    float get_height() const    { return height_; }
    void  set_height(float s)   { height_ = s; }

    void show() override;
    void attack(float factor) override;
    void make_sound() override;
};
