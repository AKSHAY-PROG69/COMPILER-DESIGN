#include <stdio.h>
#include <string.h>

void add(char first[], char c)
{
    int i;

    for (i = 0; first[i] != '\0'; i++)
    {
        if (first[i] == c)
            return;
    }

    first[i] = c;
    first[i + 1] = '\0';
}

int main()
{
    char firstS[10] = "";
    char firstA[10] = "";
    char firstB[10] = "";

    /*
        Grammar:
        S -> AaAb | BbBa
        A -> epsilon
        B -> epsilon
    */

    /* FIRST(A) */
    add(firstA, 'e');   // e represents epsilon

    /* FIRST(B) */
    add(firstB, 'e');

    /*
       FIRST(S):
       S -> AaAb
       A -> epsilon
       Therefore first terminal is 'a'

       S -> BbBa
       B -> epsilon
       Therefore first terminal is 'b'
    */
    add(firstS, 'a');
    add(firstS, 'b');

    printf("Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> epsilon\n");
    printf("B -> epsilon\n\n");

    printf("FIRST(S) = { ");
    for (int i = 0; firstS[i] != '\0'; i++)
        printf("%c ", firstS[i]);
    printf("}\n");

    printf("FIRST(A) = { epsilon }\n");
    printf("FIRST(B) = { epsilon }\n");

    return 0;
}