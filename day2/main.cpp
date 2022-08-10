#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string test = "Ugo";
std::string action;
int value = 0;




int posHorizontal = 0;
int posDepth = 0;
int posProduct = 0;
int posAim = 0;


int main(){
    std::ifstream inFile;
    inFile.open("input.txt", std::ios::in | std::ios::out);

    // Just experimenting with the stream API. This block gets the length of the file in bytes
    inFile.seekg(0, std::ios::end);
    int len = inFile.tellg();
    inFile.seekg(0, std::ios::beg);

    //! Problem 1
    // Find the product of the final horizontal position and the final depth
    while(!inFile.eof()){
        inFile >> action;
        inFile >> value;

        // By using std::string we can simply make comparisons by using '=='
        if (action == "forward"){
            posHorizontal += value;
        }
        else if (action == "up"){
            posDepth -= value;
        }
        else if (action == "down"){
            posDepth += value;
        }
        
        // Reset the variables for the next loop
        action.clear();
        value = 0;
    }

    posProduct = posDepth * posHorizontal;

    std::cout << "\nProblem 1:\n" 
    << "Horizonal position: " << posHorizontal << '\n'
    << "Depth position: " << posDepth << '\n'
    << "Product: " << posProduct << '\n';

    //! Problem 2
    // Change how you understand the data. Aim essentially represents if the sub is pointing up or down.
    // No real trigonometry is used here, but we multiply the Aim by the posHorizontal to pretend that we're doing real maths
    // Again the answer is the product of the final position values

    posHorizontal = 0;
    posDepth = 0;
    posProduct = 0;
    posAim = 0;

    // Clearing the status bits and moving the file pointer back to the beginning
    // This allows us to read the file again
    inFile.clear();
    inFile.seekg(0, std::ios::beg);
    while(!inFile.eof()){
        inFile >> action;
        inFile >> value;

        
        if (action == "forward"){
            posHorizontal += value;
            posDepth += value * posAim;
        }
        else if (action == "up"){
            posAim -= value;
        }
        else if (action == "down"){
            posAim += value;
        }
        
        action.clear();
        value = 0;
    }
    inFile.close();

    posProduct = posDepth * posHorizontal;
    
    std::cout << "\nProblem 2:\n"
    << "Horizonal position: " << posHorizontal << '\n'
    << "Depth position: " << posDepth << '\n'
    << "Product: " << posProduct << '\n';
}
