#include "dynamic-programming/rod-cutting.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    std::vector<int> prices{ 1, 5, 8, 10, 13, 17, 18, 22, 25, 30 };
    printCutRodSolution(prices, 7);

    return 0;
}
