#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

int tempCount = 1;

/* Push operator into stack */
void push(char ch)
{
    stack[++top] = ch;
}

/* Pop operator from stack */
char pop()
{
    if (top == -1)
        return '\0';

    return stack[top--];
}

/* Return top element */
char peek()
{
    if (top == -1)
        return '\0';

    return stack[top];
}

/* Check operator */
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' ||
        ch == '*' || ch == '/')
        return 1;

    return 0;
}

/* Return precedence of operator */
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    return 0;
}

/* Convert infix expression to postfix */
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        /* Ignore spaces */
        if (ch == ' ')
            continue;

        /* Operand */
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        /* Opening bracket */
        else if (ch == '(')
        {
            push(ch);
        }

        /* Closing bracket */
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1 && peek() == '(')
                pop();
        }

        /* Operator */
        else if (isOperator(ch))
        {
            while (top != -1 &&
                   peek() != '(' &&
                   precedence(peek()) >= precedence(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    /* Pop remaining operators */
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

/* Generate Three Address Code */
void generateTAC(char postfix[])
{
    char operandStack[MAX][20];
    int operandTop = -1;

    int i;

    char op1[20], op2[20], temp[20];

    printf("\nThree Address Code:\n");
    printf("--------------------------------\n");

    for (i = 0; postfix[i] != '\0'; i++)
    {
        /* If operand */
        if (isalnum(postfix[i]))
        {
            operandTop++;

            operandStack[operandTop][0] = postfix[i];
            operandStack[operandTop][1] = '\0';
        }

        /* If operator */
        else if (isOperator(postfix[i]))
        {
            /* Get second operand */
            strcpy(op2, operandStack[operandTop]);
            operandTop--;

            /* Get first operand */
            strcpy(op1, operandStack[operandTop]);
            operandTop--;

            /* Create temporary variable */
            sprintf(temp, "t%d", tempCount++);

            /* Generate TAC statement */
            printf("%s = %s %c %s\n",
                   temp,
                   op1,
                   postfix[i],
                   op2);

            /* Push temporary result */
            operandTop++;

            strcpy(operandStack[operandTop], temp);
        }
    }
}

/* Main function */
int main()
{
    char infix[MAX];
    char postfix[MAX];

    printf("============================================\n");
    printf("       THREE ADDRESS CODE GENERATOR\n");
    printf("============================================\n");

    printf("\nEnter an arithmetic expression: ");
    scanf("%s", infix);

    /* Convert infix to postfix */
    infixToPostfix(infix, postfix);

    printf("\nInfix Expression : %s", infix);
    printf("\nPostfix Expression: %s\n", postfix);

    /* Generate TAC */
    generateTAC(postfix);

    printf("--------------------------------\n");

    printf("\n============================================\n");
    printf("              PROGRAM ENDED\n");
    printf("============================================\n");

    return 0;
}