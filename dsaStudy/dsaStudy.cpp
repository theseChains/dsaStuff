﻿#include "exercises/exercises.h"
#include "matrices/matrices.h"
#include "randomized/randomized.h"
#include "searching/searching.h"
#include "sorting/sorting.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};

    std::array<int, 10> candidates{ generateArray() };
    int hiredCandidate{ hireAssistant(candidates) };
    
    std::cout << "candidates: ";
    printArray(candidates);
    std::cout << "\nhired candidate index: " << hiredCandidate << '\n';

    return 0;
}