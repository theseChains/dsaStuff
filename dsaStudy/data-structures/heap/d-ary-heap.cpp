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
	int indexOfLargest{ index };

	for (int i{ 0 }; i < numberOfChildren; ++i)
	{
		// get ith child
		int childIndex{ getChildIndex(index, i, numberOfChildren) };
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

int dAryHeapExtractMax(std::vector<int>& dAryHeap, int numberOfChildren)
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

void dAryHeapIncreaseKey(std::vector<int>& dAryHeap, int key, int index, int numberOfChildren)
{
	if (dAryHeap[index] > key)
	{
		std::cerr << "new key is smaller than the current key\n";
	}

	dAryHeap[index] = key;
	while (index > 0 && dAryHeap[(index - 1) / numberOfChildren] < dAryHeap[index])
	{
		std::swap(dAryHeap[index], dAryHeap[(index - 1) / numberOfChildren]);
		index = getParentIndex(index, numberOfChildren);
	}
}

void dAryHeapInsert(std::vector<int>& dAryHeap, int key, int numberOfChildren)
{
	dAryHeap.resize(std::size(dAryHeap) + 1);
	// yes, i know im inconsistent with these std::size() types, whatever, too lazy to fix
	int lastIndex{ static_cast<int>(std::size(dAryHeap) - 1) };
	dAryHeap[lastIndex] = std::numeric_limits<int>::min();
	dAryHeapIncreaseKey(dAryHeap, key, lastIndex, numberOfChildren);
}