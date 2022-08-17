#ifndef RANDOMIZED_ALGORITHMS_H
#define RANDOMIZED_ALGORITHMS_H

#include "../util/util.h"

int hireAssistant(std::array<int, 10>& candidates);
int onlineHireAssistant(std::array<int, 10>& candidates);

// aka exercise 5.3-7
std::set<int> getRandomSample(int setSize, int sampleSize);

#endif