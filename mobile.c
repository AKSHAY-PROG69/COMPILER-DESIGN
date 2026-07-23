#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char mobile[20];
    int i, valid = 1;

    printf("Enter Mobile Number: ");
    scanf("%s", mobile);

    if(strlen(mobile) != 10)
        valid = 0;

    for(i = 0; mobile[i] != '\0'; i++)
    {
        if(!isdigit(mobile[i]))
        {
            valid = 0;
            break;
        }
    }

    if(valid && (mobile[0] < '6' || mobile[0] > '9'))
        valid = 0;

    if(valid)
        printf("Valid Mobile Number\n");
    else
        printf("Invalid Mobile Number\n");

    return 0;
}