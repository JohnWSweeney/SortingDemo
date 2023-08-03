#pragma once
#include <iostream>
#include <vector>
#include <string>

int checkCopyVariable(std::string variableType, std::vector<int> &intVector);
void printData(std::vector<int> intVector, std::string intVectorName);
void getUserData(std::vector<std::string> tokens);
void getRandomData(int size, int min, int max);