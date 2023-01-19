#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <array>
#include <exception>

int main()
{
    std::ifstream inFile("input.txt");

    std::string inString;
    std::getline(inFile, inString);
    // std::cout << inString << std::endl;

    std::pair<int, int> lineBegin;
    std::pair<int, int> lineEnd;

    // split string in two
    std::size_t trackPos = 0;
    std::string tmpStr = inString;
    lineBegin.first = std::stoi(tmpStr, &trackPos);
    tmpStr = tmpStr.substr(trackPos + 1);
    lineBegin.second = std::stoi(tmpStr, &trackPos);
    tmpStr = tmpStr.substr(tmpStr.find("->") + 2);

    std::cout << lineBegin.first << " " << lineBegin.second << std::endl;

    lineEnd.first = std::stoi(tmpStr, &trackPos);
    tmpStr = tmpStr.substr(trackPos + 1);
    lineEnd.second = std::stoi(tmpStr, &trackPos);

    std::cout << lineEnd.first << " " << lineEnd.second << std::endl;

    // get first pair

    // get second pair
}