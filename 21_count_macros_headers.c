/* 21. C program to count the number of macros (#define) and header
   files (#include) in a given C source program. */
#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], line[300];
    int macros = 0, headers = 0;

    printf("Enter input C source file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (!fp) { printf("Could not open file.\n"); return 1; }

    while (fgets(line, sizeof(line), fp)) {
        char *trimmed = line;
        while (*trimmed == ' ' || *trimmed == '\t') trimmed++;
        if (strncmp(trimmed, "#define", 7) == 0) macros++;
        if (strncmp(trimmed, "#include", 8) == 0) headers++;
    }
    fclose(fp);

    printf("\nNumber of macros (#define)   : %d\n", macros);
    printf("Number of header files (#include): %d\n", headers);
    return 0;
}
