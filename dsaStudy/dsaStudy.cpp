#include "data-structures/stacks-and-queues/stack.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};
    
    MyStack stack{};

    stack.push(6);
    stack.push(3);
    stack.push(55);

    std::cout << stack.pop() << ' ' << stack.pop() << ' ' << stack.pop() << '\n';

    return 0;
}
