#include <stdio.h>
#include <string.h>

#define MAX 100

/* Function to display the original grammar */
void displayOriginalGrammar()
{
    printf("\nOriginal Grammar:\n");
    printf("-----------------------------\n");

    printf("S -> (L) | a\n");
    printf("L -> L,S | S\n");
}

/* Function to eliminate left recursion */
void eliminateLeftRecursion()
{
    char nonTerminal = 'L';

    char alpha[MAX] = ",S";
    char beta[MAX] = "S";

    printf("\nLeft Recursive Production Detected:\n");
    printf("------------------------------------\n");

    printf("%c -> %c%s | %s\n",
           nonTerminal,
           nonTerminal,
           alpha,
           beta);

    printf("\nApplying the formula:\n");
    printf("A -> Aalpha | beta\n");
    printf("A  -> beta A'\n");
    printf("A' -> alpha A' | epsilon\n");

    printf("\nSubstituting values:\n");
    printf("A     = L\n");
    printf("alpha = ,S\n");
    printf("beta  = S\n");

    printf("\nGrammar After Eliminating Left Recursion:\n");
    printf("------------------------------------------\n");

    printf("S  -> (L) | a\n");
    printf("L  -> S L'\n");
    printf("L' -> , S L' | e\n");
}

/* Main function */
int main()
{
    printf("============================================\n");
    printf("      LEFT RECURSION ELIMINATION\n");
    printf("============================================\n");

    displayOriginalGrammar();

    eliminateLeftRecursion();

    printf("\n============================================\n");
    printf("              PROGRAM ENDED\n");
    printf("============================================\n");

    return 0;
}