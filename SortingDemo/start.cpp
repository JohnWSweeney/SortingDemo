#include "start.h"
#include "data.h"
#include "exchangeSorts.h"
#include "test.h"

void getCommands(std::vector<std::string> &tokens)
{
	do {
		std::string input, tempStr;
		std::getline(std::cin, input, '\n');
		std::stringstream strStream(input);
		while (getline(strStream, tempStr, ' '))
		{
			tokens.push_back(tempStr);
		}
	} while (tokens.empty());
}

void startMenu(bool &running)
{
	std::vector<std::string> tokens;
	getCommands(tokens);

	if (tokens[0] == "bubble")
	{
		bubbleSort(asdf, true);
	}
	else if (tokens[0] == "data")
	{
		getData(tokens);
	}
	else if (tokens[0] == "exit")
	{
		running = false;
	}
	// reject all other inputs.
	else
	{
		std::cout << "Invalid command.\n";
	}
}