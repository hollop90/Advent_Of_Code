#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

//#define AOC_PART_ONE

std::vector<int> draw;
std::vector<std::array<std::array<int, 5>, 5>> tables;
bool winState = false;

bool checkWin(const std::array<std::array<int, 5>, 5> &tablesArg)
{
    std::array<int, 5> colMatches = {};
    std::array<int, 5> rowMatches = {};

    for (int i = 0; i < tablesArg.size(); i++)
    {
        for (int j = 0; j < tables[0].size(); j++)
        {
            if (tablesArg[i][j] == 255)
            {
                colMatches[j] += 1;
                rowMatches[i] += 1;
            }
        }
    }

    return (std::find(colMatches.begin(), colMatches.end(), 5) != colMatches.end() ||
            std::find(rowMatches.begin(), rowMatches.end(), 5) != rowMatches.end());
}

int calcScore(const std::array<std::array<int, 5>, 5> &tablesArg, const int drawArg)
{
    int scoreSum = 0;
    int scoreTotal = 0;

    for (int i = 0; i < tablesArg.size(); i++)
    {
        for (int j = 0; j < tablesArg[0].size(); j++)
        {
            if (tablesArg[i][j] != 255)
            {
                scoreSum += tablesArg[i][j];
            }
        }
    }
    scoreTotal = scoreSum * drawArg;
    std::cout << ". With a score of: " << scoreTotal << '\n';
    return scoreTotal;
}

void playBingo(int drawArg, std::vector<std::array<std::array<int, 5>, 5>> &tablesArg, std::vector<bool> &winTrackArg)
{
    // off by one error caused by decrementing the size of the vector (I think)
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
        if (winTrackArg[i] == false)
        {
            if (checkWin(tablesArg[i]))
            {
                std::cout << "Winner at table: " << i;
                calcScore(tablesArg[i], drawArg);
                winTrackArg[i] = true;
                #ifdef AOC_PART_ONE
                winState = true;
                return;
                #endif
            }
        }
    }
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

void readFile(const std::string filename, std::vector<int> &drawArg, std::vector<std::array<std::array<int, 5>, 5>> &tablesArg)
{
    std::ifstream inputFile(filename);
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

void printTable(const std::array<std::array<int, 5>, 5> &tablesArg)
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

int main()
{
    readFile("input.txt", draw, tables);

    std::vector<bool> winTrack(tables.size());
    // This feels sub optimal ^^^

    // PART ONE: WHO WILL WIN **FIRST**
    for (auto num : draw)
    {
        playBingo(num, tables, winTrack);
        if (winState == true)
        {
            break;
        }
    }
}
