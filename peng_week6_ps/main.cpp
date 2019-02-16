/*
 * PS6
 * main.cpp
 * Tristan Peng
 * CLion
 */
#include <iostream>
#include <vector>
#include "Money.h"
#include "SafeArray.h"
using namespace std;

int main()
{
  Money m (-1.09);
  m.show();
  m.setMoney(0, 999);
  m.show();
  m.increase(0, 1);
  m.show();
  m.decrease(9, 111);
  m.show();
  m.setMoney(100.05);
  m.show();
  Money m2 = m;
  m2.show();
  Money m3 (1, 2);
  m3.show();

  SafeArray s ({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
  s.addItems(9, 0);
  cout << s.at(15) << endl;
  s.removeItems(9);
  cout << s.at(4) << endl;
  try
  {
    cout << s.at(15) << endl;
  }
  catch (const char *c)
  {
    cout << c << endl;
  }
  SafeArray s1 = s;
  s1.put(6, 24);
  const int SIZE = 5;
  int *d = new int[SIZE];
  d[0] = 11;
  d[1] = 12;
  d[2] = 13;
  d[3] = 14;
  d[4] = 15;
  s1.put(1, d, SIZE);
  vector<int> v;
  s1.copyTo(v);
  for (int i = 0; i < v.size(); ++i)
  {
    cout << "V: " << v[i] << endl;
  }
  cout << s1.size() << endl;
  s1.clear();
  return 0;
}