/*
 * PS6
 * Money.cpp
 * Tristan Peng
 * CLion
 */
#include <iostream>
#include <string>
#include "Money.h"
using namespace std;

Money::Money(): dollars(0), cents(0), negative(false) {}

Money::Money(unsigned int d, unsigned int c)
{
  dollars += d;
  cents += c;
  while (cents >= 100) {
    cents -= 100;
    dollars++;
  }
  negative = false;
}

Money::Money(double m)
{
  if (m < 0)
  {
    dollars = 0;
    cents = 0;
  }
  else
  {
    dollars = static_cast<unsigned int> (m);
    cents = static_cast<unsigned int> (m * 100) - dollars * 100;
  }
  negative = dollars < 0;
}

Money::Money(const Money &m)
{
  dollars = m.dollars;
  cents = m.cents;
  negative = m.negative;
}

Money::~Money()
{
  cout << "My wallet is now empty." << endl;
}

void Money::setMoney(unsigned int d, unsigned int c)
{
  dollars = d;
  cents = c;
  while (cents >= 100)
  {
    cents -= 100;
    dollars++;
  }
  negative = false;
}

void Money::setMoney(double m)
{
  negative = m < 0;
  dollars = static_cast<unsigned int> (m);
  cents = static_cast<unsigned int> (m * 100) - dollars * 100;
}

void Money::increase(unsigned int d, unsigned int c)
{
  dollars += d;
  cents += c;
  while (cents >= 100)
  {
    cents -= 100;
    dollars++;
  }
  negative = false;
}

void Money::decrease(unsigned int d, unsigned int c)
{
  int temp = (dollars * 100 + cents) - (d * 100 + c);
  if (temp < 0)
  {
    temp = abs(temp);
    negative = true;
  }
  dollars = temp / 100;
  cents = temp - dollars * 100;
}

void Money::show() const
{
  string temp = cents < 10 ? "0" : "";
  cout << (negative ? "-" : "") << '$' << dollars << '.' << temp << cents << endl;
}