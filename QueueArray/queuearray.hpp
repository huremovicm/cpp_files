#ifndef QUEUEARRAY_HPP_
#define QUEUEARRAY_HPP_

#include <iostream>
#include <stdexcept>

template <typename T>
class Queuearray
{
private:
    int capacity_;
    int top_idx;
    T *data;
    T element;

public:
    Queuearray(const T &element) : capacity_(5), top_idx(-1), data(new T[capacity_]){};

    void enqueue(const T &);
    void dequeue();
    T &front();
    int size();
    bool empty();

    void display();

    void realocate(int);

    ~Queuearray();
};

template <typename T>
Queuearray<T>::~Queuearray()
{
    delete[] data;
}

template <typename T>
void Queuearray<T>::realocate(int new_size)
{
    T *new_array = new T[new_size];

    for (int i = 0; i < top_idx; i++)
    {
        new_array[i] = data[i];
    }

    delete[] data;
    data = new_array;
    capacity_ = size();
}

template <typename T>
int Queuearray<T>::size()
{
    return top_idx + 1;
}

template <typename T>
void Queuearray<T>::enqueue(const T &element)
{
    ++top_idx;

    if (top_idx == capacity_)
    {
        realocate(capacity_ + capacity_ / 2);
    }
    data[top_idx] = element;
}

template <typename T>
T &Queuearray<T>::front()
{
    return data[0];
}

template <typename T>
void Queuearray<T>::dequeue()
{

    if (empty())
    {
        throw std::underflow_error("Empty queue!");
    }
    else
    {
        T *tmp = new T[top_idx];
        for (size_t i = 0, j = 1; j <= top_idx; i++, j++)
        {
            tmp[i] = data[j];
        }
        top_idx = top_idx - 1;
        data = tmp;
    }
}

template <typename T>
void Queuearray<T>::display()
{

    for (int i = top_idx; i >= 0; i--)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
bool Queuearray<T>::empty()
{
    if (!size())
        return true;
    else
        return false;
}

#endif // !QUEUEARRAY_HPP_
