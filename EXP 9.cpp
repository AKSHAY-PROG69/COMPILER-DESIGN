#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char grammar[3][20] = {
    "AaAb",
    "BbBa",
    "e"
};

char nonTerminals[] = {'S', 'A', 'B'};

char follow[3][MAX];
int followCount[3] = {0, 0, 0};

/* Function to check whether a character is already present */
int isPresent(int index, char ch)
{
    int i;

    for (i = 0; i < followCount[index]; i++)
    {
        if (follow[index][i] == ch)
            return 1;
    }

    return 0;
}

/* Function to add a symbol to FOLLOW set */
void addFollow(int index, char ch)
{
    if (!isPresent(index, ch))
    {
        follow[index][followCount[index]] = ch;
        followCount[index]++;
    }
}

/* Function to find the index of a non-terminal */
int getIndex(char ch)
{
    int i;

    for (i = 0; i < 3; i++)
    {
        if (nonTerminals[i] == ch)
            return i;
    }

    return -1;
}

/* Function to display the grammar */
void displayGrammar()
{
    printf("\nGrammar:\n");
    printf("-------------------------\n");

    printf("S -> AaAb | BbBa\n");
    printf("A -> e\n");
    printf("B -> e\n");
}

/* Function to calculate FOLLOW sets */
void findFollow()
{
    int i;

    /*
       S is the start symbol.
       Therefore, $ belongs to FOLLOW(S).
    */
    addFollow(getIndex('S'), '$');

    /*
       Production:
       S -> AaAb

       First A is followed by 'a'
       Therefore, 'a' belongs to FOLLOW(A).

       Second A is followed by 'b'
       Therefore, 'b' belongs to FOLLOW(A).
    */

    addFollow(getIndex('A'), 'a');
    addFollow(getIndex('A'), 'b');

    /*
       Production:
       S -> BbBa

       First B is followed by 'b'
       Therefore, 'b' belongs to FOLLOW(B).

       Second B is followed by 'a'
       Therefore, 'a' belongs to FOLLOW(B).
    */

    addFollow(getIndex('B'), 'b');
    addFollow(getIndex('B'), 'a');
}

/* Function to display FOLLOW sets */
void displayFollow()
{
    int i, j;

    printf("\nFOLLOW Sets:\n");
    printf("-------------------------\n");

    for (i = 0; i < 3; i++)
    {
        printf("FOLLOW(%c) = { ", nonTerminals[i]);

        for (j = 0; j < followCount[i]; j++)
        {
            printf("%c", follow[i][j]);

            if (j < followCount[i] - 1)
                printf(", ");
        }

        printf(" }\n");
    }
}

int main()
{
    printf("========================================\n");
    printf("       FOLLOW SET CALCULATION\n");
    printf("========================================\n");

    displayGrammar();

    findFollow();

    displayFollow();

    printf("\n========================================\n");
    printf("            PROGRAM ENDED\n");
    printf("========================================\n");

    return 0;
}