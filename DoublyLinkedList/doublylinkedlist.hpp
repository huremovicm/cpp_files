#ifndef _DOUBLYLINKEDLIST_HPP
#define _DOUBLYLINKEDLIST_HPP

#include "node.hpp"
#include <iostream>

template <typename T>
class DLList
{
public:
  DLList();
  DLList(const DLList &);
  DLList(DLList &&);
  DLList &operator=(const DLList &);
  DLList &operator=(DLList &&);
  ~DLList();

  void add(const T &);
  void display();

  class Iterator;
  Iterator begin() { return Iterator(head_); };
  Iterator end() { return Iterator(tail_); };

  template <typename U>
  Iterator find(U);

  void remove(Iterator);

private:
  Node<T> *head_;
  Node<T> *tail_;
  int listSize;
};

template <typename T>
class DLList<T>::Iterator
{
public:
  Iterator() = default;
  Iterator(Node<T> *node) : currentNode{node} {}

  Iterator &operator=(Node<T> *pNode)
  {
    this->currentNode = pNode;
    return *this;
  }

  //Increment
  //Prefix
  Iterator &operator++()
  {
    if (currentNode)
      currentNode = currentNode->next;
    return *this;
  }

  //Postfix
  Iterator operator++(int)
  {
    Iterator iterator = *this;
    ++*this;
    return iterator;
  }

  Iterator operator+(int pos)
  {
    auto i = 0;
    if (currentNode)
    {
      while (i < pos)
      {
        currentNode = currentNode->next;
        i++;
      }
    }
    return *this;
  }

  Iterator operator-(int pos)
  {
    auto i = 0;
    if (currentNode)
    {
      while (i < pos)
      {
        currentNode = currentNode->prev;
        i++;
      }
    }
    return *this;
  }

  //Decrement
  //Prefix
  Iterator &operator--()
  {
    if (currentNode)
      currentNode = currentNode->prev;
    return *this;
  }

  //Postfix
  Iterator operator--(int)
  {
    Iterator iterator = *this;
    --*this;
    return iterator;
  }

  bool operator!=(const Iterator &iterator)
  {
    return currentNode != iterator.currentNode;
  }

  bool operator==(const Iterator &iterator)
  {
    return currentNode == iterator.currentNode;
  }

  int operator*()
  {
    return currentNode->data;
  }

  friend class DLList<T>;

private:
  Node<T> *currentNode;
};

//Default constructor
template <typename T>
DLList<T>::DLList()
{
  head_ = nullptr;
  tail_ = nullptr;
  listSize = 0;
}

//Destructor
template <typename T>
DLList<T>::~DLList()
{
  Node<T> *tmp = head_;
  Node<T> *toDelete;
  while (tmp != nullptr)
  {
    toDelete = tmp;
    delete toDelete;
    tmp = tmp->next;
  }
  delete head_;
  delete tail_;
}

//Copy constructor
template <typename T>
DLList<T>::DLList(const DLList<T> &other)
{
  if (other.head_ == nullptr)
  {
    head_ = nullptr;
    tail_ = nullptr;
    listSize = 0;

    throw std::range_error("List is empty!");
  }
  else
  {
    head_ = new Node<T>(other.head_->data);
    Node<T> *tmpOther = other.head_->next;
    Node<T> *tmp = head_;

    while (tmpOther != nullptr)
    {
      tmp->next = new Node<T>(tmpOther->data);
      tmp = tmp->next;
      tmpOther = tmpOther->next;
    }
    tail_ = tmp;
  }
}

//Move constructor
template <typename T>
DLList<T>::DLList(DLList<T> &&other)
{
  if (other.head_ == nullptr)
  {
    head_ = nullptr;
    tail_ = nullptr;
    listSize = 0;
    throw std::range_error("List is empty!");
  }
  else
  {
    head_ = other.head_;
    tail_ = other.tail_;
    listSize = other.listSize;

    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.listSize = 0;
  }
}

//Copy operator =
template <typename T>
DLList<T> &DLList<T>::operator=(const DLList<T> &other)
{
  if (other.head_ == nullptr)
  {
    head_ = nullptr;
    tail_ = nullptr;
    listSize = 0;
  }
  else
  {
    head_ = new Node<T>(other.head_);
    Node<T> *tmp = head_;
    Node<T> *tmpOther = head_->next;
    while (other.head_ == nullptr)
    {
      tmp->next = new Node<T>(tmpOther, tmp, nullptr);
      tmp = tmp->next;
      tmpOther = tmpOther->next;
    }
    tail_ = tmp;
  }

  return *this;
}

//Move operator =
template <typename T>
DLList<T> &DLList<T>::operator=(DLList<T> &&other)
{
  if (other.head_ == nullptr)
  {
    head_ = nullptr;
    tail_ = nullptr;
    listSize = 0;
    throw std::range_error("List is empty!");
  }
  else
  {
    head_ = other.head_;
    tail_ = other.tail_;
    listSize = other.listSize;

    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.listSize = 0;
  }
}

//Add
template <typename T>
void DLList<T>::add(const T &data)
{
  Node<T> *newNode = new Node<T>(data);

  Node<T> *current;

  if (head_ == nullptr)
  {
    head_ = newNode;
    tail_ = head_;
  }
  else if (head_->data >= newNode->data)
  {
    newNode->next = head_;
    newNode->next->prev = newNode;
    head_ = newNode;
  }
  else
  {
    current = head_;

    while (current->next != nullptr && current->next->data < newNode->data)
      current = current->next;

    newNode->next = current->next;

    if (current->next != nullptr)
      newNode->next->prev = newNode;

    current->next = newNode;
    newNode->prev = current;
  }
  auto tmp = head_;
  Node<T> *hold;
  while (tmp != nullptr)
  {
    hold = tmp;
    tail_ = hold;
    tmp = tmp->next;
  }
}

//Find
template <typename T>
template <typename U>
typename DLList<T>::Iterator DLList<T>::find(U predicate)
{
  DLList<T>::Iterator toReturn = this->end();
  toReturn--;

  for (DLList<T>::Iterator it = this->begin(); it != this->end(); it++)
  {
    if (predicate(*it))
      return toReturn = it;
  }

  return toReturn;
}

//Remove
template <typename T>
void DLList<T>::remove(DLList<T>::Iterator it)
{

  Node<T> *holdForDelete;
  auto tmp = head_;

  while (tmp != nullptr)
  {
    if (tmp->data == *it)
    {
      holdForDelete = tmp;
    }
    tmp = tmp->next;
  }

  if (head_ == holdForDelete)
    head_ = holdForDelete->next;

  if (holdForDelete->next != nullptr)
  {
    holdForDelete->next->prev = holdForDelete->prev;
  }

  if (holdForDelete->prev != nullptr)
  {
    holdForDelete->prev->next = holdForDelete->next;
  }
  if (holdForDelete == tail_)
  {
    tail_ = tail_->prev;
  }

  delete holdForDelete;
}

//Display
template <typename T>
void DLList<T>::display()
{
  Node<T> *tmp;
  tmp = head_;
  while (tmp != nullptr)
  {
    std::cout << tmp->data << "  ";
    tmp = tmp->next;
  }
  std::cout << '\n';
  std::cout << "--------------" << std::endl;
  std::cout << "Tail data:" << '\n';
  std::cout << tail_->data << '\n';
}

#endif
