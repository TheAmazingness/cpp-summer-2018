/*
 * GP5
 * Scene.h
 * Tristan Peng
 * CLion
 */
#pragma once
#include <string>
#include <vector>
using namespace std;

class Scene
{
  private:
    string title;
    string description;
    vector<string> choices;
    vector<Scene *> pointers;
  public:
    Scene();
    string getDescription() const;
    string getChoices() const;
    vector<Scene *> getPointer() const;
    void setDescription(string d);
    void setChoices(vector<string> c);
    void setPointer(Scene *p);
};