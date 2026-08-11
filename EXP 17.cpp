#include <stdio.h>
#include <string.h>

#define MAX 100

/* Structure for Three Address Code */
struct TAC
{
    char result[20];
    char arg1[20];
    char op[5];
    char arg2[20];
};

struct TAC code[MAX];

int n;

/* Function to generate target code */
void generateTargetCode()
{
    int i;

    printf("\n============================================\n");
    printf("            TARGET CODE\n");
    printf("============================================\n");

    for (i = 0; i < n; i++)
    {
        printf("\nInstruction %d:\n", i + 1);

        /* Load first operand into register */
        printf("MOV R0, %s\n", code[i].arg1);

        /* Perform operation */
        if (strcmp(code[i].op, "+") == 0)
        {
            printf("ADD R0, %s\n", code[i].arg2);
        }
        else if (strcmp(code[i].op, "-") == 0)
        {
            printf("SUB R0, %s\n", code[i].arg2);
        }
        else if (strcmp(code[i].op, "*") == 0)
        {
            printf("MUL R0, %s\n", code[i].arg2);
        }
        else if (strcmp(code[i].op, "/") == 0)
        {
            printf("DIV R0, %s\n", code[i].arg2);
        }
        else
        {
            printf("Unknown operator!\n");
        }

        /* Store result */
        printf("MOV %s, R0\n", code[i].result);
    }
}

/* Function to display TAC */
void displayTAC()
{
    int i;

    printf("\n============================================\n");
    printf("       THREE ADDRESS CODE\n");
    printf("============================================\n");

    for (i = 0; i < n; i++)
    {
        printf("%s = %s %s %s\n",
               code[i].result,
               code[i].arg1,
               code[i].op,
               code[i].arg2);
    }
}

/* Main function */
int main()
{
    int i;

    printf("============================================\n");
    printf("       BACK END OF THE COMPILER\n");
    printf("============================================\n");

    printf("\nEnter number of Three Address Code statements: ");
    scanf("%d", &n);

    printf("\nEnter the Three Address Code:\n");
    printf("Format: result operand1 operator operand2\n");

    for (i = 0; i < n; i++)
    {
        printf("\nStatement %d: ", i + 1);

        scanf("%s %s %s %s",
              code[i].result,
              code[i].arg1,
              code[i].op,
              code[i].arg2);
    }

    /* Display input TAC */
    displayTAC();

    /* Generate target code */
    generateTargetCode();

    printf("\n============================================\n");
    printf("             PROGRAM ENDED\n");
    printf("============================================\n");

    return 0;
}