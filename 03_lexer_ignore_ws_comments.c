/* 3. Lexical Analyzer that ignores redundant spaces, tabs, new lines and comments,
   and prints the cleaned token stream. */
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char filename[100], ch;
    int lastWasSpace = 0;

    printf("Enter source file name (e.g. sample.c): ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (!fp) { printf("Could not open file.\n"); return 1; }

    printf("\nCleaned output (comments & redundant whitespace removed):\n\n");
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '/') {
            char next = fgetc(fp);
            if (next == '/') {
                while ((ch = fgetc(fp)) != EOF && ch != '\n');
                continue;
            } else if (next == '*') {
                char prev = 0;
                while ((ch = fgetc(fp)) != EOF) {
                    if (prev == '*' && ch == '/') break;
                    prev = ch;
                }
                continue;
            } else {
                putchar('/');
                if (next != EOF) ungetc(next, fp);
                lastWasSpace = 0;
                continue;
            }
        }
        if (isspace(ch)) {
            if (!lastWasSpace) { putchar(' '); lastWasSpace = 1; }
            continue;
        }
        putchar(ch);
        lastWasSpace = 0;
    }
    printf("\n");
    fclose(fp);
    return 0;
}
