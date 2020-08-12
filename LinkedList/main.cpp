
#include "LinkedList.hpp"

#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
  LinkedList<int> obj;
 obj.InsertLast(6);
  obj.InsertLast(8);
  obj.InsertLast(4);
  obj.InsertLast(3);

  obj.Print();

  //std::cout << "//////////////////////" << '\n';
 //obj.InsertFirst(11);

  //LinkedList<int> obj2(obj);

  LinkedList<int> obj3;
  //obj3 = obj;

  obj.Print();

  return 0;
}
