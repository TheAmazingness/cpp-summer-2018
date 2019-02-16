/*
 * G2
 * peng_week2_g.cpp
 * Tristan Peng
 * CLion
 */

#include <iostream>
#include <string>
using namespace std;

/* element()
 * @param string text[][4][2] A three-dimensional array for storing all of the story's information
 * main 'control center' for directing what to display.
 */
void element(string text[][4][2]);
/* display()
 * @param int num the index of the story block to be displayed.
 * @param string text[][4][2] A three-dimensional array for storing all of the story's information
 * displays the story block and returns the value of the next story block to be displayed.
 */
int display(int num, string text[][4][2]);

int main()
{
  string text[][4][2] =
  {
    {
      { "You need to write code to display an interactive non-linear story for your C++ class!" },
        { "Have an existential crisis", "1" },
        { "Think about how to write the code", "2" },
        { "" }
    },
    {
      { "You suddenly ponder all of your life choices and feel very vulnerable." },
        { "Meditate", "3" },
        { "Start thinking about the assignment", "2" },
        { "Get angry and smash your computer", "4" }
    },
    {
      { "\"Hmmm, how should I approach this assignment\", you think. After a good hard think, you decide to start writing." },
        { "Write code in MS Paint", "5" },
        { "Write code in an IDE", "6" },
        { "Write code on paper", "7" }
    },
    { { "After meditating for 40 days, you become Buddha." }, { "" }, { "" }, { "" } },
    {
      { "You get angry and smash your beloved computer. You cry for a long time." },
        { "Buy a new computer", "8" },
        { "Write code on paper", "7" },
        { "Meditate", "3" }
    },
    {
      { "You click on MS Paint to open. Unfortunately, because MS Paint is a Microsoft product, it refuses to open." },
        { "Get angry and smash your computer", "4" },
        { "Write code in an IDE", "6" },
        { "Write code on paper", "7" }
    },
    {
      { "You open your favorite IDE and start typing away. Sadly, as all programmers experience, you get a bug in your code." },
        { "Have an existential crisis", "1" },
        { "Get angry and smash your computer", "4" },
        {"Try to debug", "9" }
    },
    { { "You decide to write code on paper. You turn in your source file on Monday but it turns out that there are many bugs in the program. You get a less than satisfactory grade." }, { "" }, { "" }, { "" } },
    {
      { "You buy a new computer. Yay!" },
        { "Rethink the assignment", "2" },
        { "Write code in an IDE", "6" },
        { "Celebrate", "10" }
    },
    { { "After many excruciating hours of tedious debugging, you finally get the program working. You turn the assignment in and get an excellent score. Yay!" }, { "" }, { "" }, { "" } },
    {
      { "You want to celebrate!" },
        { "Invite some friends", "11" },
        { "Actually don't celebrate and start thinking about the assignment", "2" }, { "" } },
    {
      { "You invite some friends over. One of them makes fun of you." },
        { "Have an existential crisis", "1" },
        { "Get angry and smash your computer once more", "4" },
        { "Cry", "12" }
    },
    {
      { "You cry in front of everyone. They all ignore you." },
        { "Have an existential crisis", "1" }, { "Go somewhere else and start thinking about your assignment", "2" }, { "Shoo them all away", "13" }
    },
    {
      { "They all go away." },
        { "Start thinking about your assignment", "2" },
        { "Go away as well", "14" },
        { "Procrastinate on your assignment", "15" }
    },
    { { "You move to the other side of the planet. You did not turn in the assignment and thus received a 0." }, { "" }, { "" }, { "" } },
    { { "You try to procrastinate as long as possible." },
        { "Keep procrastinating", "16" },
        { "Have a party", "10" }, { "" }
    },
    { { "You procrastinated past the deadline and received a 0. RIP." }, { "" }, { "" }, { "" } },
  };
  element(text);
  return 0;
}

void element(string text[][4][2])
{
  int elem = 0;
  do
  {
    elem = display(elem, text);
  } while (elem != -1);
}

int display(int num, string text[][4][2])
{
  int input = 0;
  int index = 1;
  bool choice[3] = { !text[num][1][0].empty(), !text[num][2][0].empty(), !text[num][3][0].empty() };
  bool notEmpty = choice[0] || choice[1] || choice[2];
  string hr[] = { " _", " ‾" };
  for (int i = 0; i < text[num][0][0].length() + 1; ++i)
  {
    hr[0] += "_";
    hr[1] += "‾";
  }
  cout << "_____________________________________________________________________________"
      << endl << hr[0] << endl << "| " << text[num][0][0] << " |" << endl << hr[1] << endl;
  if (notEmpty)
  {
    cout << " __________" << endl << "| What do you do?\n";
  }
  if (choice[0])
  {
    cout << "| " << index << ". " << text[num][1][0] << endl;
    index++;
  }
  if (choice[1])
  {
    cout << "| " << index << ". " << text[num][2][0] << endl;
    index++;
  }
  if (choice[2])
  {
    cout << "| " << index << ". " << text[num][3][0] << endl;
    index++;
  }
  if (notEmpty)
  {
    cout << " ‾‾‾‾‾‾‾‾‾‾" << endl;
    while (input < 1 || input > index)
    {
      cout << "> Pick a choice: ";
      cin >> input;
    }
  }
  return input == 0 ? -1 : stoi(text[num][input][1]); // stoi(); is string to int. Similar to parseInt() in JS.
}
