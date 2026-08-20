/* 23. C program to print all HTML tags found in an input file. */
#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100], ch, buffer[200];
    int i;

    printf("Enter input HTML file name (e.g. sample.html): ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (!fp) { printf("Could not open file.\n"); return 1; }

    printf("\nHTML tags found:\n");
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '<') {
            i = 0;
            buffer[i++] = ch;
            while ((ch = fgetc(fp)) != EOF && ch != '>')
                buffer[i++] = ch;
            if (ch == '>') buffer[i++] = ch;
            buffer[i] = '\0';
            printf("  %s\n", buffer);
        }
    }
    fclose(fp);
    return 0;
}
