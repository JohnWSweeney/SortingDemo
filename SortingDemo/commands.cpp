#include "commands.h"

std::vector<std::string> functionTypes = { "data", "bubble", "cocktail", "selection", "exit" };
std::vector<std::string> variableTypes = { "default", "user", "random" };

int checkFunctionType(std::string token, std::string &functionType)
{
	auto result = std::find(functionTypes.begin(), functionTypes.end(), token);
	if (result == functionTypes.end())
	{
		std::cout << "Invalid function command.\n";
		return 1;
	}
	else
	{
		functionType = token;
		return 0;
	}
}

int getVariableType(std::string token, std::string &variableType)
{
	auto result = std::find(variableTypes.begin(), variableTypes.end(), token);
	if (result == variableTypes.end())
	{
		std::cout << "Invalid variable type.\n";
		return 1;
	}
	else
	{
		variableType = token;
		return 0;
	}
}

int getInteger(std::string token, bool isSigned, int &integer, std::string intName)
{
	try {
		integer = std::stoi(token);
		if (isSigned == false)
		{
			integer = abs(integer);
		}
		return 0;
	}
	catch (std::invalid_argument)
	{
		std::cout << "Invalid integer for " << intName << ".\n";
		return 1;
	}
	catch (std::out_of_range)
	{
		std::cout << "Invalid integer for " << intName << ": out of range.\n";
		return 1;
	}
}

int getRandomParameters(std::vector<std::string> tokens, int &size, int &min, int &max)
{
	int result = getInteger(tokens[2], false, size, "random vector size");
	if (result != 0)
	{
		return 1;
	}

	result = getInteger(tokens[3], true, min, "random vector minimum");
	if (result != 0)
	{
		return 1;
	}

	result = getInteger(tokens[4], true, max, "random vector maximum");
	if (result != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int getDirection(std::string token, bool &isAscending)
{
	if (token == "asc")
	{
		isAscending = true;
		return 0;
	}
	else if (token == "desc")
	{
		isAscending = false;
		return 0;
	}
	else
	{
		std::cout << "Invalid direction command.\n";
		return 1;
	}
}

int populateCmd(std::vector<std::string> tokens, cmd &cmd)
{
	if (tokens.size() < 3)
	{
		std::cout << "Too few commands.\n";
		return 1;
	}
	else
	{
		int result = checkFunctionType(tokens[0], cmd.functionType);
		if (result != 0)
		{
			return 1;
		}

		result = getVariableType(tokens[1], cmd.variableType);
		if (result != 0)
		{
			return 1;
		}

		if (cmd.functionType == "data")
		{
			if (cmd.variableType == "random")
			{
				if (tokens.size() < 5)
				{
					std::cout << "Too few commands for random data.\n";
				}
				else
				{
					result = getRandomParameters(tokens, cmd.size, cmd.min, cmd.max);
					if (result != 0)
					{
						return 1;
					}
					else
					{
						return 0;
					}
				}
			}
			else
			{
				return 0;
			}
		}
		else
		{
			result = getDirection(tokens[2], cmd.isAscending);
			if (result != 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}	
	}
}