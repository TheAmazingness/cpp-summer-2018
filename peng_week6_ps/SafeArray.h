/*
 * PS6
 * SafeArray.h
 * Tristan Peng
 * CLion
 */
#pragma once
#include <initializer_list>
#include <vector>
using namespace std;

class SafeArray
{
  private:
    int *arr, m_size;
  public:
    SafeArray();
    SafeArray(const SafeArray &s);
    SafeArray(initializer_list<int> s);
    ~SafeArray();
    void addItems(int howMany, int value = 0);
    void removeItems(int howMany, int start = -1);
    int at(int index) const;
    void put(int index, int data);
    void put(int index, int *data, int howMany);
    void copyTo(vector<int> &v);
    int size() const;
    void clear();
};