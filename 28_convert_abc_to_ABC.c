/* 28. C program to convert every occurrence of the substring "abc" to
   "ABC" in a given input string. */
#include <stdio.h>
#include <string.h>

int main() {
    char text[500], result[600];
    int i = 0, j = 0, len;

    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;
    len = strlen(text);

    while (i < len) {
        if (i + 2 < len && text[i]=='a' && text[i+1]=='b' && text[i+2]=='c') {
            result[j++] = 'A';
            result[j++] = 'B';
            result[j++] = 'C';
            i += 3;
        } else {
            result[j++] = text[i++];
        }
    }
    result[j] = '\0';

    printf("Converted string: %s\n", result);
    return 0;
}
