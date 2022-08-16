#include "randomized.h"

void interview([[maybe_unused]] int candidate)
{
	// do something here
}

void hire([[maybe_unused]] int candidate)
{
	// do something costly here
}

// assume each candidate is represented by an integer from 0 to 9
int hireAssistant(std::array<int, 10>& candidates)
{
	/* we make sure that the candidates are randomized
	 * so that each new candidate has the same chance of 
	 * being hired. this way the algorithm has an average 
	 * total hiring cost of O(cln(n)), where c is the number
	 * of hiring function calls. worst-case: O(cn) */
	std::mt19937 mt{ std::random_device{}() };
	std::shuffle(candidates.begin(), candidates.end(), mt);

	int bestValue{ -1 };
	int best{ -1 }; // candidate -1 is a least-qualified dummy candidate
	for (int i{ 0 }; i < static_cast<int>(candidates.size()); ++i)
	{
		interview(candidates[i]);
		// candidate i has a probability of 1/i of being better qualified
		// than candidates 0 through i - 1
		if (candidates[i] > bestValue)
		{
			best = i;
			bestValue = candidates[i];
			// we go through the interview process regardless
			// but we want to minimize hiring expenses
			// the amount of calls of this function depends
			// on how lucky we got with the permutation
			// for example, if the array is sorted in a decreasing
			// order, we only call this once, 10 times in case of 
			// ascending order, but we have a random array, so the
			// cost is random too.
			hire(candidates[i]);
		}
	}

	// the candidate that we're hiring
	return best;
}