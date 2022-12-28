#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> draw;
std::vector<std::array<std::array<int, 5>, 5>> tables;
bool winState = false;

int playBingo(int drawArg, std::vector<std::array<std::array<int, 5>, 5>> &tablesArg)
{
    // draw a number
    // loop through every single table
    for (int i = 0; i < tablesArg.size(); i++)
    {
        for (int j = 0; j < tablesArg[0].size(); j++)
        {
            for (int k = 0; k < tablesArg[0][0].size(); k++)
            {
                if (tablesArg[i][j][k] == drawArg)
                {
                    tablesArg[i][j][k] = 255;
                }
            }
        }

        // After each table check if it has won
        std::array<int, 5> colMatches = {};
        std::array<int, 5> rowMatches = {};
        for (int j = 0; j < tablesArg[0].size(); j++)
        {
            for (int k = 0; k < tablesArg[0][0].size(); k++)
            {
                if (tablesArg[i][j][k] == 255)
                {
                    colMatches[k] += 1;
                    rowMatches[j] += 1;
                }
            }
        }

        int scoreSum = 0;
        int scorTotal = 0;
        if (std::find(colMatches.begin(), colMatches.end(), 5) != colMatches.end())
        {
            winState = true;
            for (int j = 0; j < tablesArg[0].size(); j++)
            {
                for (int k = 0; k < tablesArg[0][0].size(); k++)
                {
                    if (tablesArg[i][j][k] != 255)
                    {
                        scoreSum += tablesArg[i][j][k];
                    }
                }
            }
            scorTotal = scoreSum * drawArg;
            std::cout << "Winner found at table: " << i << ". With a score of: " << scorTotal << '\n';
            return scorTotal;
        }

        if (std::find(rowMatches.begin(), rowMatches.end(), 5) != rowMatches.end())
        {
            winState = true;
            for (int j = 0; j < tablesArg[0].size(); j++)
            {
                for (int k = 0; k < tablesArg[0][0].size(); k++)
                {
                    if (tablesArg[i][j][k] != 255)
                    {
                        scoreSum += tablesArg[i][j][k];
                    }
                }
            }
            scorTotal = scoreSum * drawArg;
            std::cout << "Winner found at table: " << i << ". With a score of: " << scorTotal << '\n';
            return scorTotal;
        }
    }
    // loop through table elements
    // mark table element if it mathces current draw number
    //
    return 0;
}

void makeTables(std::ifstream &fs, std::vector<std::array<std::array<int, 5>, 5>> &vec)
{
    // Fill the array with somehting so I can detect if new data was written
    std::array<std::array<int, 5>, 5> tempTable = {};
    tempTable.fill({{512, 512, 512, 512, 512}});

    for (int i = 0; i < tempTable.size(); i++)
    {
        for (int j = 0; j < tempTable[i].size(); j++)
        {
            int prevElem = tempTable[i][j];
            fs >> tempTable[i][j];
            // Check if any new data was read
            if (tempTable[i][j] == prevElem)
            {
                return;
            }
        }
    }

    vec.push_back(tempTable);
}

void readFile(std::string filename, std::vector<int> &drawArg, std::vector<std::array<std::array<int, 5>, 5>> &tablesArg)
{
    std::ifstream inputFile(filename.c_str());
    std::string tmpStr;
    std::string delim = ",";
    std::size_t pos = 0;

    inputFile >> tmpStr;

    while ((pos = tmpStr.find(delim)) != std::string::npos)
    {
        drawArg.push_back(std::stoi(tmpStr.substr(0, pos)));
        tmpStr.erase(0, tmpStr.find(delim) + delim.length());
    }
    // Add the very last element to the vector
    drawArg.push_back(std::stoi(tmpStr));

    while (!inputFile.eof())
    {
        //// // TODO: Last two tables are the same
        makeTables(inputFile, tablesArg);
    }
    // RAII should take care of this
    // inputFile.close();
}

void printTable(std::array<std::array<int, 5>, 5> tablesArg)
{
    std::cout << '\n';
    for (auto row : tablesArg)
    {
        for (auto elem : row)
        {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }
}

// int checkWinner(std::vector<std::array<std::array<int, 5>, 5>> &tablesArg, )
// {

// }
int main()
{
    readFile("input.txt", draw, tables);

    // PART ONE: WHO WILL WIN **FIRST**
    for (auto num : draw)
    {
        playBingo(num, tables);
        if (winState == true)
        {
            break;
        }
    }
    // PART TWO: WHO WILL WIN **LAST**
    // printAns();
}