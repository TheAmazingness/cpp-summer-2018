#include <string>
#pragma once
using namespace std;

void one();
void two();
void three();

class Person
{
  private:
    string name;
    int avg;
  public:
    Person(string n = "");
    void setName(string n);
    string getName();
    void computeAvg(int arr[], int len);
    int getAvg();
};