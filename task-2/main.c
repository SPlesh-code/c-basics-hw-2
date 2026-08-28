#include <stdio.h>

int Primary(int *n, int divisor) {
    if (*n < 2)
        return 0;

    if (divisor * divisor > *n)
        return 1;

    if (*n % divisor == 0)
        return 0;

    return Primary(n, divisor + 1);
}

int main() {
    int num;

    printf("Enter number: ");
    scanf("%d", &num);

    if (Primary(&num, 2))
        printf("%d is prime\n", num);
    else
        printf("%d is not prime\n", num);

    return 0;
}
