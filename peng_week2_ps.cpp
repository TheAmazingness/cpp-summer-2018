/*
 * PS2
 * pengt_week2_ps.cpp
 * Tristan Peng
 * CLion
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/* one();
 * Problem number one.
 */
void one();
/* two();
 * Problem number two.
 */
void two();
/* three();
 * Problem number three.
 */
void three();

int main()
{
  one();
  two();
  three();
  return 0;
}

void one()
{
  int x, y, z;
  double d;
  x = y = 10;

  x = x + 1;
  cout << x << endl;

  x++;
  cout << x << endl;

  x += 1;
  cout << x << endl;

  y = 4;
  z = 8;
  x = z / y;
  cout << x << endl;

  d = static_cast<double> (y) / z;
  cout << d << endl;

  if (x > 0) {
    x += 10;
  }
//  x = x > 0 ? x + 10 : x; // This is "faster"
  cout << x << endl;

  if (x > 0 && y < 10)
  {
    d++;
  }
//  d = x > 0 && y < 10 ? d + 1 : d; // This is "faster"
  cout << x << " " << y << " " << d << endl;

  if (x > 0 || y < 10)
  {
    d++;
  }
//  d = x > 0 || y < 10 ? d + 1 : d; // This is "faster"
  cout << x << " " << y << " " << d << endl;
};

void two()
{
  int hotdog, fry, soda;
  int saved[4] = { 0 };
  double tot, tax;
  time_t now = time(0);
  tm *pointer = localtime(&now);
  int day = pointer -> tm_wday;
//  int day = 1; // For testing purposes

  cout << "Welcome to Joe's" << endl << endl
       << "How many hot dogs? > ";
  cin >> hotdog;

  cout << "How many fries? > ";
  cin >> fry;

  cout << "How many sodas? > ";
  cin >> soda;

  if (hotdog == 0 && fry == 0 && soda == 0)
  {
    cout << "You did not order anything.\n";
  }
  else
  {
    if (day == 1)
    {
      saved[0] = 1;
      saved[1] = hotdog / 4;
      saved[2] = fry / 4;
      saved[3] = soda / 4;
      hotdog = hotdog - hotdog / 4;
      fry = fry - fry / 4;
      soda = soda - soda / 4;
    }
    tot = hotdog * 3.50 + fry * 2.50 + soda * 1.25;
    if (tot >= 20)
    {
      tot *= 0.9;
    }
//    tot = tot >= 20 ? tot * 0.9 : tot; // This is "faster"
    tax = tot * 0.0625;
    cout << setiosflags(ios::fixed) << setprecision(2) << "Your order:" << endl
         << hotdog << " Hot dogs";
    if (saved[0] == 1)
    {
      cout << " (" << saved[1] << " free)";
    }
    cout << endl << fry << " fries";
    if (saved[0] == 1)
    {
      cout << " (" << saved[2] << " free)";
    }
    cout << endl << soda << " sodas";
    if (saved[0] == 1)
    {
      cout << " (" << saved[3] << " free)";
    }
    cout << endl << endl << "Subtotal: $" << tot << endl
         << "Meals Tax (6.25%): $" << tax << endl
         << "Total : $" << tot + tax << endl;
  }
};

void three()
{
  int fibonacci[30] = { 0, 1 };
  int user = 0;
  for (int i = 0; i < 30; ++i)
  {
    if (i > 1)
    {
      fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
  }
  while (user < 1 || user > 30)
  {
    cout << "Enter a number: ";
    cin >> user;
  }
  for (int i = 0; i < user; i++)
  {
    if (i + 1 != user)
    {
      cout << fibonacci[i] << ", ";
    }
    else
    {
      cout << fibonacci[i];
    }
  }
}
