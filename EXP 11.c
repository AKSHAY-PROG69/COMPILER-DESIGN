#include <stdio.h>
#include <string.h>

#define MAX 100

/* Function to display the original grammar */
void displayOriginalGrammar()
{
    printf("\nOriginal Grammar:\n");
    printf("-----------------------------\n");

    printf("S -> iEtS | iEtSeS | a\n");
    printf("E -> b\n");
}

/* Function to identify common prefix */
void findCommonPrefix()
{
    char production1[] = "iEtS";
    char production2[] = "iEtSeS";

    int i = 0;

    printf("\nFinding Common Prefix:\n");
    printf("-----------------------------\n");

    while (production1[i] != '\0' &&
           production2[i] != '\0' &&
           production1[i] == production2[i])
    {
        printf("%c", production1[i]);
        i++;
    }

    printf("\n");
}

/* Function to eliminate left factoring */
void eliminateLeftFactoring()
{
    printf("\nLeft Factoring Process:\n");
    printf("-----------------------------\n");

    printf("Common prefix = iEtS\n");

    printf("\nOriginal productions:\n");
    printf("S -> iEtS | iEtSeS | a\n");

    printf("\nApplying left factoring:\n");

    printf("S -> iEtS S' | a\n");
    printf("S' -> eS | e\n");

    printf("\nFinal Grammar:\n");
    printf("-----------------------------\n");

    printf("S  -> iEtS S' | a\n");
    printf("S' -> eS | e\n");
    printf("E  -> b\n");
}

/* Main function */
int main()
{
    printf("============================================\n");
    printf("       LEFT FACTORING OF CFG\n");
    printf("============================================\n");

    displayOriginalGrammar();

    findCommonPrefix();

    eliminateLeftFactoring();

    printf("\n============================================\n");
    printf("              PROGRAM ENDED\n");
    printf("============================================\n");

    return 0;
}