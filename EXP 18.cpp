#include <stdio.h>
#include <string.h>

#define MAX 20

/* Structure for grammar production */
struct Production
{
    char lhs;
    char rhs[30];
};

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

/* Check whether symbol is already present */
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

/* Add symbol to set */
void addSymbol(char set[], int *count, char symbol)
{
    if (!isPresent(set, *count, symbol))
    {
        set[*count] = symbol;
        (*count)++;
    }
}

/* Display grammar */
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

/* Find LEADING sets */
void findLeading()
{
    char leadingE[MAX];
    char leadingT[MAX];
    char leadingF[MAX];

    int countE = 0;
    int countT = 0;
    int countF = 0;

    /*
       F -> (E)
       The first terminal is '('.
    */
    addSymbol(leadingF, &countF, '(');

    /*
       F -> id
       The first terminal is 'id'.
       We represent id using 'i'.
    */
    addSymbol(leadingF, &countF, 'i');

    /*
       T -> T*F | F

       From T -> T*F:
       '*' can occur as a leading operator.

       From T -> F:
       Everything in LEADING(F) is also
       in LEADING(T).
    */
    addSymbol(leadingT, &countT, '*');

    addSymbol(leadingT, &countT, '(');
    addSymbol(leadingT, &countT, 'i');

    /*
       E -> E+T | T

       From E -> E+T:
       '+' can occur as a leading operator.

       From E -> T:
       Everything in LEADING(T) is also
       in LEADING(E).
    */
    addSymbol(leadingE, &countE, '+');

    addSymbol(leadingE, &countE, '*');
    addSymbol(leadingE, &countE, '(');
    addSymbol(leadingE, &countE, 'i');

    /* Display results */
    printf("\nLEADING Sets:\n");
    printf("--------------------------------\n");

    printf("LEADING(E) = { +, *, (, id }\n");
    printf("LEADING(T) = { *, (, id }\n");
    printf("LEADING(F) = { (, id }\n");
}

/* Main function */
int main()
{
    printf("============================================\n");
    printf("       LEADING SET CALCULATION\n");
    printf("============================================\n");

    displayGrammar();

    findLeading();

    printf("\n============================================\n");
    printf("             PROGRAM ENDED\n");
    printf("============================================\n");

    return 0;
}