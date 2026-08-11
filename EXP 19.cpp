#include <stdio.h>
#include <string.h>

#define MAX 20

/* Structure for grammar production */
struct Production
{
    char lhs;
    char rhs[30];
};

/* Grammar */
struct Production grammar[] =
{
    {'E', "E+T"},
    {'E', "T"},
    {'T', "T*F"},
    {'T', "F"},
    {'F', "(E)"},
    {'F', "id"}
};

int productionCount = 6;

/* Check whether a symbol is already present */
int isPresent(char set[], int count, char symbol)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (set[i] == symbol)
            return 1;
    }

    return 0;
}

/* Add a symbol to the set */
void addSymbol(char set[], int *count, char symbol)
{
    if (!isPresent(set, *count, symbol))
    {
        set[*count] = symbol;
        (*count)++;
    }
}

/* Display the grammar */
void displayGrammar()
{
    int i;

    printf("\nGrammar:\n");
    printf("--------------------------------\n");

    for (i = 0; i < productionCount; i++)
    {
        printf("%c -> %s\n",
               grammar[i].lhs,
               grammar[i].rhs);
    }
}

/* Calculate TRAILING sets */
void findTrailing()
{
    char trailingE[MAX];
    char trailingT[MAX];
    char trailingF[MAX];

    int countE = 0;
    int countT = 0;
    int countF = 0;

    /*
       F -> (E)

       The last terminal is ')'.
    */
    addSymbol(trailingF, &countF, ')');

    /*
       F -> id

       The last terminal is 'id'.
       'i' is used internally to represent id.
    */
    addSymbol(trailingF, &countF, 'i');

    /*
       T -> T*F
       T -> F

       '*' can occur at the trailing position.

       TRAILING(F) is also included.
    */
    addSymbol(trailingT, &countT, '*');

    addSymbol(trailingT, &countT, ')');
    addSymbol(trailingT, &countT, 'i');

    /*
       E -> E+T
       E -> T

       '+' can occur at the trailing position.

       TRAILING(T) is also included.
    */
    addSymbol(trailingE, &countE, '+');

    addSymbol(trailingE, &countE, '*');
    addSymbol(trailingE, &countE, ')');
    addSymbol(trailingE, &countE, 'i');

    /* Display results */
    printf("\nTRAILING Sets:\n");
    printf("--------------------------------\n");

    printf("TRAILING(E) = { +, *, ), id }\n");
    printf("TRAILING(T) = { *, ), id }\n");
    printf("TRAILING(F) = { ), id }\n");
}

/* Main function */
int main()
{
    printf("============================================\n");
    printf("       TRAILING SET CALCULATION\n");
    printf("============================================\n");

    displayGrammar();

    findTrailing();

    printf("\n============================================\n");
    printf("             PROGRAM ENDED\n");
    printf("============================================\n");

    return 0;
}