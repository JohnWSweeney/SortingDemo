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

	int swapCount;
	int iterationCount = 0;
	do {
		swapCount = 0;
		for (int i = 0; i < intVector.size() - 1; i++)
		{
			int temp;
			if (isAscending == true)
			{
				if (intVector[i] > intVector[i + 1])
				{
					++swapCount;
					temp = intVector[i];
					intVector[i] = intVector[i + 1];
					intVector[i + 1] = temp;
				}
			}
			else
			{
				if (intVector[i] < intVector[i + 1])
				{
					++swapCount;
					temp = intVector[i];
					intVector[i] = intVector[i + 1];
					intVector[i + 1] = temp;
				}
			}
		}
		std::cout << "swapCount: " << swapCount << '\n';
		if (swapCount > 0)
		{
			++iterationCount;
		}
	} while (swapCount != 0);
	std::cout << "iterationCount: " << iterationCount << '\n';

	for (int i = 0; i < intVector.size(); i++)
	{
		std::cout << intVector[i] << " ";
	}
	std::cout << '\n';
}