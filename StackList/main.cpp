#include "stack.hpp"

int main(int argc, const char **argv)
{

    Stack<int> stack;
    stack.push(4);
    stack.push(78);
    stack.push(12);
    stack.push(45);
    stack.push(11);

    std::cout << "------------------" << std::endl;
    std::cout << "After push: " << std::endl;
    stack.display();

    stack.pop();
    std::cout << "After pop: " << std::endl;

    stack.display();

    std::cout << "Top:" << std::endl;
    std::cout << stack.top() << std::endl;
    std::cout << "------------------" << std::endl;

    std::cout << "Size:" << std::endl;
    std::cout << stack.size() << std::endl;
    std::cout << "------------------" << std::endl;

    return 0;
}