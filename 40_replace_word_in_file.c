/* 40. C program to replace a word with another word in a given file. */
#include <stdio.h>
#include <string.h>

int main() {
    FILE *in, *out;
    char infile[100], outfile[100] = "output_replaced.txt";
    char oldWord[100], newWord[100];
    char line[1000], result[2000];
    char *pos, *lineStart;

    printf("Enter input file name: ");
    scanf("%s", infile);
    printf("Enter word to replace: ");
    scanf("%s", oldWord);
    printf("Enter new word: ");
    scanf("%s", newWord);

    in = fopen(infile, "r");
    if (!in) { printf("Could not open file.\n"); return 1; }
    out = fopen(outfile, "w");

    while (fgets(line, sizeof(line), in)) {
        result[0] = '\0';
        lineStart = line;
        while ((pos = strstr(lineStart, oldWord)) != NULL) {
            strncat(result, lineStart, pos - lineStart);
            strcat(result, newWord);
            lineStart = pos + strlen(oldWord);
        }
        strcat(result, lineStart);
        fputs(result, out);
    }

    fclose(in);
    fclose(out);
    printf("\nReplacement complete. Output written to: %s\n", outfile);
    return 0;
}
