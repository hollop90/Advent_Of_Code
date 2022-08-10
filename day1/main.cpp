#include <iostream>
#include <fstream>
#define DEBUG_OUT

#define INPUT_SIZE 2000
#define SLIDING_WINDOW 3

std::fstream inFile;
int inBuff[INPUT_SIZE];


int increments = 0;

int winA[SLIDING_WINDOW];
int winB[SLIDING_WINDOW];

int sumA = 0;
int sumB = 0;

int main(){
    //! Problem 1: 
    // How many times does the depth increase relative to the previous measurment

    inFile.open("input");
    for (int i = 0; i < INPUT_SIZE; i++){
        inFile >> inBuff[i];
        #ifdef DEBUG_OUT
        //std::cout << inBuff[i] << '\n';
        #endif //DEBUG_OUT
    }
    inFile.close();

    for(int i = 1; i < INPUT_SIZE; i++){
        if(inBuff[i] > inBuff[i-1]){
            increments++;
        }
    }
    
    std::cout << "PART ONE " << increments << '\n';
    increments = 0;


    //! Problem 2:
    //  Count how many times the sum of a window increses relative to the previous window

    // for loop to go through all the elements
        // in each loop
        //  fill up the array
        //  get the sum
        //  compare
        //  increment a value
	
    for (int i = 0; i < (INPUT_SIZE - SLIDING_WINDOW); i++){ // Make sure that the loop ends when winB contains the last element of inBuff
        
        // Filling up each window and calculating their sum in the same loop. 
        // 'i+j' is used to fill in the windows relative to where 'i' points to within inBuff. The '+1' is how far ahead winB is
        for(int j = 0; j < 3; j++){
            winA[j] = inBuff[i+j];
            winB[j] = inBuff[i+j+1];

            sumA += winA[j];
            sumB += winB[j];
        }

        #ifdef DEBUG_OUT
        std::cout << "SumA: " << sumA << '\n'
                  << "SumB: " << sumB << '\n'
                  << "====="  << '\n';
        #endif //DEBUG_OUT
        if (sumA < sumB){
            increments++;
        }
        sumA = 0;
        sumB = 0;

    }

    std::cout << "PART TWO " << increments << '\n';
    increments = 0;
}
