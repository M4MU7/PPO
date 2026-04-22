#include <iostream>
#include "Point.h"
#include "Comparison.h"
#include "RandomPointGenerator.h"

int main()
{
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  std::cout << "\n int \n"
            << std::endl;

  Point<int> heroPositionInt(3, 5);
  Point<int> enemyPositionInt(9, 13);

  std::cout << "pozycja bohatera: ";
  heroPositionInt.display();
  std::cout << std::endl;

  std::cout << "pozycja wroga: ";
  enemyPositionInt.display();
  std::cout << std::endl;

  Comparison<int> comparisonInt(heroPositionInt, enemyPositionInt);
  comparisonInt.displayBothPoints();
  comparisonInt.calculateDistance();
  std::cout << "odleglosc: " << comparisonInt.getSolution() << std::endl;

  std::cout << "\n double" << std::endl;

  Point<double> heroPositionDouble(1.5, 2.5);
  Point<double> enemyPositionDouble(7.5, 10.5);

  std::cout << "pozycja bohatera: ";
  heroPositionDouble.display();
  std::cout << std::endl;

  std::cout << "pozycja wroga: ";
  enemyPositionDouble.display();
  std::cout << std::endl;

  Comparison<double> comparisonDouble(heroPositionDouble, enemyPositionDouble);
  comparisonDouble.displayBothPoints();
  comparisonDouble.calculateDistance();
  std::cout << "odleglosc (double): " << comparisonDouble.getSolution() << std::endl;

  std::cout << "\nmetody int " << std::endl;
  comparisonInt.displayAllInfo();

  std::cout << "\nmetody double" << std::endl;
  comparisonDouble.displayAllInfo();

  std::cout << "\nlosowe punkty int" << std::endl;

  Point<int> randomIntPoint1(0, 0);
  Point<int> randomIntPoint2(0, 0);

  generateRandomPoint(randomIntPoint1);
  generateRandomPoint(randomIntPoint2, 10, 40);

  std::cout << "losowy punkt: ";
  randomIntPoint1.display();
  std::cout << std::endl;

  std::cout << "losowy punkt: ";
  randomIntPoint2.display();
  std::cout << std::endl;

  Comparison<int> comparisonRandomInt(randomIntPoint1, randomIntPoint2);
  comparisonRandomInt.displayAllInfo();

  std::cout << "\nlosowe double" << std::endl;

  Point<double> randomDoublePoint1(0.0, 0.0);
  Point<double> randomDoublePoint2(0.0, 0.0);

  generateRandomPoint(randomDoublePoint1);
  generateRandomPoint(randomDoublePoint2, 5.0, 25.0);

  std::cout << "losowy punkt: ";
  randomDoublePoint1.display();
  std::cout << std::endl;

  std::cout << "losowy punk: ";
  randomDoublePoint2.display();
  std::cout << std::endl;

  Comparison<double> comparisonRandomDouble(randomDoublePoint1, randomDoublePoint2);
  comparisonRandomDouble.displayAllInfo();

  return 0;
}