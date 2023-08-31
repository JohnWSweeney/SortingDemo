#include "data.h"
#include "random.h"

std::vector<int> defaultData = { 1,7,3,9,2,4,6,8,5,0 };
std::vector<int> userData;
std::vector<int> randomData;

void printVector(std::vector<int> intVector, std::string intVectorName)
{
	std::cout << intVectorName << " integer vector: ";
	for (int i = 0; i < intVector.size(); i++)
	{
		std::cout << intVector[i] << " ";
	}
	std::cout << '\n';
}

void swap(std::vector<int> &intVector, int indexA, int indexB)
{
	int temp = intVector[indexA];
	intVector[indexA] = intVector[indexB];
	intVector[indexB] = temp;
}

void printPerformanceResults(int swapCount, int sweepCount)
{
	std::cout << "swapCount: " << swapCount << '\t' << "sweepCount: " << sweepCount << '\n';
}

int checkCopyVariable(std::string variableType, std::vector<int> &intVector)
{
	if (variableType == "default")
	{
		intVector = defaultData;
		return 0;
	}
	else if (variableType == "user")
	{
		if (userData.empty())
		{
			std::cout << "User data is empty.\n";
			return 1;
		}
		else
		{
			intVector = userData;
			return 0;
		}
	}
	else if (variableType == "random")
	{
		if (randomData.empty())
		{
			std::cout << "Random data is empty.\n";
			return 1;
		}
		else
		{
			intVector = randomData;
			return 0;
		}
	}
}

void getUserData(std::vector<std::string> tokens)
{
	userData.clear();
	for (int i = 2; i < tokens.size(); i++)
	{
		int element;
		try {
			element = stoi(tokens[i]);
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid integer for element " << i + 1 << ".\n";
			userData.clear();
			return;
		}
		catch (std::out_of_range)
		{
			std::cout << "Invalid integer for element " << i + 1 << ": out of range.\n";
			userData.clear();
			return;
		}
		userData.push_back(element);
	}
	printVector(userData, "User unsorted");
}

void getRandomData(int size, int min, int max)
{
	randomData.clear();
	random random;
	random.initMt();
	for (int i = 0; i < size; i++)
	{
		int integer = random.getNum(min, max);
		randomData.push_back(integer);
	}
	printVector(randomData, "Random unsorted");
}