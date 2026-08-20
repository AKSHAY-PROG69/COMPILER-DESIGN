/* 25. C program to count the number of comment lines in a given C
   program and eliminate them, writing the remaining code into another file. */
#include <stdio.h>

int main() {
    FILE *in, *out;
    char infile[100], outfile[100] = "output_no_comments.c";
    char ch;
    int commentLines = 0;
    int inLineComment = 0, inBlockComment = 0;

    printf("Enter input C source file name: ");
    scanf("%s", infile);
    in = fopen(infile, "r");
    if (!in) { printf("Could not open file.\n"); return 1; }
    out = fopen(outfile, "w");

    while ((ch = fgetc(in)) != EOF) {
        if (!inLineComment && !inBlockComment && ch == '/') {
            char next = fgetc(in);
            if (next == '/') { inLineComment = 1; commentLines++; continue; }
            else if (next == '*') { inBlockComment = 1; commentLines++; continue; }
            else { fputc(ch, out); if (next != EOF) fputc(next, out); continue; }
        }
        if (inLineComment) {
            if (ch == '\n') { inLineComment = 0; fputc(ch, out); }
            continue;
        }
        if (inBlockComment) {
            if (ch == '\n') commentLines++;
            if (ch == '*') {
                char next = fgetc(in);
                if (next == '/') { inBlockComment = 0; continue; }
                if (next != EOF) ungetc(next, in);
            }
            continue;
        }
        fputc(ch, out);
    }
    fclose(in);
    fclose(out);

    printf("\nNumber of comment lines removed: %d\n", commentLines);
    printf("Comment-free code written to: %s\n", outfile);
    return 0;
}
