/*
 * PS3
 * pengt_week3_ps.cpp
 * Tristan Peng
 * CLion
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

static vector<vector<int>> total = { /* Hotdogs */ { 1, 0 }, /* Fries */ { 2, 0 }, /* Soda */ { 3, 0 }, /* Sauerkraut */ { 4, 0 } };
static const vector<double> prices = { /* Hotdogs */ 3.5, /* Fries */ 2.5, /* Soda */ 1.25, /* Sauerkraut */ 3 };

/*
 * Main function to calculate prices
 */
void calculate();

/*
 * @return double - The discount if applicable
 */
double discount(double subtotal);

/*
 * Displays prices and savings (if applicable)
 */
void display(vector<double> info);

/*
 * Formats the money
 */
void format();

/*
 * Recursive function to order things
 */
void joes();

/*
 * Displays the menu
 */
void menu();

/*
 * Accepts order
 */
vector<int> order();

/*
 * Determines if it is buy 3 get 1 free Mondays
 */
bool special();

/*
 * Calculates subtotal
 */
double subtotal();

/*
 * Calculates tax
 */
double taxation(double subtotal);

void three()
{
  joes();
}

void calculate()
{
  format();
  if (special())
  {
    for (int i = 0; i < total.size(); ++i)
    {
      int saved = total[i][1] / 4;
      total[i][1] = total[i][1] - saved;
      total[i][2] = saved;
    }
  }
  double sub = subtotal();
  double dis = discount(sub);
  double tax = taxation(sub);
  double tot = sub + dis + tax;
  display({ sub, dis, tax, tot });
}

double discount(double subtotal)
{
  return subtotal >= 20 ? subtotal * 0.1 : 0;
}

void display(vector<double> info)
{
  if (special())
  {
    vector<string> names = { "Hotdog(s)", "Fries", "Soda(s)", "Sauerkraut(s)" };
    cout << endl << "You saved:\n";
    for (int i = 0; i < total.size(); ++i)
    {
      cout << total[i][2] << " " << names[i] << endl;
    }
  }
  cout << endl << "Subtotal:\t$ " << info[0] << endl
      << "Discount:\t$ " << info[1] << endl
      << "Tax:\t\t$ " << info[2] << endl
      << "Total:\t\t$ " << info[3] << endl;
}

void format()
{
  cout << setiosflags(ios::fixed) << setprecision(2);
}

void joes()
{
  vector<int> item = order();
  string cont;
  for (int i = 0; i < total.size(); ++i)
  {
    if (item[0] == total[i][0])
    {
      total[i][1] += item[1];
    }
  }
  cout << " _________________\n"
       << "|    YOUR ORDER   |\n"
       << "| Hotdog\t- " << total[0][1] << "   |\n"
       << "| Fries\t\t- " << total[1][1] << "   |\n"
       << "| Soda\t\t- " << total[2][1] << "   |\n"
       << "| Sauerkraut - " << total[3][1] << "  |\n"
       << " \u023E\u023E\u023E\u023E\u023E\u023E\u023E\u023E\u023E\u023E\u023E\u023E\u023E\u023E\u023E\u023E\u023E\u023E\n\n"
       << "Continue ordering? (Y or N) > ";
  cin >> cont;
  if (cont == "Y")
  {
    joes();
  }
  else
  {
    calculate();
  }
}

void menu()
{
  cout << " __________________\n"
      << "|       MENU       |\n"
      << "|   1. Hotdog      |\n"
      << "|   2. Fries       |\n"
      << "|   3. Soda        |\n"
      << "|   4. Sauerkraut  |\n"
      << " \u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\u203E\n";
}

vector<int> order()
{
  menu();
  int order = 0, quantity = -1;
  do
  {
    cout << "What would you like to order? > ";
    cin >> order;
  } while (order < 1);
  do
  {
    cout << "How many would you like to order? > ";
    cin >> quantity;
  } while (quantity < 0);
  return { order, quantity };
}

bool special()
{
  time_t now = time(0);
  tm *pointer = localtime(&now);
  int day = pointer -> tm_wday;
//  int day = 1; // For testing purposes
  return day == 1;
}

double subtotal()
{
  return total[0][1] * prices[0] + total[1][1] * prices[1] + total[2][1] * prices[2] + total[3][1] * prices[3];
}

double taxation(double subtotal)
{
  const double TAX = 0.0625;
  return subtotal * TAX;
}
