#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i, count = 0;

    printf("Enter a String: ");
    fgets(str, sizeof(str), stdin);

    printf("\nVowels Found:\n");

    for(i = 0; str[i] != '\0'; i++)
    {
        char ch = tolower(str[i]);

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            printf("%c\n", str[i]);
            count++;
        }
    }

    printf("\nTotal Vowels = %d\n", count);

    return 0;
}
