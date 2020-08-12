#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include <stdexcept>
#include <iostream>

template <typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
        Node(const T &value) : next(nullptr), prev(nullptr), data(value) {}
    };
    Node *head_;
    Node *top_;
    int size_;

public:
    Queue() : size_(0){};

    void enqueue(const T &);
    void dequeue();
    T &front();
    int size();
    bool empty();

    void display();

    ~Queue();
};

template <typename T>
Queue<T>::~Queue()
{
    Node *tmp = head_;
    while (tmp != nullptr)
    {
        head_ = head_->next;
        delete tmp;
        tmp = head_;
    }
}

template <typename T>
bool Queue<T>::empty()
{

    bool toReturn = false;

    if (head_ == nullptr)
        toReturn = true;
    return toReturn;
}

template <typename T>
void Queue<T>::enqueue(const T &data)
{
    Node *tmp = new Node(data);

    if (empty())
    {
        head_ = new Node(data);
        top_ = head_;
    }
    else
    {

        top_->next = tmp;
        tmp->prev = top_;
        top_ = tmp;
        tmp = nullptr;
    }

    ++size_;
}

template <typename T>
void Queue<T>::dequeue()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty!");
    }
    else
    {
        Node *toDelete = head_;
        head_ = head_->next;
        head_->prev = nullptr;
        delete toDelete;
    }
    --size_;
}

template <typename T>
T &Queue<T>::front()
{
    return head_->data;
}

template <typename T>
int Queue<T>::size()
{
    return size_;
}

template <typename T>
void Queue<T>::display()
{
    auto tmp = top_;
    while (tmp != nullptr)
    {
        std::cout << tmp->data << " ";
        tmp = tmp->prev;
    }
    std::cout << std::endl;
    std::cout << "------------------" << std::endl;
}

#endif // !QUEUE_HPP_