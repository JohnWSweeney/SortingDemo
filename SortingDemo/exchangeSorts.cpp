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