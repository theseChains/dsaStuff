#ifndef ROD_CUTTING_H
#define ROD_CUTTING_H

/* a company buys long steel rods and cuts them into shorter rods, which it then sells
 * each cut is free, the management wants to know the best way to cut up the rods
 * given a rod of length n inches and a table of prices determine the max revenue
 * obtainable by cutting up the rod and selling pieces */

#include "../util/util.h"

// a straightforward recursive implementation
// O(2^n) complexity
int recursiveCutRod(const std::vector<int>& prices, int length);

// the dynamic-programming method works as follows: having observed taht a naive recursive
// solution is inefficient because it solves the same subproblems, we arrange for each
// subproblem to be solved only once, saving its solution

// the first approach is top-down with memoization (comes from word memo)
// similar to the recursive method, but modified to save the result of each subproblem
// O(n^2) complexity
int memoizedCutRod(const std::vector<int>& prices, int length);
int memoizedCutRodAuxiliary(const std::vector<int>& prices, int length, std::vector<int>& results);

// the second approach is the bottom-up method, it depends on some natural notion of the "size"
// of a subproblem, such that solving any particular subproblem depends only on solving "smaller"
// subproblems. we sort the subproblems by size and solve them in size order, smallest first.
// when solving a particular subproblem, we have already solved all of the smaller subproblems
// its solution depends upon, and we have saved their solutions
// O(n^2) complexity
int bottomUpCutRod(const std::vector<int>& prices, int length);

// we can also print the solution itself by returning max revenue ans optimal size arrays:
std::pair<std::vector<int>, std::vector<int>> extendedBottomUpCutRod(const std::vector<int>& prices, int length);

void printCutRodSolution(const std::vector<int>& prices, int length);

#endif
