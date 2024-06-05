%{
//Write a program to check whether the input is digit or not
%}
%option noyywrap

%%
^[0-9]+$                                    {printf("Digit");}
^[0-9]*[a-zA-Z]+[0-9\w]*                   {printf("Not a Digit");}
%%

int main(){
    yylex(); //this function is given by Flex
    return 0;
}
