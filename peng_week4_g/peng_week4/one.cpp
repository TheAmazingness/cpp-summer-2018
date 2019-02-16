/*
 * PS4
 * pengt_week4_ps.cpp
 * Tristan Peng
 * CLion
 */

#include <iostream>
#include <string>
using namespace std;

/*
 * Part 1 of question 1 on the problem set
 */
void part1();

/*
 * Part 2 of question 1 on the problem set, this is the "main()" function for part two of question two
 */
void part2();

/*
 * Function described in part 2 of question 1 in the problem set
 */
void makeFibSeries(int * p, int size);

void one()
{
  part1();
  part2();
}

void part1()
{
  const int SIZE = 30;
  int fib[SIZE];
  cout << "First 30 Fibonacci Numbers: ";
  for (int * i = fib, j = 0; i - fib < SIZE ; i++, j++)
  {
    if (j == 0)
    {
      *i = 0;
    }
    else if (j == 1)
    {
      *i = 1;
    }
    else
    {
      *i = *(i - 1) + *(i - 2);
    }
    cout << *i << ", ";
  }
  cout << endl;
}

void part2()
{
  int size, * fib;
  cout << "How many numbers? > ";
  cin >> size;
  fib = new int[size];
  if (!fib)
  {
    cout << "Sad." << endl;
    exit(-1);
  }
  makeFibSeries(fib, size);
  for (int i = 0; i < size; i++)
  {
    cout << fib[i] << ", ";
  }
  cout << endl;
}

void makeFibSeries(int * p, int size)
{
  for (int * i = p, j = 0; i - p < size ; i++, j++)
  {
    if (j == 0)
    {
      *i = 0;
    }
    else if (j == 1)
    {
      *i = 1;
    }
    else
    {
      if (*(i - 1) + *(i - 2) < 0)
      {
        cout << "This series will pass INT_MAX, all of the numbers past number " << j << " will be zero because they are not calculated: ";
        break;
      }
      *i = *(i - 1) + *(i - 2);
    }
  }
}
