#include "priority-queue.h"

// a priority is a ds for maintaining a set S of elements, each with
// an associated value called a key

// a max-priority queue supports the following operations:
// 1. Insert(S, x) - insert element x into the set S
// 2. Maximum(S) - returns element with the largest key
// 3. Extract-Max(S) - removes and returns the element with the largest key
// 4. Increase-Key(S, x, k) increases the value of x's key to value k (assume k >= x)

// we can implement a priority queue using a heap

void maxHeapifyForQueue(std::vector<int>& prQueue, int index, int size)
{
	int leftChildIndex{ index * 2 + 1 };
	int rightChildIndex{ index * 2 + 2 };

	int indexOfLargest{ index };
	if (leftChildIndex < size && prQueue[leftChildIndex] > prQueue[index])
	{
		indexOfLargest = leftChildIndex;
	}
	else
	{
		indexOfLargest = index;
	}

	if (rightChildIndex < size && prQueue[rightChildIndex] > prQueue[indexOfLargest])
	{
		indexOfLargest = rightChildIndex;
	}

	if (indexOfLargest != index)
	{
		std::swap(prQueue[index], prQueue[indexOfLargest]);
		maxHeapifyForQueue(prQueue, indexOfLargest, size);
	}
}

// max-priority queue:

int maxMaximum(const std::vector<int>& prQueue)
{
	// the biggest element of the heap is at the top
	return prQueue[0];
}

int maxExtractMax(std::vector<int>& prQueue)
{
	int size{ static_cast<int>(std::size(prQueue)) };

	if (size < 1)
	{
		std::cerr << "heap underflow";
	}

	int maxElement{ prQueue[0] };
	// put the last (smallest) element at the top
	prQueue[0] = prQueue[static_cast<std::size_t>(size) - 1];
	prQueue.resize(static_cast<std::size_t>(size) - 1);
	// max heapify again since the smallest element is at the top now
	maxHeapifyForQueue(prQueue, 0, size);

	return maxElement;
}

void maxIncreaseKey(std::vector<int>& prQueue, int index, int key)
{
	if (key < prQueue[index])
	{
		std::cerr << "new key is smaller than current key";
	}

	prQueue[index] = key;
	// travel to the root of the heap to find a new place for this key
	// index / 2 - parent node
	while (index > 0 && prQueue[index / 2] < prQueue[index])
	{
		std::swap(prQueue[index], prQueue[index / 2]);
		index /= 2; // set parent index
	}
}

void maxPrQueueInsert(std::vector<int>& prQueue, int key)
{
	prQueue.resize(std::size(prQueue) + 1);
	int newSize{ static_cast<int>(std::size(prQueue)) };
	prQueue[newSize] = std::numeric_limits<int>::min();
	// insert new key in last node and then find a new place for it in this function
	maxIncreaseKey(prQueue, newSize - 1, key);
}