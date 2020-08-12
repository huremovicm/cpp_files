#include <vector>

template <typename T>
class Stack
{
public:
    Stack() = default;

    void push(const T &);
    void pop();
    T &top();
    int size();
    bool empty();

    T &operator[](T);

    ~Stack() = default;

private:
    T top_;
    std::vector<T> container_;
};

template <typename T>
T &Stack<T>::operator[](T b)
{
    return container_[b];
}

template <typename T>
void Stack<T>::push(const T &obj)
{
    container_.push_back(obj);
    top_ = obj;
}

template <typename T>
void Stack<T>::pop()
{

    container_.pop_back();
}


template <typename T>
T &Stack<T>::top()
{
    return top_;
}


template <typename T>
int Stack<T>::size()
{
    return container_.size();
}


template <typename T>
bool Stack<T>::empty()
{
    auto toReturn = true;
    if (container_.size() == 0)
        toReturn = false;

    return toReturn;
}
