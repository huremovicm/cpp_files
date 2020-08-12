#include "queue.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
    Queue<int> queue;
    queue.enqueue(5);
    queue.enqueue(56);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(200);

    std::cout << "------------------" << std::endl;
    std::cout << "After enqueue: " << std::endl;
    queue.display();

    queue.dequeue();
    std::cout << "After dequeue: " << std::endl;

    queue.display();

    std::cout << "Front:" << std::endl;
    std::cout << queue.front() << std::endl;
    std::cout << "------------------" << std::endl;

    std::cout << "Size:" << std::endl;
    std::cout << queue.size() << std::endl;
    std::cout << "------------------" << std::endl;

    return 0;
}
