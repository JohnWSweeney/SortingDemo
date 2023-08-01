#pragma once
#include <iostream>
#include <string>
#include <vector>

struct cmd
{
	std::string functionType;
	std::string variableType;
	bool isAscending;
};

int checkFunctionType(std::string token, std::string &functionType);
int getVariableType(std::string token, std::string &variableType);
int getInteger(std::string token, bool isSigned, int &integer, std::string intName);
int getDirection(std::string token, bool &isAscending);
int populateCmd(std::vector<std::string> tokens, cmd &cmd);