/* 2. Lexical Analyzer to check whether a given line is a comment or not.
   Recognizes // single-line comments and /* ... *\/ multi-line comments. */
#include <stdio.h>
#include <string.h>

int isComment(char *line) {
    int len = strlen(line);
    int i;
    /* trim leading spaces */
    for (i = 0; i < len && (line[i] == ' ' || line[i] == '\t'); i++);

    if (line[i] == '/' && line[i+1] == '/')
        return 1; /* single line comment */

    if (line[i] == '/' && line[i+1] == '*') {
        /* check for closing */
        char *end = strstr(line + i, "*/");
        if (end != NULL) return 2; /* complete /* ... *\/ comment on one line */
        return 3; /* multi-line comment start */
    }
    return 0;
}

int main() {
    char line[500];
    int result;
    printf("Enter a line of code:\n");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = 0;

    result = isComment(line);
    switch (result) {
        case 1: printf("The line is a single-line comment (//).\n"); break;
        case 2: printf("The line is a complete block comment (/* ... */).\n"); break;
        case 3: printf("The line begins a multi-line block comment (/* ...).\n"); break;
        default: printf("The line is NOT a comment.\n");
    }
    return 0;
}
