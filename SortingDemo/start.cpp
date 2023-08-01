#include "start.h"
#include "commands.h"
#include "data.h"
#include "exchangeSorts.h"
#include "variables.h"

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

	cmd cmd;
	int result = populateCmd(tokens, cmd);
	if (result != 0)
	{
		return;
	}

	if (cmd.functionType == "bubble")
	{
		bubbleSort(cmd.variableType, cmd.isAscending);
	}
	else if (cmd.functionType == "data")
	{
		if (cmd.variableType == "user")
		{
			getUserData(tokens);
		}
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