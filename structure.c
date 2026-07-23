#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;

    printf("Enter Input (Press Ctrl+Z and Enter to Stop):\n");

    while((ch = getchar()) != EOF)
    {
        if(isalpha(ch))
        {
            printf("Word : ");

            while(isalpha(ch))
            {
                putchar(ch);
                ch = getchar();
            }

            printf("\n");
        }

        if(isdigit(ch))
        {
            printf("Number : ");

            while(isdigit(ch))
            {
                putchar(ch);
                ch = getchar();
            }

            printf("\n");
        }
    }

    return 0;
}