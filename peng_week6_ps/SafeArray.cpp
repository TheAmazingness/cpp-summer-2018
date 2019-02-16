/*
 * PS6
 * SafeArray.cpp
 * Tristan Peng
 * CLion
 */
#include <iostream>
#include <vector>
#include "SafeArray.h"
using namespace std;

SafeArray::SafeArray()
{
  arr = new int[0];
  m_size = 0;
};

SafeArray::SafeArray(const SafeArray &s)
{
  arr = new int[s.m_size];
  m_size = s.m_size;
  for (int i = 0; i < m_size; ++i)
  {
    arr[i] = s.arr[i];
  }
}

SafeArray::SafeArray(initializer_list<int> s)
{
  vector<int> temp = s;
  arr = new int[temp.size()];
  for (int i = 0; i < temp.size(); i++)
  {
    arr[i] = temp[i];
  }
  m_size = static_cast<int> (temp.size());
}

SafeArray::~SafeArray()
{
  delete[] arr;
}

void SafeArray::addItems(int howMany, int value)
{
  int *temp = new int[m_size];
  for (int i = 0; i < m_size; ++i)
  {
    temp[i] = arr[i];
  }
  delete[] arr;
  arr = new int[m_size + howMany];
  for (int i = 0; i < m_size + howMany; ++i)
  {
    if (i < m_size)
    {
      arr[i] = temp[i];
    }
    else
    {
      arr[i] = value;
    }
  }
  m_size += howMany;
}

void SafeArray::removeItems(int howMany, int start)
{
  if (start >= 0 && start + howMany <= m_size)
  {
    int *temp = new int[m_size - howMany], index = 0;
    for (int i = 0; i < m_size; i++)
    {
      if (i < start || i >= start + howMany)
      {
        temp[index] = arr[i];
        index++;
      }
    }
    delete[] arr;
    m_size -= howMany;
    arr = new int[m_size];
    for (int i = 0; i < m_size; ++i)
    {
      arr[i] = temp[i];
    }
  }
  else if (start < 0 && howMany <= m_size)
  {
    int *temp = new int[m_size - howMany];
    for (int i = 0; i < m_size - howMany; i++)
    {
      temp[i] = arr[i];
    }
    delete[] arr;
    m_size -= howMany;
    arr = new int[m_size];
    for (int i = 0; i < m_size; ++i)
    {
      arr[i] = temp[i];
    }
  }
}

int SafeArray::at(int index) const
{
  if (index >= m_size)
  {
    throw "Error: Index out of bounds.";
  }
  return arr[index];
}

void SafeArray::put(int index, int data)
{
  if (index >= m_size)
  {
    throw "Error: Index out of bounds.";
  }
  int *temp = new int[m_size], i1 = 0;
  for (int i = 0; i < m_size; ++i)
  {
    temp[i] = arr[i];
  }
  delete[] arr;
  m_size++;
  arr = new int[m_size];
  for (int i = 0; i < m_size; i++)
  {
    if (i != index)
    {
      arr[i] = temp[i1];
      i1++;
    }
    else
    {
      arr[i] = data;
    }
  }
}

void SafeArray::put(int index, int *data, int howMany)
{
  if (index >= m_size)
  {
    throw "Error: Index out of bounds.";
  }
  int *temp = new int[m_size], i1 = 0, i2 = 0;
  for (int i = 0; i < m_size; ++i)
  {
    temp[i] = arr[i];
  }
  delete[] arr;
  m_size += howMany;
  arr = new int[m_size];
  for (int i = 0; i < m_size; ++i)
  {
    if (i >= index && i <= howMany)
    {
      arr[i] = data[i2];
      i2++;
    }
    else
    {
      arr[i] = temp[i1];
      i1++;
    }
  }
}

void SafeArray::copyTo(vector<int> &v)
{
  for (int i = 0; i < m_size; ++i)
  {
    v.push_back(arr[i]);
  }
}

int SafeArray::size() const
{
  return m_size;
}

void SafeArray::clear()
{
  delete[] arr;
  arr = new int[0];
  m_size = 0;
}