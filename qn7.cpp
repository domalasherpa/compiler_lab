// Q. Write a program to count number of operators used in given input.
#include <iostream>
#define OPERATOR_COUNT 12
#define CHAR_SET_SIZE 127

bool operatorSet[CHAR_SET_SIZE];
using namespace std;

void initializeOperatorSet() {
    for (int i = 0; i < CHAR_SET_SIZE; i++) {
        operatorSet[i] = false;
    }
    
    // List of operators
    char operators[] = {'+', '-', '*', '/', '%', '=', '<', '>', '!', '&', '|'};

    // Adding operators to the set
    for (int i = 0; i < OPERATOR_COUNT; i++) {
        operatorSet[(int)operators[i]] = true;
    }
}

int operatorCount(string str){
    int count = 0;
    
    for(char s: str){
        if(operatorSet[(int)s]){
            ++count;
        }
    }
    return count;
}

int main(){

    string str;
    initializeOperatorSet();
    while(1){
        cout << "Enter a string: ";
        cin >> str;

        cout<< "No of operators: "<< operatorCount(str) << "\n";
    }
    return 0;
}