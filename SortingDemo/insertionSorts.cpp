#include "insertionSorts.h"
#include "data.h"

void pushInsert(std::vector<int> &intVector, int startIndex, int insertIndex, int insertValue)
{
	if (startIndex > insertIndex)
	{
		intVector[startIndex] = intVector[startIndex - 1];
		return pushInsert(intVector, startIndex - 1, insertIndex, insertValue);
	}
	else
	{
		intVector[insertIndex] = insertValue;
		return;
	}
}

void insertionSort(std::string variableType, bool isAscending)
{
	std::vector<int> intVector;
	int result = checkCopyVariable(variableType, intVector);
	if (result != 0)
	{
		return;
	}

	int index = 1;
	do {
		int i = 0;
		do {
			if (isAscending == true) // sort ascending.
			{
				if (intVector[index] < intVector[i])
				{
					pushInsert(intVector, index, i, intVector[index]);
					break;
				}
			}
			else // sort descending.
			{
				if (intVector[index] > intVector[i])
				{
					pushInsert(intVector, index, i, intVector[index]);
					break;
				}
			}
			++i;
		} while (i < index);
		++index;
	} while (index < intVector.size());

	printVector(intVector, "Insertion sorted");
}