#ifndef STACK_DATA_STRUCTURE_H
#define STACK_DATA_STRUCTURE_H

#include "../../util/util.h"

// a stack can be implemented as an array

class MyStack
{
private:
    int m_top{ -1 };

public:
    std::array<int, util::arraySize> m_array{};
    
    MyStack() = default;

    bool isEmpty() const;
    void push(int newValue);
    int pop();
};

bool MyStack::isEmpty() const
{
    if (m_top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MyStack::push(int newValue)
{
    ++m_top;
    m_array[m_top] = newValue;
}

int MyStack::pop()
{
    if (isEmpty())
    {
        std::cerr << "The stack is empty\n";
        return -1;
    }
    else
    {
        --m_top;
        return m_array[m_top + 1];
    }
}

#endif
