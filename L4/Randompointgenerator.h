#pragma once

#include "Point.h"
#include <cstdlib>
#include <ctime>

template <typename T>
void generateRandomPoint(Point<T>& point) {
    T randomX = static_cast<T>(static_cast<double>(std::rand()) / RAND_MAX * 50.0);
    T randomY = static_cast<T>(static_cast<double>(std::rand()) / RAND_MAX * 50.0);
    point.setX(randomX);
    point.setY(randomY);
}

template <typename T>
void generateRandomPoint(Point<T>& point, T rangeStart, T rangeEnd) {
    double range = static_cast<double>(rangeEnd - rangeStart);
    T randomX = rangeStart + static_cast<T>(static_cast<double>(std::rand()) / RAND_MAX * range);
    T randomY = rangeStart + static_cast<T>(static_cast<double>(std::rand()) / RAND_MAX * range);
    point.setX(randomX);
    point.setY(randomY);
} 