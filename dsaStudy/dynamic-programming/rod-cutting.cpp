#include "rod-cutting.h"

int recursiveCutRod(const std::vector<int>& prices, int length)
{
    // if size is 0, then the revenue is 0
    if (length == 0)
    {
        return 0;
    }

    int maxRevenue{ std::numeric_limits<int>::min() };
    for (int i{ 1 }; i <= length; ++i)
    {
        // recursively make cuts, decreasing length by 1 each time and finding the max revenue
        // this is inefficient since the algorithm solves the same subproblems many times
        // for length = 4 it calls recursiveCutRod(p, i) where i = 0, 1, 2, 3, and
        // for i = 3 it calls recursiveCutRod(p, j) where j = 0, 1, 2 and so on
        maxRevenue = std::max(maxRevenue, prices[i - 1] + recursiveCutRod(prices, length - i));
    }
    return maxRevenue;
}

int memoizedCutRod(const std::vector<int>& prices, int length)
{
    // initialize with minimum values
    std::vector<int> resultsOfSubproblems(length + 1, std::numeric_limits<int>::min());

    return memoizedCutRodAuxiliary(prices, length, resultsOfSubproblems);
}

int memoizedCutRodAuxiliary(const std::vector<int>& prices, int length, std::vector<int>& results)
{
    if (results.at(length) >= 0)
    {
        return results.at(length);
    }

    int result{};
    if (length == 0)
    {
        result = 0;
    }
    else
    {
        result = std::numeric_limits<int>::min();
        for (int i{ 0 }; i < length; ++i)
        {
            result = std::max(result, prices.at(i) + memoizedCutRodAuxiliary(prices,
                        length - i - 1, results));
        }
    }

    // "remember" the result
    results.at(length) = result;
    return result;
}

int bottomUpCutRod(const std::vector<int>& prices, int length)
{
    // results for each length of a rod
    std::vector<int> results(length + 1);
    // not necessary, but shows that the price of a rod of length 0 is 0
    results[0] = 0;
    int result{};
    for (int j{ 1 }; j <= length; ++j)
    {
        result = std::numeric_limits<int>::min();
        for (int i{ 0 }; i < j; ++i)
        {
            // a problem of size i is smaller than a problem of size j,
            // thus, the procedure solves problems of sizes j = 0, 1, ..., n in that order
            result = std::max(result, prices[i] + results[j - i - 1]);
        }
        // remember the optimal result
        results[j] = result;
    }

    // return desired result
    return results[length];
}

std::pair<std::vector<int>, std::vector<int>> extendedBottomUpCutRod(const std::vector<int>& prices, int length)
{
    std::vector<int> revenues(length + 1);
    std::vector<int> optimalSizes(length + 1);
    revenues[0] = 0;
    for (int j{ 1 }; j <= length; ++j)
    {
        int result{ std::numeric_limits<int>::min() };
        for (int i{ 0 }; i < j; ++i)
        {
            if (result < prices[i] + revenues[j - i - 1])
            {
                result = prices[i] + revenues[j - i - 1];
                // same as before, but we update the optimalSizes[j] to hold the optimal
                // size i of the first piece to cut off when solving a subproblem of size j
                optimalSizes[j] = i + 1;
            }
        }
        revenues[j] = result;
    }

    return { revenues, optimalSizes };
}

void printCutRodSolution(const std::vector<int>& prices, int length)
{
    auto [revenues, optimalSizes]{ extendedBottomUpCutRod(prices, length) };
    std::cout << "sizes: ";
    while (length > 0)
    {
        std::cout << optimalSizes[length] << ' ';
        length -= optimalSizes[length];
    }
    std::cout << '\n';
}
