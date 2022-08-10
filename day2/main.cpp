#include <iostream>
#include <fstream>
#include <string.h>

char action[20];
int value = 0;

int posHorizontal = 0;
int posDepth = 0;
int posProduct = 0;

int main(){
    std::fstream inFile;
    inFile.open("input.txt");
    int i = 0;

    // read a line from the file
    // copy the "action" into a string and the value into an int
    // use a switch case block to increment or decrement the appropritae variables
    // multiply the final position values together

    while(!inFile.eof()){
        inFile >> action;
        inFile >> value;

        
        if (strcmp(action, "forward") == 0){
            posHorizontal++;
        }
        else if (strcmp(action, "up") == 0){
            posDepth--;
        }
        else if (strcmp(action, "down") == 0){
            posDepth++;
        }
        else{
            std::cout << "Bad stuff" << std::endl;
        }
        std::cout << i++ << '\n';
    }

    std::cout << "Horizonal position: " << posHorizontal << '\n';
    std::cout << "Depth position: " << posDepth;
    std::cout << "Product: " << posProduct;
}
