#include <stdio.h>
#include <string.h>

int main()
{
    char email[100];
    int i, at = 0, dot = 0, valid = 1;

    printf("Enter Email: ");
    scanf("%s", email);

    for(i = 0; email[i] != '\0'; i++)
    {
        if(email[i] == '@')
            at++;

        if(email[i] == '.' && at > 0)
            dot++;
    }

    if(at != 1 || dot == 0)
        valid = 0;

    if(valid)
        printf("Valid Email\n");
    else
        printf("Invalid Email\n");

    return 0;
}