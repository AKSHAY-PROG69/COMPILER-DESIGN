#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *fp;

    char filename[100];
    char ch;

    int characters = 0;
    int words = 0;
    int lines = 0;

    int inWord = 0;

    printf("============================================\n");
    printf("          LEXICAL ANALYZER\n");
    printf("============================================\n");

    /* Get file name from user */
    printf("\nEnter the file name: ");
    scanf("%s", filename);

    /* Open the file */
    fp = fopen(filename, "r");

    /* Check whether file exists */
    if (fp == NULL)
    {
        printf("\nError: Unable to open the file.\n");
        printf("Please check the file name.\n");

        return 1;
    }

    printf("\nFile opened successfully!\n");

    /* Read file character by character */
    while ((ch = fgetc(fp)) != EOF)
    {
        /* Count every character */
        characters++;

        /* Count lines */
        if (ch == '\n')
        {
            lines++;
        }

        /*
           Check whether the current character
           is part of a word.
        */
        if (isspace(ch))
        {
            inWord = 0;
        }
        else
        {
            /*
               If previous character was whitespace
               and current character is not whitespace,
               a new word has started.
            */
            if (inWord == 0)
            {
                words++;
                inWord = 1;
            }
        }
    }

    /* Close the file */
    fclose(fp);

    /* Display results */
    printf("\n============================================\n");
    printf("             FILE ANALYSIS\n");
    printf("============================================\n");

    printf("\nNumber of Characters : %d", characters);
    printf("\nNumber of Words      : %d", words);
    printf("\nNumber of Lines      : %d", lines);

    printf("\n\n============================================\n");
    printf("              PROGRAM ENDED\n");
    printf("============================================\n");

    return 0;
}