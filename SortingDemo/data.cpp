#include "data.h"

void getData(std::vector<std::string> tokens)
{
	std::vector<int> intVector;
	for (int i = 1; i < tokens.size(); i++)
	{
		int element;
		try {
			element = stoi(tokens[i]);
		}
		catch (std::invalid_argument)
		{
			std::cout << "Invalid integer for element " << i << ".\n";
			//return 1;
		}
		catch (std::out_of_range)
		{
			std::cout << "Invalid integer for element " << i << ": out of range.\n";
			//return 1;
		}

		intVector.push_back(element);
	}

	for (int i = 0; i < intVector.size(); i++)
	{
		std::cout << intVector[i] << " ";
	}
	std::cout << '\n';
}