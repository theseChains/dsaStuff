#include "randomized.h"

/* we assume that no two candidates have the same score
 * and the amount of candidates interviewed at first is less
 * than array size (firstPart < 10 here).
 * if we implement this strategy with firstPart = n/e
 * (where n is the amount of candidates), we succees in hiring
 * our best-qualified applicant with probability of at least 1/e. */
int onlineHireAssistant(std::array<int, 10>& candidateScore, int firstPart)
{
	int bestScore{ std::numeric_limits<int>::min() };
	int lastCandidate{ static_cast<int>(std::size(candidateScore)) };

	for (int i{ 0 }; i < firstPart; ++i)
	{
		if (candidateScore[i] > bestScore)
		{
			bestScore = candidateScore[i];
		}
	}

	for (int i{ firstPart }; i < lastCandidate; ++i)
	{
		if (candidateScore[i] > bestScore)
		{
			return i;
		}
	}

	return lastCandidate;
}