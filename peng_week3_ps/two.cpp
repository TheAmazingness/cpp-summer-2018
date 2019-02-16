/*
 * PS3
 * pengt_week3_ps.cpp
 * Tristan Peng
 * CLion
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void two()
{
  vector<int> fibonacci = { 0, 1 };
  int user = 0;
  do
  {
    cout << "How many numbers displayed? > ";
    cin >> user;
  } while (user < 1);
  for (int i = 0; i < user; ++i)
  {
    if (i > 1) {
      fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
    cout << fibonacci[i] << ", ";
  }
}
