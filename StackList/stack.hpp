#ifndef STACK_HPP_
#define STACK_HPP_

#include <stdexcept>
#include <iostream>

template <typename T>
class Stack
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
    Stack() : size_(0){};

    void push(const T &);
    void pop();
    T &top();
    int size();
    bool empty();

    void display();

    ~Stack();
};

template <typename T>
Stack<T>::~Stack()
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
bool Stack<T>::empty()
{

    bool toReturn = false;

    if (head_ == nullptr)
        toReturn = true;
    return toReturn;
}

template <typename T>
void Stack<T>::push(const T &data)
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
void Stack<T>::pop()
{
    if (empty())
    {
        throw std::out_of_range("Stack is empty!");
    }
    else
    {
        Node *toDelete = top_;
        top_ = top_->prev;
        top_->next = nullptr;
        delete toDelete;
    }
    --size_;
}

template <typename T>
T &Stack<T>::top()
{
    return top_->data;
}

template <typename T>
int Stack<T>::size()
{
    return size_;
}

template <typename T>
void Stack<T>::display()
{
    auto tmp = top_;
    while (tmp != nullptr)
    {
        std::cout << tmp->data << std::endl;
        tmp = tmp->prev;
    }
    std::cout << std::endl;
    std::cout << "------------------" << std::endl;
}

#endif // !STACK_HPP_