#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <string>
#include <vector>

void maketable( std::fstream &fs, std::vector<std::array<std::array<int, 5>, 5>> &vec)
    {
        std::array<std::array<int, 5>, 5> tempTable;
        for (int i = 0; i < tempTable.size(); i++)
        {
            for (int j = 0; j < tempTable[i].size(); j++)
            {
                fs >> tempTable[i][j];
            }
        }

        vec.push_back(tempTable);
    }
    
int main()
{
    // load in a list for the draw
    // load bingo tables into memory
    std::cout << "AOC Day 4" << std::endl;
    std::fstream inFile;
    std::string inStr;
    std::vector<int> draw;
    std::stringstream ss;

    inFile.open("input.txt", std::ios::in);
    if (!inFile.is_open())
    {
        std::cerr << "ERROR: File not found.";
        exit(EXIT_FAILURE);
    }

    inFile >> inStr;
    ss << inStr;

    int drawNum{};
    char delim{};
    while (!ss.eof())
    {
        ss >> drawNum >> delim;
        draw.push_back(drawNum);
    }

    // // for (auto selection : draw)
    // // {
    // //     std::cout << selection;
    // //     if (selection != draw.at(draw.size() - 1))
    // //     {
    // //         std::cout << ", ";
    // //     }
    // // }
    // // std::cout << std::endl;

    // todo make a bingo table class
    std::vector<std::array<std::array<int, 5>, 5>> bingoTableList;
    
    

    while(!inFile.eof())
    {
        maketable(inFile, bingoTableList);
        //volatile auto count = bingoTableList.size();
    }
    // // std::array<std::array<int, 5>, 5> bingoTable;
    // // for (int i = 0; i < bingoTable.size(); i++)
    // // {
    // //     for (int j = 0; j < bingoTable[i].size(); j++)
    // //     {
    // //         inFile >> bingoTable[i][j];
    // //     }
    // // }

    // // for (int i = 0; i < bingoTable.size(); i++)
    // // {
    // //     for (int j = 0; j < bingoTable[i].size(); j++)
    // //     {
    // //         std::cout << bingoTable[i][j] << " ";
    // //     }
    // //     std::cout << std::endl;
    // // }
}