#include "selectionSorts.h"
#include "data.h"

void selectionSort(std::string variableType, bool isAscending)
{
	std::vector<int> intVector;
	int result = checkCopyVariable(variableType, intVector);
	if (result != 0)
	{
		return;
	}

	int sortedIndex = 0;
	int unsortedIndex = 1;
	int resultIndex = 0;
	do {
		for (int i = unsortedIndex; i < intVector.size(); i++)
		{
			if (isAscending == true)
			{
				if (intVector[i] < intVector[resultIndex])
				{
					resultIndex = i;
				}
			}
			else
			{
				if (intVector[i] > intVector[resultIndex])
				{
					resultIndex = i;
				}
			}
		}

		std::rotate(intVector.begin() + sortedIndex, intVector.begin() + resultIndex, intVector.end());
		++sortedIndex;
		++unsortedIndex;
		resultIndex = sortedIndex;
	} while (sortedIndex < intVector.size());

	printData(intVector, "Selection sorted");
}