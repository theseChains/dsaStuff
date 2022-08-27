#include "randomized.h"

/* a random sample of a set of size n is an m-element subset S where 0 <= m <= n.
 * the following recursive procedure returns a random m-subset S{ 1, 2, 3, ... , n },
 * in which each m-subset is equally likely, while making only m calls to getNumber() */

std::set<int> getRandomSample(int setSize, int sampleSize)
{
	if (sampleSize == 0)
	{
		return std::set<int>(); // return an empty set
	}
	else
	{
		std::set<int> sample{ getRandomSample(setSize - 1, sampleSize - 1) };
		int number{ rnd::getNumber(1, setSize) };
		if (sample.contains(number))
		{
			// this will never merge the same value since setSize 
			// will change in the previous recursion call
			// this way the subset won't have repeating numbers
			sample.merge(std::set<int>{ setSize }); // merge with set containing one number - the set size
		}
		else
		{
			sample.merge(std::set<int>{ number }); // merge with set containing one random number
		}

		return sample;
	}
}
