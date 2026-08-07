#include <stdio.h>

int main()
{
    int day, month, year;

    printf("Enter DOB (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &day, &month, &year);

    if(day >= 1 && day <= 31 &&
       month >= 1 && month <= 12 &&
       year >= 1900 && year <= 2100)
    {
        printf("Valid DOB\n");
    }
    else
    {
        printf("Invalid DOB\n");
    }

    return 0;
}