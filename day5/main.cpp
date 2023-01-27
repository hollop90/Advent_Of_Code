#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <array>
#include <exception>
#include <vector>

template <typename T>
void printPair(std::pair<T, T> _pair)
{
    std::cout << "[" << _pair.first << ", " << _pair.second << "]" << '\n';
}

std::pair<std::pair<int, int>, std::pair<int, int>> 
parseLine ( std::string _line)
{
    // Example of input line: "0,9 -> 5,9"
    std::pair<int, int> begin;
    std::pair<int, int> end;
    std::size_t posTrack = 0;
    std::string delim = "->";
    std::string tmp_string;

    tmp_string = _line.substr(0, _line.find(delim));
    begin.first = std::stoi(tmp_string, &posTrack);
    tmp_string = tmp_string.substr(posTrack + 1);
    begin.second = std::stoi(tmp_string);

    tmp_string = _line.substr(_line.find(delim) + delim.length());
    end.first = std::stoi(tmp_string, &posTrack);
    tmp_string = tmp_string.substr(posTrack + 1);
    end.second = std::stoi(tmp_string);

    return std::make_pair(begin, end);
}

int main()
{
    std::ifstream inFile("input.txt");
    std::string inString;

    std::vector< std::pair< std::pair<int, int>, 
                            std::pair<int, int> > > myLines;

    while (!inFile.eof())
    {
        std::getline(inFile, inString);
        if (!inString.compare(""))
            break;
        myLines.push_back(parseLine(inString));
    }
    
    for (auto line : myLines)
    {
        std::cout << "Begin:\t";
        printPair(line.first);
        std::cout << "End:\t";
        printPair(line.second);
        std::cout << "\n";
    }
}