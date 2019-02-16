/*
 * PS4
 * pengt_week4_ps.cpp
 * Tristan Peng
 * CLion
 */

#include <iostream>
#include <string>
using namespace std;

string * allocName();

void two()
{
  string * name = allocName();
  cout << endl << * name << endl;
  delete name;
}

string * allocName()
{
  string first, last, * full;
  cout << "First name: ";
  cin >> first;
  cout << "Last name: ";
  cin >> last;
  full = new string;
  if (!full)
  {
    cout << "Sad." << endl;
    exit(-1);
  }
  * full = first + " " + last;
  return full;
}
