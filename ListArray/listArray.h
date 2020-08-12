#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class ListArray
{
private:
  T *elements;
  int sizeList;
  int maxsizeList;

public:
  ListArray(int n = 100);
  ListArray(const ListArray<T> &List);
  const ListArray<T> &operator=(const ListArray<T> &);
  bool empty() const;
  bool full() const;
  int sizeL() const { return sizeList; }
  int maxsizeL() const { return maxsizeList; }
  void print() const;
  T &getElement(int location);
  ~ListArray(void) { delete[] elements; }

  // 1
  ListArray<T> &push_back(const T &objAdd);
  ListArray<T> &pop_back();
  // 2
  ListArray<T> &addToLocation(int location, const T &objAdd);
  ListArray<T> &removeFromLocation(int location);
  // 3
  ListArray<T> &push_front(const T &objAdd);
  ListArray<T> &pop_front();
  // 4
  ListArray<T> &invert();
  // 5
  int find(const T &obj); // Return index of element
  ListArray<T> &replace(const T &old, const T &objNew);
};

template <typename T>
ListArray<T>::ListArray(int n)
{
  n < 0 ? maxsizeList = 100 : maxsizeList = n;
  sizeList = 0;
  elements = new T[maxsizeList];
}

template <typename T>
ListArray<T>::ListArray(const ListArray<T> &List)
{
  maxsizeList = List.maxsizeL();
  sizeList = List.sizeL();
  elements = new T[maxsizeList];
  for (int i = 0; i < sizeList; i++)
    elements[i] = List.elements[i];
}

template <typename T>
const ListArray<T> &ListArray<T>::operator=(const ListArray<T> &otherList)
{
  if (this != &otherList)
  {
    delete[] elements;
    maxsizeList = otherList.maxsizeL();
    sizeList = otherList.sizeL();
    elements = new T[maxsizeL()];
    for (int i = 1; i < sizeList; i++)
      elements[i] = otherList.elements[i];
  }
  return *this;
}

template <typename T>
bool ListArray<T>::empty() const { return (sizeList == 0); }

template <typename T>
bool ListArray<T>::full() const
{
  return (sizeList == maxsizeList);
}

template <typename T>
void ListArray<T>::print() const
{
  for (int i = 0; i < sizeList; i++)
    cout << elements[i] << " ";
  cout << endl;
}

template <typename T>
T &ListArray<T>::getElement(int location)
{
  if (location < 0 || location >= sizeList)
    throw out_of_range("Incorrect index!");
  else
    return elements[location];
}

// 1
template <typename T>
ListArray<T> &ListArray<T>::push_back(const T &objAdd)
{
  sizeList++;
  if (empty())
  {
    elements[0] = objAdd;
  }
  else
  {
    elements[sizeList - 1] = objAdd;
  }

  return *this;
}

template <typename T>
ListArray<T> &ListArray<T>::pop_back()
{
  if (sizeList == 0)
    std::cout << "List is empty!" << std::endl;
  sizeList = sizeList - 1;
  return *this;
}

// 2
template <typename T>
ListArray<T> &ListArray<T>::addToLocation(int location, const T &objAdd)
{

  ListArray<T> newArray;
  newArray.sizeList = sizeList + 1;

  for (int i = 0, j = 0; i < newArray.sizeList; j++, i++)
  {
    if (i == location - 1)
    {
      newArray.elements[i] = objAdd;
      j--;
    }
    else
    {
      newArray.elements[i] = elements[j];
    }
  }
  sizeList = newArray.sizeList;
  for (size_t i = 0; i < sizeList; i++)
  {
    elements[i] = newArray.elements[i];
  }

  return *this;
}

template <typename T>
ListArray<T> &ListArray<T>::removeFromLocation(int location)
{
  if (this->sizeL() == 0)
    std::cout << "List is empty!" << '\n';

  ListArray<T> newList;
  newList.sizeList = sizeList - 1;

  for (size_t i = 0, j = 0; i < newList.sizeList; i++, j++)
  {
    if (i == location - 1)
    {
      newList.elements[i] = elements[i + 1];
      j = j + 1;
    }
    else
    {
      newList.elements[i] = elements[j];
    }
  }

  sizeList = newList.sizeList;
  for (size_t i = 0; i < sizeList; i++)
  {
    elements[i] = newList.elements[i];
  }

  return *this;
}

// 3
template <typename T>
ListArray<T> &ListArray<T>::push_front(const T &objAdd)
{

  ListArray<T> newList;
  newList.sizeList = sizeList + 1;

  for (size_t i = 1, j = 0; i < newList.sizeList; i++, j++)
  {
    newList.elements[i] = elements[j];
  }

  newList.elements[0] = objAdd;

  sizeList = newList.sizeList;

  for (size_t i = 0; i < sizeList; i++)
  {
    elements[i] = newList.elements[i];
  }

  return *this;
}

template <typename T>
ListArray<T> &ListArray<T>::pop_front()
{
  ListArray<T> newList;
  newList.sizeList = sizeList - 1;

  for (size_t i = 0, j = 1; i < newList.sizeList; i++, j++)
  {
    newList.elements[i] = elements[j];
  }

  sizeList = newList.sizeList;

  for (size_t i = 0; i < sizeList; i++)
  {
    elements[i] = newList.elements[i];
  }

  return *this;
}

// 4
template <typename T>
ListArray<T> &ListArray<T>::invert()
{
  ListArray<T> newList;
  newList.sizeList = sizeList;

  for (size_t i = 0, j = sizeList - 1; i < sizeList;
       i++, j--)
  {

    newList.elements[i] = elements[j];
  }

  for (size_t i = 0; i < sizeList; i++)
  {
    elements[i] = newList.elements[i];
  }

  return *this;
}

// 5
template <typename T>
int ListArray<T>::find(const T &obj)
{
  int tmp = 0;
  for (size_t i = 0; i < sizeList; i++)
  {
    if (elements[i] == obj)
      tmp = i;
  }

  return tmp;
}

template <typename T>
ListArray<T> &ListArray<T>::replace(const T &old, const T &objNew)
{
  for (size_t i = 0; i < sizeList; i++)
  {
    if (elements[i] == old)
      elements[i] = objNew;
  }

  return *this;
}
