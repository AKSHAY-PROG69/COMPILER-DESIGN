#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[100];
    int i, valid = 1;

    printf("Enter an Identifier: ");
    scanf("%s", str);

    // Check first character
    if(!(isalpha(str[0]) || str[0] == '_'))
        valid = 0;

    // Check remaining characters
    for(i = 1; str[i] != '\0'; i++)
    {
        if(!(isalnum(str[i]) || str[i] == '_'))
        {
            valid = 0;
            break;
        }
    }

    if(valid)
        printf("\nValid Identifier\n");
    else
        printf("\nInvalid Identifier\n");

    printf("\nCapital Letters:\n");

    for(i = 0; str[i] != '\0'; i++)
    {
        if(isupper(str[i]))
            printf("%c\n", str[i]);
    }

    return 0;
}