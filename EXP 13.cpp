#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[100];
int pos = 0;

/* Function declarations */
void E();
void Eprime();
void T();
void Tprime();
void F();

/* Error function */
void error()
{
    printf("\nString is NOT accepted by the grammar.\n");
    exit(0);
}

/* E -> T E' */
void E()
{
    printf("E -> T E'\n");

    T();
    Eprime();
}

/* E' -> + T E' | epsilon */
void Eprime()
{
    if (input[pos] == '+')
    {
        printf("E' -> + T E'\n");

        pos++;
        T();
        Eprime();
    }
    else
    {
        printf("E' -> epsilon\n");
    }
}

/* T -> F T' */
void T()
{
    printf("T -> F T'\n");

    F();
    Tprime();
}

/* T' -> * F T' | epsilon */
void Tprime()
{
    if (input[pos] == '*')
    {
        printf("T' -> * F T'\n");

        pos++;
        F();
        Tprime();
    }
    else
    {
        printf("T' -> epsilon\n");
    }
}

/* F -> ( E ) | id */
void F()
{
    if (input[pos] == 'i' && input[pos + 1] == 'd')
    {
        printf("F -> id\n");

        pos = pos + 2;
    }
    else if (input[pos] == '(')
    {
        printf("F -> ( E )\n");

        pos++;

        E();

        if (input[pos] == ')')
        {
            pos++;
        }
        else
        {
            error();
        }
    }
    else
    {
        error();
    }
}

/* Main function */
int main()
{
    printf("============================================\n");
    printf("       RECURSIVE DESCENT PARSER\n");
    printf("============================================\n");

    printf("\nGrammar:\n");
    printf("E  -> T E'\n");
    printf("E' -> + T E' | epsilon\n");
    printf("T  -> F T'\n");
    printf("T' -> * F T' | epsilon\n");
    printf("F  -> ( E ) | id\n");

    printf("\nEnter the input string: ");
    scanf("%s", input);

    printf("\nParsing Steps:\n");
    printf("--------------------------------------------\n");

    E();

    /* Check whether entire input is consumed */
    if (input[pos] == '\0')
    {
        printf("--------------------------------------------\n");
        printf("\nString is ACCEPTED by the grammar.\n");
    }
    else
    {
        printf("--------------------------------------------\n");
        printf("\nString is NOT ACCEPTED by the grammar.\n");
    }

    printf("\n============================================\n");
    printf("              PROGRAM ENDED\n");
    printf("============================================\n");

    return 0;
}