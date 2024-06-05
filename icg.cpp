#include <iostream>
#include <cstring>

using namespace std;

struct Operator {
    int position;
    char symbol;
};

int i = 1, j = 0, no = 0, tmpch = 90;
char str[100], leftExp[15], rightExp[15]; // Renamed from left and right

void findopr();
void explore();
void fleft(int);
void fright(int);

struct exp {
    int pos;
    char op;
} k[15];

int main() {
    cout << "\t\tINTERMEDIATE CODE GENERATION\n\n";
    cout << "Enter the Expression: ";
    cin >> str;
    cout << "The intermediate code:\tExpression\n";
    findopr();
    explore();
    return 0;
}

void findopr() {
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':') {
            k[j].pos = i;
            k[j++].op = ':';
        }
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/') {
            k[j].pos = i;
            k[j++].op = '/';
        }
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '*') {
            k[j].pos = i;
            k[j++].op = '*';
        }
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+') {
            k[j].pos = i;
            k[j++].op = '+';
        }
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            k[j].pos = i;
            k[j++].op = '-';
        }
    }
}

void explore() {
    i = 1;
    while (k[i].op != '\0') {
        fleft(k[i].pos);
        fright(k[i].pos);
        str[k[i].pos] = tmpch--;
        cout << "\t" << str[k[i].pos] << " := " << leftExp << k[i].op << rightExp << "\t\t";
        for (j = 0; j < strlen(str); j++) {
            if (str[j] != '$') {
                cout << str[j];
            }
        }
        cout << endl;
        i++;
    }
    fright(-1);
    if (no == 0) { 
        fleft(strlen(str));
        cout << "\t" << rightExp << " := " << leftExp << "\n";
        exit(0);
    }
    cout << "\t" << rightExp << " := " << str[k[--i].pos];
}

void fleft(int x) {
    int w = 0, flag = 0;
    x--;
    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '=' && str[x] != '\0' &&
           str[x] != '-' && str[x] != '/' && str[x] != ':') {
        if (str[x] != '$' && flag == 0) {
            leftExp[w++] = str[x];
            leftExp[w] = '\0';
            str[x] = '$';
            flag = 1;
        }
        x--;
    }
}

void fright(int x) {
    int w = 0, flag = 0;
    x++;
    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '\0' &&
           str[x] != '=' && str[x] != ':' && str[x] != '-' && str[x] != '/') {
        if (str[x] != '$' && flag == 0) {
            rightExp[w++] = str[x];
            rightExp[w] = '\0';
            str[x] = '$';
            flag = 1;
        }
        x++;
    }
}
