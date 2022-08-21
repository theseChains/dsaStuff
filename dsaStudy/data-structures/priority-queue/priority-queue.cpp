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

void minHeapifyForQueue(std::vector<int>& heap, int index, int size)
{
	int leftChildIndex{ index * 2 + 1 };
	int rightChildIndex{ index * 2 + 2 };

	int indexOfSmallest{ index };
	if (leftChildIndex < size && heap[leftChildIndex] < heap[index])
	{
		indexOfSmallest = leftChildIndex;
	}
	else
	{
		indexOfSmallest = index;
	}

	if (rightChildIndex < size && heap[rightChildIndex] < heap[indexOfSmallest])
	{
		indexOfSmallest = rightChildIndex;
	}

	if (indexOfSmallest != index)
	{
		std::swap(heap[index], heap[indexOfSmallest]);
		minHeapifyForQueue(heap, indexOfSmallest, size);
	}
}

// max-priority queue:

int maximum(const std::vector<int>& prQueue)
{
	// the biggest element of the heap is at the top
	return prQueue[0];
}

int extractMax(std::vector<int>& prQueue)
{
	int size{ static_cast<int>(std::size(prQueue)) };

	if (size < 1)
	{
		std::cerr << "heap underflow\n";
	}

	int maxElement{ prQueue[0] };
	// put the last element at the top
	prQueue[0] = prQueue[static_cast<std::size_t>(size) - 1];
	prQueue.resize(static_cast<std::size_t>(size) - 1);
	// max heapify again since the smallest element is at the top now
	maxHeapifyForQueue(prQueue, 0, size - 1);

	return maxElement;
}

void increaseKey(std::vector<int>& prQueue, int index, int key)
{
	if (key < prQueue[index])
	{
		std::cerr << "new key is smaller than current key\n";
		return;
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
	prQueue[static_cast<std::size_t>(newSize) - 1] = std::numeric_limits<int>::min();
	// insert new key in last node and then find a new place for it in this function
	increaseKey(prQueue, newSize - 1, key);
}

// min-priority queue

int minumum(const std::vector<int>& prQueue)
{
	// smallest element is at the top
	return prQueue[0];
}

int extractMin(std::vector<int>& prQueue)
{
	int size{ static_cast<int>(std::size(prQueue)) };

	if (size < 1)
	{
		std::cerr << "heap underflow\n";
	}

	int minElement{ prQueue[0] };
	// put the biggest element at the top now
	prQueue[0] = prQueue[static_cast<std::size_t>(size) - 1];
	prQueue.resize(static_cast<std::size_t>(size) - 1);
	minHeapifyForQueue(prQueue, 0, size - 1);

	return minElement;
}

void decreaseKey(std::vector<int>& prQueue, int index, int key)
{
	if (prQueue[index] < key)
	{
		std::cerr << "new key is bigger than current key\n";
		return;
	}

	prQueue[index] = key;
	while (index > 0 && prQueue[index / 2] > prQueue[index])
	{
		std::swap(prQueue[index], prQueue[index / 2]);
		index /= 2;
	}
}

void minPrQueueInsert(std::vector<int>& prQueue, int key)
{
	prQueue.resize(std::size(prQueue) + 1);
	int newSize{ static_cast<int>(std::size(prQueue)) };
	prQueue[static_cast<std::size_t>(newSize) - 1] = std::numeric_limits<int>::max();
	decreaseKey(prQueue, newSize - 1, key);
}