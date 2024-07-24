/*
  Sophie Samuels
  COP 3014
  Assignment 8
  (header file)
  07.24.2024
*/

//header file

//directive checks to see if RATIONALS_H has been defined
#ifndef RATIONALS_H 
//adds RATIONALS_H to a list indicating RATIONALS_H has been seen
#define RATIONALS_H 

#include <iostream>

//ADD NAMESPACE
namespace ssamuels_rationals {

//rational number class
class RationalNumber
{
private:
  int numerator;
  int denominator;

  //function to calc greatest common divisor (gcd)
  int gcd(int x, int y) const;

  //function to reduce rational number
  void reduce();

public:
  //constructor declarations
  //default construtor to initialize rational num to 0/1
  RationalNumber();

  //constructor including 2 int parameters, initializes num/num
  RationalNumber(int num, int den);

  //constructor including 1 int parameter, initializes num/1
  RationalNumber(int num);

  //declare friend functions for input and output
  //friend: need to acces private/protected data members of the class
  //overload functions for reading / writing rational numbers
  friend std::istream& operator >> (std::istream& ins, RationalNumber& rat);
  friend std::ostream& operator << (std::ostream& outs, const RationalNumber& rat);

  //declare operation overloads for boolean/comparison operators
  //including const indicates the operations do not modify the object(s) they are called on
  bool operator==(const RationalNumber& other) const;
  bool operator<(const RationalNumber& other) const;
  bool operator<=(const RationalNumber& other) const;
  bool operator>(const RationalNumber& other) const;
  bool operator>=(const RationalNumber& other) const;
  bool operator!=(const RationalNumber& other) const;

  //declare operation overloads for arithmetic operators
  //including const indicates the operations do not modify the object(s) they are called on
  RationalNumber operator+(const RationalNumber& other) const;
  RationalNumber operator-(const RationalNumber& other) const;
  RationalNumber operator*(const RationalNumber& other) const;
  RationalNumber operator/(const RationalNumber& other) const;

  //declare operation overload for unary operator -
  //including const indicates the operations do not modify the object(s) they are called on
  RationalNumber operator-() const;

  //declare static member function to allow testing of all overloaded operators
  //https://www.geeksforgeeks.org/static-member-function-in-cpp/
  static void DemonstrateOperations();

  //declare static member function to allow testing of constructors
  static void TestConstructors();
};

}

//if RATIONALS_H has been defined, skip to #endif
#endif 