/* 6. Lexical Analyzer to test whether a given identifier is valid or not. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidIdentifier(char *id) {
    int i, len = strlen(id);
    char *keywords[] = {"int","float","char","double","if","else","while","for",
                         "return","void","break","continue"};
    if (len == 0) return 0;
    if (!isalpha(id[0]) && id[0] != '_') return 0;
    for (i = 1; i < len; i++)
        if (!isalnum(id[i]) && id[i] != '_') return 0;
    for (i = 0; i < 12; i++)
        if (strcmp(id, keywords[i]) == 0) return 0; /* keyword, not identifier */
    return 1;
}

int main() {
    char id[100];
    printf("Enter an identifier: ");
    scanf("%s", id);
    if (isValidIdentifier(id))
        printf("\"%s\" is a VALID identifier.\n", id);
    else
        printf("\"%s\" is NOT a valid identifier.\n", id);
    return 0;
}
