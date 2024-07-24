/*
  Sophie Samuels
  COP 3014
  Assignment 8
  (application file)
  07.24.2024
*/

//application file

#include "rationals_ss.h"
#include <iostream>

//ADD namespace
using namespace ssamuels_rationals;

//main function
int main() {
  
  //call static member function to demonstrate performance of all overloaded operators
  //outputs results to screen
  ssamuels_rationals::RationalNumber::DemonstrateOperations();

  //test constructor
  //outputs results to screen
  ssamuels_rationals::RationalNumber::TestConstructors();

  //special test cases
 std::cout << "Testing special cases:" << std::endl;
  std::cout << std::endl;
  //zero tests
  ssamuels_rationals::RationalNumber zero(0, 1);
  ssamuels_rationals::RationalNumber R3(5/6);
  std::cout << "Add zero: " << R3 + zero << " (Expected: 5/6)" << std::endl;
  std::cout << std::endl;
  //division by zero test
  ssamuels_rationals::RationalNumber divByZero = R3 / zero;
  std::cout << "Divide by zero: " << divByZero << std::endl;
  std::cout << std::endl;
  //zero divided by zero test
  ssamuels_rationals::RationalNumber zeroByZero = zero / zero;
  std::cout << "Divide zero by zero: " << zeroByZero << " (Expected: 0/1)" << std::endl;
  std::cout << std::endl;
  //negative number test
  ssamuels_rationals::RationalNumber negative(-2, 3);
  std::cout << "Negative number: " << negative << " (Expected: -2/3)" << std::endl;
  std::cout << std::endl;
  //inversion of number test
  ssamuels_rationals::RationalNumber inversion(1, -5);
  std::cout << "Inverted number: " << inversion << " (Expected: -1/5)" << std::endl;
  std::cout << std::endl;
  //large numbers test
  ssamuels_rationals::RationalNumber big(600000000, 300000000);
  std::cout << "Large number: " << big << " (Expected: 2/1)" << std::endl;
  std::cout << std::endl;

  return 0;
}