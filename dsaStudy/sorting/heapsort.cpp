#include "sorting.h"

// the (binary) heap data structure is an array object that we can
// view as a nearly complete binary tree

//array: 16-14-10-8-7-9-3-2-4-1
//binary tree:     16(idx = 0)
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
void makeMaxHeap(std::array<int, util::arraySize>& numbers, int index, int size)
{
	int leftChildIndex{ getLeftChildIndex(index) };
	int rightChildIndex{ getRightChildIndex(index) };

	int indexOfLargest{ index };
	if (leftChildIndex < size && numbers[leftChildIndex] > numbers[index])
	{
		indexOfLargest = leftChildIndex;
	}
	else
	{
		indexOfLargest = index;
	}

	if (rightChildIndex < size && numbers[rightChildIndex] > numbers[indexOfLargest])
	{
		indexOfLargest = rightChildIndex;
	}

	if (indexOfLargest != index)
	{
		std::swap(numbers[index], numbers[indexOfLargest]);
		makeMaxHeap(numbers, indexOfLargest, size);
	}
}

void makeMinHeap(std::array<int, util::arraySize>& numbers, int index, int size)
{
	int leftChildIndex{ getLeftChildIndex(index) };
	int rightChildIndex{ getRightChildIndex(index) };

	int indexOfSmallest{ index };
	if (leftChildIndex < size && numbers[leftChildIndex] < numbers[index])
	{
		indexOfSmallest = leftChildIndex;
	}
	else
	{
		indexOfSmallest = index;
	}

	if (rightChildIndex < size && numbers[rightChildIndex] < numbers[indexOfSmallest])
	{
		indexOfSmallest = rightChildIndex;
	}

	if (indexOfSmallest != index)
	{
		std::swap(numbers[index], numbers[indexOfSmallest]);
		makeMaxHeap(numbers, indexOfSmallest, size);
	}
}

// a more efficient version
void iterativeMakeMaxHeap(std::array<int, util::arraySize>& numbers, int index, int size)
{
	while (index < size)
	{
		int rightChildIndex{ getRightChildIndex(index) };
		int leftChildIndex{ getLeftChildIndex(index) };
		int indexOfLargest{ index };

		if (rightChildIndex < size && numbers[rightChildIndex] > numbers[index])
		{
			indexOfLargest = rightChildIndex;
		}

		if (leftChildIndex < size && numbers[leftChildIndex] > numbers[index])
		{
			indexOfLargest = leftChildIndex;
		}

		if (indexOfLargest != index)
		{
			std::swap(numbers[index], numbers[indexOfLargest]);
		}
		else
		{
			return;
		}
	}
}

void buildMaxHeap(std::array<int, util::arraySize>& numbers)
{
	int size{ static_cast<int>(std::size(numbers)) };

	// with size / 2 we can still access every node of the heap
	// and for every node of the heap we call the make max heap function
	for (int i{ size / 2 - 1 }; i >= 0; --i)
	{
		makeMaxHeap(numbers, i, size);
	}
}

void heapSort(std::array<int, util::arraySize>& numbers)
{
	buildMaxHeap(numbers);

	int size{ static_cast<int>(std::size(numbers)) };
	for (int i{ size - 1 }; i > 0; --i)
	{
		std::swap(numbers[0], numbers[i]);
		makeMaxHeap(numbers, 0, i);
	}
}