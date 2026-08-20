/* 7. C program to find FIRST() for a predictive parser.
   Hardcoded for the grammar:
       S -> A a A b | B b B a
       A -> epsilon
       B -> epsilon
   (epsilon is represented by '#') */
#include <stdio.h>
#include <string.h>

#define MAXP 10
#define MAXL 10

char productions[MAXP][MAXL] = {
    "S=AaAb",
    "S=BbBa",
    "A=#",
    "B=#"
};
int numProd = 4;

char nonTerminals[] = "SAB";

void findFirst(char nt, int visited[]);

void printFirst(char nt) {
    int visited[128] = {0};
    printf("FIRST(%c) = { ", nt);
    findFirst(nt, visited);
    printf("}\n");
}

int printedSet[128] = {0};

void addToFirst(char c) {
    if (!printedSet[(int)c]) {
        printf("%c ", c);
        printedSet[(int)c] = 1;
    }
}

void findFirst(char nt, int visited[]) {
    int i;
    if (visited[(int)nt]) return;
    visited[(int)nt] = 1;

    for (i = 0; i < numProd; i++) {
        if (productions[i][0] == nt) {
            char first = productions[i][2]; /* char right after '=' */
            if (first == '#') {
                addToFirst('#');
            } else if (isupper(first)) {
                /* first symbol is a non-terminal: recurse */
                findFirst(first, visited);
            } else {
                addToFirst(first);
            }
        }
    }
}

int main() {
    int i;
    printf("Grammar:\n");
    printf(" S -> AaAb | BbBa\n A -> epsilon(#)\n B -> epsilon(#)\n\n");
    for (i = 0; i < 3; i++) {
        memset(printedSet, 0, sizeof(printedSet));
        printFirst(nonTerminals[i]);
    }
    return 0;
}
