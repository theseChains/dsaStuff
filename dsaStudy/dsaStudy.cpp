#include "data-structures/priority-queue/priority-queue.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};

    std::vector<int> maxPrQueue{ 45, 34, 22, 21, 18, 18, 9, 5, 3, 2 };
    
    std::cout << "initial max pr. queue:\n";
    printVector(maxPrQueue);
    std::cout << '\n';

    std::cout << "max element: " << maximum(maxPrQueue) << '\n';
    std::cout << "extracting max element...\n";
    int maxElement{ extractMax(maxPrQueue) };
    std::cout << "extracted element: " << maxElement << "\nnew max pr. queue:\n";
    printVector(maxPrQueue);
    std::cout << '\n';
    
    std::cout << "increasing 3rd key to 33...\n";
    increaseKey(maxPrQueue, 2, 33);
    std::cout << "new max pr. queue:\n";
    printVector(maxPrQueue);
    std::cout << '\n';

    std::cout << "inserting key 14...\n";
    maxPrQueueInsert(maxPrQueue, 14);
    std::cout << "new max pr. queue:\n";
    printVector(maxPrQueue);
    std::cout << '\n';

    return 0;
}