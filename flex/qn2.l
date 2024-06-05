%{
    //Write a program to identify tokens.
%}

%option noyywrap

%%
bool|int|float|double|char|void                 {printf("keyword");}
[+,-]?[0-9]+[.]?[0-9]+                          {printf("Constants");}
[;."']+                                         {printf("punctuations");}
[!@#$%^&*()]+                                   {printf("Special Chars");}
[_]?[a-zA-Z]+[0-9]*                             {printf("Identifiers");}
%%


int main(){
    yylex();
    return 0;
}