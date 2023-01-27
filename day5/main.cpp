#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <array>
#include <exception>

template <typename T>
void printPair(std::pair<T, T> aPair)
{
    std::cout << "[" << aPair.first << ", " << aPair.second << "]" << '\n';
}

template <typename T>
void parseLine(std::string a_line, std::pair<T,T> &a_pair, std::pair<T,T> &b_pair)
{
    // Example of input line: "0,9 -> 5,9"
    std::size_t     posTrack    = 0;
    std::string     delim       = "->";

    a_pair.first = std::stoi(a_line, &posTrack);
    a_line = a_line.substr(posTrack + 1);
    a_pair.second = std::stoi(a_line, &posTrack);
    a_line = a_line.substr(a_line.find(delim) + delim.length());
    
    b_pair.first = std::stoi(a_line, &posTrack);
    a_line = a_line.substr(posTrack + 1);
    b_pair.second = std::stoi(a_line, &posTrack);
}

int main()
{
    std::ifstream inFile("input.txt");

    std::string inString;
    std::getline(inFile, inString);

    std::pair<int, int> lineBegin;
    std::pair<int, int> lineEnd;

    auto line = std::make_pair(lineBegin, lineEnd);

    parseLine(inString, lineBegin, lineEnd);
    printPair(lineBegin);
    printPair(lineEnd);
}