//dfa that accepts the string abba
#include <iostream>
#include <cctype>

using namespace std;

bool parser(string str) {
    int state = 0; // Starting state

    for(char s: str){
        if(state == 0 && (s == '_' || isalpha(s))){
            state = 1;
        }
        else if(state == 1 && (s == '_' || isdigit(s) || isalpha(s))){
            state = 1;
        }
        else{
            return false;
        }
    }
    return state == 1; // Check if the final state is the accepting state
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
