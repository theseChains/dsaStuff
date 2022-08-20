#ifndef PRIORITY_QUEUE_DS_H
#define PRIORITY_QUEUE_DS_H

#include "../../util/util.h"

// max-priority queue
int maxMaximum(const std::vector<int>& prQueue);
int maxExtractMax(std::vector<int>& prQueue);
void maxIncreaseKey(std::vector<int>& prQueue, int index, int key);
void maxPrQueueInsert(std::vector<int>& prQueue, int key);


#endif