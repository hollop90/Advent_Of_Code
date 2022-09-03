#include <iostream>
#include <fstream>
#include <string>
#include <array>

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

    std::cout << "GAMMA: ";
    uint16_t gamma{};
    // int tracker = 5;

    // for (int i = 0; i < count.size(); i++)
    // {
    //     if (count[i] > 0)
    //     {
    //         gamma |= 1UL << (tracker - 1);
    //     }
    //     else
    //     {
    //         gamma &= ~(1UL << (tracker - 1));
    //     }
    //     tracker--;
    // }
    // std::cout << gamma;
    for(auto i: count){

        if(i > 0) {
            std::cout << 1;
        }else{
            std::cout << 0;
        }

    }
    std::cout << std::endl;

    std::cout << "EPSILON: ";
    for (auto i : count)
    {
        if (i > 0)
        {
            std::cout << 0;
        }
        else
        {
            std::cout << 1;
        }
    }
    std::cout << std::endl;
}