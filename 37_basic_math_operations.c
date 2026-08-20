/* 37. C program to perform basic mathematical operations
   (+, -, *, /, %) on two numbers entered by the user. */
#include <stdio.h>

int main() {
    double a, b;
    char op;

    printf("Enter first number: ");
    scanf("%lf", &a);
    printf("Enter operator (+, -, *, /, %%): ");
    scanf(" %c", &op);
    printf("Enter second number: ");
    scanf("%lf", &b);

    switch (op) {
        case '+': printf("Result: %.2lf\n", a + b); break;
        case '-': printf("Result: %.2lf\n", a - b); break;
        case '*': printf("Result: %.2lf\n", a * b); break;
        case '/':
            if (b != 0) printf("Result: %.2lf\n", a / b);
            else printf("Error: division by zero.\n");
            break;
        case '%':
            printf("Result: %d\n", (int)a % (int)b);
            break;
        default: printf("Invalid operator.\n");
    }
    return 0;
}
