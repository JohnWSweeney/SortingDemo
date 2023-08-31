#pragma once
#include <iostream>
#include <vector>
#include <string>

int checkCopyVariable(std::string variableType, std::vector<int> &intVector);
void swap(std::vector<int> &intVector, int indexA, int indexB);
void printVector(std::vector<int> intVector, std::string intVectorName);
void printPerformanceResults(int swapCount, int sweepCount);
void getUserData(std::vector<std::string> tokens);
void getRandomData(int size, int min, int max);