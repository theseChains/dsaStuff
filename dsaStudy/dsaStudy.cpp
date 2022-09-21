#include "data-structures/stacks-and-queues/queue.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};
    
    MyQueue queue{};

    queue.enqueue(5);
    queue.enqueue(66);
    queue.enqueue(43);

    std::cout << queue.dequeue() << ' ' << queue.dequeue() << ' ' << queue.dequeue() << '\n';

    return 0;
}
