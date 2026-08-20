/* 1. Lexical Analyzer to identify identifiers, constants and operators.
   Ignores redundant spaces, tabs, newlines and comments (both comment styles). */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 100

int isKeyword(char *buffer) {
    char *keywords[] = {"int","float","char","double","if","else","while","for",
                         "return","void","break","continue","switch","case","default"};
    int i;
    for (i = 0; i < 15; i++)
        if (strcmp(buffer, keywords[i]) == 0) return 1;
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[MAXLEN];
    int i = 0;
    char filename[100];

    printf("Enter source file name (e.g. sample.c): ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (!fp) { printf("Could not open file %s\n", filename); return 1; }

    while ((ch = fgetc(fp)) != EOF) {
        /* skip whitespace */
        if (isspace(ch)) continue;

        /* skip single-line comments */
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
                printf("Operator: /\n");
                if (next != EOF) ungetc(next, fp);
                continue;
            }
        }

        /* identifiers / keywords */
        if (isalpha(ch) || ch == '_') {
            i = 0;
            buffer[i++] = ch;
            while ((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch == '_'))
                buffer[i++] = ch;
            buffer[i] = '\0';
            if (ch != EOF) ungetc(ch, fp);
            if (isKeyword(buffer))
                printf("Keyword: %s\n", buffer);
            else
                printf("Identifier: %s\n", buffer);
            continue;
        }

        /* constants (numbers) */
        if (isdigit(ch)) {
            i = 0;
            buffer[i++] = ch;
            while ((ch = fgetc(fp)) != EOF && (isdigit(ch) || ch == '.'))
                buffer[i++] = ch;
            buffer[i] = '\0';
            if (ch != EOF) ungetc(ch, fp);
            printf("Constant: %s\n", buffer);
            continue;
        }

        /* operators */
        if (strchr("+-*/%=<>!&|", ch)) {
            printf("Operator: %c\n", ch);
            continue;
        }

        /* punctuation - ignored/printed separately */
        if (strchr("(){}[];,", ch)) {
            printf("Punctuation: %c\n", ch);
            continue;
        }
    }
    fclose(fp);
    return 0;
}
