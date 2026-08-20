/* 19. C program (LEX-style behaviour implemented in plain C) that takes
   an input C source file and counts the number of characters, lines
   and words in it, ignoring redundant spaces/tabs/newlines and comments. */
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char filename[100], ch, prev = 0;
    long chars = 0, words = 0, lines = 0;
    int inWord = 0;

    printf("Enter input C source file name (e.g. sample.c): ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (!fp) { printf("Could not open file.\n"); return 1; }

    while ((ch = fgetc(fp)) != EOF) {
        /* skip comments so they are not counted */
        if (ch == '/' ) {
            char next = fgetc(fp);
            if (next == '/') {
                while ((ch = fgetc(fp)) != EOF && ch != '\n');
                lines++;
                inWord = 0;
                continue;
            } else if (next == '*') {
                char p = 0;
                while ((ch = fgetc(fp)) != EOF) {
                    if (ch == '\n') lines++;
                    if (p == '*' && ch == '/') break;
                    p = ch;
                }
                continue;
            } else {
                if (next != EOF) ungetc(next, fp);
            }
        }

        chars++;
        if (ch == '\n') lines++;
        if (isspace(ch)) inWord = 0;
        else if (!inWord) { inWord = 1; words++; }
        prev = ch;
    }
    fclose(fp);

    printf("\nCharacters : %ld\n", chars);
    printf("Words      : %ld\n", words);
    printf("Lines      : %ld\n", lines);
    return 0;
}
