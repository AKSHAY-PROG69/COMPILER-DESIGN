/* 33. C program to identify and count positive and negative numbers in
   a given input. */
#include <stdio.h>

int main() {
    int n, i, num, positives = 0, negatives = 0, zeros = 0;

    printf("Enter how many numbers you want to enter: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num > 0) positives++;
        else if (num < 0) negatives++;
        else zeros++;
    }

    printf("\nPositive numbers: %d\n", positives);
    printf("Negative numbers: %d\n", negatives);
    printf("Zeros            : %d\n", zeros);
    return 0;
}
