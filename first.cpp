#include <iostream>
#include <cctype>
#include <vector>
#include <unordered_set>
using namespace std;

// Function prototypes
void computeFirst(unordered_set<char>&, char);
void addToResultSet(unordered_set<char>&, char);

// Global variables
int numOfProductions;
vector<string> productionSet;

int main() { 
    cout << "How many number of productions? ";
    cin >> numOfProductions;

    productionSet.resize(numOfProductions);

    for (int i = 0; i < numOfProductions; ++i) {
        cout << "Enter production number " << i + 1 << ": ";
        cin >> productionSet[i];
    }

    char choice;
    do {
        char c;
        cout << "\nFind the FIRST of: ";
        cin >> c;

        unordered_set<char> result;
        computeFirst(result, c);

        cout << "FIRST(" << c << ") = { ";
        for (char ch : result)
            cout << ch << " ";
        cout << "}\n";

        cout << "Press 'y' to continue: ";
        cin >> choice;
    } while (tolower(choice) == 'y');

    return 0;
}

void computeFirst(unordered_set<char>& result, char c) {
    if (!isupper(c)) {
        result.insert(c);
        return;
    }

    for (const string& production : productionSet) {
        if (production[0] == c) {
            int i = 2;
            while (production[i] != '\0') {
                unordered_set<char> subResult;
                computeFirst(subResult, production[i]);
                for (char ch : subResult)
                    addToResultSet(result, ch);
                if (subResult.find('$') == subResult.end())
                    break;
                ++i;
            }
        }
    }
}

void addToResultSet(unordered_set<char>& resultSet, char val) {
    resultSet.insert(val);
}
