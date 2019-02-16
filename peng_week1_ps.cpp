/*
 * PS1
 * peng_week1_ps.cpp
 * Tristan Peng
 */

#include <iostream>
#include <string>
using namespace std;

int one() {
  int catAge = 1;
  double gpa = 4.0;
  string football = "Seahawks";
  int beans = 15402471;
  bool pizza = true;
  int max = 50;
  cout << "Hello World!" << endl;
  return 0;
}

int two() {
  string first, last, streetNum, streetName, streetType, city, state, zip;

  cout << "First Name: ";
  cin >> first;

  cout << "Last Name: ";
  cin >> last;

  cout << "Street Number: ";
  cin >> streetNum;

  cout << "Street Name: ";
  cin >> streetName;

  cout << "Street Type (Ex: \"Rd\", \"St\", \"Ave\", ...): ";
  cin >> streetType;

  cout << "City: ";
  cin >> city;

  cout << "State: ";
  cin >> state;

  cout << "Zip Code: ";
  cin >> zip;

  cout << endl << first << " " << last << endl
       << streetNum << " " << streetName << " " << streetType << endl
       << city << ", " << state << " " << zip << endl;

  return 0;
}

int three() {
  int hotdog, fry, soda, tot, tax;

  cout << "Welcome to Joe's" << endl << endl
      << "How many hot dogs? > ";
  cin >> hotdog;

  cout << "How many fries? > ";
  cin >> fry;

  cout << "How many sodas? > ";
  cin >> soda;

  tot = static_cast<int> ((hotdog * 3.50 + fry * 2.50 + soda * 1.25) * 100);
  tax = static_cast<int> (tot * 0.0625);

  cout << "Your order:" << endl
      << hotdog << " Hot dogs" << endl
      << fry << " Fries" << endl
      << soda << " Sodas\n\n"
      << "Subtotal: $" << static_cast<double> (tot) / 100 << endl
      << "Meals Tax (6.25%): $" << static_cast<double> (tax) / 100 << endl
      << "Total : $" << static_cast<double> (tot) / 100 + static_cast<double> (tax) / 100 << endl;

  return 0;
}

int main() {
  one();
  two();
  three();
  return 0;
}
