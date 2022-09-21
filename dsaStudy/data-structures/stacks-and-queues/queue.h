#ifndef QUEUE_DATA_STRUCTURE_H
#define QUEUE_DATA_STRUCTURE_H

#include "../../util/util.h"

class MyQueue
{
private:
    std::array<int, util::arraySize> m_array{};
    int m_head{ 0 };
    int m_tail{ 0 };

public:
    MyQueue() = default;

    void enqueue(int newValue);
    int dequeue();
};

void MyQueue::enqueue(int newValue)
{
    m_array[m_tail] = newValue;
    if (m_tail == m_array.size())
    {
        m_tail = 0;
    }
    else
    {
        ++m_tail;
    }
}

int MyQueue::dequeue()
{
    int deletedElement{ m_array[m_head] };
    if (m_head == m_array.size())
    {
        m_head = 0;
    }
    else
    {
        ++m_head;
    }
    return deletedElement;
}

#endif
