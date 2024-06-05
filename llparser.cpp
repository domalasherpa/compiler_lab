#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

char s[20], stack[20];

int main()
{
    char m[5][6][4] = {"tb", " ", " ", "tb", " ", " ", " ", "+tb", " ", " ", "n", "n", "fc", " ", " ",
                       "fc", " ", " ", " ", "n", "*fc", " a", "n", "n", "i", " ", " ", "(e)", " ", " "};
    int size[5][6] = {{2, 0, 0, 2, 0, 0}, {0, 3, 0, 0, 1, 1}, {2, 0, 0, 0, 1, 3}, {0, 1, 1, 1, 0, 0}, {3, 0, 0, 0, 1, 0}};
    int i, j, k, n, str1, str2;

    cout << "\nEnter the input string: ";
    cin >> s;
    strcat(s, "$");
    n = strlen(s);
    stack[0] = '$';
    stack[1] = 'e';

    i = 1;
    j = 0;
    cout << "\nStack Input\n"; 
    cout << "__________________\n";
    while ((stack[i] != '$') && (s[j] != '$'))
    {
        if (stack[i] == s[j])
        {
            i--;
            j++;
        }
        switch (stack[i])
        {
        case 'e':
            str1 = 0;
            break;
        case 'b':
            str1 = 1;
            break;
        case 't':
            str1 = 2;
            break;
        case 'c':
            str1 = 3;
            break;
        case 'f':
            str1 = 4;
            break;
        }
        switch (s[j])
        {

        case 'i':
            str2 = 0;
            break;
        case '+':
            str2 = 1;
            break;
        case '*':
            str2 = 2;
            break;
        case '(':
            str2 = 3;
            break;
        case ')':
            str2 = 4;
            break;
        case '$':
            str2 = 5;
            break;
        }
        if (m[str1][str2][0] == '\0')
        {
            cout << "\nERROR";
            exit(0);
        }
        else if (m[str1][str2][0] == 'n')
            i--;
        else if (m[str1][str2][0] == 'i')
            stack[i] = 'i';
        else
        {
            for (k = size[str1][str2] - 1; k >= 0; k--)
            {
                stack[i] = m[str1][str2][k];
                i++;
            }
            i--;
        }
        for (k = 0; k <= i; k++)
            cout << " " << stack[k];
        cout << " \t\t";
        for (k = j; k <= n; k++)
            cout << s[k];
        cout << " \n ";
    }
    cout << "\nSUCCESS";
    return 0;
}
