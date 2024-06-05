// write a program to check where a valid comment or not.
#include <iostream>
using namespace std;

bool singleLineComment(string str){
    int state = 1;
    for(char s: str){
        if(state == 1 && s == '\n'){ //end of single line comment
            state = 2;
        }
        else if(state == 2){ //characters in the new line
            state = 3; 
        }
    }
    return state == 1 || state == 2;
}

bool multilineComment(string str){
    int state = 1;
    for(char s: str){
        if(state == 1 && s == '*'){
            state = 2;
        }
        else if(state == 2 && s == '/'){ //end of the comment & accepted
            state = 3;
        }
        else if(state == 2 && s != '*'){ // if * is not found
            state = 1;
        }
        else if(state == 3){
            state = 4;
        }
        else{
            state = 2;
        }
    }
    return state == 3;
}

bool parser(string str){
    int state = 0;

    if(str[0] == '/'){
        if(str[1] == '/'){
            return singleLineComment(str.substr(2));
        }
        if(str[1] == '*'){
            return multilineComment(str.substr(2));
        }
    }
    return false

}

int main(){
    string str;
    while(1){
        cout << "Enter a string: ";
        cin >> str;

        if(parser(str)){
            cout << str << " is a valid comment.\n";
        }
        else{
            cout << str << " is not a valid comment.\n"; 
        }
    }
    return 0;
}