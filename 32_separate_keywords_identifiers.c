/* 32. C program to separate keywords and identifiers from an input C
   source file (keywords are predefined reserved words). */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keywords[] = {
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","int","long","register",
    "return","short","signed","sizeof","static","struct","switch","typedef",
    "union","unsigned","void","volatile","while"
};
int numKeywords = 32;

int isKeyword(char *buffer) {
    int i;
    for (i = 0; i < numKeywords; i++)
        if (strcmp(buffer, keywords[i]) == 0) return 1;
    return 0;
}

int main() {
    FILE *fp;
    char filename[100], ch, buffer[100];
    int i;

    printf("Enter input C source file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (!fp) { printf("Could not open file.\n"); return 1; }

    printf("\nKeywords found:\n");
    fseek(fp, 0, SEEK_SET);
    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch) || ch == '_') {
            i = 0; buffer[i++] = ch;
            while ((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch=='_')) buffer[i++] = ch;
            buffer[i] = '\0';
            if (ch != EOF) ungetc(ch, fp);
            if (isKeyword(buffer)) printf("  %s\n", buffer);
        }
    }

    printf("\nIdentifiers found:\n");
    fseek(fp, 0, SEEK_SET);
    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch) || ch == '_') {
            i = 0; buffer[i++] = ch;
            while ((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch=='_')) buffer[i++] = ch;
            buffer[i] = '\0';
            if (ch != EOF) ungetc(ch, fp);
            if (!isKeyword(buffer)) printf("  %s\n", buffer);
        }
    }

    fclose(fp);
    return 0;
}
