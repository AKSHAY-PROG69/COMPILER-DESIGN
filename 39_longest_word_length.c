/* 39. C program to find the length of the longest word in a given
   sentence. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[500], word[100], longest[100] = "";
    int i = 0, j = 0, maxLen = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (i = 0; i <= (int)strlen(sentence); i++) {
        if (isalpha(sentence[i])) {
            word[j++] = sentence[i];
        } else {
            if (j > 0) {
                word[j] = '\0';
                if (j > maxLen) {
                    maxLen = j;
                    strcpy(longest, word);
                }
                j = 0;
            }
        }
    }
    printf("Longest word : %s\n", longest);
    printf("Length       : %d\n", maxLen);
    return 0;
}
