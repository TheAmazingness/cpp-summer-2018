#include <iostream>
#include <string>
#include <fstream>
#include "problems.h"
using namespace std;

void partA();
void partB();
void partC();
int count(const string &s, bool partb);
void sort(string arr[], int l);
void sort(Person arr[], int l);

void three()
{
  partA();
  partB();
  partC();
}

void partA()
{
  int index = 0;
  ifstream f;
  f.open("../three.txt", ios::in);
  if (f.fail())
  {
    cout << "Could not open three.txt" << endl;
  }
  while (!f.eof())
  {
    string first, last;
    f >> first >> last;
    cout << first << ' ' << last << endl;
    index++;
  }
  cout << "There were " << index << " names." << endl;
  f.close();
}

void partB()
{
  ifstream f;
  f.open("../three.txt", ios::in);
  int index = count("../three.txt", true);
  if (f.fail())
  {
    cout << "Could not open three.txt" << endl;
  }
  auto *names = new string[index];
  int i = 0;
  while (!f.eof())
  {
    string first, last;
    f >> first >> last;
    names[i] = first + " " + last;
    i++;
  }
  sort(names, index);
  for (int i = 0; i < index; ++i)
  {
    cout << names[i] << ", ";
  }
  cout << endl;
  ofstream o ("../three-output.txt");
  for (int i = 0; i < index; i++)
  {
    o << names[i] << endl;
  }
  if (o.fail())
  {
    cout << "Could not open output.txt" << endl;
  }
  delete[] names;
}

void partC()
{
  ifstream f;
  int index = 0;
  f.open("../three-partc.txt", ios::in);
  if (f.fail())
  {
    cout << "Could not open three.txt" << endl;
  }
  int num = count("../three-partc.txt", false);
  Person *p = new Person[num];
  while (!f.eof())
  {
    string first, last;
    int grade[4];
    f >> first >> last;
    f >> grade[0] >> grade[1] >> grade[2] >> grade[3];
    Person temp (first + " " + last);
    temp.computeAvg(grade, 4);
    p[index] = temp;
    index++;
  }
  sort(p, num);
  for (int i = 0; i < num; ++i)
  {
    cout << "Name: " << p[i].getName() << ", Average: " << p[i].getAvg() << endl;
  }
  delete[] p;
}

int count(const string &s, bool partb)
{
  ifstream f;
  f.open(s, ios::in);
  int index = 0;
  if (f.fail())
  {
    cout << "Could not open " << s << endl;
  }
  while (!f.eof())
  {
    string first, last;
    f >> first >> last;
    if (!partb)
    {
      int grade[4];
      f >> grade[0] >> grade[1] >> grade[2] >> grade[3];
    }
    index++;
  }
  f.close();
  return index;
}

void sort(string arr[], int l)
{
  static bool sorted = false;
  string temp = "";
  if (!sorted)
  {
    for (int i = 0; i < l - 1; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
    if (temp == "")
    {
      sorted = true;
    }
    sort(arr, l);
  }
}

void sort(Person arr[], int l)
{
  static bool sorted = false;
  Person temp;
  if (!sorted)
  {
    for (int i = 0; i < l - 1; i++)
    {
      if (arr[i].getAvg() < arr[i + 1].getAvg())
      {
        temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
    if (temp.getName() == "")
    {
      sorted = true;
    }
    sort(arr, l);
  }
}

Person::Person(string n)
{
  name = n;
  avg = 0;
}

void Person::setName(string n)
{
  name = n;
}

string Person::getName()
{
  return name;
}

void Person::computeAvg(int arr[], int len)
{
  for (int i = 0; i < len; ++i)
  {
    avg += arr[i];
  }
  avg /= len;
}

int Person::getAvg()
{
  return avg;
}