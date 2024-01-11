#include "doublylinkedlist.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
  DLList<int> dllist;

  dllist.add(40);
  dllist.add(112);
  dllist.add(50);
  dllist.add(20);
  dllist.add(2);
  dllist.add(13);

  dllist.add(200);
  dllist.add(160);

  std::cout << "In list:" << '\n';
  dllist.display();
  std::cout << "--------------" << std::endl;

  DLList<int> dllist2(dllist); // Copy constructor
  std::cout << "Testing find predicate find ex. number 40" << std::endl;
  auto it = dllist.find([](int a)
                        { return a == 40; });

  std::cout << "--------------" << std::endl;
  std::cout << "Find:" << '\n';
  std::cout << *it << std::endl;
  std::cout << "--------------" << std::endl;

  auto iter = dllist.begin() + 5;
  auto toPrintRemoved = *iter;
  dllist.remove(iter);
  std::cout << "After remove" << '\n';
  dllist.display();
  std::cout << "--------------" << std::endl;
  std::cout << "Removed:" << '\n';
  std::cout << toPrintRemoved << '\n';

  return 0;
}
