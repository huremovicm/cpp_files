#include "queuearray.hpp"

int main(int argc, const char **argv)
{

    Queuearray<int> queuearray(3);
    queuearray.enqueue(10);
    queuearray.enqueue(5);
    queuearray.enqueue(2);
    queuearray.enqueue(11);
    queuearray.enqueue(99);
    queuearray.enqueue(6);
    queuearray.enqueue(12);

    std::cout << "After enqueue:" << std::endl;
    queuearray.display();
    std::cout << "------------------" << std::endl;

    std::cout << "Size: " << queuearray.size() << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "Front: " << queuearray.front() << std::endl;
    std::cout << "------------------" << std::endl;

    queuearray.dequeue();
    std::cout << "After dequeue:" << std::endl;
    queuearray.display();

    std::cout << "------------------" << std::endl;
    std::cout << "Size: " << queuearray.size() << std::endl;
    std::cout << "------------------" << std::endl;

    return 0;
}