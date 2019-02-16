/*
 * PS3
 * pengt_week3_ps.cpp
 * Tristan Peng
 * CLion
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

static vector<vector<int>> used;

enum Suit
{
  club,
  diamond,
  heart,
  spade
};

int dealACard(Suit &s, string &rank);
bool contains(vector<int> info);

void four()
{
  Suit s;
  string rank;
  vector<string> suits = { "Clubs", "Diamonds", "Hearts", "Spades" };
  for (int i = 0; i < 52; ++i) {
    int val = dealACard(s, rank);
    cout << endl << "Suit: " << suits[s] << endl << "Rank: " << rank << endl << "Integer Value: " << (val > 10 ? 10 : val) << endl;
  }
}

int dealACard(Suit &s, string &rank)
{
  srand(time(0));
  static const vector<string> NAME = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
  int index, suit;
  do {
    index = rand() % 13;
    suit = rand() % 4;
  } while (contains({ suit, index }));
  rank = NAME[index];
  s = static_cast<Suit> (suit);
  used.push_back({ suit, index });
  return index + 1;
}

bool contains(vector<int> info)
{
  if (used.size() < 45)
  {
    for (auto i : used)
    {
      if (i[0] == info[0] && i[1] == info[1])
      {
        return true;
      }
    }
  }
  else
  {
    used.clear();
    return false;
  }
  return false;
}
