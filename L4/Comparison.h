#pragma once

#include "Point.h"

template <typename T>
class Comparison {
private:
    Point<T> _firstPoint;
    Point<T> _secondPoint;
    double _solution;  

public:
  
    Comparison(Point<T> firstPoint, Point<T> secondPoint);

    ~Comparison();

    // Gettery
    Point<T> getFirstPoint() const;
    Point<T> getSecondPoint() const;
    double getSolution() const;

    // Settery
    void setFirstPoint(Point<T> firstPoint);
    void setSecondPoint(Point<T> secondPoint);


    void displayBothPoints() const;
    void calculateDistance();


    Point<T> calculateMidpoint() const;

    double calculateCircumference() const;

    void displayAllInfo();
};


#include <iostream>
#include <cmath>

template <typename T>
Comparison<T>::Comparison(Point<T> firstPoint, Point<T> secondPoint)
    : _firstPoint(firstPoint), _secondPoint(secondPoint), _solution(0.0) {
}

template <typename T>
Comparison<T>::~Comparison() {
   std::cout << "Obiekt Comparison zostal usuniety." << std::endl;
}

template <typename T>
Point<T> Comparison<T>::getFirstPoint() const {
    return _firstPoint;
}

template <typename T>
Point<T> Comparison<T>::getSecondPoint() const {
    return _secondPoint;
}

template <typename T>
double Comparison<T>::getSolution() const {
    return _solution;
}

template <typename T>
void Comparison<T>::setFirstPoint(Point<T> firstPoint) {
    _firstPoint = firstPoint;
}

template <typename T>
void Comparison<T>::setSecondPoint(Point<T> secondPoint) {
    _secondPoint = secondPoint;
}


template <typename T>
void Comparison<T>::displayBothPoints() const {
    std::cout << "Punkt 1: ";
    _firstPoint.display();
    std::cout << std::endl;
    std::cout << "Punkt 2: ";
    _secondPoint.display();
    std::cout << std::endl;
}


template <typename T>
void Comparison<T>::calculateDistance() {
    double deltaX = static_cast<double>(_secondPoint.getX() - _firstPoint.getX());
    double deltaY = static_cast<double>(_secondPoint.getY() - _firstPoint.getY());
    _solution = std::sqrt(deltaX * deltaX + deltaY * deltaY);
}


template <typename T>
Point<T> Comparison<T>::calculateMidpoint() const {
    T midX = (_firstPoint.getX() + _secondPoint.getX()) / static_cast<T>(2);
    T midY = (_firstPoint.getY() + _secondPoint.getY()) / static_cast<T>(2);
    return Point<T>(midX, midY);
}


template <typename T>
double Comparison<T>::calculateCircumference() const {
    const double PI = 3.14159265358979323846;
    double radius = _solution / 2.0;
    return 2.0 * PI * radius;
}


template <typename T>
void Comparison<T>::displayAllInfo() {
    calculateDistance(); 

    std::cout << "Informacja o punktach" << std::endl;

    std::cout << "Punkt 1: ";
    _firstPoint.display();
    std::cout << std::endl;

    std::cout << "Punkt 2: ";
    _secondPoint.display();
    std::cout << std::endl;

    std::cout << "Odleglosc: " << _solution << std::endl;

    Point<T> midpoint = calculateMidpoint();
    std::cout << "Srodkowy: ";
    midpoint.display();
    std::cout << std::endl;

    std::cout << "Obwod: " << calculateCircumference() << std::endl;
}