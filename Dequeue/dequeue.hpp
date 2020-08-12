#ifndef DEQUEUE_HPP_
#define DEQUEUE_HPP_

#include <list>
#include <stdexcept>
#include <iostream>

template <typename T>
class Dequeue
{
private:
    T front_;
    T back_;
    int size_;
    std::list<T> container_;

public:
    Dequeue() : size_(0){};
    void push_front(const T &);
    void push_back(const T &);
    void pop_back();
    void pop_front();
    T &front();
    T &back();
    int size();
    bool empty();

    void display();

    ~Dequeue() = default;
};

template <typename T>
void Dequeue<T>::push_front(const T &element)
{
    container_.push_front(element);
    ++size_;
}

template <typename T>
void Dequeue<T>::push_back(const T &element)
{
    container_.push_back(element);
    ++size_;
}

template <typename T>
void Dequeue<T>::pop_front()
{
    if (empty())
    {
        throw std::underflow_error("Dequeue is empty!");
    }
    else
    {
        container_.pop_front();
        --size_;
    }
}

template <typename T>
void Dequeue<T>::pop_back()
{
    if (empty())
    {
        throw std::underflow_error("Dequeue is empty!");
    }
    else
    {
        container_.pop_back();
        --size_;
    }
}

template <typename T>
T &Dequeue<T>::front()
{
    if (empty())
    {
        throw std::underflow_error("Dequeue is empty!");
    }
    else
    {
        front_ = container_.front();
        return front_;
    }
}

template <typename T>
T &Dequeue<T>::back()
{
    if (empty())
    {
        throw std::underflow_error("Dequeue is empty!");
    }
    else
    {
        back_ = container_.back();
        return back_;
    }
}

template <typename T>
int Dequeue<T>::size()
{
    return size_;
}

template <typename T>
bool Dequeue<T>::empty()
{
    if (!size_)
        return true;
    else
        return false;
}

template <typename T>
void Dequeue<T>::display()
{
    for (auto it = container_.rbegin(); it != container_.rend(); it++)
    {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

#endif // !DEQUEUE_HPP_
