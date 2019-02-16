/*
 * G4
 * peng_week4_g.cpp
 * Tristan Peng
 * CLion
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "jotto.h"
using namespace std;

const int LENGTH = 6;
const int NUM_WORDS = 100;

int main()
{
  jotto();
  return 0;
}

void jotto()
{
  srand(static_cast<unsigned int> (time(0)));
  ifstream file;
  char dictionary[NUM_WORDS][LENGTH];
  file.open("../dictionary.txt");
  if (!file)
  {
    cout << "Unable to open file dictionary.txt";
    exit(-1);
  }
  int words = 0;
  char temp[6];
  while (file >> temp)
  {
    strcpy(dictionary[words], temp);
    words++;
  }
  int index = rand() % 100;
  //  int index = 11; // For testing purposes
  char word[LENGTH];
  int count = 0;
  bool guessed = false;
  strcpy(word, dictionary[index]);
  while (!guessed)
  {
    count++;
    guessed = guess(word);
  }
  cout << "You guessed the word " << word << "! You used " << count << " tries.\n";
}

bool guess(char word[])
{
  char guess[LENGTH];
  cout << "Guess a word (type :( to give up): ";
  cin >> guess;
  for (char &g : guess)
  {
    g = static_cast<char> (tolower(g));
  }
  eval(word, guess);
  return !strcmp(word, guess);
}

void eval(char word[], char guess[])
{
  if (!strcmp(guess, ":("))
  {
    cout << endl << "You gave up. The word was " << word << ".\n";
    exit(0);
  }
  char correct[LENGTH * 3];
  int index = 0, numCorrect = 0;
  for (char *i = word; i - word < LENGTH - 1; i++)
  {
    for (char *j = guess; j - guess < LENGTH - 1; j++)
    {
      if (tolower(*i) == tolower(*j))
      {
        correct[index] = ' ';
        correct[index + 1] = static_cast<char> (tolower(*i));
        correct[index + 2] = ',';
        numCorrect++;
        index += 3;
        break;
      }
    }
  }
  cout << "Correct Letters: " << numCorrect << " (for" << correct << ")\n\n";
}