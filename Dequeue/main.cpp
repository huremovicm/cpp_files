#include "dequeue.hpp"

int main(int argc, const char **argv)
{

    Dequeue<int> dequeue;
    dequeue.push_back(10);
    dequeue.push_back(2);
    dequeue.push_back(103);
    dequeue.push_back(1);
    dequeue.push_back(29);
    dequeue.push_back(36);

    std::cout << "---------------------------" << std::endl;
    std::cout << "After push_back:" << std::endl;
    dequeue.display();
    std::cout << "---------------------------" << std::endl;

    dequeue.push_front(1000);
    std::cout << "After push_front:" << std::endl;
    dequeue.display();
    std::cout << "---------------------------" << std::endl;

    dequeue.pop_front();
    std::cout << "After pop_front:" << std::endl;
    dequeue.display();
    std::cout << "---------------------------" << std::endl;

    dequeue.pop_back();
    std::cout << "After pop_back:" << std::endl;
    dequeue.display();
    std::cout << "---------------------------" << std::endl;

    std::cout << "Front: " << dequeue.front() << std::endl;
    std::cout << "---------------------------" << std::endl;

    std::cout << "Back: " << dequeue.back() << std::endl;
    std::cout << "---------------------------" << std::endl;

    std::cout << "Size: " << dequeue.size() << std::endl;
    std::cout << "---------------------------" << std::endl;

    return 0;
}