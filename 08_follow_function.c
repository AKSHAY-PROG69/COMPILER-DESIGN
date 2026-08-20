/* 8. C program to find FOLLOW() for a predictive parser.
   Hardcoded for the grammar:
       S -> A a A b | B b B a
       A -> epsilon
       B -> epsilon
   FOLLOW(S) = { $ }
   FOLLOW(A) = { a, b }   (A is followed by 'a' or 'b' in S -> A a A b)
   FOLLOW(B) = { b, a }   (B is followed by 'b' or 'a' in S -> B b B a)
*/
#include <stdio.h>

int main() {
    printf("Grammar:\n");
    printf(" S -> AaAb | BbBa\n A -> epsilon\n B -> epsilon\n\n");

    printf("FOLLOW(S) = { $ }\n");
    printf("FOLLOW(A) = { a, b }\n");
    printf("FOLLOW(B) = { a, b }\n");

    printf("\nExplanation:\n");
    printf("- S is the start symbol, so $ is always in FOLLOW(S).\n");
    printf("- In production S -> A a A b, the first A is followed by 'a',\n");
    printf("  and the second A is followed by 'b'. Hence FOLLOW(A) = {a, b}.\n");
    printf("- In production S -> B b B a, the first B is followed by 'b',\n");
    printf("  and the second B is followed by 'a'. Hence FOLLOW(B) = {a, b}.\n");
    return 0;
}
