#ifndef QUEUECBUFF_HPP_
#define QUEUECBUFF_HPP_

#include <iostream>
#include <stdexcept>

template <typename T>
class Queuecbuff
{
private:
    int capacity_;
    int frontel_;
    int rear_;
    T *data_;
    T element_;

public:
    Queuecbuff() : capacity_(10), frontel_(-1), rear_(-1), data_(new T[capacity_]){};

    void enqueue(const T &);
    void dequeue();
    T &front();
    T &rear();
    int size();
    bool empty();

    void display();

    ~Queuecbuff();
};

template <typename T>
Queuecbuff<T>::~Queuecbuff()
{
    delete[] data_;
}

template <typename T>
int Queuecbuff<T>::size()
{
    return rear_ + 1;
}

template <typename T>
void Queuecbuff<T>::enqueue(const T &element_)
{
    if ((frontel_ == 0 && rear_ == capacity_) || (rear_ + 1 == frontel_))
    {
        throw std::overflow_error("Overflow!");
    }
    else
    {
        if (rear_ == -1)
        {
            frontel_ = 0;
            rear_ = 0;
        }
        else if (rear_ == capacity_ - 1)
            rear_ = 0;
        else
            ++rear_;
        data_[rear_] = element_;
    }
}

template <typename T>
T &Queuecbuff<T>::front()
{
    return data_[frontel_];
}

template <typename T>
T &Queuecbuff<T>::rear()
{
    return data_[rear_];
}

template <typename T>
void Queuecbuff<T>::dequeue()
{

    int tmp;

    if (empty())
    {
        throw std::underflow_error("Empty queue!");
    }
    else
    {
        T *tmp = new T[rear_];
        for (size_t i = 0, j = 1; j <= rear_; i++, j++)
        {
            tmp[i] = data_[j];
        }
        rear_ = rear_ - 1;
        data_ = tmp;
    }
}

template <typename T>
void Queuecbuff<T>::display()
{

    for (int i = rear_; i >= 0; i--)
    {
        std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool Queuecbuff<T>::empty()
{
    if (!size())
        return true;
    else
        return false;
}

#endif // !QUEUECBUFF_HPP_