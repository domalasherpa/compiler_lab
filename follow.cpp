#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int n, I = 0, j = 0;
char a[10][10], Result[10];
char subResult[20];

void follow(char Result[], char c);
void first(char Result[], char c);
void addToResultSet(char[], char);

int main() {
    int choice;
    char c;
    
    cout << "Enter the no. of productions: ";
    cin >> n;

    cout << "Enter " << n << " productions\nProduction with multiple terms should be given as separate productions\n";
    for (I = 0; I < n; I++)
        cin >> a[I];
    
    do {
        cout << "Find FOLLOW of: ";
        cin >> c;
        follow(Result, c);
        
        cout << "FOLLOW(" << c << ") = { ";
        for (I = 0; Result[I] != '\0'; I++)
            cout << Result[I] << " ";
        cout << "}\n";

        cout << "Do you want to continue? (Press 1 to continue): ";
        cin >> choice;
    } while (choice == 1);

    return 0;
}

void follow(char Result[], char c) {
    int k;
    subResult[0] = '\0';
    Result[0] = '\0';

    if (a[0][0] == c)
        addToResultSet(Result, '$');

    for (I = 0; I < n; I++) {
        for (j = 2; j < strlen(a[I]); j++) {
            if (a[I][j] == c) {
                if (a[I][j + 1] != '\0')
                    first(subResult, a[I][j + 1]);
                if (a[I][j + 1] == '\0' && c != a[I][0])
                    follow(subResult, a[I][0]);
                for (k = 0; subResult[k] != '\0'; k++)
                    addToResultSet(Result, subResult[k]); 
            }
        }
    }
}

void first(char Result[], char c) {
    int k, m;
    
    if (!(isupper(c)) && c != '#')
        addToResultSet(Result, c);

    for (k = 0; k < n; k++) {
        if (a[k][0] == c) {
            if (a[k][2] == '#' && c != a[I][0])
                follow(Result, a[I][0]);
            else if (!(isupper(a[k][2])) && a[k][2] != '#')
                addToResultSet(Result, a[k][2]);
            else
                first(Result, a[k][2]);
            
            for (m = 0; Result[m] != '\0'; m++)
                addToResultSet(Result, Result[m]);
        }
    }
}

void addToResultSet(char Result[], char val) {
    int k;
    for (k = 0; Result[k] != '\0'; k++) {
        if (Result[k] == val)
            return;
    }
    Result[k] = val;
    Result[k + 1] = '\0';
}
