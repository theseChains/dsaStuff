#include "heap.h"

// the (binary) heap data structure is an array object that we can
// view as a nearly complete binary tree

// array: 16-14-10-8-7-9-3-2-4-1
// binary tree:     16(idx = 0)
//				  /    \
//				14      10
//			  /   \    /  \
//			 8     7  9    3
//		    /  \   /
//		   2   4  1

int getParentIdx(int heapSize)
{
	return heapSize / 2;
}

int getLeftChildIdx(int parentIndex)
{
	return parentIndex * 2;
}

int getRightChildIdx(int parentIndex)
{
	return parentIndex * 2 + 1;
}

// function to maintain max-heap property, i. e.:
// for every node i other than the root, array[parent(i)] >= array[i]
// at each step, the largest of the elements array[index], array[right], 
// and array[left] is determined and stored in indexOfLargest
void maxHeapify(std::array<int, util::arraySize>& heap, int index, int size)
{
	int leftChildIndex{ getLeftChildIdx(index) };
	int rightChildIndex{ getRightChildIdx(index) };

	int indexOfLargest{ index };
	if (leftChildIndex < size && heap[leftChildIndex] > heap[index])
	{
		indexOfLargest = leftChildIndex;
	}
	else
	{
		indexOfLargest = index;
	}

	if (rightChildIndex < size && heap[rightChildIndex] > heap[indexOfLargest])
	{
		indexOfLargest = rightChildIndex;
	}

	if (indexOfLargest != index)
	{
		std::swap(heap[index], heap[indexOfLargest]);
		maxHeapify(heap, indexOfLargest, size);
	}
}

void minHeapify(std::array<int, util::arraySize>& heap, int index, int size)
{
	int leftChildIndex{ getLeftChildIdx(index) };
	int rightChildIndex{ getRightChildIdx(index) };

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
		minHeapify(heap, indexOfSmallest, size);
	}
}

// a more efficient version
void iterativeMaxHeapify(std::array<int, util::arraySize>& heap, int index, int size)
{
	while (index < size)
	{
		int rightChildIndex{ getRightChildIdx(index) };
		int leftChildIndex{ getLeftChildIdx(index) };
		int indexOfLargest{ index };

		if (rightChildIndex < size && heap[rightChildIndex] > heap[index])
		{
			indexOfLargest = rightChildIndex;
		}
		else
		{
			indexOfLargest = index;
		}

		if (leftChildIndex < size && heap[leftChildIndex] > heap[indexOfLargest])
		{
			indexOfLargest = leftChildIndex;
		}

		if (indexOfLargest != index)
		{
			std::swap(heap[index], heap[indexOfLargest]);
		}
		else
		{
			return;
		}
	}
}

void buildMaximumHeap(std::array<int, util::arraySize>& heap)
{
	int size{ static_cast<int>(std::size(heap)) };

	// with size / 2 we can still access every node of the heap
	// and for every node of the heap we call the make max heap function
	for (int i{ size / 2 - 1 }; i >= 0; --i)
	{
		maxHeapify(heap, i, size);
	}
}