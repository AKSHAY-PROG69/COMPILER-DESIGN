#include <stdio.h>
#include <string.h>

int main()
{
    char url[100];
    int valid = 0;

    printf("Enter URL: ");
    scanf("%s", url);

    if(strncmp(url, "http://", 7) == 0 ||
       strncmp(url, "https://", 8) == 0)
    {
        valid = 1;
    }

    if(valid)
        printf("Valid URL\n");
    else
        printf("Invalid URL\n");

    return 0;
}