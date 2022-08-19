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

int getParentIndex(int heapSize)
{
	return heapSize / 2;
}

int getLeftChildIndex(int parentIndex)
{
	return parentIndex * 2;
}

int getRightChildIndex(int parentIndex)
{
	return parentIndex * 2 + 1;
}

// function to maintain max-heap property, i. e.:
// for every node i other than the root, array[parent(i)] >= array[i]
// at each step, the largest of the elements array[index], array[right], 
// and array[left] is determined and stored in indexOfLargest
void makeMaxHeap(std::array<int, util::arraySize>& heap, int index, int size)
{
	int leftChildIndex{ getLeftChildIndex(index) };
	int rightChildIndex{ getRightChildIndex(index) };

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
		makeMaxHeap(heap, indexOfLargest, size);
	}
}

void makeMinHeap(std::array<int, util::arraySize>& heap, int index, int size)
{
	int leftChildIndex{ getLeftChildIndex(index) };
	int rightChildIndex{ getRightChildIndex(index) };

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
		makeMaxHeap(heap, indexOfSmallest, size);
	}
}

// a more efficient version
void iterativeMakeMaxHeap(std::array<int, util::arraySize>& heap, int index, int size)
{
	while (index < size)
	{
		int rightChildIndex{ getRightChildIndex(index) };
		int leftChildIndex{ getLeftChildIndex(index) };
		int indexOfLargest{ index };

		if (rightChildIndex < size && heap[rightChildIndex] > heap[index])
		{
			indexOfLargest = rightChildIndex;
		}

		if (leftChildIndex < size && heap[leftChildIndex] > heap[index])
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

void buildMaxHeap(std::array<int, util::arraySize>& heap)
{
	int size{ static_cast<int>(std::size(heap)) };

	// with size / 2 we can still access every node of the heap
	// and for every node of the heap we call the make max heap function
	for (int i{ size / 2 - 1 }; i >= 0; --i)
	{
		makeMaxHeap(heap, i, size);
	}
}