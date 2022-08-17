#include "exercises/exercises.h"
#include "matrices/matrices.h"
#include "randomized/randomized.h"
#include "searching/searching.h"
#include "sorting/sorting.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};

    std::set<int> randomSample{ getRandomSample(10, 6) };

    for (const auto element : randomSample)
    {
        std::cout << element << ' ';
    }


    return 0;
}