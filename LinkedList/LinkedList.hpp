#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <algorithm>
#include <iostream>

template <class T> struct Node {
  T data;
  Node<T> *next;
};

template <class T> class LinkedList {
private:
  Node<T> *_head;
  Node<T> *_tail;

public:
  LinkedList() : _head{nullptr}, _tail{nullptr} {}
  LinkedList(const LinkedList &);
  LinkedList &operator=(const LinkedList &);
  LinkedList(LinkedList &&);
  LinkedList &operator=(LinkedList &&);

  ~LinkedList();

  void Print();
  void InsertFirst(T);
  void InsertLast(T);

};

template <class T> LinkedList<T>::LinkedList(const LinkedList &other) {
  _head = nullptr;
  _tail = nullptr;

  Node<T> *temp = other._head;

  while (temp != nullptr) {
    InsertLast(temp->data);
    temp = temp->next;
  }
}

template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
  LinkedList tmp(rhs);

  std::swap(tmp._head, _head);
  std::swap(tmp._tail, _tail);

  return *this;
}

template <class T> LinkedList<T>::LinkedList(LinkedList &&other) {
  _head = other._head;
  _tail = other._tail;
  other._head = nullptr;
  other._tail = nullptr;
}

template <class T> LinkedList<T> &LinkedList<T>::operator=(LinkedList &&rhs) {
  _head = rhs._head;
  _tail = rhs._tail;
  rhs._head = nullptr;
  rhs._tail = nullptr;

  return &this;
}

template <class T> LinkedList<T>::~LinkedList() {
  Node<T> *tmp = _head;
  while (tmp != _tail) {
    Node<T> *next = tmp->next;
    delete tmp;
    tmp = next;
  }
  _head = nullptr;
  _tail = nullptr;

  std::cout << "Destructor!" << '\n';
}

template<class T>
void LinkedList<T>::InsertFirst(T first)
{
  Node<T> *tmp = new Node<T>;
  tmp->data = _head->data;
  tmp->next = _head->next;
  _head->data = first;
  _head->next = tmp;

}

template <class T> void LinkedList<T>::InsertLast(T last) {
  Node<T> *tmp = new Node<T>;
  tmp->data = last;
  tmp->next = nullptr;

  if (_head == nullptr) {
    _head = tmp;
    _tail = tmp;

  } else {
    _tail->next = tmp;
    _tail = _tail->next;
  }
}



template <class T> void LinkedList<T>::Print() {
  Node<T> *help = _head;
  while (help != nullptr) {
    std::cout << help->data << "\n";
    help = help->next;
  }
}

#endif
