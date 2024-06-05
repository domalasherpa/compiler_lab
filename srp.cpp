#include <iostream>
#include <cstring>

using namespace std;

char ip_sym[15], stack[15];
int ip_ptr = 0, st_ptr = 0, len, i;
char temp[2], temp2[2];
char act[15];

void check();

int main() {
    cout << "\n\t\tSHIFT REDUCE PARSER\n";
    cout << "\nGRAMMAR\n";
    cout << "\nE->E+E\nE->E/E";
    cout << "\nE->E*E\nE->a/b\n";
    cout << "\nEnter the input symbol: ";
    cin.getline(ip_sym, 15);
    cout << "\n\tStack Implementation Table";
    cout << "\nStack\t\tInput Symbol\t\tAction";
    cout << "\n______\t\t____________\t\t______\n";
    cout << "\n$\t\t" << ip_sym << "$\t\t\t--";

    strcpy(act, "shift ");
    temp[0] = ip_sym[ip_ptr];
    temp[1] = '\0';
    strcat(act, temp);
    len = strlen(ip_sym);

    for (i = 0; i <= len - 1; i++) {
        stack[st_ptr] = ip_sym[ip_ptr];
        stack[st_ptr + 1] = '\0';
        ip_sym[ip_ptr] = ' ';
        ip_ptr++;
        cout << "\n$" << stack << "\t\t" << ip_sym << "$\t\t\t" << act;
        strcpy(act, "shift ");
        temp[0] = ip_sym[ip_ptr];
        temp[1] = '\0';
        strcat(act, temp);
        check();
        st_ptr++;
    }

    st_ptr++;
    check();

    return 0;
}

void check() {
    int flag = 0;
    temp2[0] = stack[st_ptr];
    temp2[1] = '\0';

    if ((!strcasecmp(temp2, "a")) || (!strcasecmp(temp2, "b"))) {
        stack[st_ptr] = 'E';
        if (!strcasecmp(temp2, "a"))
            cout << "\n$" << stack << "\t\t" << ip_sym << "$\t\t\tE->a";
        else
            cout << "\n$" << stack << "\t\t" << ip_sym << "$\t\t\tE->b";
        flag = 1;
    }

    if ((!strcasecmp(temp2, "+")) || (!strcasecmp(temp2, "*")) || (!strcasecmp(temp2, "/"))) {
        flag = 1;
    }

    if ((!strcasecmp(stack, "E+E")) || (!strcasecmp(stack, "E/E")) || (!strcasecmp(stack, "E*E"))) {
        strcpy(stack, "E");
        st_ptr = 0;
        if (!strcasecmp(stack, "E+E"))
            cout << "\n$" << stack << "\t\t" << ip_sym << "$\t\t\tE->E+E";
        else if (!strcasecmp(stack, "E/E"))
            cout << "\n$" << stack << "\t\t" << ip_sym << "$\t\t\tE->E/E";
        else
            cout << "\n$" << stack << "\t\t" << ip_sym << "$\t\t\tE->E*E";
        flag = 1;
    }

    if (!strcasecmp(stack, "E") && ip_ptr == len) {
        cout << "\n$" << stack << "\t\t" << ip_sym << "$\t\t\tACCEPT\n";
        exit(0);
    }

    if (flag == 0) {
        cout << "\n" << stack << "\t\t\t" << ip_sym << "\t\t reject\n";
        exit(0);
    }

    return;
}
