#include "listArray.h"
#include <iostream>

int main(int argc, char const *argv[])
{

  ListArray<int> ob(100);

  std::cout << "push_back - test:" << '\n';
  ob.push_back(5);
  ob.push_back(3);
  ob.push_back(7);
  ob.push_back(9);
  ob.push_back(2);

  ob.print();
  std::cout << "--------------------------------------------------------"
            << '\n';
  std::cout << "addToLocation - test (location no.3):" << '\n';
  ob.addToLocation(3, 10);

  ob.print();
  std::cout << "--------------------------------------------------------"
            << '\n';

  std::cout << "removeFromLocation - test (location no.4):" << '\n';
  ob.removeFromLocation(4);

  ob.print();
  std::cout << "--------------------------------------------------------"
            << '\n';

  std::cout << "push_front - test: " << '\n';
  ob.push_front(100);

  ob.print();
  std::cout << "--------------------------------------------------------"
            << '\n';

  std::cout << "pop_front - test: " << '\n';
  ob.pop_front();

  ob.print();
  std::cout << "--------------------------------------------------------"
            << '\n';

  std::cout << "invert - test: " << '\n';
  ob.invert();

  ob.print();
  std::cout << "--------------------------------------------------------"
            << '\n';

  std::cout << "Element 9 index: " << ob.find(9) << '\n';

  ob.replace(3, 56);

  ob.print();
  std::cout << "--------------------------------------------------------"
            << '\n';

  return 0;
}
