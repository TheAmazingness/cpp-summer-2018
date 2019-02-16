/*
 * PS2
 * pengt_week3_g.cpp
 * Tristan Peng
 * CLion
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

static string displayed;

/*
 * @param string word - the word to be displayed
 * @param int length - length of the word
 */
void display(string word, int length);

/*
 * @param string word - the word to be displayed
 * @param int length - length of the word
 * @param int missed - number of guesses wrong
 */
bool guess(string word, int length, int missed);

/*
 * @description gets word and word length and passes it to display();
 */
void hangman();

/*
 * @return bool - if the word was guessed
 */
bool validate();

int main() {
  hangman();
  return 0;
}

void display(string word, int length)
{
  const int GUESSES = 10;
  int index = 0;
  int tot = 0;
  for (int i = 0; i < length; ++i)
  {
    displayed += "_ ";
  }
  cout << displayed << " (" << to_string(length) << " letters)\n";
  while (index < GUESSES)
  {
    if (validate())
    {
      cout << "\nYay! You figured out the word " << word << "! You used " << tot << " guess(es).\n" ;
      break;
    }
    cout << "Total number of guesses so far: " << tot << endl;
    if (!guess(word, length, index))
    {
      index++;
    }
    tot++;
  }
  if (!validate())
  {
    cout << ":( The word was " << word <<".\n";
  }
}

bool guess(string word, int length, int missed)
{
  static vector<char> alphabet = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
  static vector<char> missList;
  string wordGuess;
  char guess;
  bool valid = false, guessed = false;
  int index = 0;
  if (missed > 0)
  {
    string disp;
    for (auto i : missList)
    {
      disp += i;
      disp += ", ";
    }
    cout << "Missed letters: " << disp << " (You have missed " << to_string(missed) << " letter(s))" << endl;
  }
  do
  {
    int erase = 0;
    cout << "Guess a letter: ";
    cin >> wordGuess;
    if (wordGuess.size() == 1)
    {
      guess = wordGuess[0];
      for (char letter : alphabet)
      {
        if (tolower(guess) == letter)
        {
          valid = true;
          alphabet.erase(alphabet.begin() + erase);
        }
        erase++;
      }
    }
  } while (!valid && wordGuess.size() == 1);
  if (wordGuess.size() == 1)
  {
    for (char c : word)
    {
      if (tolower(guess) == c)
      {
        displayed[index] = static_cast<char> (tolower(guess));
        guessed = true;
      }
      index += 2;
    }
    if (!guessed)
    {
      missList.push_back(static_cast<char> (tolower(guess)));
    }
    cout << endl << displayed << " (" << to_string(length) << " letters)\n";
    return guessed;
  }
  else
  {
    if (wordGuess == word)
    {
      displayed = word;
      return true;
    }
    return false;
  }
}

void hangman()
{
  srand(time(0));
  const vector<string> DICTIONARY = { "concentration", "strategic", "telephone", "preoccupation", "possession", "orchestra", "negligence", "separation", "exception", "background", "obligation", "environment", "volunteer", "assumption", "communist", "acquaintance", "transition", "diplomatic", "injection", "conference", "lifestyle", "character", "landscape", "education", "dependence", "vegetarian", "conscious", "understand", "administration", "discrimination", "replacement", "perforate", "television", "breakfast", "exaggerate", "chemistry", "authority", "representative", "demonstrate", "spokesperson", "brainstorm", "mechanism", "fireplace", "motivation", "assessment", "explosion", "countryside", "sensation", "satisfied", "foundation", "disturbance", "translate", "effective", "institution", "exhibition", "manufacture", "interactive", "appearance", "competition", "conspiracy", "systematic", "craftsman", "overcharge", "syllabus", "interface", "negotiation", "accompany", "foreigner", "goalkeeper", "evolution", "houseplant", "incongruous", "acceptable", "operation", "artificial", "possibility", "correspond", "pneumonia", "correspondence", "leftovers", "inspiration", "hostility", "spontaneous", "hierarchy", "essential", "investment", "rehabilitation", "formation", "frequency", "substitute", "undermine", "absorption", "information", "ignorance", "financial", "temperature", "atmosphere", "migration", "prediction", "sensitivity" };
  int index = rand() % static_cast<int> (DICTIONARY.size());
//  int index = 0; // For testing purposes
  string word = DICTIONARY[index];
  auto length = static_cast<int> (word.size());
  display(word, length);
}

bool validate()
{
  return displayed.find('_') > displayed.size();
}
