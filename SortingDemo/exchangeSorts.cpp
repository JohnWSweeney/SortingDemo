#include "exchangeSorts.h"
#include "data.h"

void bubbleSort(std::string variableType, bool isAscending)
{
	std::vector<int> intVector;
	int result = checkCopyVariable(variableType, intVector);
	if (result != 0)
	{
		return;
	}

	int swaps = 0;
	int swapCount = 0;
	int sweepCount = 0;
	do {
		swaps = 0;
		for (int i = 0; i < intVector.size() - 1; i++)
		{
			int temp;
			if (isAscending == true)
			{
				if (intVector[i] > intVector[i + 1])
				{
					temp = intVector[i];
					intVector[i] = intVector[i + 1];
					intVector[i + 1] = temp;
					++swaps;
				}
			}
			else
			{
				if (intVector[i] < intVector[i + 1])
				{
					temp = intVector[i];
					intVector[i] = intVector[i + 1];
					intVector[i + 1] = temp;
					++swaps;
				}
			}
		}
		++sweepCount;
		swapCount = swapCount + swaps;
	} while (swaps != 0);

	printVector(intVector, "Bubble sorted");
	printPerformanceResults(swapCount, sweepCount);
}

void cocktailShakerSort(std::string variableType, bool isAscending)
{
	std::vector<int> intVector;
	int result = checkCopyVariable(variableType, intVector);
	if (result != 0)
	{
		return;
	}

	int swaps = 0;
	int swapCount = 0;
	int sweepCount = 0;
	do {
		swaps = 0;
		int temp;
		for (int i = 0; i < intVector.size() - 1; i++)
		{
			if (isAscending == true)
			{
				if (intVector[i] > intVector[i + 1]) // sort ascending.
				{
					temp = intVector[i];
					intVector[i] = intVector[i + 1];
					intVector[i + 1] = temp;
					++swaps;
				}
			}
			else
			{
				if (intVector[i] < intVector[i + 1]) // sort descending.
				{
					temp = intVector[i];
					intVector[i] = intVector[i + 1];
					intVector[i + 1] = temp;
					++swaps;
				}
			}
		}
		++sweepCount;

		if (swaps == 0)
		{
			break;
		}

		for (int i = intVector.size() - 1; i > 0; i--)
		{
			if (isAscending == true)
			{
				if (intVector[i] < intVector[i - 1]) // sort ascending.
				{
					temp = intVector[i];
					intVector[i] = intVector[i - 1];
					intVector[i - 1] = temp;
					++swaps;
				}
			}
			else
			{
				if (intVector[i] > intVector[i - 1]) // sort descending.
				{
					temp = intVector[i];
					intVector[i] = intVector[i - 1];
					intVector[i - 1] = temp;
					++swaps;
				}
			}
		}
		++sweepCount;
		swapCount = swapCount + swaps;
	} while (swapCount != 0);

	printVector(intVector, "Cocktail shaker sorted");
	printPerformanceResults(swapCount, sweepCount);
}

void combSort(std::string variableType, bool isAscending)
{
	std::vector<int> intVector;
	int result = checkCopyVariable(variableType, intVector);
	if (result != 0)
	{
		return;
	}

	float shrinkFactor = 1.3;
	int step = 0;
	int k = 1;
	int leftIndex, rightIndex;
	int swaps = 0;
	int swapCount = 0;
	int sweepCount = 0;

	do {
		step = intVector.size() / pow(shrinkFactor, k);
		leftIndex = 0;
		rightIndex = step;
		do {
			swaps = 0;
			int temp;
			if (isAscending == true)
			{
				if (intVector[leftIndex] > intVector[rightIndex]) // sort ascending.
				{
					temp = intVector[leftIndex];
					intVector[leftIndex] = intVector[rightIndex];
					intVector[rightIndex] = temp;
					++swaps;
				}
			}
			else
			{
				if (intVector[leftIndex] < intVector[rightIndex]) // sort descending.
				{
					temp = intVector[leftIndex];
					intVector[leftIndex] = intVector[rightIndex];
					intVector[rightIndex] = temp;
					++swaps;
				}
			}
			++leftIndex;
			++rightIndex;
			swapCount = swapCount + swaps;
		} while (rightIndex < intVector.size());
		++sweepCount;
		++k;

	} while (step > 1);
	printVector(intVector, "Comb sorted");
	printPerformanceResults(swapCount, sweepCount);
}

void evenOddSort(std::string variableType, bool isAscending)
{
	std::vector<int> intVector;
	int result = checkCopyVariable(variableType, intVector);
	if (result != 0)
	{
		return;
	}

	int swaps = 0;
	int swapCount = 0;
	int sweepCount = 0;
	do {
		swaps = 0;
		for (int i = 0; i < intVector.size() - 1; i += 2) // odd pairs.
		{
			if (intVector[i] > intVector[i + 1])
			{
				swap(intVector, i, i + 1);
				++swaps;
			}
		}

		for (int i = 1; i < intVector.size() - 2; i += 2) // even pairs.
		{
			if (intVector[i] > intVector[i + 1])
			{
				swap(intVector, i, i + 1);
				++swaps;
			}
		}
		++sweepCount;
		swapCount = swapCount + swaps;
	} while (swaps != 0);
	printVector(intVector, "Even-odd sorted");
	printPerformanceResults(swapCount, sweepCount);
}

int partition(std::vector<int> &intVector, int lo, int hi)
{
	int pivotIndex = hi;
	while (lo < hi)
	{
		while (intVector[lo] <= intVector[pivotIndex] and lo < hi)
		{
			++lo;
		}
		while (intVector[hi] > intVector[pivotIndex] and lo < hi)
		{
			--hi;
		}
		swap(intVector, lo, hi);
	}
	swap(intVector, lo, pivotIndex);
	return lo;
}

void quickSortRecursion(std::vector<int> &intVector, int lo, int hi)
{
	if (lo < hi)
	{
		int pivotIndex = partition(intVector, lo, hi);
		quickSortRecursion(intVector, lo, pivotIndex - 1);
		quickSortRecursion(intVector, pivotIndex + 1, hi);
	}
}

void quickSort(std::string variableType, bool isAscending)
{
	std::vector<int> intVector;
	int result = checkCopyVariable(variableType, intVector);
	if (result != 0)
	{
		return;
	}

	quickSortRecursion(intVector, 0, intVector.size() - 1);
	printVector(intVector, "Quick-sort sorted");
}
