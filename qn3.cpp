#include <iostream>
using namespace std;

bool parser(string str) {
    int state = 0; // Starting state
    for(char s: str){
        if(state == 0 && s == 'B'){
            state = 1;
        }
        else if(state == 1 && s == 'a'){
            state = 2;
        }
        else if(state == 2 && s == 'a'){
            state = 3;
        }
        else if(state == 3 && s == 'b'){
            state = 4;
        }
        else{
            return false;
        }
    }
    return state == 4; // Check if the final state is the accepting state
}

int main(){
    string str;

    while(1){
        cout << "Enter the string: ";
        cin >> str;
        if(parser(str)){
            cout << str << " is accepted.\n";
        }
        else{
            cout << str << " is not accepted.\n";
        }
    }
    return 0;
}
