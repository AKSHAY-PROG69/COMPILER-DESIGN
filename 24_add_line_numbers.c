/* 24. C program that adds line numbers to a given C program file and
   displays the result on the standard output. */
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], line[500];
    int lineNum = 1;

    printf("Enter input file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (!fp) { printf("Could not open file.\n"); return 1; }

    while (fgets(line, sizeof(line), fp)) {
        printf("%4d: %s", lineNum++, line);
        if (line[0] != '\0' && line[strlen(line) - 1] != '\n')
            printf("\n");
    }
    fclose(fp);
    return 0;
}
