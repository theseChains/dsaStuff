#include "d-ary-heap.h"

int getChildIndex(int parentIndex, int child, int numberOfChildren)
{
	return numberOfChildren * (parentIndex + 1) - numberOfChildren + 1 + child;
}

int getParentIndex(int index, int numberOfChildren)
{
	return (index - 1) / numberOfChildren;
}

void dAryMaxHeapify(std::vector<int>& dAryHeap, int numberOfChildren, std::size_t size, int index)
{
	std::vector<int> childNodeIndices(numberOfChildren);
	int indexOfLargest{ index };

	for (int i{ 0 }; i < numberOfChildren; ++i)
	{
		// get ith child
		childNodeIndices[i] = getChildIndex(index, i, numberOfChildren);
	}

	for (const auto childIndex : childNodeIndices)
	{
		if (childIndex < size && dAryHeap[childIndex] > dAryHeap[indexOfLargest])
		{
			indexOfLargest = childIndex;
		}
	}

	if (index != indexOfLargest)
	{
		std::swap(dAryHeap[index], dAryHeap[indexOfLargest]);
		dAryMaxHeapify(dAryHeap, numberOfChildren, size, indexOfLargest);
	}
}

int extractMax(std::vector<int>& dAryHeap, int numberOfChildren)
{
	std::size_t size{ std::size(dAryHeap) };

	if (size < 1)
	{
		std::cerr << "d-ary heap underflow\n";
	}

	int maxElement{ dAryHeap[0] };
	dAryHeap[0] = dAryHeap[size - 1];
	dAryHeap.resize(size - 1);
	dAryMaxHeapify(dAryHeap, numberOfChildren, size - 1, 0);

	return maxElement;
}