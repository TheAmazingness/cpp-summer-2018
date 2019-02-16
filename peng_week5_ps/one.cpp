#include <iostream>
using namespace std;

class Money
{
  private:
    int dollars, cents;
  public:
    Money();
    void addMoney(int d, int c);
    void showMoney();
};

Money::Money()
{
  dollars = cents = 0;
}

void Money::addMoney(int d, int c)
{
  while (c >= 100)
  {
    d++;
    c -= 100;
  }
  dollars += d;
  cents += c;
}

void Money::showMoney()
{
  if (cents < 10)
  {
    cout << '$' << dollars << ".0" << cents << endl;
  }
  else
  {
    cout << '$' << dollars << '.' << cents << endl;
  }
}

void one()
{
  Money m;
  m.showMoney();
  m.addMoney(4, 5);
  m.showMoney();
  m.addMoney(2, 560);
  m.showMoney();
}