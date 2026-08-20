/* 26. C program to identify the capitalized words from a given input. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char text[500], word[100];
    int i = 0, j = 0;

    printf("Enter a sentence: ");
    fgets(text, sizeof(text), stdin);

    printf("\nCapitalized words:\n");
    for (i = 0; i <= (int)strlen(text); i++) {
        if (isalpha(text[i])) {
            word[j++] = text[i];
        } else {
            if (j > 0) {
                word[j] = '\0';
                if (isupper(word[0]))
                    printf("  %s\n", word);
                j = 0;
            }
        }
    }
    return 0;
}
