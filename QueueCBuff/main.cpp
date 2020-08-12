#include "queuecbuff.hpp"

int main(int argc, const char **argv)
{

    Queuecbuff<int> queuecbuff;
    queuecbuff.enqueue(10);
    queuecbuff.enqueue(11);
    queuecbuff.enqueue(14);
    queuecbuff.enqueue(12);
    queuecbuff.enqueue(223);
    queuecbuff.enqueue(18);

    std::cout << "After enqueue:" << std::endl;
    queuecbuff.display();
    std::cout << "------------------" << std::endl;

    std::cout << "Size: " << queuecbuff.size() << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "Front: " << queuecbuff.front() << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << "Rear: " << queuecbuff.rear() << std::endl;
    std::cout << "------------------" << std::endl;

    queuecbuff.dequeue();
    std::cout << "After dequeue:" << std::endl;
    queuecbuff.display();

    std::cout << "------------------" << std::endl;
    std::cout << "Size: " << queuecbuff.size() << std::endl;
    std::cout << "------------------" << std::endl;

    return 0;
}