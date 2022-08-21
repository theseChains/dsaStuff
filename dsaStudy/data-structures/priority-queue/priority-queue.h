#ifndef PRIORITY_QUEUE_DS_H
#define PRIORITY_QUEUE_DS_H

#include "../../util/util.h"

// max-priority queue
int maximum(const std::vector<int>& prQueue);
int extractMax(std::vector<int>& prQueue);
void increaseKey(std::vector<int>& prQueue, int index, int key);
void maxPrQueueInsert(std::vector<int>& prQueue, int key);
void maxPrQueueDelete(std::vector<int>& prQueue, int index);

// min-priority queue
int minumum(const std::vector<int>& prQueue);
int extractMin(std::vector<int>& prQueue);
void decreaseKey(std::vector<int>& prQueue, int index, int key);
void minPrQueueInsert(std::vector<int>& prQueue, int key);

#endif