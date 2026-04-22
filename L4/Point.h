#pragma once

#include <iostream>

template <typename T>
class Point {
private:
    T _x;
    T _y;

public:

    Point(T x, T y);

    ~Point();

    // Gettery
    T getX() const;
    T getY() const;

    // Settery
    void setX(T x);
    void setY(T y);

    void display() const;
};


template <typename T>
Point<T>::Point(T x, T y) : _x(x), _y(y) {}

template <typename T>
Point<T>::~Point() {
  std::cout << "Point (" << _x << ", " << _y << ") zostal usuniety." << std::endl;
}

template <typename T>
T Point<T>::getX() const {
    return _x;
}

template <typename T>
T Point<T>::getY() const {
    return _y;
}

template <typename T>
void Point<T>::setX(T x) {
    _x = x;
}

template <typename T>
void Point<T>::setY(T y) {
    _y = y;
}

template <typename T>
void Point<T>::display() const {
    std::cout << "(" << _x << ", " << _y << ")";
}