#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    string op, arg1, arg2, result;

    while (inputFile >> op >> arg1 >> arg2 >> result) {
        if (op == "+") {
            outputFile << "\n MOV R0," << arg1;
            outputFile << "\n ADD R0," << arg2;  
            outputFile << "\n MOV " << result << ",R0";
        }
        else if (op == "*") {
            outputFile << "\n MOV R0," << arg1;
            outputFile << "\n MUL R0," << arg2;
            outputFile << "\n MOV " << result << ", R0";
        }
        else if (op == "-") {
            outputFile << "\n MOV R0," << arg1;
            outputFile << "\n SUB R0," << arg2;
            outputFile << "\n MOV " << result << ",R0";
        }
        else if (op == "/") {
            outputFile << "\n MOV R0," << arg1;
            outputFile << "\n DIV R0," << arg2;
            outputFile << "\n MOV " << result << ",R0";
        }
        else if (op == "=") {
            outputFile << "\n MOV R0," << arg1;
            outputFile << "\n MOV " << result << ",R0";
        }
    }

    inputFile.close();
    outputFile.close();
    cout << "machine code sucessfully generated.";

    return 0;
}
