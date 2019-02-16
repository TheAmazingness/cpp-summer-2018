/*
 * PS3
 * pengt_week3_ps.cpp
 * Tristan Peng
 * CLion
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void one()
{
  srand(time(0));
  enum Color
  {
    red,
    green,
    blue,
    purple,
    orange,
    yellow
  };
  Color random[] = { static_cast<Color> (rand() % 6), static_cast<Color> (rand() % 6), static_cast<Color> (rand() % 6), static_cast<Color> (rand() % 6) };
  string names[] = { "red", "green", "blue", "purple", "orange", "yellow" };
  for (auto i : random)
  {
    cout << names[i] << endl;
  }
}
