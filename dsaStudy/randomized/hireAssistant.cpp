#include "randomized.h"

void interview([[maybe_unused]] int candidate)
{
	// do something here
}

void hire([[maybe_unused]] int candidate)
{
	// do something costly here
}

// randomly permuting arrays

void randomizeInPlace(std::array<int, 10>& array)
{
	int size{ static_cast<int>(std::size(array)) };
	for (int i{ 0 }; i < size; ++i)
	{
		int newIndex{ random::getNumber(i, size - 1) };
		std::swap(array[i], array[newIndex]);
	}
}

/* if our initial array is A{ 1, 2, 3, 4 } and we choose random priorities
 * P{ 36, 3, 62, 19 }, we would produce an array B{ 2, 4, 1, 3 }, since the second
 * priority is the smallest, followed by the fourth, then the first, and finally the third*/
void permuteBySorting(std::array<int, 10>& candidates)
{
	std::array<int, 10> priorities{};
	// now we make sure that all priorities are unique!
	// (aka exercise 5.3-6)
	for (int i{ 0 }; i < std::size(priorities); ++i)
	{
		priorities[i] = i;
	}
	randomizeInPlace(priorities);

	// sort candidates array with priorities as keys
	std::array<std::pair<int, int>, 10> candidatesAndKeys{};
	for (std::size_t i{ 0 }; i < std::size(candidatesAndKeys); ++i)
	{
		candidatesAndKeys[i] = std::make_pair(candidates[i], priorities[i]);
	}

	std::sort(std::begin(candidatesAndKeys), std::end(candidatesAndKeys),
		[](const std::pair<int, int>& a, const std::pair<int, int>& b) {
			return (a.second < b.second); // sort by priority value
		});

	for (std::size_t i{ 0 }; i < std::size(candidates); ++i)
	{
		candidates[i] = candidatesAndKeys[i].first;
	}
}

// assume each candidate is represented by an integer from 0 to 9
int hireAssistant(std::array<int, 10>& candidates)
{
	/* we make sure that the candidates are randomized
	 * so that each new candidate has the same chance of 
	 * being hired. this way the algorithm has an average 
	 * total hiring cost of O(cln(n)), where c is the number
	 * of hiring function calls. worst-case: O(cn) */
	randomizeInPlace(candidates);

	int bestValue{ -1 };
	int best{ -1 }; // candidate -1 is a least-qualified dummy candidate
	for (int i{ 0 }; i < std::size(candidates); ++i)
	{
		interview(candidates[i]);
		// candidate i has a probability of 1/i of being better qualified
		// than candidates 0 through i - 1
		if (candidates[i] > bestValue)
		{
			best = i;
			bestValue = candidates[i];
			/* we go through the interview process regardless
			 * but we want to minimize hiring expenses
			 * the amount of calls of this function depends
			 * on how lucky we got with the permutation
			 * for example, if the array is sorted in a decreasing
			 * order, we only call this once, 10 times in case of 
			 * ascending order, but we have a random array, so the
			 * cost is random too. */
			hire(candidates[i]);
		}
	}

	// the candidate that we're hiring
	return best;
}