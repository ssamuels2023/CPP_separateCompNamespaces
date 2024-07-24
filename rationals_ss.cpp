/*
  Sophie Samuels
  COP 3014
  Assignment 8
  (implementation file)
  07.24.2024
*/

//implementation file

#include <iostream> //standard input/output stream library
#include "rationals_ss.h" //include directive to include interface file

//ADD NAMESPACE
namespace ssamuels_rationals {

//function definitions
//function to calc greatest common divisor (gcd)
int RationalNumber::gcd(int x, int y) const {
  while (y != 0) {
    int temp = y;
    y = x % y; //modulo operator for correct calc
    x = temp;
  }
  return x;
}

//function to reduce rational number
void RationalNumber::reduce() {
  int div = gcd(numerator, denominator);
  numerator /= div;
  denominator/= div;

  if (denominator < 0) { //make sure denominator is positive
    numerator = -numerator;
    denominator = -denominator;
  }
}

//default construtor to initialize rational num to 0/1
RationalNumber::RationalNumber() : numerator(0), denominator(1) {}

//constructor including 2 int parameters, initializes num/num
RationalNumber::RationalNumber(int num, int den) : numerator(num), denominator(den) {
  if (den == 0) {
    std::cout << "Denominator cannot be zero" << std::endl;
    numerator = 0;
    denominator = 1;
  } else {
    reduce();
  }
}

//constructor including 1 int parameter, initializes num/1
RationalNumber::RationalNumber(int num) : numerator(num), denominator(1) {}

//define friend function for input
//overload the input operator to read rational numbers
std::istream& operator >> (std::istream& ins, RationalNumber& rat) { 
  char obelus;
  ins >> rat.numerator >> obelus >> rat.denominator; 
  if (rat.denominator == 0) { //makes sure denominator is not zero
    std::cout << "Denominator cannot be zero" << std::endl;
    rat.numerator = 0;
    rat.denominator = 1; //if denominator zero, sets num to 0/1 and prints error message (above)
  } else {
    rat.reduce(); //if denominator is not zero, function called to reduce fraction
  }
  return ins;
}

//define friend function for output
//overload the output operator to write rational numbers
std::ostream& operator << (std::ostream& outs, const RationalNumber& rat) { 
  outs << rat.numerator << '/' << rat.denominator; //outputs rational number in numerator/denominator
  return outs;
}

//define overload for equality operator
// (a/b) == (c/d) means (a * d) == (c * b) 
bool RationalNumber::operator==(const RationalNumber& other) const {
  return (numerator * other.denominator) == (other.numerator * denominator);
}

//define overload for less than operator
// (a/b) < (c/d) means (a * d) < (c * b)
bool RationalNumber::operator<(const RationalNumber& other) const {
  return (numerator * other.denominator) < (other.numerator * denominator);
}

//define overload for less than or equal to operator
// (a/b) <= (c/d) means (a * d) <= (c * b)
bool RationalNumber::operator<=(const RationalNumber& other) const {
  return (numerator * other.denominator) <= (other.numerator * denominator);
}

//define overload for greater than operator
// (a/b) > (c/d) means (a * d) > (c * b)
bool RationalNumber::operator>(const RationalNumber& other) const {
  return (numerator * other.denominator) > (other.numerator * denominator);
}

//define overload for greater than or equal to operator
// (a/b) >= (c/d) means (a * d) >= (c * b)
bool RationalNumber::operator>=(const RationalNumber& other) const {
  return (numerator * other.denominator) >= (other.numerator * denominator);
}

//define overload for inequality operator
// (a/b) != (c/d) means (a * d) != (c * b)
bool RationalNumber::operator!=(const RationalNumber& other) const {
  return (numerator * other.denominator) != (other.numerator * denominator);
}

//define overload for addition operator
// a/b + c/d = (a * d + b * c) / (b * d)
RationalNumber RationalNumber::operator+(const RationalNumber& other) const {
  int num = (numerator * other.denominator) + (denominator * other.numerator);
  int den = denominator * other.denominator;
  return RationalNumber(num, den);
}

//define overload for subtraction operator
// a/b - c/d = (a * d - b * c) / (b * d)
RationalNumber RationalNumber::operator-(const RationalNumber& other) const {
  int num = (numerator * other.denominator) - (denominator * other.numerator);
  int den = denominator * other.denominator;
  return RationalNumber(num, den);
}

//define overload for multiplication operator
// (a/b) * (c/d) = (a * c) / (b * d)
RationalNumber RationalNumber::operator*(const RationalNumber& other) const {
  int num = numerator * other.numerator;
  int den = denominator * other.denominator;
  return RationalNumber(num, den);
}

//define overload for division operator
// (a/b) / (c/d) = (a * d) / (c * b)
RationalNumber RationalNumber::operator/(const RationalNumber& other) const {
  if (other.numerator == 0) {
    std::cout << "Division by zero" << std::endl;
    return RationalNumber(0, 1);
  }
  int num = numerator * other.denominator;
  int den = other.numerator * denominator;
  return RationalNumber(num, den);
}

//define overload for unary minus operator
// -(a/b) = (-a/b)
RationalNumber RationalNumber::operator-() const {
  return RationalNumber(numerator, denominator);
}

//define static member function to allow testing of all overloaded operators
void RationalNumber::DemonstrateOperations() {

  //declare objects of class RationalNumber
  RationalNumber Num1, Num2;
  //prompt user to enter two rational numbers
  std::cout << "Enter the first rational number as a/b format: ";
  std::cin >> Num1;
  std::cout << "Enter the second rational number as a/b format: ";
  std::cin >> Num2;
  std::cout << std::endl;

  std::cout << "You entered: " << std::endl;
  std::cout << "Rational Number 1: " << Num1 << std::endl;
  std::cout << "Rational Number 2: " << Num2 << std::endl;
  std::cout << std::endl;

  //demonstrate boolean/comparison operations on the entered rational numbers
  //output results of each
  std::cout << "Boolean Opeations: " << std::endl;
  std::cout << std::endl;

  if (Num1 == Num2) { //equality operator
    std::cout << Num1 << " == " << Num2 << " is true." << std::endl;
  } else {
    std::cout << Num1 << " == " << Num2 << " is false." << std::endl;
  }

  if (Num1 < Num2) { //less than operator
  std::cout << Num1 << " < " << Num2 << " is true." << std::endl;
  } else {
    std::cout << Num1 << " < " << Num2 << " is false." << std::endl;
  }

  if (Num1 <= Num2) { //less than or equal to operator
    std::cout << Num1 << " <= " << Num2 << " is true." << std::endl;
    } else {
      std::cout << Num1 << " <= " << Num2 << " is false." << std::endl;
    }

  if (Num1 > Num2) { //greater than operator
    std::cout << Num1 << " > " << Num2 << " is true." << std::endl;
    } else {
      std::cout << Num1 << " > " << Num2 << " is false." << std::endl;
    }

  if (Num1 >= Num2) { //greater than or equal to operator
    std::cout << Num1 << " >= " << Num2 << " is true." << std::endl;
    } else {
      std::cout << Num1 << " >= " << Num2 << " is false." << std::endl;
    }

  if (Num1 != Num2) { //inequality operator
    std::cout << Num1 << " != " << Num2 << " is true." << std::endl;
    } else {
      std::cout << Num1 << " != " << Num2 << " is false." << std::endl;
    }

  std::cout << std::endl;

  //demonstrate arithmetic operations on the entered rational numbers
  //output results of each
  std::cout << "Arithmetic Operations: " << std::endl;
  RationalNumber sum = Num1 + Num2;
  std::cout << Num1 << " + " << Num2 << " = " << sum << std::endl;

  RationalNumber difference = Num1 - Num2;
  std::cout << Num1 << " - " << Num2 << " = " << difference << std::endl;

  RationalNumber product = Num1 * Num2;
  std::cout << Num1 << " * " << Num2 << " = " << product << std::endl;

  RationalNumber quotient = Num1 / Num2;
  std::cout << Num1 << " / " << Num2 << " = " << quotient << std::endl;

  std::cout << std::endl;

  //demonstrate unary operation -
  //output result
  std::cout << "Negation Operation: " << std::endl;
  RationalNumber negatedNum1 = -Num1;
  std::cout << "Negation of " << Num1 << " = " << -negatedNum1 << std::endl;
  RationalNumber negatedNum2 = -Num2;
  std::cout << "Negation of " << Num2 << " = " << negatedNum2 << std::endl;

  std::cout << std::endl;
  std::cout << "Demonstration Complete." << std::endl;
  std::cout << std::endl;
}

//define static member function to allow testing of constructors
void RationalNumber::TestConstructors() {
  std::cout << "Testing constructors:" << std::endl;
  std::cout << std::endl;

  RationalNumber thisNum;
  std::cout << "Default: " << thisNum << " (Expected: 0/1)" << std::endl;
  std::cout << std::endl;

  RationalNumber singleParameter(8);
  std::cout << "Single parameter: " << singleParameter << " (Expected: 8/1)" << std::endl;
  std::cout << std::endl;

  RationalNumber doubleParameter(3, 9);
  std::cout << "Double parameter: " << doubleParameter << " (Expected: 1/3 after reduced)" << std::endl;
  std::cout << std::endl;
}

}