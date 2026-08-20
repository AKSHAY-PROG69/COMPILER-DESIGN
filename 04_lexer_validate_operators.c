/* 4. Lexical Analyzer to validate/recognize arithmetic operators +, -, *, / */
#include <stdio.h>
#include <ctype.h>

int isArithmeticOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main() {
    char expr[200];
    int i;
    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);

    for (i = 0; expr[i] != '\0' && expr[i] != '\n'; i++) {
        if (isArithmeticOperator(expr[i]))
            printf("'%c' is a valid arithmetic operator\n", expr[i]);
        else if (isalnum(expr[i]) || expr[i] == ' ')
            continue;
        else
            printf("'%c' is NOT a recognized arithmetic operator\n", expr[i]);
    }
    return 0;
}
