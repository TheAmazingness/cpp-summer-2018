/*
 * PS4
 * pengt_week4_ps.cpp
 * Tristan Peng
 * CLion
 */

#include <iostream>
using namespace std;

char * subString(char * s, int index, int howMany = -1);
char * extraCredit(char * s, int index, int howMany = -1);

void four()
{
  char s[] = "Hello World!";
  cout << subString(s, 3, 5) << endl;
  char s2[] = "Hello World!";
  cout << extraCredit(s2, 3, 5) << endl;
}

char * subString(char * s, int index, int howMany /* = -1 */)
{
  if (howMany < -1)
  {
    cout << "Error\n";
    return nullptr;
  }
  for (int i = 0; i < index; i++)
  {
    s++;
  }
  if (howMany > -1)
  {
    char * end = s;
    for (int i = 0; i < howMany; ++i)
    {
      end++;
    }
    * end = '\0';
    return s;
  }
  return s;
}

char * extraCredit(char * s, int index, int howMany /* = -1 */)
{
  if (howMany < -1)
  {
    cout << "Error\n";
    return nullptr;
  }
  char * sub;
  sub = new char[howMany];
  if (!sub)
  {
    cout << "Sad.\n";
    exit(-1);
  }
  for (int i = 0; i < index; i++)
  {
    s++;
  }
  if (howMany > -1)
  {
    char * end = s;
    for (int i = 0; i < howMany; ++i)
    {
      end++;
    }
    * end = '\0';
    strcpy(sub, s);
    return sub;
  }
  return sub;
}
