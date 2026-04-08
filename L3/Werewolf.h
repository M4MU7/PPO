#pragma once
#include "Enemy.h"

class Werewolf : public Enemy
{
private:
    float radius_;

public:
    Werewolf() : Enemy(), radius_(0.0f) {}
    Werewolf(float x, float y, float s, float r) : Enemy(x, y, s), radius_(r) {}
    ~Werewolf() override { std::cout << "Werewolf destroyed" << std::endl; }

    float get_radius() const  { return radius_; }
    void  set_radius(float s) { radius_ = s; }

    void show() override;
    void attack(float factor) override;
    void make_sound() override;
};
