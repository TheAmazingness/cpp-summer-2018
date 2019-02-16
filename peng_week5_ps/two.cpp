#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void two()
{
  int sum = 0;
  string numbers = "1 2 3 4 5";
  istringstream i (numbers);
  for (int j = 0; j < 5; ++j)
  {
    int temp;
    i >> temp;
    sum += temp;
  }
  cout << numbers << "\t" << sum;
}