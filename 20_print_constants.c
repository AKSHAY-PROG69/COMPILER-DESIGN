/* 20. C program to print all the constants (numeric literals) found
   in a given C source program file. */
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char filename[100], ch, buffer[100];
    int i;

    printf("Enter input C source file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (!fp) { printf("Could not open file.\n"); return 1; }

    printf("\nConstants found in the file:\n");
    while ((ch = fgetc(fp)) != EOF) {
        if (isdigit(ch)) {
            i = 0;
            buffer[i++] = ch;
            while ((ch = fgetc(fp)) != EOF && (isdigit(ch) || ch == '.'))
                buffer[i++] = ch;
            buffer[i] = '\0';
            if (ch != EOF) ungetc(ch, fp);
            printf("  %s\n", buffer);
        }
    }
    fclose(fp);
    return 0;
}
