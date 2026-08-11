#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[100];
int pos = 0;

/* Function declarations */
int E();
int Eprime();
int T();
int Tprime();
int F();

/* E -> T E' */
int E()
{
    printf("E -> T E'\n");

    if (T())
    {
        if (Eprime())
            return 1;
    }

    return 0;
}

/* E' -> + T E' | epsilon */
int Eprime()
{
    if (input[pos] == '+')
    {
        printf("E' -> + T E'\n");

        pos++;

        if (T())
        {
            if (Eprime())
                return 1;
        }

        return 0;
    }

    printf("E' -> epsilon\n");

    return 1;
}

/* T -> F T' */
int T()
{
    printf("T -> F T'\n");

    if (F())
    {
        if (Tprime())
            return 1;
    }

    return 0;
}

/* T' -> * F T' | epsilon */
int Tprime()
{
    if (input[pos] == '*')
    {
        printf("T' -> * F T'\n");

        pos++;

        if (F())
        {
            if (Tprime())
                return 1;
        }

        return 0;
    }

    printf("T' -> epsilon\n");

    return 1;
}

/* F -> ( E ) | id */
int F()
{
    /* F -> id */
    if (input[pos] == 'i' &&
        input[pos + 1] == 'd')
    {
        printf("F -> id\n");

        pos = pos + 2;

        return 1;
    }

    /* F -> ( E ) */
    if (input[pos] == '(')
    {
        printf("F -> ( E )\n");

        pos++;

        if (E())
        {
            if (input[pos] == ')')
            {
                pos++;

                return 1;
            }
        }

        return 0;
    }

    return 0;
}

/* Main function */
int main()
{
    printf("============================================\n");
    printf("          TOP-DOWN PARSER\n");
    printf("============================================\n");

    printf("\nGrammar:\n");
    printf("--------------------------------------------\n");

    printf("E  -> T E'\n");
    printf("E' -> + T E' | epsilon\n");
    printf("T  -> F T'\n");
    printf("T' -> * F T' | epsilon\n");
    printf("F  -> ( E ) | id\n");

    printf("\nEnter input string: ");
    scanf("%s", input);

    printf("\nParsing Process:\n");
    printf("--------------------------------------------\n");

    if (E() && input[pos] == '\0')
    {
        printf("--------------------------------------------\n");
        printf("\nInput string is ACCEPTED.\n");
        printf("The string satisfies the grammar.\n");
    }
    else
    {
        printf("--------------------------------------------\n");
        printf("\nInput string is NOT ACCEPTED.\n");
        printf("The string does not satisfy the grammar.\n");
    }

    printf("\n============================================\n");
    printf("              PROGRAM ENDED\n");
    printf("============================================\n");

    return 0;
}