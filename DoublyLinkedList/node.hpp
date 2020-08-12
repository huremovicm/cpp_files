#ifndef NODE_HPP_
#define NODE_HPP_

template <typename T>
class Node
{
public:
  T data;
  Node *prev;
  Node *next;
  Node(const T &element) : data(element), prev(nullptr), next(nullptr) {}
};

#endif
