#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <bitset>
#include <chrono>
#include <vector>
#include <algorithm>

constexpr int NUM_BITS = 12;

/**
 * TODO Make some functions for repeated operations (finding MCB and LCB, converting to a bitset etc.)
 * TODO Remove the dependance of compile time constants for the bitsets (eg. give them a large size and only use whats needed)
 */

int main()
{
    std::fstream inFile;
    std::string inData;
    std::vector<std::string> byteList;
    int oneCnt{};
    int zeroCnt{};
    std::bitset<NUM_BITS> gamma;
    std::bitset<NUM_BITS> epsilon;

    inFile.open("input.txt", std::ios::in);
    while (!inFile.eof())
    {
        inFile >> inData;
        byteList.push_back(inData);
    }
    inFile.close();

    int wordSize = byteList[0].size();

    for (int i = 0; i < wordSize; i++)
    {
        for (auto bit : byteList)
        {
            if (bit[i] == '1')
            {
                oneCnt++;
            }
            else if (bit[i] == '0')
            {
                zeroCnt++;
            }
        }

        if (oneCnt > zeroCnt)
        {
            gamma.set((wordSize - 1) - i);
        }
        else
        {
            gamma.set((wordSize - 1) - i, 0);
        }
        oneCnt = zeroCnt = 0;
    }

    epsilon = gamma;
    epsilon.flip();

    std::cout << "#### PART ONE OUTPUT ####" << std::endl;
    std::cout << "GAMMA: " << gamma.to_string() << '\t' << gamma.to_ulong() << std::endl;
    std::cout << "EPSILON: " << epsilon << '\t' << epsilon.to_ulong() << std::endl;
    std::cout << "POWER: " << (gamma.to_ulong() * epsilon.to_ulong()) << std::endl;

    std::vector<std::string> filterList = byteList;
    std::bitset<NUM_BITS> oxygen;
    std::bitset<NUM_BITS> carbon;
    char MCB{};
    int removedCnt {};
    oneCnt = zeroCnt = 0;

    for (int i = 0; i < wordSize; i++)
    {
        for (auto bit : filterList)
        {
            if (bit.compare("N"))
            {

                if (bit[i] == '1')
                {
                    oneCnt++;
                }
                else if (bit[i] == '0')
                {
                    zeroCnt++;
                }
            }
        }

        if (oneCnt > zeroCnt)
        {
            MCB = '1';
        }
        else if (oneCnt < zeroCnt)
        {
            MCB = '0';
        }
        else if (oneCnt == zeroCnt)
        {
            MCB = '1';
        }

        for (auto &bit : filterList)
        {
            if (bit[i] != MCB)
            {
                bit = "N";
            }
        }

        oneCnt = zeroCnt = 0;
        if (filterList.size() -  std::count(filterList.begin(), filterList.end(), "N") == 1)
        {
            break;
        }
    }

    for (auto word : filterList)
    {
        if (word.compare("N"))
        {
            for (int k = 0; k < wordSize; k++)
            {
                if (word[k] == '1')
                {
                    oxygen.set((wordSize - 1) - k);
                }
                else if (word[k] == '0')
                {
                    oxygen.set((wordSize - 1) - k, 0);
                }
            }
        }
    }

    filterList = byteList;
    char LCB{};
    oneCnt = zeroCnt = 0;

    for (int i = 0; i < wordSize; i++)
    {
        for (auto bit : filterList)
        {
            if (bit.compare("N"))
            {

                if (bit[i] == '1')
                {
                    oneCnt++;
                }
                else if (bit[i] == '0')
                {
                    zeroCnt++;
                }
            }
        }

        if (oneCnt < zeroCnt)
        {
            LCB = '1';
        }
        else if (oneCnt > zeroCnt)
        {
            LCB = '0';
        }
        else if (oneCnt == zeroCnt)
        {
            LCB = '0';
        }

        for (auto &bit : filterList)
        {
            if (bit[i] != LCB)
            {
                bit = "N";
            }
        }

        oneCnt = zeroCnt = 0;
        if (filterList.size() -  std::count(filterList.begin(), filterList.end(), "N") == 1)
        {
            break;
        }
    }

    for (auto word : filterList)
    {
        if (word.compare("N"))
        {
            for (int k = 0; k < wordSize; k++)
            {
                if (word[k] == '1')
                {
                    carbon.set((wordSize - 1) - k);
                }
                else if (word[k] == '0')
                {
                    carbon.set((wordSize - 1) - k, 0);
                }
            }
        }
    }

    std::cout << "#### PART TWO OUTPUT ####" << std::endl;
    std::cout << "OXYGEN: " << oxygen.to_string() << '\t' << oxygen.to_ulong() << std::endl;
    std::cout << "CARBON: " << carbon << '\t' << carbon.to_ulong() << std::endl;
    std::cout << "LIFE: " << (oxygen.to_ulong() * carbon.to_ulong()) << std::endl;
    getchar();
}