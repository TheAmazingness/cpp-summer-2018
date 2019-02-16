/*
 * GP5
 * Scene.cpp
 * Tristan Peng
 * CLion
 */
#include <string>
#include <vector>
#include "Scene.h"
using namespace std;

Scene::Scene() {}

string Scene::getChoices() const
{
  string temp;
  for (const auto &i : choices)
  {
    temp += i + "\n";
  }
  return temp;
}

string Scene::getDescription() const
{
  return description;
}

vector<Scene *> Scene::getPointer() const
{
  return pointers;
}

void Scene::setDescription(const string d)
{
  description = d;
}

void Scene::setChoices(const vector<string> c)
{
  choices = c;
}

void Scene::setPointer(Scene *p)
{
  pointers.push_back(p);
}