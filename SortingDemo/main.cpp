#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &test, bool isAscending)
{
	int swapCount;
	int iterationCount = 0;
	do {
		swapCount = 0;
		for (int i = 0; i < test.size() - 1; i++)
		{
			int temp;
			if (isAscending == true)
			{
				if (test[i] > test[i + 1])
				{
					++swapCount;
					temp = test[i];
					test[i] = test[i + 1];
					test[i + 1] = temp;
				}
			}
			else
			{
				if (test[i] < test[i + 1])
				{
					++swapCount;
					temp = test[i];
					test[i] = test[i + 1];
					test[i + 1] = temp;
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
}

int main()
{
	std::cout << "sortingDemo v0.0.0\n\n";

	std::vector<int> test = { 1,7,3,9,2,4,6,8,5,0 };

	for (int i = 0; i < test.size(); i++)
	{
		std::cout << test[i] << " ";
	}
	std::cout << '\n';

	bubbleSort(test, false);

	for (int i = 0; i < test.size(); i++)
	{
		std::cout << test[i] << " ";
	}
	std::cout << '\n';
}