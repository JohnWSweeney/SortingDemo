#include "data.h"
#include "variables.h"

void printData(std::vector<int> intVector, std::string intVectorName)
{
	std::cout << "Unsorted " << intVectorName << " integer vector: ";
	for (int i = 0; i < userData.size(); i++)
	{
		std::cout << userData[i] << " ";
	}
	std::cout << '\n';
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

	printData(userData, "user");
}