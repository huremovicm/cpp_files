#include "stack.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{

    Stack<int> v;

    v.push(5);
    v.push(10);
    v.push(3);
    v.push(1);

    std::cout << "On stack: " << '\n';

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';

    //////////////////////////////////////////////////////
    std::cout << "---------------------" << '\n';

    std::cout << "Top: " << v.top() << '\n';
    std::cout << "---------------------" << '\n';

    //////////////////////////////////////////////////////
    v.pop();
    std::cout << "After pop:" << '\n';

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
    std::cout << "---------------------" << '\n';

    //////////////////////////////////////////////////////
    std::cout << "Size of stack: " << v.size() << '\n';
    std::cout << "---------------------" << '\n';

    return 0;
}
