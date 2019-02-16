/*
 * GP1
 * peng_week1_g.cpp
 * Tristan Peng
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/* shelper()
 * fastShell() helper function - determines if user guess is correct
 * @param num the number of boxes
 * @param box the box number of the box with the shell
 * @return bool if the user guess is the same as the "shelled" box
 */
bool shelper(int num, int box)
{
  int guess;
  cout << "Where is the shell? Choose box 1 - " << num << " > ";
  cin >> guess;
  return guess == box;
}

/* fastShell()
 * This is the shell game with "better" code.
 */
int fastShell()
{
  srand(time(0));
  int num;
  cout << "How many boxes would you like to work with? > ";
  cin >> num;
//  int num = 5;
  int box = rand() % num + 1;
  int tries = static_cast<int> (num * 0.4) == 0 ? 1 : static_cast<int> (num * 0.4);
  cout << "You have " << tries << " tries to guess where the shell is.\n";
  for (int i = 0; i < tries; i++)
  {
    if (shelper(num, box))
    {
      cout << "Correct!\n";
      break;
    } else
    {
      cout << "That is incorrect.\n";
      i + 1 == tries ? cout << "The shell is in box " << box << endl : cout << "You may try again.\n";
    }
  }
  return 0;
}

/* shell()
 * This is the shell game with code we learned in class
 */
int shell()
{
  srand(time(0));
  int num = 5;
  int box = rand() % num + 1;
  cout << "You have 2 tries to guess where the shell is.\n";
  int guess;
  cout << "Where is the shell? Choose box 1 - " << num << " > ";
  cin >> guess;
  if (guess == box)
  {
    cout << "Correct!\n";
  } else
  {
    cout << "That is incorrect.\nYou may try again.\nWhere is the shell? Choose box 1 - 5 > ";
    cin >> guess;
    if (guess == box)
    {
      cout << "Correct!\n";
    } else
    {
      cout << "That is incorrect.\nThe shell was in box " << box << endl;
    }
  }
  return 0;
}

/* fastFortune()
 * This is the fortune teller with less code.
 */
int fastFortune()
{
  srand(time(0));
  string question;
  string response[] =
  {
      "Not in your lifetime.",
      "Maybe next week.",
      "Yes!",
      "Nope. Never.",
      "Probably not.",
      "According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible."
  };
  int index = rand() % 6;
  cout << "What is your burning question? > ";
  cin >> question;
  cout << response[index];
  return 0;
}

/* fortune()
 * This is the fortune teller with code we learned in class
 */
int fortune()
{
  srand(time(0));
  string question;
  cout << "What is your burning question? > ";
  cin >> question;
  int index = rand() % 6;
  if (index == 0)
  {
    cout << "Not in your lifetime.";
  } else if (index == 1)
  {
    cout << "Maybe next week.";
  } else if (index == 2)
  {
    cout << "Yes!";
  } else if (index == 3)
  {
    cout << "Nope. Never.";
  } else if (index == 4)
  {
    cout << "Probably not.";
  } else if (index == 5)
  {
    cout << "According to all known laws of aviation, there is no way a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible.";
  }
  return 0;
}

int main()
{
//  fastShell();
  shell();
//  fastFortune();
  fortune();
  return 0;
}