/* 5. Lexical Analyzer to find the number of whitespaces and newline characters. */
#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100], ch;
    int spaces = 0, tabs = 0, newlines = 0;

    printf("Enter source file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (!fp) { printf("Could not open file.\n"); return 1; }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ') spaces++;
        else if (ch == '\t') tabs++;
        else if (ch == '\n') newlines++;
    }
    fclose(fp);

    printf("Number of spaces   : %d\n", spaces);
    printf("Number of tabs     : %d\n", tabs);
    printf("Number of newlines : %d\n", newlines);
    printf("Total whitespace   : %d\n", spaces + tabs + newlines);
    return 0;
}
