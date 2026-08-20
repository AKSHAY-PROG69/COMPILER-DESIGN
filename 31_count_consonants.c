/* 31. C program to count the number of consonants in a given word/sentence. */
#include <stdio.h>
#include <ctype.h>

int main() {
    char sentence[500];
    int i, count = 0;

    printf("Enter a word/sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (i = 0; sentence[i] != '\0'; i++) {
        char c = tolower(sentence[i]);
        if (isalpha(c) && !(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'))
            count++;
    }
    printf("Number of consonants: %d\n", count);
    return 0;
}
