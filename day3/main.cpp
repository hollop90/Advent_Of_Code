#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <bitset>
#include <chrono>

constexpr int NUM_BITS = 12;
std::array<int, NUM_BITS> count = {};

int main()
{
    std::fstream inFile("input.txt");
    std::string inData;
    std::cout << inData << '\n';

    // loop through the file
    while (!inFile.eof())
    {
        inFile >> inData;

        // loop through each line. Increment or decrtement a value depending
        // on if the current character is a one or a zero
        for (int i = 0; i < NUM_BITS; i++)
        {
            if (inData[i] == '0')
            {
                count[i]++; // ZERO
            }
            else
            {
                count[i]--; // ONE
            }
        }
    }

    std::bitset<NUM_BITS> gamma;
    int tracker = count.size();

    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] > 0)
        {
            gamma.set(tracker -1);
        }
        else
        {
            gamma.set(tracker - 1, 0);
        }
        tracker--;
    }

    std::cout << "GAMMA: " << gamma.to_ulong() << std::endl;

    std::bitset<NUM_BITS> epsilon(gamma);
    epsilon.flip();

    std::cout << "EPSILON: " << epsilon.to_ulong() << std::endl;

    std::cout << "POWER: " << (gamma.to_ulong() * epsilon.to_ulong()) << std::endl;
}