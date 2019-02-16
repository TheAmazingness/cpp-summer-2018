/*
 * PS4
 * pengt_week4_ps.cpp
 * Tristan Peng
 * CLion
 */

#include <iostream>
#include <string>
using namespace std;

struct Money
{
  int dollars;
  int cents;
};

void addMoney(Money & m, int d, int c);
void showMoney(Money m);

void three()
{
  Money m = { 80, 20 };
  addMoney(m, 3, 75);
  showMoney(m);
}

void addMoney(Money & m, int d, int c)
{
  m.dollars += d;
  m.cents += c;
}

void showMoney(Money m)
{
  cout << "$" << m.dollars << "." << m.cents << endl;
}
