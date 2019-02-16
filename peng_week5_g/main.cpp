/*
 * GP5
 * main.cpp
 * Tristan Peng
 * CLion
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Scene.h"
using namespace std;

void parse(const string &file, vector<Scene> &s);
vector<int> parseHelper(ifstream &f, Scene &s);
void display(vector<Scene> s);

int main()
{
  const string FILENAME = "../story.txt";
  vector<Scene> s;
  parse(FILENAME, s);
  display(s);
  return 0;
}

void parse(const string &file, vector<Scene> &s)
{
  static int index = 0;
  ifstream f (file);
  vector<vector<int>> pointers;
  do
    {
    Scene scene;
    s.push_back(scene);
    pointers.push_back(parseHelper(f, s[index]));
    index++;
  } while (f.peek() != -1);
  for (int i = 0; i < s.size(); ++i)
  {
    for (auto &pointer : pointers)
    {
      for (auto k : pointer)
      {
        if (k < s.size())
        {
          s[i].setPointer(&s[k]);
        }
        else
        {
          s[i].setPointer(nullptr);
        }
      }
    }
  }
}

vector<int> parseHelper(ifstream &f, Scene &s)
{
  vector<string> scene, choices;
  vector<int> next;
  string sscene, temp;
  int at;
  int i1 = -1;
  do
  {
    i1++;
    scene.push_back("");
    getline(f, scene[i1]);
    sscene += scene[i1] + "\n";
  } while (!scene[i1].empty());
  s.setDescription(sscene);
  for (int i = 0; i < 3; ++i)
  {
    choices.push_back("");
    next.push_back(-1);
    string tempInt;
    at = f.get();
    getline(f, choices[i]);
    getline(f, temp);
    getline(f, tempInt);
    next[i] = stoi(tempInt) - 1;
    getline(f, temp);
    if (next[i] == -2)
    {
      choices.pop_back();
      next.pop_back();
      break;
    }
  }
  s.setChoices(choices);
  getline(f, temp);
  return next;
}

void display(vector<Scene> s)
{
  int choice;
  cout << s[0].getDescription() << s[0].getChoices() << "\nChoose: ";
  cin >> choice;
  Scene *point = s[0].getPointer()[choice - 1];
  while (point != nullptr)
  {
    cout << choice - 1 << point << endl;
    cout << endl << point -> getDescription() << point -> getChoices() << "\nChoose: ";
    cin >> choice;
    point = point -> getPointer()[choice - 1];
  }
  cout << endl << "The story ended. Thanks!" << endl;
}